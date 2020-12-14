#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "assets/libs/functions.h"
#include "assets/libs/rend_taco.h"
#include "assets/libs/set_routes.h"
#include "assets/libs/engine_balls.h"

int main(int argc, char *argv[]){

	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;

	int posX = 10, posY = 20, width = 900, height = 540;
	float Bx, By, deg = -90, mouseX = 0, mouseY = 0, div_larg, div_alt; //217.5 y 150 x
	int activePlay = 0;
	int loadSinuca = 0;

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Snooker Game by Ser3n0s group", posX, posY, width, height, 0);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_ShowCursor(SDL_DISABLE);

	//mesa 800x 400h
	//42 px l esquerda && 837 px r direita && 34 px cima 402 baixo

	float bx_central, mirax_central, by_central, miray_central, deg_mode, df_x, df_y, add_deg;
	bool stop_move = false;

    //move branca lisa vars
    float f_cue, calc_cue, divAL, divLA, add_v;
    float f = 0;
    int init_mode[1], vetN[16], vetM[16];

    float vetAX[16], vetAY[16], vetV[16], vetF[16], init_x[16], init_y[16], return_x[1], return_y[1];
    float vetX[16];
    float vetY[16];

    char random_units[1], mode_play[1];

    random_units[0] = 'f';

    //move branca lisa vars
	Uint32 windowID = SDL_GetWindowID(win);
    SDL_Event event;
   
    init_random(random_units, vetN, vetM, vetV, vetF, vetX, vetY, init_x, init_y);

    while (1==1){

        SDL_RenderClear(renderer);
		loadMesa(renderer);

        if(mouseX == 0 && mouseY == 0){
            mouseX = Bx+200;
            mouseY = By;
        }
		while (SDL_PollEvent(&event) != 0){

			switch (event.type){

			case SDL_KEYDOWN:

                if(event.key.keysym.sym == SDLK_r){ // return init game

                    for(int r = 0; r < 16; r++){
                    
                        vetN[r] = 100;
                        vetM[r] = 100;
                        vetF[r] = 0;
                        vetV[r] = 0;
                        vetX[r] = 0;
                        vetY[r] = 0;
                        vetAX[r] = 0;
                        vetAY[r] = 0; 
                    }
                    
                    random_units[0] = 'f';
                    init_mode[0] = 't';

                    init_random(random_units, vetN, vetM, vetV, vetF, vetX, vetY, init_x, init_y);

                }else if(event.key.keysym.sym == SDLK_SPACE && mode_play[0] != 'f'){

                    if(f > 0){

                        f = f - 0.5; //decremeta 1 no valor da (forca)
                        
                        f_cue = 10 / 10;
                        calc_cue = f_cue * f;
                        add_v = f * 1.5000 + (calc_cue); //f forca -> cue * aceleracao 1.0
                    }

				}else if (event.key.keysym.sym == SDLK_f && mode_play[0] != 'f'){

					if (f < 11){

						f = f + 0.5; //incrementa 1 no valor da forca (taco)
                        
                        f_cue = 10 / 10;
                        calc_cue = f_cue * f;
                        add_v = f * 1.5000 + (calc_cue); //f forca -> cue * aceleracao 1.0
					
                    }

				}else if (event.key.keysym.sym == SDLK_j && mode_play[0] != 'f'){
                    //start player if force != 0

					if (f > 0 && activePlay == 0){
						// SDL_StopTextInput();
                        init_x[15] = vetX[15]; 
                        init_y[15] = vetY[15];
                        vetM[15] = init_mode[0];
                        vetV[15] = add_v;
                        vetF[15] = add_v;
    					activePlay = 1;
    			
				    }
                    //end player if force != 0
                
                }else if(event.key.keysym.sym == SDLK_b && mode_play[0] == 'f'){

                    vetX[15] = return_x[0];
                    vetY[15] = return_y[0];
                    mode_play[0] = 't';

                }

    		    break;
    			//start window close event
    		    case SDL_WINDOWEVENT:

    	           if(event.window.windowID == windowID){
    	        
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

                        if(mode_play[0] == 'f'){

                            mouseX = event.motion.x;
                            mouseY = event.motion.y;

                            mirax_central = mouseX + 10;
                            miray_central = mouseY + 10;

                            return_x[0] = mirax_central;
                            return_y[0] = miray_central;
                        }

                        if(activePlay == 0 && mode_play[0] != 'f'){ // player && machine mode of

                            mouseX = event.motion.x;
                            mouseY = event.motion.y;
                            bx_central = vetX[15] + 10; //center x bola branca
                            mirax_central = mouseX + 10; //center x mira (mouse cursor)

                            by_central = vetY[15] + 10; //center y bola branca
                            miray_central = mouseY + 10; //center y mira(mouse cursor)

                            Bx = vetX[15];
                            By = vetY[15];

                            //start calcs divisao e diferencia largura x altura
                            if(mirax_central <= bx_central && miray_central <= by_central){

                                div_larg = Bx - mouseX; //calc diferencia de largura
                                div_alt = By - mouseY; //cal diferencia de altura
                                df_x = bx_central - mirax_central; //calculo diferencia largura
                                df_y = by_central - miray_central; //calculo diferencia de altura
                                deg_mode = 180;
                                deg = 180;
                                init_mode[0] = 2;

                            }else if(mirax_central >= bx_central && miray_central >= by_central){

                                div_larg = mouseX - Bx; //calc diferencia largura
                                div_alt = mouseY - By; //calc diferencia altura
                                df_x = mirax_central - bx_central; //calculo diferencia largura
                                df_y = miray_central - by_central; //calculo diferencia de altura
                                deg_mode = 0;
                                deg = 0;
                                init_mode[0] = 3;

                            }else if(mirax_central <= bx_central && miray_central > by_central){

                                div_larg = Bx - mouseX; //calc diferencia largura
                                div_alt = mouseY - By; //calc direferencia altura
                                df_x = bx_central - mirax_central; //calculo diferencia largura
                                df_y = miray_central - by_central; //calculo diferencia de altura
                                deg_mode = 90;
                                deg = 90;
                                init_mode[0] = 1;

                            }else if(mirax_central >= bx_central && miray_central < by_central){

                                div_larg = mouseX - Bx; //calc diferencia largura
                                div_alt = By - mouseY; //calc diferencia altura
                                df_x = mirax_central - bx_central; //calculo diferencia largura
                                df_y = by_central - miray_central; //calculo diferencia de altura
                                deg_mode = -90;
                                deg = -90;
                                init_mode[0] = 0;
                            }

                            divLA = div_larg / div_alt; //largura / altura
                            divAL = div_alt / div_larg; //altura / largura
                            
                            if(divLA >= 1){

                                vetAX[15] = 1;
                                vetAY[15] = divAL;

                            }else{

                                vetAX[15] = divLA;
                                vetAY[15] = 1;
                            }
                            //end calcs divisao e diferencia largura x altura
                        }
                    }

    	          break;

    			}
    			//end window close event
		}

	   
        if(vetX[15] == 0 && vetY[15] == 0){

            mode_play[0] = 'f';
        }

        engine_show_all(renderer, vetN, vetM, vetV, vetF, vetX, vetY, vetAX, vetAY, init_x, init_y);

        //start show in mode off
        if(activePlay != 1){

            rendFor(renderer, f);
            
            if(vetX[15] != 0 && vetY[15] != 0){
                rendMiraDest(renderer, mouseX, mouseY);
            }else{
                rendHand(renderer, mouseX, mouseY);
            }

            rendTaco(renderer, vetX, vetY, deg, deg_mode, df_x, df_y);
        }
        //end show in mode off
        
        //start reset mode off
        if(activePlay == 1 && vetM[15] == 100){

            activePlay = 0;
            f = 0;
            add_v = 0;
        }
        //end reset mode off

		SDL_RenderPresent(renderer);
        SDL_Delay(6);

	}

	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;

}
