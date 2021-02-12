
void trace_route_xy(char type_route[], int type_v[], int m_num, int vetN[], float x[], float y[], float hw, float wh, int b_checked[], float ax[], float ay[], char mode_player[]){

	//trace_route_xy(vetN, x, y, hw, wh, mode_player);
	float all_x[15], all_y[15];
	float check_co[7], target_x, target_y, x_co[7], y_co[7];
	int m = 0, ct = 0;

	//
	for(int t = 0; t < 15; t++){

		if(vetN[t] == m_num){
			
			target_x = x[t]+10;
			target_y = y[t]+10;
		
		}else{

			all_x[ct] = x[t];
			all_y[ct] = y[t];
			ct++;
		}		

	}
	//

	//
	int rt = 0, r = 0, cont_valid = 0;
	float distance, dx, dy;
	
	for(int cv = 0; cv < 7; cv++){

		if(b_checked[cv] != 0){

			cont_valid++;
			if(cont_valid >= 7){
				cont_valid = 7;
			}
		}
	}

	if(wh >= 1){

		wh = 1;
		hw = hw;

	}else{

		wh = wh;
		hw = 1;
	}

	bool checked = false;
	float df_limit, limit_y, cont_limit;

	if(type_route[0] == 'c' && type_route[1] == 'd'){

		limit_y = 404;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = limit_y - target_y;

				while(r <= df_limit){

					target_x = target_x - wh;
					target_y = target_y + hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}
					
					r++;
				}

				r = 0;

				//start add pre valid check
				if(checked == false && rt >= 13 && m_num != 8){
					
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 5;
					
				}
				//end add pre valid check
			}

			rt++;
		}

	}else if(type_route[0] == 'l' && type_route[1] == 'd'){

		limit_y = 412;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = limit_y - target_y;

				while(r <= df_limit){

					target_x = target_x - wh;
					target_y = target_y + hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}

					r++;
				}
				r = 0;
				//start add valid pre shot
				if(checked == false && rt >= 13 && m_num != 8){
					
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 3;
					
				}
				//end add valid pre shot
			}

			rt++;
		}

		//SDL_Quit();

	}else if(type_route[0] == 'l' && type_route[1] == 'u'){

		limit_y = 49;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = target_y - limit_y;

				while(r <= df_limit){

					target_x = target_x - wh;
					target_y = target_y - hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}

					r++;
				}

				r = 0;
				//start add valid pre shot
				if(checked == false && rt >= 13 && m_num != 8){
					
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 1;
				
				}
				//end add valid pre shot
			}

			rt++;
		}

	}else if(type_route[0] == 'c' && type_route[1] == 'u'){

		limit_y = 49;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = target_y - limit_y;

				while(r <= df_limit){

					target_x = target_x - wh;
					target_y = target_y - hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}

					r++;
				}

				r = 0;
				//start add valid pre shot
				if(checked == false && rt >= 13 && m_num != 8){
					
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 2;
					
				}
				//end add valid pre shot
			}

			rt++;
		}

	}else if(type_route[0] == 'r' && type_route[1] == 'u'){

		limit_y = 49;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = target_y - limit_y;

				while(r <= df_limit){

					target_x = target_x + wh;
					target_y = target_y - hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}

					r++;
				}

				r = 0;
				//start add valid pre shot
				if(checked == false && rt >= 13 && m_num != 8){
					
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 4;
									
				}
				//end add valid pre shot
			}

			rt++;
		}

	}else if(type_route[0] == 'r' && type_route[1] == 'd'){

		limit_y = 412;

		while(rt < 15){

			if(vetN[rt] != m_num){

				df_limit = limit_y - target_y;

				while(r <= df_limit){

					target_x = target_x + wh;
					target_y = target_y + hw;

					dx = target_x - (x[rt]+10);
					dy = target_y - (y[rt]+10);
						
					distance = sqrt(dx*dx + dy*dy);
					
					if(distance < 20){
						
						//invalid shot
						checked = false;

					}

					r++;
				}

				r = 0;
				//start add valid pre shot
				if(checked == false && rt >= 13 && m_num != 8){
							
					b_checked[cont_valid] = m_num;
					ax[cont_valid] = wh;
					ay[cont_valid] = hw;
					type_v[cont_valid] = 6;
				
				}
				//end add valid pre shot
			}

			rt++;
		}
	}
	//
	//SDL_Quit();
}

void pre_final_check(char mode_player[], int type_v[], int m[], float v[], float f[], float auxx[], float auxy[], int vetN[], float x[], float y[], int b_checked[], float ax[], float ay[], float dwt_x, float dwt_y, int valid_check[]){
					
	int b_c = 0, cont_v = 0, c = 0, m_aux, target_m[7], mode_m[7];
	float distance, limit_dfx, limit_dfy, df_x, df_y, hw, wh, mx[7], my[7];
	float dsty[7], dstx[7], baux[7], bauy[7];
	bool checked = false;

	//start get set pos x y (valid pre shot)
	for(int m = 0; m < 7; m++){

		if(b_checked[m] != 0){

			for(int i = 0; i < 15; ++i){
				
				if(b_checked[m] == vetN[i]){
					
					mx[m] = x[i];
					my[m] = y[i];
				}
			}

			b_c++;
		}
	}
	//end get set pos x y (valid pre shot)

	//start
	for(int mcf = 0; mcf < 7; mcf++){

		if(b_checked[mcf] != 0 && mcf == 0){

			if(dwt_x >= mx[mcf] && dwt_y >= my[mcf]){

				df_x = dwt_x - mx[mcf];
				df_y = dwt_y - my[mcf];
				m_aux = 2;

			}else if(dwt_x >= mx[mcf] && dwt_y < my[mcf]){

				df_x = dwt_x - mx[mcf];
				df_y = my[mcf] - dwt_y;
				m_aux = 1;

			}else if(dwt_x < mx[mcf] && dwt_y >= my[mcf]){

				df_x = mx[mcf] - dwt_x;
				df_y = dwt_y - my[mcf];
				m_aux = 0;

			}else if(dwt_x < mx[mcf] && dwt_y < my[mcf]){

				df_x = mx[mcf] - dwt_x;
				df_y = my[mcf] - dwt_y;
				m_aux = 3;

			}	

			hw = df_y / df_x;
			wh = df_x / df_y;

			if(wh >= 1){
				wh = 1;
			}else{
				hw = 1;
			}

			if(dwt_y >= my[mcf]){
				limit_dfy = 0; 
			}else{
				limit_dfy = 1;
			}

			if(dwt_x >= mx[mcf]){
				limit_dfx = 0;
			}else{
				limit_dfx = 1;
			}

			for(int pcf = 0; pcf < 15; pcf++){

				if(cont_v == 0 && vetN[pcf] != 8 && b_checked[mcf] != vetN[pcf] && mcf != pcf){

					dwt_x = dwt_x;
					dwt_y = dwt_y;

					while(c < df_y){

						if(limit_dfy == 0){
							dwt_y = dwt_y - hw;
						}else{
							dwt_y = dwt_y + hw;
						}

						if(limit_dfx == 0){
							dwt_x = dwt_x - wh;
						}else{
							dwt_x = dwt_x + wh;
						}

						df_x = dwt_x - x[pcf];
						df_y = dwt_y - y[pcf];

						distance = sqrt(df_x*df_x + df_y*df_y);
					
						if(distance < 20){
							
							//invalid shot
							//checked = false;

						}

						c++;
					}

					c = 0;
				
					//start add valid shot
					if(checked == false){

						bool valid_1 = true;

						for(int cb = 0; cb <= cont_v; cb++){
							
							if(valid_check[cb] == b_checked[mcf]){
								valid_1 = false;
							}
						}

						if(valid_1 == true){
							
							valid_check[cont_v] = b_checked[mcf];
							
							dsty[cont_v] = df_y;
							dstx[cont_v] = df_x;

							bool stop_check = false;
							
							for(int xy = 0; xy < 15; xy++){

								if(stop_check == false){

									if(vetN[xy] == b_checked[mcf]){

										baux[cont_v] = ax[xy];
										bauy[cont_v] = ay[xy];
										target_m[cont_v] = type_v[xy];
										mode_m[cont_v] = m_aux;
										stop_check = true;
									}
								}
							}

							cont_v++;
						
						}

					}else{

						checked = false; //turn 'invalid' -> pre valid
					}
					//end add valid shot
				}
			}
		}
	}
	//end

	//start valid shot route 
	float deg_x, deg_y, df_degx, df_degy, w_wh, w_hw;
	int target, center_t;

	center_t = 435;

	if(b_c != 0){
		
		if(cont_v >= 0){

		cont_v = 0;
		for(int fnd = 0; fnd < 15; fnd++){

			if(vetN[fnd] != 8 && vetN[fnd] == valid_check[0]){

				//start
				if(target_m[cont_v] == 1){ //target == left up

					deg_x = (x[fnd] + 10) + 10 * baux[cont_v];
					deg_y = (y[fnd] + 10) + 10 * bauy[cont_v];

				}else if(target_m[cont_v] == 2){ // target == center up

					if(x[fnd] <= center_t){

						deg_x = (x[fnd] + 10) - 10 * baux[cont_v];
						deg_y = (y[fnd] + 10) + 10 * bauy[cont_v];
						
					}else{

						deg_x = (x[fnd] + 10) + 10 * baux[cont_v];
						deg_y = (y[fnd] + 10) + 10 * bauy[cont_v];
					}

				}else if(target_m[cont_v] == 3){ // target == left down

					deg_x = (x[fnd] + 10) + 10 * baux[cont_v];
					deg_y = (y[fnd] + 10) - 10 * bauy[cont_v];

				}else if(target_m[cont_v] == 4){ // target == right up

					deg_x = (x[fnd] + 10) - 10 * baux[cont_v];
					deg_y = (y[fnd] + 10) + 10 * bauy[cont_v];

				}else if(target_m[cont_v] == 5){ // target == center down

					if(x[fnd] <= center_t){
						
						deg_x = (x[fnd] + 10) - 10 * baux[cont_v]; 
						deg_y = (y[fnd] + 10) + 10 * bauy[cont_v];  
					
					}else{

						deg_x = (x[fnd] + 10) + 10 * baux[cont_v];
						deg_y = (x[fnd] + 10) + 10 * bauy[cont_v];
					}

				}else if(target_m[cont_v] == 6){ // target == right down

					deg_x = (x[fnd] + 10) - 10 * baux[cont_v];
					deg_y = (y[fnd] + 10) - 10 * bauy[cont_v];

				}
				//end

				
				if(mode_m[cont_v] == 0){ // y- x+
				
					df_degx = deg_x - (x[15] + 10);
					df_degy = (y[15] + 10) - deg_y;

				}else if(mode_m[cont_v] == 1){ // y+ x
					
					df_degx = (x[15] + 10) - deg_x;
					df_degy = deg_y - (y[15] + 10);

				}else if(mode_m[cont_v] == 2){ // y- x-
					
					df_degx = (x[15] + 10) - deg_x;
					df_degy = (y[15] + 10) - deg_y;

				}else if(mode_m[cont_v] == 3){ //y+ x+
					
					df_degx = deg_x - (x[15] + 10);
					df_degy = deg_y - (y[15] + 10);
				}

				w_wh = df_degx / df_degy;
				w_hw = df_degy / df_degx;
				
				if(w_hw >= 1){

					w_hw = 1;

				}else{

					w_wh = 1;
				}

				float vf;
				float p_final, p_size_x, p_size_y, size_x, size_y, calc_cue, f_cue, add_v;

				if(dstx[cont_v] >= dsty[cont_v]){

					size_x = 900 - dstx[cont_v];
					p_size_x = (size_x / 900) * 100;
					p_final = p_size_x;

				}else{

					size_y = 540 - dsty[cont_v];
					p_size_y = (size_y / 540) * 100;
					p_final = p_size_y;
				}

				vf = p_final / 10;
				f_cue = 10 / 10;
                calc_cue = f_cue * (vf / 10);
                add_v = vf * 1.8 + (calc_cue); //f forca -> cue * aceleracao 1.0

				auxx[15] = w_wh;
				auxy[15] = w_hw;
				m[15] = mode_m[cont_v];
				f[15] = add_v+5;
				v[15] = add_v+5;
			}
		}
		//SDL_Quit();

		}else if(cont_v > 1){


		}else if(cont_v == 0){

		}
	
	}else{

		m[15] = 3;
		f[15] = 10;
		v[15] = 10;
		auxx[15] = 1;
		auxy[15] = 0.1;

	}

	//end valid shot route

}

void check_route(int b_checked[], int on_rands[], int mr, char route_v[]){


	for(int cn = 0; cn < 7; cn++){
	
		if(b_checked[cn] == on_rands[mr] && b_checked[cn] != 0){

			route_v[0] = 't';
		}
	}
	
}

void machine_route(int vetN[], int m[], float v[], float f[], float x[], float y[], float auxx[], float auxy[], char rand_on[], char mode_player[]){

	int mon = 0;
	float mx[7], my[7], ax[7], ay[7];
	int on_rands[7], valid_check[7], b_checked[7], type_v[7];
	float wt_x, wt_y, dwt_x, dwt_y;

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

		m[15] = 3;
		f[15] = 10;
		v[15] = 10;
		auxx[15] = 1;
		auxy[15] = 0.1;
	
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
	float cmp_x, cmp_y, wh, hw, center_tbx;
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

	//
	tumx = 435;
	tumy = 52;
	tdmx = 435;
	tdmy = 404;
	//

	tdlx = 50;
	tdly = 412;
	tdrx = 837;
	tdry = 412;

	center_tbx = 430;

	if(stage2 == 0 && mode_player[1] == '7' || mode_player[1] == '9'){

		for(int mr = 0; mr < 7; mr++){

			//start pre check routes
			if(x[15] >= mx[mr] && y[15] <= my[mr]){

				//start find routes
				if(mx[mr] >= center_tbx){ //white >  pos x center table 

					//start
					if(stage1 == 0 && stage2 == 0){ // center 

						cmp_x = (mx[mr] + 10) - tdmx;
						cmp_y = tdmy - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'd';
						
						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}

					}else if(stage1 == 1 && stage2 == 0){ // left down

						cmp_x = (mx[mr] + 10) - tdlx;
						cmp_y = tdly - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}

					}else if(stage1 == 2 && stage2 == 0){ // left up

						cmp_x = (mx[mr] + 10) - tulx;
						cmp_y = (my[mr] + 10) - tuly;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
			
					}

					//end 
				}else{

					if(stage1 == 0 && stage2 == 0){

						cmp_x = tdmx - (mx[mr] + 10);
						cmp_y = tdmy - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
					
					}else if(stage1 == 1 && stage2 == 0){

						cmp_x = (mx[mr] + 10) - tdlx;
						cmp_y = tdly - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}

					}else if(stage1 == 2 && stage2 == 0){

						cmp_x = (mx[mr] + 10) - tulx;
						cmp_y = (my[mr] + 10) - tuly;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
					}

				}
				//end find routes
									
			}else if(x[15] >= mx[mr] && y[15] > my[mr]){

				//start find routes
				if(mx[mr] >= center_tbx){

					if(stage1 == 0 && stage2 == 0){ // center

						cmp_x = (mx[mr] + 10) - tumx;
						cmp_y = (my[mr] + 10) - tumy;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}

					}else if(stage1 == 1 && stage2 == 0){ // left up

						cmp_x = (mx[mr] + 10) - tulx;
						cmp_y = (my[mr] + 10) - tuly;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}

					}else if(stage1 == 2 && stage2 == 0){ // left down

						cmp_x = (mx[mr] + 10) - tdlx;
						cmp_y = tdly - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}	
					
				}else{

					if(stage1 == 0 && stage2 == 0){

						cmp_x = tumx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tumy;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}	
					
					}else if(stage1 == 1 && stage2 == 0){

						cmp_x = (mx[mr] + 10) - tulx;
						cmp_y = (my[mr] + 10) - tuly;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						

					}else if(stage1 == 2 && stage2 == 0){

						cmp_x = (mx[mr] + 10) - tdlx;
						cmp_y = tdly - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'l';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}
					
				}
				//end find routes
									
			}else if(x[15] < mx[mr] && y[15] <= my[mr]){

				//start find routes 
				if(mx[mr] >= center_tbx){

					if(stage1 == 0 && stage2 == 0){ // center 

						cmp_x = (mx[mr] + 10) - tdmx;
						cmp_y = tdmy - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}						

					}else if(stage1 == 1 && stage2 == 0){ // right down 

						cmp_x = tdrx - (mx[mr] + 10);
						cmp_y = tdry - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						

					}else if(stage1 == 2 && stage2 == 0){ // right up

						cmp_x = turx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tury;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);	
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}
					
				}else{

					if(stage1 == 0 && stage2 == 0){

						cmp_x = tdmx - (mx[mr] + 10);
						cmp_y = tdmy - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
					
					}else if(stage1 == 1 && stage2 == 0){

						cmp_x = tdrx - (mx[mr] + 10);
						cmp_y = tdry - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);	
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}else if(stage1 == 2 && stage2 == 0){

						cmp_x = turx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tury;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}
					
				}
				//end find routes
										
			}else if(x[15] < mx[mr] && y[15] > my[mr]){

				//start find routes
				if(mx[mr] >= center_tbx){

					if(stage1 == 0 && stage2 == 0){ // center

						cmp_x = (mx[mr] + 10) - tumx;
						cmp_y = (my[mr] + 10) - tumy;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}						

					}else if(stage1 == 1 && stage2 == 0){ // right up

						cmp_x = turx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tury;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						

					}else if(stage1 == 2 && stage2 == 0){ // right down

						cmp_x = tdrx - (mx[mr] + 10);
						cmp_y = tdry - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}
					
				}else{

					if(stage1 == 0 && stage2 == 0){

						cmp_x = tumx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tumy;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'c';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}	
					
					}else if(stage1 == 1 && stage2 == 0){

						cmp_x = turx - (mx[mr] + 10);
						cmp_y = (my[mr] + 10) - tury;

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'u';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}else if(stage1 == 2 && stage2 == 0){

						cmp_x = tdrx - (mx[mr] + 10);
						cmp_y = tdry - (my[mr] + 10);

						hw = cmp_y / cmp_x;
						wh = cmp_x / cmp_y;

						m_num = on_rands[mr];
						type_route[0] = 'r';
						type_route[1] = 'd';

						trace_route_xy(type_route, type_v, m_num, vetN, x, y, hw, wh, b_checked, ax, ay, mode_player);
						check_route(b_checked, on_rands, mr, route_v);

						if(route_v[0] == 'f'){

							stage1++;
						}else{
							stage1 = 3;
						}
						
					}
				}
				//end find routes			
			}
			//end pre check routes
			
			//SDL_Quit();
			route_v[0] = 'f'; //next loop (ball)
		}

	}else if(stage1 != 0){ // init stage2 checks

	}
	//end pre check

	//start pre check final
	if(mode_player[1] == '7' || mode_player[1] == '9'){
		//SDL_Quit();
		pre_final_check(mode_player, type_v, m, v, f, auxx, auxy, vetN, x, y, b_checked, ax, ay, dwt_x, dwt_y, valid_check);
	}
	//end pre check final

}