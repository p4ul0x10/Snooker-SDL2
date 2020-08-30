#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "assets/libs/functions.h"
#include "assets/libs/rend_taco.h"
#include "assets/libs/move_balls.h"

int main(int argc, char *argv[]){
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;

	int posX = 10, posY = 20, width = 900, height = 540, initLoad = 0, pos_taco = 1;
	float Bx = 317, By =217, deg = -90, mouseX = 0, mouseY = 0, div_larg, div_alt, div_bola_larg, div_bola_alt; //217.5 y 150 x
	int activePlay = 0, stop_j = 0;
	int loadSinuca = 0, dec_f = 0, dec_fs = 0;

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Sinuca Game by Ser3n0s group", posX, posY, width, height, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_DISABLE);

	//mesa 800x 400h
	//42 px l esquerda && 837 px r direita && 34 px cima 402 baixo

	float l1 = 42, l2 = 837, c1 = 34, c2 = 402, bx_central, mirax_central, by_central, miray_central, deg_mode, df_x, df_y, div_angulo, add_deg, calc_deg, top_b;
	bool load_tri = false, stop_move = false, run_on;

    //move branca lisa vars
    float incPx, divAL, divLA, auxpx, divDf, add_v, calc_angulo;
    int divALInt, px = 0;
    int limit_f = 10, div_f_px, f_px_limit = 0, f = 0, f_px = 0;
    int vet_f[10], vet_px[10], vet_fpx[10], get_mode_x = 0, get_mode_y = 0, aux_k, mode_init_j;

    char *p_str_x, *p_str_y, str_mode_x[2], str_mode_y[2];

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

	while (activePlay == 0)
	{
        SDL_RenderClear(renderer);
		loadMesa(renderer);

        if(mouseX == 0 && mouseY == 0){
            mouseX = Bx+200;
            mouseY = By;
        }
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:

				if (event.key.keysym.sym == SDLK_SPACE)
				{

                    if(f > 0){
                        f--; //decremeta 1 no valor da forca
                        add_v = f * 1.5714; //10 / 7 max velocidade == 7 if f == 10
                        f_px = vet_px[f-1];
                    }
				}
				else if (event.key.keysym.sym == SDLK_f)
				{
					if (f < 11)
					{
						f++;
                        add_v = f * 1.5714; //10 / 7 max velocidade == 7 if f == 10
					}

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
					run_on = true;
                    //load_tri = true;
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

                if(px == 0){

                    mouseX = event.motion.x;
                    mouseY = event.motion.y;
                    bx_central = Bx + 10; //center x bola branca
                    mirax_central = mouseX + 10; //center x mira (mouse cursor)

                    by_central = By + 10; //center y bola branca
                    miray_central = mouseY + 10; //center y mira(mouse cursor)

                    //start calcs divisao e diferencia largura x altura
                    if(mirax_central <= bx_central && miray_central < by_central){

                        div_larg = Bx - mouseX; //calc diferencia de largura
                        div_alt = By - mouseY; //cal diferencia de altura
                        df_x = bx_central - mirax_central; //calculo diferencia largura
                        df_y = by_central - miray_central; //calculo diferencia de altura
                        deg_mode = 180;
                        deg = 180;
                        get_mode_x = 1;
                        get_mode_y = 0;

                    }else if(mirax_central >= bx_central && miray_central > by_central){

                        div_larg = mouseX - Bx; //calc diferencia largura
                        div_alt = mouseY - By; //calc diferencia altura
                        df_x = mirax_central - bx_central; //calculo diferencia largura
                        df_y = miray_central - by_central; //calculo diferencia de altura
                        deg_mode = 0;
                        deg = 0;
                        get_mode_x = 0;
                        get_mode_y = 1;

                    }else if(mirax_central < bx_central && miray_central > by_central){

                        div_larg = Bx - mouseX; //calc diferencia largura
                        div_alt = mouseY - By; //calc direferencia altura
                        df_x = bx_central - mirax_central; //calculo diferencia largura
                        df_y = miray_central - by_central; //calculo diferencia de altura
                        deg_mode = 90;
                        deg = 90;
                        get_mode_x = 1;
                        get_mode_y = 1;

                    }else if(mirax_central > bx_central && miray_central < by_central){

                        div_larg = mouseX - Bx; //calc diferencia largura
                        div_alt = By - mouseY; //calc diferencia altura
                        df_x = mirax_central - bx_central; //calculo diferencia largura
                        df_y = by_central - miray_central; //calculo diferencia de altura
                        deg_mode = -90;
                        deg = -90;
                        get_mode_x = 0;
                        get_mode_y = 0;
                    }

                    divLA = div_larg / div_alt; //largura / altura
                    divAL = div_alt / div_larg; //altura / largura
                    divALInt = div_alt / div_larg; //alt / larg int
                    incPx = div_alt / divAL; //altura / divAL
                    divDf = div_alt - div_larg; //altura - largura

                    //end calcs divisao e diferencia largura x altura
                }
            }

	          break;

			}
			//end window close event
		}
        rendFor(renderer, f);
		//end dec forca taco f-- while(stop_move != true && activePlay == 1 && f >= 1){
        while(activePlay == 1 && f_px >= 1){

            //start tabelas mode pos y x bola branca clear
            if(Bx > l2){
                get_mode_x = 1;
            }

            if(Bx < l1){
                get_mode_x = 0;

            }

            if(By < c1){
                get_mode_y = 1;

            }

            if(By > c2){
                get_mode_y = 0;

            }
            //end tabelas mode pos y x bola branca clear

            if(divLA >= 1){ //start if div largura / altura >= 1  adds x y


                if(get_mode_x == 1){
                    Bx -= 1*add_v;
                }else if(get_mode_x == 0){
                    Bx += 1*add_v;
                }

                if(get_mode_y == 1){
                    By += divAL*add_v;
                }else if(get_mode_y == 0){
                    By -= divAL*add_v;
                }

            }else{ //end start div largura / altura < 1 adds x y

                //start adds incremento x pos tabela left right
                if(get_mode_x == 1){
                    Bx -= divLA*add_v;
                }else if(get_mode_x == 0){
                    Bx += divLA*add_v;
                }
                //end adds incrementto x pos tabelma left right

                //start adds incremento y pos tabela up down
                if(get_mode_y == 1){
                    By += 1*add_v;
                }else if(get_mode_y == 0){
                    By -= 1*add_v;
                }
                //end adds incremento y pos tabela up  down

            }//end div largura / altura < 1 adds x y

            px++;

            SDL_RenderClear(renderer);
            loadMesa(renderer);
            bolaBranca(renderer, Bx, By);
            //start load bolas coloridas
            loadTriangulo(renderer, load_tri, run_on, mouseX, mouseY, Bx, By);
            //end load bolas coloridas
            rendMiraDest(renderer, mouseX, mouseY);
            SDL_RenderPresent(renderer);

            if(f_px <= 1){
                activePlay = 0;
                stop_move = true;
                run_on = false;
                f_px = 0;
                f = 0;
                add_v = 0;
                px = 0;
                get_mode_x = 0;
                get_mode_y = 0;
            }

            if(f_px_limit >= limit_f){

                if(add_v > 1.5714){
                    add_v = add_v - 0.5714;
                    f_px = f_px - f;
                    f_px_limit = 0;
                }

            }
            f_px_limit++;
            f_px--;
        }


        stop_move = false;
        rendMiraDest(renderer, mouseX, mouseY);
        //rendTaco(renderer, mouseX, mouseY, deg, deg_mode, df_x, df_y);
        if(activePlay != 1){

            bolaBranca(renderer, Bx, By);
            rendTaco(renderer, Bx, By, deg, deg_mode, df_x, df_y, by_central, bx_central);
            //start load bolas coloridas
            loadTriangulo(renderer, load_tri, run_on, mouseX, mouseY, Bx, By);
            //end load bolas coloridas
		}

		SDL_RenderPresent(renderer);
        SDL_Delay(10);

	}

	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;

}
