
void machine_route(int vetN[], int m[], float v[], float f[], float x[], float y[], float auxx[], float auxy[], char rand_on[], char mode_player[]){

	int mon = 0;
	int t1, t2;
	float mx[7], my[7], ax[7], ay[7];
	int on_rands[7], valid_check[7], b_checked[7], type_v[7];
	float target_inix, target_iniy, iniwh, inihw, wt_x, wt_y, dwt_x, dwt_y;
	float cmp_x, cmp_y, wh, hw, center_tbx;
	//start get set ball values
	wt_x = x[15] + 10;
	wt_y = y[15] + 10;
	dwt_x = x[15];
	dwt_y = y[15];

	for(int mc = 0; mc < 7; mc++){

		on_rands[mc] = 0;
		b_checked[mc] = 0;
		valid_check[mc] = 0;
		ax[mc] = 0;
		ay[mc] = 0;
	}

	if(mode_player[0] == '0' && mode_player[1] == '0'){

		target_inix = x[4];
		target_iniy = y[4];

		if(x[15] > target_inix){
			t1 = 1;
		}else{
			t1 = 0;
		}

		if(y[15] > target_iniy){
			t2 = 1;
		}else{
			t2 = 0;
		}

		if(t1 == 1){
			cmp_x = x[15] - target_inix;
		}else{
			cmp_x = target_inix - x[15];
		}

		if(t2 == 1){
			cmp_y = y[15] - target_iniy;
		}else{
			cmp_y = target_iniy - y[15];
		}

		inihw = cmp_y / cmp_x;
		iniwh = cmp_x / cmp_y;

		if(iniwh >= 1){
			iniwh = 1;
		}else{
			inihw = 1;
		}

		if(t1 == 1 && t2 == 1){
			m[15] = 2;
		}else if(t1 == 1 && t2 == 0){
			m[15] = 1;
		}else if(t1 == 0 && t2 == 1){
			m[15] = 0;
		}else if(t1 == 0 && t2 == 0){
			m[15] = 3;
		}
		
		auxx[15] = iniwh;
		auxy[15] = inihw;
		v[15] = 16;
		f[15] = 16;
	
	}else if(mode_player[0] == 'p' && mode_player[1] == '7'){ //machine 9 >=

		for(int on = 0; on < 15; on++){

			if(vetN[on] > 8 && x[on] != 0 && y[on] != 0){

				on_rands[mon] = vetN[on];
				mx[mon] = x[on];
				my[mon] = y[on];
				mon++;

			}
		}

		//SDL_Quit();

	}else if(mode_player[0] == 'p' && mode_player[1] == '9'){ //machine 7 <= 

		for(int on = 0; on < 15; on++){

			if(vetN[on] < 8 && x[on] != 0 && y[on] != 0){

				on_rands[mon] = vetN[on];
				mx[mon] = x[on];
				my[mon] = y[on];
				mon++;

			}
		}

		//SDL_Quit();
	}
	//end get set ball values

	//start pre check
	int stage1=0, stage2=0, true_r = 0, m_num;
	float center_tabx, center_taby, vet_st0[7], vet_st1[7], vet_stt0[7], vet_stt1[7];
	float tulx, turx, tdlx, tdrx;
	float tuly, tury, tdly, tdry;
	float tumx, tumy,tumrx, tdmx, tdmy;	
	char type_route[2], route_v[1];
	bool true_b = false;

	route_v[0] = 'f';

	tulx = 50;
	tuly = 49;
	
	turx = 837;
	tury = 49;

	tumx = 435;
	tumy = 52;
	
	tdmx = 435;
	tdmy = 404;

	tdlx = 50;
	tdly = 412;
	
	tdrx = 837;
	tdry = 412;

	center_tbx = 430;
	
	int c1 = 0, c2 = 0, cr1 = 0, cr2 = 0; //init counts
	int x_mod, y_mod, c_mod;
	float cx, cy, cb, df_limit, df_limit_y, df_limit_x, bw, bh, cmp_xb, cmp_yb;
	float get_deg, set_deg, deg, pi, px, py, divAL, target_y, target_x, t = 1, tt = 0.01;

	if(mode_player[1] == '7' || mode_player[1] == '9'){
		
		while(c1 < 7){

			cb = mx[c1] + 10;
			
			if(cb <= 1000 && mx[c1] != 0 && my[c1] != 0){

				if(x[15] >= mx[c1] && y[15] > my[c1] && mx[c1] != 0 && my[c1] != 0){

					//left up
					//center up
					y_mod = 1;
					x_mod = 1;

				}else if(x[15] >= mx[c1] && y[15] < my[c1]){

					//left down
					//center down
					y_mod = 1;
					x_mod = 0;

				}else if(x[15] < mx[c1] && y[15] >= my[c1]){

					//center up
					//right up
					y_mod = 0;
					x_mod = 1;

				}else if(x[15] < mx[c1] && y[15] < my[c1]){

					//center down
					//right down
					y_mod = 0;
					x_mod = 0;
				}

				c_mod = 0; // center < 

			}else{

				if(x[15] >= mx[c1] && y[15] > my[c1]){

					//left up
					//center up
					y_mod = 1;
					x_mod = 1;

				}else if(x[15] >= mx[c1] && y[15] < my[c1]){

					//left down
					//center down
					y_mod = 1;
					x_mod = 0;

				}else if(x[15] < mx[c1] && y[15] >= my[c1]){

					//center up
					//right up
					y_mod = 0;
					x_mod = 1;

				}else if(x[15] < mx[c1] && y[15] < my[c1]){

					//center down
					//right down
					y_mod = 0;
					x_mod = 0;
				}

				c_mod = 1; // center >
			} 
			//end get set mods

			cx = mx[c1] + 10;
			cy = my[c1] + 10;

			float auxcx, auxcy;

			auxcx = mx[c1] + 10;
			auxcy = my[c1] + 10;

			if(y_mod == 1 && x_mod == 1 && c_mod == 0){

				//start left up
				int circle_x, circle_bx;
		        int circle_y, circle_by;
		        int circle_radius;

		        //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

		        int point_x, point_bx;
		        int point_y, point_by;
		        int c = 0;

		        circle_radius = 10;
		     
	            circle_x = mx[c1] + 10;
	            circle_y = my[c1] + 10;
	            
	            for (float t = 1; t <= 360; t += 0.1){

	                point_x = circle_x + circle_radius * cos(t);
	                point_y = circle_y + circle_radius * sin(t);
	             	
	             	if(point_x >= circle_x && point_y >= circle_y){

	             		target_x = point_x+10;

	             		cmp_x = target_x - cx;
	             		cmp_y = point_y - cy;

	             		wh = cmp_x / cmp_y;
	             		hw = cmp_y / cmp_x;

	             		if(wh >= 1){
	             			wh = 1;
	             		}else{
	             			hw = 1;
	             		}

	             		int cc = 0;
	             		while(cc < 2001){

	             			if(cx <= 51 && cx > 49 && cy <= 50 && cy > 48){
	
	             				cmp_xb = (x[15] + 10) - target_x;
	             				cmp_yb = (y[15] + 10) - point_y;
	             				
	             				bw = cmp_xb / cmp_yb;
	             				bh = cmp_yb / cmp_xb;

	             				if(bw >= 1){
	             					bw = 1;
	             				}else{
	             					bh = 1;
	             				}

	             				v[15] = 10*1.4;
								f[15] = 10*1.4;
								auxy[15] = bh;
								auxx[15] = bw;
								m[15] = 2;
								cc = 2001;
	             				//SDL_Quit();
	             			}

	             			cx -= wh;
	             			cy -= hw;
	             			cc++;
	             		}

	             		cx = mx[c1] + 10;
	             		cy = my[c1] + 10;
	             	}   
	                //SDL_RenderDrawPoint(renderer, point_x, point_y);
	                //SDL_RenderFillRect(renderer, &pxxx_rect);
	            }
		       
				t = 1;
				tt = 0.1;
				if(v[15] == 0){
					t = 0;
					cx = mx[c1] + 10;
					cy = my[c1] + 10;
					while(t <= 1){

						while(cy >= 1 && c1 < 8){

							if(cx >= 49 && cx < 51 && cy > 49 && cy <= 50){

								
								target_x = (mx[c1] + 10) + 10 * t;
								target_y = (my[c1] + 20);
								
								cmp_xb = (x[15] + 10) - target_x;
								cmp_yb = y[15] - target_y;

								hw = cmp_yb / cmp_xb;
								wh = cmp_xb / cmp_yb;

								if(hw >= 1){
									hw = 1;
								}else{
									wh = 1;
								}

								v[15] = 10*1.4;
								f[15] = 10*1.4;
								auxy[15] = hw;
								auxx[15] = wh;
								m[15] = 2;

								t = 1;
								c1 = 8;
								tt = 1;
								//SDL_Quit();
							}

							cx -= t;
							cy -= 1;
						}

						cx = mx[c1] + 10;
						cy = my[c1] + 10;

						tt++;
						t += 0.01;
					}
				}
				//end left up
			}
			//m_num = on_rands[c1];
			//route_mod(c_mod, x_mod, y_mod, m_num, vetN, x, y, m, v, f, auxx, auxy);
			c1++;
		}

		//start rand shot
		if(v[15] == 0){

			target_x = mx[0];
			target_y = my[0];

			if(x[15] > target_x){
				t1 = 1;
			}else{
				t1 = 0;
			}

			if(y[15] > target_y){
				t2 = 1;
			}else{
				t2 = 0;
			}

			if(t1 == 1){
				cmp_x = x[15] - target_x;
			}else{
				cmp_x = target_x - x[15];
			}

			if(t2 == 1){
				cmp_y = y[15] - target_y;
			}else{
				cmp_y = target_y - y[15];
			}

			hw = cmp_y / cmp_x;
			wh = cmp_x / cmp_y;

			if(wh >= 1){
				wh = 1;
			}else{
				hw = 1;
			}

			if(t1 == 1 && t2 == 1){
				m[15] = 2;
			}else if(t1 == 1 && t2 == 0){
				m[15] = 1;
			}else if(t1 == 0 && t2 == 1){
				m[15] = 0;
			}else if(t1 == 0 && t2 == 0){
				m[15] = 3;
			}
			
			auxx[15] = wh;
			auxy[15] = hw;
			v[15] = 14;
			f[15] = 14;

		}
		//end rand shot
	}
	//end pre check final

}

void check_units(int cont_m[], int cont_p[], int vetN[], float vetX[], float vetY[], char mode_player[]){

	int count = 0, cp = 0, cm = 0;

	if(mode_player[1] == '7'){		

		for(int p1 = 0; p1 < 15; p1++){
			
			if(vetN[p1] < 8 && vetY[p1] != 0 && vetX[p1] != 0){
				cp++;
				cont_p[0] = cp;
			}

			if(vetN[p1] > 8 && vetY[p1] != 0 && vetX[p1] != 0){
				cm++;
				cont_m[0] = cm;
			}
		}

	}else if(mode_player[1] == '9'){

		for(int p2 = 0; p2 < 15; p2++){
			
			if(vetN[p2] > 8 && vetY[p2] != 0 && vetX[p2] != 0){
				cp++;
				cont_p[0] = cp;
			}

			if(vetN[p2] < 8 && vetY[p2] != 0 && vetX[p2] != 0){
				cm++;
				cont_m[0] = cm;
			}
		}
	}

}