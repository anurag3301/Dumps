#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <float.h>

#define SCREEN_RADIUS 5
#define MEAN_RADIUS (SCREEN_RADIUS*2)
#define MIN_X -20.0
#define MAX_X 20.0
#define MIN_Y -20.0
#define MAX_Y 20.0
#define K 3

static Vector2 project_sample_to_screen(Vector2 sample){

    float w = GetScreenWidth();
    float h = GetScreenHeight();
    return CLITERAL(Vector2){
        .x = (sample.x - MIN_X)/(MAX_X - MIN_X)*w,
        .y = h - (sample.y - MIN_Y)/(MAX_X - MIN_X)*h
    };
}

typedef struct{
    Vector2 *items;
    size_t count;
    size_t capacity;
} Samples;

static float rand_float(){
    return (float)rand()/RAND_MAX;
}

static void resize(Samples *samples){
    if(samples->capacity == 0){
        samples->capacity = 4;
        samples->items = malloc(sizeof(Vector2) * samples->capacity);
        return;
    }
    samples->capacity *= 2;
    Vector2 *new_items = malloc(sizeof(Vector2) * samples->capacity);
    memcpy(new_items, samples->items, sizeof(Vector2)*samples->count);
    free(samples->items);
    samples->items = new_items;
}

static void generate_cluster(Vector2 center, float radius, size_t count, Samples *samples){
    for(size_t i=0; i<count; i++){
        float angle = rand_float()*2*PI;
        float mag = rand_float();
        Vector2 sample = {
            .x = center.x + cosf(angle)*mag*radius,
            .y = center.y + sinf(angle)*mag*radius,
        };
        if(samples->count == samples->capacity){
            resize(samples);
        }
        samples->items[samples->count++] = sample;
    }
}

Color colours[] = {GOLD, PINK, MAROON, GREEN, 
                 SKYBLUE, PURPLE, VIOLET, BEIGE, BROWN};
static int colour_count = sizeof(colours)/sizeof(Color);
static Samples cluster[K] = {0};
static Vector2 means[K] = {0};
static Samples set = {0};


static void generate_new_state(void){
    set.count = 0;
    generate_cluster(CLITERAL(Vector2){0}, 10, 100, &set);
    generate_cluster(CLITERAL(Vector2){MIN_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);
    generate_cluster(CLITERAL(Vector2){MAX_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);
    for(size_t i=0; i<K; i++){
        means[i].x = Lerp(MIN_X, MAX_X, rand_float());
        means[i].y = Lerp(MIN_Y, MAX_Y, rand_float());
    }
}

static void recluster_state(void){
    for(size_t j=0; j<K; j++){
        cluster[j].count = 0;
    }

    for(size_t i = 0; i<set.count; i++){
        Vector2 p = set.items[i];
        int k = -1;
        float s = FLT_MAX;
        for(size_t j=0; j<K; j++){
            Vector2 m = means[j];
            float sm = Vector2LengthSqr(Vector2Subtract(p, m));
            if(sm < s){
                s = sm;
                k = j;
            }
        }

        if(cluster[k].count == cluster[k].capacity){
            resize(&cluster[k]);
        }
        cluster[k].items[cluster[k].count++] = p;
    }
}

void update_means(void){
    for(size_t i=0; i<K; i++){
        if(cluster[i].count > 0){
            assert(cluster[i].count > 0);
            means[i] = Vector2Zero();
            for(size_t j=0; j<cluster[i].count; j++){
                means[i] = Vector2Add(means[i], cluster[i].items[j]);
            }
            means[i].x /= cluster[i].count;
            means[i].y /= cluster[i].count;
        }else{
            means[i].x = Lerp(MIN_X, MAX_X, rand_float());
            means[i].y = Lerp(MIN_Y, MAX_Y, rand_float());
        }
    }
}

int main(){
    /* SetConfigFlags(FLAG_WINDOW_RESIZABLE); */

    InitWindow(800, 600, "K-Means");

    generate_new_state();
    recluster_state();

    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_R)){
            generate_new_state();
            recluster_state();
        }
        if(IsKeyPressed(KEY_SPACE)){
            update_means();
            recluster_state();
        }
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));
        for(size_t i=0; i<set.count; i++){
            Vector2 it = set.items[i];
            DrawCircleV(project_sample_to_screen(it), SCREEN_RADIUS, WHITE);
        }
        for(size_t i=0; i<K; i++){
            Color colour = colours[i%colour_count];
            for(size_t j=0; j<cluster[i].count; j++){
                Vector2 it = cluster[i].items[j];
                DrawCircleV(project_sample_to_screen(it), SCREEN_RADIUS, colour);
            }
            DrawCircleV(project_sample_to_screen(means[i]), MEAN_RADIUS, colour);
        }
        EndDrawing();
    }
    free(set.items);
    CloseWindow();
    return 0;
}
