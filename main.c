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
#include "assets/libs/check_mods.h"
#include "assets/libs/machine_trace.h"
#include "assets/libs/machine_make_route.h"
#include "assets/libs/libunits.h"

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
    float f = 0, al;
    int cont_play = 0, init_mode[1], vetN[16], vetM[16], all_k[1], e_x[1], e_y[1];
    int cont_units[1], cont_ball[15], cont_p[1], cont_m[1], cont_all[1];
    float eq_y, div_eq_y, percent_y_1, percent_y_2, percent_y;
    float vetAX[16], vetAY[16], vetV[16], vetF[16], init_x[16], vang[16], init_y[16], return_x[1], return_y[1];
    float vetX[16];
    float vetY[16];
    float p_x[1], p_y[1];
    char random_units[1], mode_play[1], rand_on[1], status_check[1], mode_player[2], change_mode[1];
    random_units[0] = 'f';
    p_x[0] = 0;
    p_y[0] = 0;
    all_k[0] = 0;
    //move branca lisa vars
	Uint32 windowID = SDL_GetWindowID(win);
    SDL_Event event;

    const char* SDL_GetKeyName(SDL_Keycode key);

    init_random(random_units, vetN, vetM, vetV, vetF, vetX, vetY, init_x, init_y);
    
    //
    int b = 0;
    while(b < 15){

        cont_ball[b] = 0;
        b++;
    }
    //
    
    //start init coord x y effect img
    e_y[0] = (40 / 2) + 465;
    e_x[0] = (40 / 2) + 750;
    //end init coord x y effect img
    
    srand (time(NULL));
    activePlay = rand() % 2+1;
    cont_units[0] = 0;
    rand_on[0] = 'n';
    status_check[0] = 'n';
    change_mode[0] = 't';
    mode_player[0] = '0';
    mode_player[1] = '0';
    while (true){

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
                        cont_ball[r] = 0;
                    }

                    all_k[0] = 0;
                    random_units[0] = 'f';
                    init_mode[0] = 't';
                    mode_play[0] = 't';
                    init_random(random_units, vetN, vetM, vetV, vetF, vetX, vetY, init_x, init_y);
                    vetY[15] = 217;
                    vetX[15] = 317;
                    vetM[15] = 0;
                    f = 0;
                    cont_play = 0;
                    cont_units[0] = 0;
                    rand_on[0] = 'n';
                    status_check[0] = 'n';
                    mode_player[0] = '0';
                    mode_player[1] = '0';
                    change_mode[0] = 't'; 
                    srand (time(NULL));
                    activePlay = rand() % 2+1;
                
                    //start init coord x y effect img
                    e_y[0] = (40 / 2) + 465;
                    e_x[0] = (40 / 2) + 750;
                    //end init coord x y effect img
                
                }else if(event.key.keysym.sym == SDLK_SPACE && mode_play[0] != 'f'){

                    if(f > 0){

                        f = f - 0.5; //decremeta 1 no valor da (forca)

                        f_cue = 10 / 10;
                        calc_cue = f_cue * f;
                        add_v = f * 1.8 + (calc_cue); //f forca -> cue * aceleracao 1.0
                    }

				}else if (event.key.keysym.sym == SDLK_f && mode_play[0] != 'f'){

				    if(f < 11){

    					if(f > 10){
    						f = 10;
    					}

    					f = f + 0.5; //incrementa 1 no valor da forca (taco)

                        f_cue = 10 / 10;
                        calc_cue = f_cue * (f / 10);
                        add_v = f * 1.8 + (calc_cue); //f forca -> cue * aceleracao 1.0

                    }

				}else if (event.key.keysym.sym == SDLK_j && mode_play[0] != 'f'){
                    //start player if force != 0

					if (f > 0 && activePlay == 2){
						// SDL_StopTextInput();
                        all_k[0] = 0;
                        init_x[15] = vetX[15];
                        init_y[15] = vetY[15];
                        vetM[15] = init_mode[0];
                        vetV[15] = add_v;
                        vetF[15] = add_v;
    					activePlay = 2;
                        change_mode[0] = 'n';
                        cont_play++;

				    }

                    check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
                    //end player if force != 0

                }else if(event.key.keysym.sym == SDLK_b && mode_play[0] == 'f'){

                    vetX[15] = return_x[0];
                    vetY[15] = return_y[0];
                    mode_play[0] = 't';

                }else if(event.key.keysym.sym == SDLK_UP){

                    if(e_y[0] >= 466){ //end top

                        e_y[0] = e_y[0] - 1; // dec 1 y force effect
                    }

                    //start percentual for affects y u & y d,  x l & x r
                    if(e_y[0] <= 485){ //init center up (continue effect)

                        eq_y = (40 / 2) + 465 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_1 = 100 - percent_y;

                        printf("\nEFFECT Y UP -> %.2f up\n", percent_y_1);

                    }else{ //init center up down (continue effect)

                        eq_y = (40 / 2) + 485 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_2 = percent_y;

                        printf("\nEFFECT Y DOWN -> %.2f up\n", percent_y_2);

                    }
                    //end percentual for effects y u & y d, x l & x r

                }else if(event.key.keysym.sym == SDLK_DOWN){

                    if(e_y[0] <= 504){ //end final down

                        e_y[0] = e_y[0] + 1; //inc 1 force effect
                    }

                    //start percentual for effects y u & y d, l x &  x r
                    if(e_y[0] <= 485){ //init top for center

                        eq_y = (40 / 2) + 465 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_1 = 100 - percent_y;

                        printf("\nEFFECT Y UP -> %.2f down\n", percent_y_1);

                    }else{ //init center + for center

                        eq_y = (40 / 2) + 485 - e_y[0];

                        div_eq_y = (40 / 2) - eq_y;

                        percent_y = (div_eq_y / 20) * 100;

                        percent_y_2 = percent_y;

                        printf("\nEFFECT Y DOWN -> %.2f down\n", percent_y_2);
                    }
                    //end percentual for effects y u & y d, l x & x r

                }else if(event.key.keysym.sym == SDLK_q){

                    printf("Key %s = quit", SDL_GetKeyName(event.key.keysym.sym));

                    printf("\nSNOOKER GAME END\n");
                    
                    SDL_DestroyWindow(win);
                    SDL_Quit();
                    
                    return 0;

                }
    		    break;
    			//start window close event
    		    case SDL_WINDOWEVENT:

    	           if(event.window.windowID == windowID){

                        switch (event.window.event)  {

    	                   case SDL_WINDOWEVENT_CLOSE:

                            //event.type = SDL_QUIT;
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

                        if(activePlay == 2 && vetM[15] > 3 && mode_play[0] != 'f'){ // player && machine mode of

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
                            vang[15] = divAL;

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

        if(activePlay == 1 && change_mode[0] == 't'){
     
            machine_route(vetN, vetM, vetV, vetF, vetX, vetY, vetAX, vetAY, rand_on, mode_player);
            check_units(cont_m, cont_p, vetN, vetX, vetY, mode_player);
            cont_play++;
            change_mode[0] = 'n';

            sleep(2);
        }

        engine_show_all(renderer, vetN, vetM, vetV, vetF, vetX, vetY, vetAX, vetAY, all_k, init_x, init_y, e_x, e_y);

        //start reset mode off
        if(change_mode[0] == 'n' && vetM[15] == 100 && cont_play >= 1 && activePlay == 1 || activePlay == 2){

            if(change_mode[0] == 'n'){

                int get_y, get_x;
                get_y = e_y[0];
                get_x = e_x[0];
                if(all_k[0] >= 15){

                    //activePlay = 0;
                    f = 0;
                    add_v = 0;

                    //reset effect adds
                    e_x[0] = (40 / 2) + 750;
                    e_y[0] = (40 / 2) + 465;
                    //reset effect adds  
                }

                if(vetM[15] == 100 && vetV[15] == 0 && status_check[0] != 't'){

                    bool num_checked = false;
                    int cont_b, cont_s = 1;
                    cont_b = cont_units[0];

                    for(int s = 0; s < 15; s++){ 
                           
                        if(vetV[s] == 0 && vetM[s] > 3 && vetAX[s] == 0 && vetAY[s] == 0){
                            cont_s++;
                        }
                        /*for(int c = 14; c >= 0; c--){
                         
                            if(vetX[c] == 0 && vetY[c] == 0){

                                if(cont_ball[s] == vetN[c]){

                                    num_checked = true;
                                }   
                            }

                            if(c == 0 && num_checked == false){

                                cont_ball[s] = vetN[c];
                                cont_units[0] = cont_units[0] + 1;
                            }
                        }*/ 
                    
                    }

                    if(cont_s > 15){

                        for(int ss = 0; ss < 15; ss++){

                            if(vetN[ss] != 0 && vetX[ss] == 0 && vetY[ss] == 0){
                            
                                if(vetN[ss] != cont_ball[0]){

                                    cont_ball[cont_b] = vetN[ss];
                                    cont_units[0] = cont_b + 1;
                                }
                            }
                        }
                    }

                    if(rand_on[0] == 'n' && cont_units[0] >= 1 && cont_ball[1] != 0){

                        int check_range;

                        check_range = cont_ball[1];

                        if(rand_on[0] == 'n'){

                            if(activePlay == 2 && check_range > 8){

                                rand_on[0] = 'j';
                                mode_player[0] = 'p';
                                mode_player[1] = '9';

                            }else if(activePlay == 2 && check_range < 8){
                            
                                rand_on[0] = 'j';
                                mode_player[0] = 'p';
                                mode_player[1] = '7';
                            }
                        
                            if(activePlay == 1 && check_range > 8){
                             
                                rand_on[0] = 'm';
                                mode_player[0] = 'p';
                                mode_player[1] = '7';

                            }else if(activePlay == 1 && check_range < 8){
                            
                                rand_on[0] = 'm';
                                mode_player[0] = 'p';
                                mode_player[1] = '9';
                            }
                        }   

                        if(rand_on[0] == 'j' || rand_on[0] == 'm'){

                            status_check[0] = 't';
                        }

                    }
                    
                }

                if(status_check[0] != 'n'){
              
                    //show units
                    count_units(renderer, vetX, vetY, cont_units, vetN, mode_player);                    
                }

                if(change_mode[0] == 'n'){

                    int cont_pm = 1;

                    for(int pm = 0; pm < 15; pm++){

                        if(vetV[pm] == 0 && vetM[pm] > 3 && vetAX[pm] == 0 && vetAY[pm] == 0){
                            cont_pm++;
                        }
                    }

                    if(vetM[15] == 100 && vetV[15] == 0 && cont_pm > 15 && change_mode[0] == 'n'){
                        
                        //start check units
                        int cp = 0, cm = 0, ca = 0;

                        if(mode_player[1] == '7'){

                            for(int p1 = 0; p1 < 15; p1++){
            
                                if(vetN[p1] < 8 && vetY[p1] != 0 && vetX[p1] != 0){
                                    cp++;
                                }

                                if(vetN[p1] > 8 && vetY[p1] != 0 && vetX[p1] != 0){
                                    cm++;
                                }
                            }

                        }else if(mode_player[1] == '9'){

                            for(int p2 = 0; p2 < 15; p2++){
            
                                if(vetN[p2] > 8 && vetY[p2] != 0 && vetX[p2] != 0){
                                    cp++;
                                }

                                if(vetN[p2] < 8 && vetY[p2] != 0 && vetX[p2] != 0){
                                    cm++;
                                }
                            }
                        }

                        for(int all = 0; all < 15; all++){

                            if(vetX[all] == 0 && vetY[all] == 0){
                                ca++;
                            }
                        }
                        //end check units

                        //start reset mode player x machine 
                        if(activePlay == 1 && change_mode[0] == 'n'){

                            if(mode_player[1] == '0' && ca == 0 || ca == 1){
                                activePlay = 2;
        
                            }

                            if(cm == cont_m[0] && mode_player[1] != '0'){
                                activePlay = 2;
                            }

                            change_mode[0] = 't';

                        }else if(activePlay == 2 && change_mode[0] == 'n'){

                            if(mode_player[1] == '0' && ca == 0 || ca == 1){
                                activePlay = 1;
                            }
                            
                            if(cp == cont_p[0] && mode_player[1] != '0'){
                                activePlay = 1; 
                            }

                            change_mode[0] = 't';
                        }
                        //end
                    }
                }
            }
        }
        //end reset mode off

        //start show in mode off
        if(activePlay == 2 && vetM[15] > 3){

            rendFor(renderer, f);

            if(vetX[15] != 0 && vetY[15] != 0){
                rendMiraDest(renderer, mouseX, mouseY);
            }else{
                rendHand(renderer, mouseX, mouseY);
            }

            rendEffects(renderer, e_x, e_y);
            rendTaco(renderer, vetX, vetY, deg, deg_mode, df_x, df_y, p_x, p_y);
            count_units(renderer, vetX, vetY, cont_units, vetN, mode_player); 
        }
        //end show in mode off

        //Circle test
        int circle_x;
        int circle_y;
        int circle_radius;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        int point_x;
        int point_y;
        int c = 0;
        circle_radius = 10;

        /*while(c < 16){

            circle_x = vetX[c] + 10;
            circle_y = vetY[c] + 10;
            
            for (float t = 1; t <= 360; t += 0.01){

                point_x = circle_x + circle_radius * cos(t);
                point_y = circle_y + circle_radius * sin(t);
                
               
                SDL_RenderDrawPoint(renderer, point_x, point_y);
                
                //SDL_RenderFillRect(renderer, &pxxx_rect);
            }

            c++;
        }*/

		SDL_RenderPresent(renderer);
        SDL_Delay(6);

	}

    printf("SNOOKER GAME");
    return 0;
	SDL_DestroyWindow(win);
	SDL_Quit();

}
