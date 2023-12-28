#include <stdio.h>
#include <raylib.h>

int main(void){

    InitWindow(800, 600, "Musializer");
    SetTargetFPS(60);

    InitAudioDevice();
    Music music = LoadMusicStream("sounds/gris.mp3");
    PlayMusicStream(music);
    while(!WindowShouldClose()){
        UpdateMusicStream(music);
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    } 
}
