#include <iostream>
#include <SDL/SDL.h>

using std::cout;
using std::endl;

int main(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL init failed" << endl;
        return 1;
    }

    cout << "SDL Init succeeded..." << endl;
    SDL_Quit();
    return 0;
}
