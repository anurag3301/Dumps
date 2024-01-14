#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include <string.h>
#include <time.h>

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

int main(){
    /* SetConfigFlags(FLAG_WINDOW_RESIZABLE); */

    InitWindow(800, 600, "K-Means");
    Samples set = {0};
    generate_cluster(CLITERAL(Vector2){0}, 10, 100, &set);
    generate_cluster(CLITERAL(Vector2){MIN_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);
    generate_cluster(CLITERAL(Vector2){MAX_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);


    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_R)){
            set.count = 0;
            generate_cluster(CLITERAL(Vector2){0}, 10, 100, &set);
            generate_cluster(CLITERAL(Vector2){MIN_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);
            generate_cluster(CLITERAL(Vector2){MAX_X*0.5f, MAX_Y*0.5f}, 5, 50, &set);
            for(size_t i=0; i<K; i++){
                means[i].x = Lerp(MIN_X, MAX_X, rand_float());
                means[i].y = Lerp(MIN_Y, MAX_Y, rand_float());
            }
        }
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));
        for(size_t i=0; i<set.count; i++){
            Vector2 it = set.items[i];
            DrawCircleV(project_sample_to_screen(it), SCREEN_RADIUS, RED);
        }
        for(size_t i=0; i<K; i++){
            Vector2 it = means[i];
            DrawCircleV(project_sample_to_screen(it), MEAN_RADIUS, colours[i%colour_count]);
        }
        EndDrawing();
    }
    free(set.items);
    CloseWindow();
    return 0;
}
