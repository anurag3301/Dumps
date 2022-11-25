#include <iostream>
#include <SDL2/SDL.h>

using std::cout;
using std::cerr;
using std::endl;

int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL init failed" << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", 
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, 0);

    if(window == NULL){
        cerr << "SDL window failed to initialise: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }

    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
