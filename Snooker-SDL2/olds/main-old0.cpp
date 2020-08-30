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

	int posX = 10, posY = 20, width = 800, height = 460, initLoad = 0, f = 0, pos_taco = 1, auxYX = 0, auxY = 0, deg = 0, set_deg = 180, deg_mod = 1, typeP;
	float Mx, My, Ty, Tx, Bx = 340, By = 200;
	int f_px = 50, activePlay = 0, deg_cont = 0;
	int loadSinuca = 0, defM = 0, dec_f = 0, dec_fs = 0;
	/*srand(time_t(NULL));
	loadSinuca = rand() % 10;*/
	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Sinuca Game by Ser3n0s group", posX, posY, width, height, SDL_RENDERER_PRESENTVSYNC);

	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	Tx = Bx + 8.5;
	Ty = By - 400;
	Mx = Bx;
	My = By;
	//mesa 700x 400h
	//40 px 635px direita esquerda
	//.50 px 320px cima baixo
	//boca 340 30 boca 30 40 boca 635 40 boca 645 340 boca 335 340 boca 30 340
	int lP1 = 50, lP2 = 320, lP3 = 40, lP4 = 635, stop_j = 0, deg_m = 0, deg_fm = 0;
	float cAng = 0;
	int mAng = 0, mod_set = 1;
	char last_mode[1];
	bool action = false, mMod = false;
	float divAng, divAng1, angP, ang, angInc;
	Uint32 windowID = SDL_GetWindowID(win);

	while (1)
	{

		loadMesa(renderer);
		if (action == true)
		{
			
			divAng = 25 / 18; //div bola
			ang = 180 / 18; //div angulo 180
			angInc = ang * mAng; //angulo now
		
			if (angInc <= 90)
			{
				if (mAng != 1)
				{
					if (angInc <= 30)
					{
						if (mAng == 2)
						{
							Ty = Ty + divAng + 5;
							Tx = Tx + divAng + 10 * mAng + 10;
						}
						else if (mAng == 3)
						{
							Ty = Ty + divAng + 15;
							Tx = Tx + divAng + 10 * mAng + 10;
						}
					}
					else if (angInc > 30 && angInc <= 60)
					{
						if (mAng == 4)
						{
							Ty = Ty + divAng + 20;
							Tx = Tx + divAng + 20 + 10;
						}
						else if (mAng >= 5)
						{
							Ty = Ty + divAng + 30;
							Tx = Tx + divAng + 20;
						}
					}
					else if (angInc > 60 && angInc <= 90)
					{
						if (mAng == 6)
						{
							Ty = Ty + divAng + 20 + 10;
							Tx = Tx + divAng + 20 + 10;
						}
						else if (mAng == 7)
						{
							Ty = Ty + divAng + 20 + 10;
							Tx = Tx + divAng + 10 + 10;
						}
						else if (mAng == 8)
						{
							Ty = Ty + divAng + 20 + 20;
							Tx = Tx + divAng + 10;
						}
						else
						{
							Tx = Tx + divAng;
							Ty = Ty + divAng + 30 + 10;
						}
					}
				}
				else if (mAng == 1)
				{
					Tx = Tx + divAng + 10 + 10 + 25;
					//Ty = Ty + divAng+tSize;
				}
			}
			else if (angInc > 90 && angInc <= 180)
			{
				Ty = Ty + divAng;
				Tx = Tx - divAng;
			}
			else if (angInc > 180 && angInc <= 270)
			{
				if (mAng != 6)
				{
					Ty = Ty - divAng;
				}
				Tx = Tx - divAng;
			}
			else if (angInc > 270 && angInc <= 360)
			{
				Ty = Ty - divAng;
				Tx = Tx + divAng + 10 * mAng;
			}

			action = false;
		}
		posTaco(renderer, Tx, Ty, pos_taco, deg, angInc, divAng, mAng);
		//genMira(renderer, Bx, By, pos_taco, typeP, Bx);
		 
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:

				if (event.key.keysym.sym == SDLK_SPACE)
				{
					if (mAng >= 36)
					{
						mAng = 0;
						angInc = 0;
						Tx = Bx + 8.5;
						Ty = By - 400;
					}
					
					mAng += 1;
					action = true;
					deg += 10;

				}
				else if (event.key.keysym.sym == SDLK_f)
				{
					if (f < 11)
					{
						f++;
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
								f_px = 25;
							}
							else
							{
								f_px = 35;
							}
						}
						else if (f > 2)
						{
							if (f == 3)
							{
								f_px = 40;
							}
							else if (f == 4)
							{
								f_px = 50;
							}
							else if (f == 5)
							{
								f_px = 60;
							}
							else if (f == 6)
							{
								f_px = 70;
							}
							else if (f == 7)
							{
								f_px = 80;
							}
							else if (f == 8)
							{
								f_px = 100;
							}
							else if (f == 9)
							{
								f_px = 130;
							}
							else
							{
								f_px = 150;
							}
						}
					}
					f_px *= f;
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
	          
	          break;

			}
			//end window close event
		}

		if (activePlay == 1)
		{
			if (pos_taco == 1)
			{
				int Py, cb = 0;
				Py = By - lP1; //limit pos y 1
				Py += 30;	  //inc size ball
				float fDec, f_move = 0, active_new_deg = 0;
				int active_deg_v = 0;
				if (f > 5 && f < 8)
				{
					f_move = f_px / 20000;
				}
				else if (f > 7)
				{
					f_move = f_px / 15000;
				}
				else
				{
					f_move = f_px / 10000;
				}
				fDec = f;
				while (cb < f_px)
				{
					if (deg_cont == 0 && pos_taco == 1)
					{
						if (active_new_deg == 0 && By < lP1)
						{
							active_new_deg = 1;
						}

						if (active_new_deg == 1)
						{
							By += 1;
							if (By > lP2)
							{
								active_new_deg = 2;
							}
						}
						else if (active_new_deg == 2)
						{
							By -= 1;
							if (By < lP1)
							{
								active_new_deg = 1;
							}
						}
						else if (active_new_deg == 0)
						{
							By -= 1;
						}
					}
					else if (deg_cont == 0 && pos_taco == 4)
					{
						if (active_new_deg == 0 && By > lP2)
						{
							active_new_deg = 1;
						}

						if (active_new_deg == 1)
						{
							By -= 1;
							if (By < lP1)
							{
								active_new_deg = 2;
							}
						}
						else if (active_new_deg == 2)
						{
							By += 1;
							if (By > lP2)
							{
								active_new_deg = 1;
							}
						}
						else if (active_new_deg == 0)
						{
							By += 1;
						}
					}
					//begin init deg x y
					if (deg_cont != 0 && pos_taco == 1 || pos_taco == 4)
					{
						if (deg_cont != 0 && typeP == 0 && pos_taco == 1)
						{
							if (By < lP1 && active_deg_v == 0)
							{
								active_deg_v = 1;
							}
							if (Bx > lP4 && active_deg_v == 1)
							{
								active_deg_v = 2;
							}
							if (By > lP2 && active_deg_v == 2)
							{
								active_deg_v = 3;
							}
							if (By < lP1 && active_deg_v == 3)
							{
								active_deg_v = 2;
							}
							if (Bx < lP3 && active_deg_v == 2)
							{
								active_deg_v = 1;
							}
							if (By > lP2 && active_deg_v == 1)
							{
								active_deg_v = 0;
							}
							if (active_deg_v == 0)
							{
								By -= deg_cont;
								Bx += deg_cont;
							}
							else if (active_deg_v == 1)
							{
								By += deg_cont;
								Bx += deg_cont;
							}
							else if (active_deg_v == 2)
							{
								By += deg_cont;
								Bx -= deg_cont;
							}
							else if (active_deg_v == 3)
							{
								By -= deg_cont;
								Bx -= deg_cont;
							}
						}
						else if (deg_cont != 0 && typeP == 1 && pos_taco == 1)
						{
							if (By < lP1 && active_deg_v == 0)
							{
								active_deg_v = 1;
							}
							if (Bx < lP3 && active_deg_v == 1)
							{
								active_deg_v = 2;
							}
							if (By > lP2 && active_deg_v == 2)
							{
								active_deg_v = 3;
							}
							if (By < lP1 && active_deg_v == 3)
							{
								active_deg_v = 2;
							}
							if (Bx > lP4 && active_deg_v == 2)
							{
								active_deg_v = 1;
							}
							if (By > lP2 && active_deg_v == 1)
							{
								active_deg_v = 0;
							}
							if (active_deg_v == 0)
							{
								By -= deg_cont;
								Bx -= deg_cont;
							}
							else if (active_deg_v == 1)
							{
								By += deg_cont;
								Bx -= deg_cont;
							}
							else if (active_deg_v == 2)
							{
								By += deg_cont;
								Bx += deg_cont;
							}
							else if (active_deg_v == 3)
							{
								By -= deg_cont;
								Bx += deg_cont;
							}
						}
						else if (deg_cont != 0 && typeP == 0 && pos_taco == 4)
						{
							if (By > lP2 && active_deg_v == 0)
							{
								active_deg_v = 1;
							}
							if (Bx < lP3 && active_deg_v == 1)
							{
								active_deg_v = 2;
							}
							if (By < lP1 && active_deg_v == 2)
							{
								active_deg_v = 3;
							}
							if (By > lP2 && active_deg_v == 3)
							{
								active_deg_v = 2;
							}
							if (Bx > lP4 && active_deg_v == 2)
							{
								active_deg_v = 1;
							}

							if (active_deg_v == 0)
							{
								By += deg_cont;
								Bx -= deg_cont;
							}
							else if (active_deg_v == 1)
							{
								By -= deg_cont;
								Bx -= deg_cont;
							}
							else if (active_deg_v == 2)
							{
								By -= deg_cont;
								Bx += deg_cont;
							}
							else if (active_deg_v == 3)
							{
								By += deg_cont;
								Bx += deg_cont;
							}
						}
						
					}
					//end init deg x y
					playJogada(renderer, Bx, By, pos_taco, typeP, deg_cont);
					SDL_RenderPresent(renderer);
					loadMesa(renderer);
					f_move = f_move * f; //dec speed bola branca

					usleep(f_move);
					cb++;
				}
			}
			My = By;
			Mx = Bx;
			if (set_deg == 0)
			{
				deg = 0;
			}
			
			deg_cont = 0;
			activePlay = 0;
			stop_j = 0;
		}
		
		bolaBranca(renderer, Bx, By, deg);
		rendFor(renderer, f); //forca taco texture

		//start dec forca taco f--
		if (f >= 0 && dec_f > 1)
		{
			f--;
		}else if(f > 0){
			dec_f += 1;
		}else if(f == 0 && loadSinuca == 1){
			loadSinuca = 0;

		}
		//end dec forca taco f--
		SDL_RenderPresent(renderer);

		usleep(500000);
	}
	

	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
    
}