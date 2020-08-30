#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void Block_px(SDL_Renderer *renderer, float xxx, float yyy, float larg, float alt)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	int px = 0, block_px = 0;
	int divALInt, divDf;
	float incPx, divAL, divLA, auxpx, auxdiv;

	divLA = larg / alt; //largura / altura
	divAL = alt / larg; //altura / largura
	divALInt = alt / larg; //alt / larg int
	incPx = alt / divAL; //altura / divAL
	divDf = alt - larg; //altura - largura

    if(divLA < 1){
        incPx = alt;
    }
	while (px < incPx)
	{

        if(divLA >= 1){
            xxx -= 1; //1 / 10
            yyy -= divAL;//divAL*2;
        }else {
            xxx -= divLA;
            yyy -= 1;
        }

		SDL_Rect pxxx_rect;
		pxxx_rect.w = 1;
		pxxx_rect.h = 1;
		pxxx_rect.x = xxx;
		pxxx_rect.y = yyy;

		SDL_RenderDrawRect(renderer, &pxxx_rect);
		SDL_RenderFillRect(renderer, &pxxx_rect);
		px++;
		//usleep(500000);
	}
}
int main(int argc, char *argv[])
{
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;

	int posX = 10, posY = 20, width = 750, height = 700;
	float x, y;
	float xx, yy;
	float larg, alt;
	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Px renderer by Ser3n0s group", posX, posY, width, height, SDL_RENDERER_PRESENTVSYNC);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
	//  //
	SDL_Rect px_rect;
	px_rect.w = 1;
	px_rect.h = 1;
	x = 200;
	y = 200;
	px_rect.x = x;
	px_rect.y = y;
	SDL_RenderDrawRect(renderer, &px_rect);
	SDL_RenderFillRect(renderer, &px_rect);
	// //
	SDL_Rect pxx_rect;
	pxx_rect.w = 1;
	pxx_rect.h = 1;
	xx = 350;
	yy = 420;
	pxx_rect.x = xx;
	pxx_rect.y = yy;
	SDL_RenderDrawRect(renderer, &pxx_rect);
	SDL_RenderFillRect(renderer, &pxx_rect);
	larg = xx - x;
	alt = yy - y;
	Block_px(renderer, xx, yy, larg, alt);
	SDL_RenderPresent(renderer);
	SDL_Delay(1000000);
	return 0;
}
