#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <math.h>
#include <string.h>

#define MIN_X -20.0
#define MAX_X 20.0
#define MIN_Y -20.0
#define MAX_Y 20.0

Vector2 project_sample_to_screen(Vector2 sample){
    
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

float rand_float(){
    return (float)rand()/RAND_MAX;
}

void resize(Samples *samples){
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

void generate_cluster(Vector2 center, float radius, size_t count, Samples *samples){
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

int main(){
    /* SetConfigFlags(FLAG_WINDOW_RESIZABLE); */

    InitWindow(800, 600, "K-Means");
    Samples cluster = {0};
    generate_cluster(CLITERAL(Vector2){0}, 10, 100, &cluster);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));
        for(size_t i=0; i<cluster.count; i++){
            Vector2 it = cluster.items[i];
            DrawCircleV(project_sample_to_screen(it), 10, RED);
        }
        EndDrawing();
    }
    free(cluster.items);
    CloseWindow();
    return 0;
}
