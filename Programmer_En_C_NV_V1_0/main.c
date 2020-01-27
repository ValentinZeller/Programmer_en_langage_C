#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(0));
    SDL_Window *pWindow=NULL; //Pointeur typedef SDL_Window possède la référence d'une window(Win32)
    SDL_Renderer *pRenderer=NULL;//Pointeur typedef SDL_Renderer possède la référence du rendu encapsule dans une window
    SDL_Texture *pTexture=NULL;//Pointeur typedef SDL_Texture possède la référence de l'objet image, materiel ou texture qui sera blite dans le renderer

    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        pWindow = SDL_CreateWindow("SDL_Application",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,780,SDL_WINDOW_SHOWN);
        if (pWindow != NULL) {
            pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

            SDL_SetRenderDrawColor(pRenderer,0,0,0,SDL_ALPHA_OPAQUE);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(2000);

            SDL_SetRenderDrawColor(pRenderer,255,0,0,SDL_ALPHA_OPAQUE);
            SDL_RenderClear(pRenderer);
            SDL_RenderPresent(pRenderer);
            SDL_Delay(2000);

            int i = 0;
            while (i < 40)
            {
                int red = rand() % 255;
                int green = rand() % 255;
                int blue = rand() % 255;

                SDL_SetRenderDrawColor(pRenderer, red, green, blue, 0);
                SDL_RenderFillRect(pRenderer, NULL);
                SDL_RenderPresent(pRenderer);
                SDL_Delay(50);

                i++;
            }

            SDL_DestroyRenderer(pRenderer);
            SDL_DestroyWindow(pWindow);
            SDL_Quit();
        }
    } else {
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());//on affiche l'erreur
        return 0;//on sort du programme pour éviter de plus gros problèmes

    }



    return 0;
}
