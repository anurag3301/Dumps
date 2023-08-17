#include <iostream>
#include <SDL2/SDL.h>
#define HEIGHT 500
#define WIDTH 500

using std::cout;
using std::cerr;
using std::endl;

int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL init failed" << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

    if(window == NULL){
        cerr << "SDL window failed to initialise: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }


    SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGB888,
            SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);

    Uint32 *buffer = new Uint32[WIDTH * HEIGHT];
    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    delete []buffer;
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
