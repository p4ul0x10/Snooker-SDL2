void show_init_pos(int n[], float vetX[], float vetY[]){

	/*
		init pos x y
		count -> counter limit max ball
		step_x -> counter columns 
		step_y -> recover and counter coluns y
		inc_x -> increment total x && inc_y -> increment total y		
	*/
	
	int count = 0, step_x = 0, step_y = 0;

	float x, y, x_inc, y_inc, y_limit_space=0;

	x = 700;
	y = 217;

	while(count < 15){

		//start increment step x -> limit left or right
		if(count == 1 || count == 3 || count == 6 || count == 10){

			step_x++; 
		}
		//end increment step x -> limit left or right

		x_inc = x + (1 * step_x) + (18 * step_x); 

		if(count == 0){
		
			vetX[count] = x;
			vetY[count] = y;

		}else if(count > 0 && count < 3){
			
			//1 2
			step_y = count;

			if(count == 1){
				y_inc = y - 10 - 0.50;
			}else{
				y_inc = y - 10 + 20 + 0.50;
			}

			vetX[count] = x_inc;
			vetY[count] = y_inc;

		}else if(count > 2 && count <= 5){
			
			//3 4 5

			step_y = count - 2;
			y_inc = y - 40 + (20 * step_y);
			
			if(count == 3){
				y_inc = y_inc - 0.50;
			}

			if(count == 4){

				y_inc = y_inc;
			}
			
			if(count == 5){
				y_inc = y_inc + 2;

			}
			vetX[count] = x_inc;
			vetY[count] = y_inc;

		}else if(count > 5 && count < 10){
			
			//6 7 8 9
			step_y = count - 4;
			y_inc = y - 70 + (20 * step_y);
			
			if(count == 6){
				y_inc = y_inc - 0.50;
			}

			if(count == 7){
				y_inc = y_inc;
			}

			if(count == 8){
				y_inc = y_inc + 2;
			}

			if(count == 9){
				y_inc = y_inc + 3;
			}

			vetX[count] = x_inc;
			vetY[count] = y_inc;

		}else{

			step_y = count - 10;
			y_inc = y - 40 + (20 * step_y);
		
			if(count == 10){
				y_inc = y_inc - 0.50;
			}
			if(count == 11){
				y_inc = y_inc;
			}
			if(count == 12){
				y_inc = y_inc + 2;
			}
			if(count == 13){
				y_inc = y_inc + 3;
			}
			if(count == 14){
				y_inc = y_inc + 4;
			}

			vetX[count] = x_inc;
			vetY[count] = y_inc;
		}

		count++;
	}
}

void init_random(char random_units[], int n[], int vetM[], float v[], float f[], float vetX[], float vetY[], float ini_x[], float ini_y[]){

	/*
	vetor x -> init pos x 
	vetor y -> init pos y
	vetor m = 100 -> null ball < 100 movements true 
	vetor n = random num ball -> 1 <= 15
	*/

	int count_ax = 0, count_units = 0, num_n;
    bool add_num = true;

    srand (time(NULL));
    // init random (triangle pos)
    while(random_units[0] == 'f'){

        num_n = rand() % 15+1;
       
        if(num_n == 0){
            num_n = 1;
        }

        if(num_n > 15){
            num_n = 15;
        }

        while(count_ax <= count_units){

            if(num_n == n[count_ax]){
                add_num = false;
            }
            count_ax++;
        }

        count_ax = 0;

        if(add_num == true){

            n[count_units] = num_n;
            v[count_units] = 0;
            f[count_units] = 0;
            vetM[count_units] = 100;
         	ini_x[count_units] = 0;
         	ini_y[count_units] = 0;
            count_units++;
        }

        add_num = true;
    
        if(count_units > 14){

        	vetX[15] = 317;
        	vetY[15] = 217;
        	vetM[15] = 100;
        	v[15] = 0;
        	f[15] = 0;
        	n[15] = 0;
    		ini_x[15] = 0;
    		ini_y[15] = 0;

        	show_init_pos(n, vetX, vetY);
            random_units[0] = 't';
        }
    }
    //end init random triangle
}

void check_point(int i_key, int vetM[], float vetX[], float vetY[], float ini_x[], float ini_y[]){

	float y_d, x_d;
		
	y_d = vetY[i_key] + 20;
	x_d = vetX[i_key] + 20;

	if(vetX[i_key] < 42 && vetY[i_key] <= 54 || vetX[i_key] > 837 && vetY[i_key] <= 54){

		if(vetY[i_key] < 52 && vetX[i_key] < 42 || vetY[i_key] < 52 && x_d > 837){		
			
			vetX[i_key] = 0;
			vetY[i_key] = 0;
			vetM[i_key] = 100;
			ini_x[i_key] = 0;
			ini_y[i_key] = 0; 
		}

	}
	
	if(vetX[i_key] <= 45 && vetY[i_key] <= 35 || vetX[i_key] >= 840 && vetY[i_key] <= 35){

		vetX[i_key] = 0;
		vetY[i_key] = 0;
		vetM[i_key] = 100;
		ini_x[i_key] = 0;
		ini_y[i_key] = 0;
	}

	if(vetX[i_key] >= 420 && vetX[i_key] <= 460 && vetY[i_key] < 32 ||
	 vetX[i_key] >= 420 && vetX[i_key] <= 460 && vetY[i_key] > 404){
	
			vetX[i_key] = 0;
			vetY[i_key] = 0;
			vetM[i_key] = 100;
			ini_x[i_key] = 0;
			ini_y[i_key] = 0; 

	}
	
	if(vetX[i_key] < 42 && y_d > 390 || vetX[i_key] > 837 && y_d > 390){

		if(y_d > 392 && vetX[i_key] < 42 || y_d > 392 && vetX[i_key] > 837){

			vetX[i_key] = 0;
			vetY[i_key] = 0;
			vetM[i_key] = 100;
			ini_x[i_key] = 0;
			ini_y[i_key] = 0; 
		}
	}

	if(vetX[i_key] <= 45 && y_d >= 401 || vetX[i_key] >= 840 && y_d >= 401){

		vetX[i_key] = 0;
		vetY[i_key] = 0;
		vetM[i_key] = 100;
		ini_x[i_key] = 0;
		ini_y[i_key] = 0;
	}
}

void check_table(int i_key, int vetM[], float vetX[], float vetY[], float ini_x[], float ini_y[]){

	//42 px l esquerda && 837 px r direita && 34 px cima 402 baixo

	float r_x, l_x, u_y, d_y, center_x;

	center_x = vetX[i_key] + 10;
	
	if(vetM[i_key] == 0){ //-Y +X

		r_x = vetX[i_key] + 20;
		u_y = vetY[i_key];
		
		//start match point
		check_point(i_key, vetM, vetX, vetY, ini_x, ini_y);
		//end match point 

		if(vetM[i_key] != 100){

			if(vetX[i_key] >= 837 && u_y > 54){

				vetM[i_key] = 2; //-y -x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key];
			}

			if(u_y <= 38 && r_x < 420 || u_y <= 38 && vetX[i_key] > 460){

				vetM[i_key] = 3; //+y -x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key];
			}
		}

	}else if(vetM[i_key] == 1){ // +Y -X

		d_y = vetY[i_key] + 20;
		l_x = vetX[i_key]+20;
		
		//start match point
		check_point(i_key, vetM, vetX, vetY, ini_x, ini_y);
		//end match point 

		if(vetM[i_key] != 100){
			
			if(vetX[i_key] <= 42 && d_y <= 390){

				vetM[i_key] = 3; //+y +x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key];
			}

			if(d_y >= 415 && l_x < 420 || d_y >= 415 && vetX[i_key] > 460){

				vetM[i_key] = 2; //+y +x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key]; 
			}
		}
	
	}else if(vetM[i_key] == 2){ // -Y -X

		l_x = vetX[i_key] + 20;
		//start match point
		check_point(i_key, vetM, vetX, vetY, ini_x, ini_y);
		//end match point 

		if(vetM[i_key] != 100){

			if(vetX[i_key] <= 42 && vetY[i_key] > 54){

				vetM[i_key] = 0; //-y +x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key]; 
			}

			if(vetY[i_key] <= 38 && l_x < 420 || vetY[i_key] <= 38 && vetX[i_key] > 460){

				vetM[i_key] = 1; //+y -x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key]; 
			}
		}

	}else if(vetM[i_key] == 3){ // +X +Y

		r_x = vetX[i_key] + 20;
		d_y = vetY[i_key] + 20;

		//start match point
		check_point(i_key, vetM, vetX, vetY, ini_x, ini_y);
		//end match point 

		if(vetM[i_key] != 100){

			if(vetX[i_key] >= 837 && d_y <= 390){

				vetM[i_key] = 1; //+y -x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key]; 
			}

			if(d_y >= 415 && r_x < 420 || d_y >= 415 && vetX[i_key] > 460){

				vetM[i_key] = 0; //-y +x
				ini_x[i_key] = vetX[i_key];
				ini_y[i_key] = vetY[i_key]; 
			}
		}
	}

}

void engine_show_all(SDL_Renderer *rendEngine, int n[], int m[], float v[], float f[], float x[], float y[], float ax[], float ay[], float ini_x[], float ini_y[], int ex[], int ey[]){

	int vet_kmain[16], limit_count = 0;
	float center_x[16], center_y[16], vetV[16], vetF[16];

	//start init gets
	for(int c = 0; c < 16; c++){

		vet_kmain[c] = c; //key main -> valids ball
		center_x[c] = x[c] + 10;
		center_y[c] = y[c] + 10;
		limit_count++; // limit for -> balls valid
		
	}
	//end init gets

	//start engine motion
	// m1 -> bola que colide inicialmente, a uma ou mais - m2 alvo que recebe choque da m1
	float check_x, check_y, calc_wh, calc_hw;
	
	for(int m1 = 0; m1 <= 15; m1++){

		if(x[m1] != 0 && y[m1] != 0 && m[m1] < 4){

			for(int m2 = 15; m2 >= 0; m2--){

				if(m1 != m2 && n[m1] != n[m2] && x[m2] != 0 && y[m2] != 0){

					if(center_x[m1] <= center_x[m2] && center_y[m1] >= center_y[m2]){

						check_x = center_x[m2] - center_x[m1];
						check_y = center_y[m1] - center_y[m2];

					}else if(center_x[m1] <= center_x[m2] && center_y[m1] < center_y[m2]){

						check_x = center_x[m2] - center_x[m1];
						check_y = center_y[m2] - center_y[m1];

					}else if(center_x[m1] > center_x[m2] && center_y[m1] >= center_y[m2]){

						check_x = center_x[m1] - center_x[m2];
						check_y = center_y[m1] - center_y[m2];

					}else if(center_x[m1] > center_x[m2] && center_y[m1] < center_y[m2]){

						check_x = center_x[m1] - center_x[m2];
						check_y = center_y[m2] - center_y[m1];

					}
					
					if(check_x <= 20 && check_y <= 20 && v[m1] != 0){ //check_x & check_y limit for shock

						float conv_ang, calc_ang_x, calc_ang_y, conv_ang_x, conv_ang_y, px_hw, px_wh;
						float prox, limit_prox, rec_ang_x, rec_ang_y;

						conv_ang = 45 / 20; //45 degs / size x y - > width & height

						calc_ang_x = check_x * conv_ang; //find angle (degs) x
						calc_ang_y = check_y * conv_ang; //find angle (degs) y

						conv_ang_x = calc_ang_x / 45; //convert degs in px - > x
						conv_ang_y = calc_ang_y / 45; //convert degs in px -> y

						px_hw = conv_ang_y / conv_ang_x; // px x -> calc width / height
						px_wh = conv_ang_x / conv_ang_y; // px y -> calc height / width 
	 
						rec_ang_x = 20 - check_x; // recover angle x -> limit de profundidade
						rec_ang_y = 20 - check_y; //recover angle y -> limit de profundidade

						if(ini_x[m2] == 0 && ini_y[m2] == 0){
							
							ini_x[m2] = x[m2]; // init pos x after shock (pos - > width)
							ini_y[m2] = y[m2]; // init pos y after shock (pos - > height)
						
						}

						if(m[m1] == 0){ // -y +x

							if(conv_ang_x >= conv_ang_y){ // degs x > degs y

								prox = x[m1] + 20; 
								limit_prox = x[m2] + rec_ang_x;

								if(prox >= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}

							}else{

								prox = y[m1];
								limit_prox = (y[m2] + 20) - rec_ang_y;

								if(prox <= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}
							}

						}else if(m[m1] == 1){ // +y -x 

							if(conv_ang_x >= conv_ang_y){ //x deg > y deg -> relativo max 45 deg 45 deg

								prox = x[m1];
								limit_prox = (x[m2] + 20) - rec_ang_x;

								if(prox >= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}

							}else{

								prox = y[m1] + 20;
								limit_prox = y[m2] + rec_ang_y;

								if(prox <= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}
							}

						}else if(m[m1] == 2){ // -y -x

							if(conv_ang_x >= conv_ang_y){ // x deg > y deg -> relativo max 45 deg x 45 deg y

								prox = x[m1];
								limit_prox = (x[m2] + 20) - rec_ang_x;

								if(prox <= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}

							}else{

								prox = y[m1];
								limit_prox = (y[m2] + 20) - rec_ang_y;
								
								if(prox <= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}
							}

						}else if(m[m1] == 3){ // +y +x

							if(conv_ang_x >= conv_ang_y){

								prox = x[m1] + 20;
								limit_prox = x[m2] + rec_ang_x;

								if(prox >= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}

							}else{	

								prox = y[m1] + 20;
								limit_prox = y[m2] + rec_ang_y;

								if(prox >= limit_prox){
									set_dest_xy(m1, m2, px_wh, px_hw, m, x, y, ini_x, ini_y, ax, ay, v, f, ex, ey);
								}
							}

						}
					}
				}
			}
		}
	}
	//end engine motion

	//start show renderer balls && check tables 
	SDL_Rect Texture_rect;
   	
    Texture_rect.w = 20;
    Texture_rect.h = 20;
    
    int v_key, count = 0;
    float deg, t_x, t_y;
    bool run = true;
    
    //start pointers decrarement
    SDL_Surface *Surface;
    SDL_Texture *Texture;

    SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
    //end pointers declarement

    while(run == true){

    	/*
    		v[] -> speed 
    		vetM[] -> moviment mode
    		vetM = 0 -> -y +x 
    		vetM = 1 -> +y -x 
    		vetM = 2 -> -y -x 
    		vetM = 3 -> +y +x
    	*/
    	
    	v_key = count;
    	
    	if(x[v_key] > 0 && y[v_key] > 0){

	    	if(m[v_key] == 0 && v[v_key] > 0.0){

	    		if(x[v_key] != 0 && y[v_key] != 0){

	    			//start add mode 0 = -y +x
	    			x[v_key] = x[v_key] + v[v_key] * ax[v_key];
	    			y[v_key] = y[v_key] - v[v_key] * ay[v_key];
	    			//end add mode 0 = -y +x
	    			
	    			check_table(v_key, m, x, y, ini_x, ini_y);
	    		}

	    	}else if(m[v_key] == 1 && v[v_key] > 0.0){

	    		if(x[v_key] != 0 && y[v_key] != 0){
	    		
	    			//start add mode 1 = +y -x
	    			x[v_key] = x[v_key] - v[v_key] * ax[v_key];
	    			
	    			y[v_key] = y[v_key] + v[v_key] * ay[v_key];
	    			//end add mode 1 = +y -x
	    			check_table(v_key, m, x, y, ini_x, ini_y);
	    		
	    		}

	    	}else if(m[v_key] == 2 && v[v_key] > 0.0){

	    		if(x[v_key] != 0 && y[v_key] != 0){
	    		
	    			//start add mode 2 = -y -x
	    			x[v_key] = x[v_key] - v[v_key] * ax[v_key];
	    			
	    			y[v_key] = y[v_key] - v[v_key] * ay[v_key];
	    			//end add mode 2 = -y -x
	    			check_table(v_key, m, x, y, ini_x, ini_y);
	    		
	    		}

	    	}else if(m[v_key] == 3 && v[v_key] > 0.0){

	    		if(x[v_key] != 0 && y[v_key] != 0){

	    			//start add mode 3 = +y +x
	    			x[v_key] = x[v_key] + v[v_key] * ax[v_key];
	    			
	    			y[v_key] = y[v_key] + v[v_key] * ay[v_key];
	    			//end add mode 3 = +y +x
	    			check_table(v_key, m, x, y, ini_x, ini_y);
	    		
	    		}

	    	}

	    	if(v[v_key] >= 0.0 && m[v_key] < 4){

	    		float calc_v, calc_fv, calc_dst, v_move, max_v, dec_m, dec_f, percent_fs, rec_percent;
	    		float ey_point, ex_point;
	    		
	    		max_v = f[v_key];
	    		v_move = v[v_key];
	    		
	    		dec_m = 0.1; //massa 1
	    		dec_f = 0.2; //massa 02 

	    		calc_dst = f[v_key] - v[v_key]; //total distancia percorrida -> max init - f speed now

	    		percent_fs = (calc_dst / f[v_key]) * 100; // percentual de perda de forca

	    		rec_percent = 100 - percent_fs; // recupera porcentagem crescente 0 ~ 100
	    
	    		calc_v = (dec_m / 100) * rec_percent; // calcula porcentual de perda atual, baseado forca atual  
	    		
	    		calc_fv = (dec_f / 100) * percent_fs; //dec weight ball

	    		v[v_key] = v[v_key] - calc_fv;
	    		v[v_key] = v[v_key] - calc_v;
	    	}

	    	//start stop engine
	    	if(m[v_key] < 4 && v[v_key] < 0.0){

	    		m[v_key] = 100;
	    		v[v_key] = 0; 
	    		f[v_key] = 0;
	    		ini_x[v_key] = 0;
	    		ini_y[v_key] = 0;
	    		ax[v_key] = 0;
	    		ay[v_key] = 0;
	    	}
	    	
	    	if(m[v_key] == 100 && f[v_key] > 0){
	    	
	    		ini_x[v_key] = 0;
	    		ini_y[v_key] = 0;
	    		f[v_key] = 0;
	    		v[v_key] = 0;
	    		ax[v_key] = 0;
	    		ay[v_key] = 0;
	    	
	    	}
	    	//end stop engines
	    	
	    	deg = 0;

	    	if(n[v_key] == 1){
	   
	    		Surface = IMG_Load("assets/images/b1.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];
	   	
	   			Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 2){
		
				Surface = IMG_Load("assets/images/b2.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];
	    	
	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 3){
	    
	    		Surface = IMG_Load("assets/images/b3.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 4){
	    
	    		Surface = IMG_Load("assets/images/b4.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 5){
	    		
	    		Surface = IMG_Load("assets/images/b5.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 6){
	    		
	    		Surface = IMG_Load("assets/images/b6.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 7){
	    		
	    		Surface = IMG_Load("assets/images/b7.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 8){
	    		
	    		Surface = IMG_Load("assets/images/b8.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 9){
	    		
	    		Surface = IMG_Load("assets/images/b9.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 10){
	    		
	    		Surface = IMG_Load("assets/images/b10.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 11){
	    		
	    		Surface = IMG_Load("assets/images/b11.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 12){
	    		
	    		Surface = IMG_Load("assets/images/b12.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 13){
	    		
	    		Surface = IMG_Load("assets/images/b13.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 14){
	    		
	    		Surface = IMG_Load("assets/images/b14.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];

	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 15){
	    		
	    		Surface = IMG_Load("assets/images/b15.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];	
	    		
	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);

	    	}else if(n[v_key] == 0){

	    		Surface = IMG_Load("assets/images/bm.png");
	    		Texture_rect.x = x[v_key];
	    		Texture_rect.y = y[v_key];	
	    		
	    		Texture = SDL_CreateTextureFromSurface(rendEngine, Surface);
	    		SDL_FreeSurface(Surface);

	    		SDL_RenderCopyEx(rendEngine, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
	    		SDL_DestroyTexture(Texture);
	    	}

 		}

    	if(count <= 16){

    		count++; //increment ball count if limit true
    	}
    	
   		if(count >= 16){

    		run = false; // end loop
    	}
    	
	}
    //end show move && check tables
}
//move balls functions

