#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "assets/libs/functions.h"

int main(int argc, char *argv[])
{
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;

	int posX = 10, posY = 20, width = 900, height = 540, initLoad = 0, pos_taco = 1;
	float Bx = 217, By =217.5, deg = -90, mouseX, mouseY, div_larg, div_alt, div_bola_larg, div_bola_alt; //217.5 y 150 x
	int activePlay = 0, stop_j = 0;
	int loadSinuca = 0, dec_f = 0, dec_fs = 0;

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Sinuca Game by Ser3n0s group", posX, posY, width, height, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_DISABLE);

	//mesa 800x 400h
	//42 px l esquerda && 837 px r direita && 34 px cima 402 baixo

	int l1 = 42, l2 = 837, c1 = 34, c2 = 402;
	bool load_tri = false, stop_move = false;

    //move branca lisa vars
    float incPx, divAL, divLA, auxpx, divDf, add_v;
    int divALInt, px = 0;
    int limit_f = 10, div_f_px, f_px_limit = 0, f = 0, f_px = 0;
    int vet_f[10], vet_px[10], vet_fpx[10], get_vet_aux, aux_k;

    //move branca lisa vars
	Uint32 windowID = SDL_GetWindowID(win);
    SDL_Event event;

    //start vetor valores forca px
    for(int k = 0; k < 10; k++){

        aux_k = k + 1;
        vet_f[k] = k+1;

        if(k == 0){
            vet_px[k] = 25;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 1){
            vet_px[k] = 30;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 2){
            vet_px[k] = 40;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 3){
            vet_px[k] = 50;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 4){
            vet_px[k] = 60;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 5){
            vet_px[k] = 70;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 6){
            vet_px[k] = 80;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 7){
            vet_px[k] = 90;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 8){
            vet_px[k] = 110;
            vet_fpx[k] = vet_px[k] * aux_k;
        }else if(k == 9){
            vet_px[k] = 120;
            vet_fpx[k] = vet_px[k] * aux_k;
        }
    }

	//end vetor valores forca px
	while (1)
	{
        SDL_RenderClear(renderer);
		loadMesa(renderer);
		//start load bolas coloridas
		//loadTriangulo(renderer, load_tri);
		//end load bolas coloridas
        if(mouseX == 0 && mouseY == 0 && load_tri == false){
            mouseX = Bx+200;
            mouseY = By;
            load_tri = true;
        }
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:

				if (event.key.keysym.sym == SDLK_SPACE)
				{

                //clear
				}
				else if (event.key.keysym.sym == SDLK_f)
				{
					if (f < 11)
					{
						f++;
                        add_v = f * 1.5714; //10 / 7 max velocidade == 7 if f == 10
					}
					loadSinuca = 1;
				}
				else if (event.key.keysym.sym == SDLK_j)
				{
					if (f > 0 && stop_j == 0)
					{
						// SDL_StopTextInput();
						if (f > 0 && f < 3)
						{
							if (f == 1)
							{
								f_px = vet_px[f-1];

							}
							else
							{
								f_px = vet_px[f-1];

							}
						}
						else if (f > 2)
						{
							if (f == 3)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 4)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 5)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 6)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 7)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 8)
							{
								f_px = vet_px[f-1];

							}
							else if (f == 9)
							{
								f_px = vet_px[f-1];

							}
							else
							{
                                if(f == 10){

                                    f_px = vet_px[f-1];
                                }
							}
						}
					}
					f_px = 0;
					f_px = vet_fpx[f-1];
					activePlay = 1;
					stop_j = 1;
				}

		    break;
			//start window close event
		    case SDL_WINDOWEVENT:
	          if (event.window.windowID == windowID)  {
	            switch (event.window.event)  {

	              case SDL_WINDOWEVENT_CLOSE:
	                event.type = SDL_QUIT;
	                SDL_PushEvent(&event);
	              	SDL_DestroyWindow(win);
					SDL_Quit();

	                break;
	              }

	            }
            case SDL_MOUSEMOTION:{

                if(px <= 1){

                    mouseX = event.motion.x;
                    mouseY = event.motion.y;

                    //start calcs divisao e diferencia largura x altura
                    div_larg = mouseX - Bx; //calc diferencia largura
                    div_alt = mouseY - By; //calc diferencia altura
                    divLA = div_larg / div_alt; //largura / altura
                    divAL = div_alt / div_larg; //altura / largura
                    divALInt = div_alt / div_larg; //alt / larg int
                    incPx = div_alt / divAL; //altura / divAL
                    divDf = div_alt - div_larg; //altura - largura
                    //end calcs divisao e diferencia largura x algura

                    /*if(f_px > 0 && f > 0){
                        div_f_px = f_px / f; //35 / 11
                        limit_f = div_f_px; //limit dec velocidade
                    }*/
                }
            }

	          break;

			}
			//end window close event
		}



        if (divALInt % 2 != 0 && divAL != 1 && divAL >= 1)
        {
            auxpx = divAL / div_alt;
            auxpx = auxpx * divDf;
            auxpx = auxpx * incPx;
            incPx = auxpx + auxpx;
        }
        //start decremento forca && forca px
        if(f > 1 && activePlay != 1){

            //start decrement forca f && f px

            rendFor(renderer, f); //forca taco texture
            f--; //decremeta 1 no valor da forca
            add_v = f * 1.5714; //10 / 7 max velocidade == 7 if f == 10
            //end decrement forca f && f px

		}else if(activePlay != 1 && f < 2){

            f = 0; //forca 0
            f_px = 0;
		}
		//end dec forca taco f--
        while(stop_move != true && activePlay == 1 && f >= 1){

            while (stop_move != true)
            {
                if (divAL >= 1 && divAL < 2)
                {
                    if (divALInt % 2 != 0)
                    {
                        if (px % divALInt == 0)
                        {
                            Bx += divLA*add_v;
                        }
                        By += divALInt*add_v;
                    }
                    else
                    {
                        if (px > 1 && px % divALInt == 0)
                        {
                            Bx += divAL*add_v;
                        }
                        By += divAL*add_v;
                    }
                }
                else
                {
                    Bx += 1*add_v;
                    By += divAL*add_v;
                }

                px++;

                SDL_RenderClear(renderer);
                loadMesa(renderer);
                bolaBranca(renderer, Bx, By);
                rendMiraDest(renderer, mouseX, mouseY);
                SDL_RenderPresent(renderer);
                if(f_px < 1){
                    activePlay = 0;
                    stop_move = true;
                    f_px = 0;
                    f = 0;
                    add_v = 0;
                    px = 0;
                }

                if(f_px_limit >= limit_f){

                    if(add_v > 1.5714){
                        add_v = add_v - 1.5714;
                    }
                    f_px_limit = 0;
                }
                f_px_limit++;
                f_px--;
            }

        }


        stop_move = false;
        rendMiraDest(renderer, mouseX, mouseY);
        if(activePlay != 1){
            bolaBranca(renderer, Bx, By);
		}

		SDL_RenderPresent(renderer);
        SDL_Delay(10);
		usleep(500000);
	}

	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;

}
