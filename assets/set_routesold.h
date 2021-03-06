void mode_op_change(int i_key, int mode_op[], char mode_e[]){

	/*
		i_key -> key (index)
		mode op vals -> 0, 1, 2, 3
		0 -> -y +x
		1 -> +y -x
		2 -> -y -x
		3 -> +y +x

		mode_y vals
		t = center for top
		b = center for bottom

	*/

	if(mode_op[i_key] == 0){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 1;
		}

	}else if(mode_op[i_key] == 1){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 0;
		}

	}else if(mode_op[i_key] == 2){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 3;
		}

	}else if(mode_op[i_key] == 3){

		if(mode_e[0] == 't'){

		}else if(mode_e[0] == 'b'){

			mode_op[i_key] = 2;
		}
	}
}

void add_effect(int i_key, char mode_e[], float dec_percent, float f[], float v[]){

	float dec_p, dec_v, mb;

	if(mode_e[0] == 't' || mode_e[0] == 'b' || mode_e[0] == 'n'){

		dec_p = (dec_percent / 100) * v[i_key];
		dec_v = v[i_key] - dec_p;

		v[i_key] = dec_v;
		f[i_key] = dec_v;

	}else if(mode_e[0] == 'l' || mode_e[0] == 'r' || mode_e[0] == 'n'){


	}
}

void check_effect_xy(int m1, char mode_ex[], float percent_efx, char mode_ey[], float percent_efy, float v[], float f[], int m[]){

	/*
	m1 = key for vetor(s) - > speed, force, mode op
	mode_ex = effect x (l = center x from left or r = center y for right);
	percent_efx = percent 0 ~ 100 % effect x (side l or side r)
	mode_ey = effect y (t = center y for top y or b = center y for bottom);
	percent_efy = percent 0 ~ 100 % effect y (top or right)
	v = vetor force + speed
	m = vetor mode op (moviments, x y);
	*/

	float calc_efy, dec_percent_y, final_percent_y;
	float calc_efx, dec_percent_x, final_percent_x;

	//start check effect y x

	//if(percent_efy >= percent_efx){ //percent ef y > perfecnt ef x

		if(mode_ey[0] == 't'){ //y center for top y

			dec_percent_y = (v[m1] / 100) * percent_efy;

			mode_op_change(m1, m, mode_ey); //check change mode op
			add_effect(m1, mode_ey, dec_percent_y, f, v);

			if(mode_ex[0] != 'n'){ //init check dec inc effect x side

				if(mode_ex[0] == 'l'){ //ef x -> left

				}else if(mode_ex[0] == 'r'){ // ef x -> right

				}
			}

		}else if(mode_ey[0] == 'b'){

			dec_percent_y = (v[m1] / 100) * percent_efy;

			mode_op_change(m1, m, mode_ey); //check change mode op
			add_effect(m1, mode_ey, dec_percent_y, f, v);

			if(mode_ex[0] != 'n'){ //init check dec inc effect x side

	 			if(mode_ex[0] == 'l'){ //ef x -> left

	 			}else if(mode_ex[0] == 'r'){ // ef x -> right

	 			}
			}

		}else{


		}

	/*}else{

	}*/

	//end check effect y x

}

void rendEffects(SDL_Renderer *rendE, int e_x[], int e_y[]){

	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture_play = SDL_CreateTextureFromSurface(rendE, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;

	image_branca_rect.w = 40;
	image_branca_rect.h = 40;
	image_branca_rect.x = 750;
	image_branca_rect.y = 465;

	SDL_RenderCopy(rendE, texture_play, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_play);

	SDL_SetRenderDrawColor(rendE, 0, 0, 0, 1);

	int pos_ex, pos_ey;

	SDL_Rect e_rect;

	e_rect.w = 3;
	e_rect.h = 3;
	e_rect.x = e_x[0];
	e_rect.y = e_y[0];

	SDL_RenderDrawRect(rendE, &e_rect);
	SDL_RenderFillRect(rendE, &e_rect);

}

void coord_xy(int m1, int m2, float wh, float hw, float ax[], float ay[]){

	/*
	m1 -> ball
	m2 -> ball target
	wh -> width /height  && height / width
	ax[] -> aux ang vetor x
	ay[] -> aux ang vetor y
	*/
	//start add x y - > angle in px
	if(wh >= 1){

		ax[m1] = 1;
		ay[m1] = hw;

		ax[m2] = 1;
		ay[m2] = hw;

	}else{

		ax[m1] = wh;
		ay[m1] = 1;

		ax[m2] = wh;
		ay[m2] = 1;
	}
	//end add x y -> angle in px
}
void set_dest_xy(int m1, int m2, float px_wh, float px_hw, int m[], float x[], float y[], float ini_x[], float ini_y[], float ax[], float ay[], float v[], float f[], int ex[], int ey[]){

	/*
		find mode X left or X right & Y up or Y down (find 90 degs)
		calc destino (route) x y
	*/

	float center_x1, center_y1, center_x2, center_y2;
	float ef_yu, ef_yd, percent_efy, calc_df_efy, percent_efx, calc_df_efx;
    char mode_ey[1], mode_ex[1];

  //ey -> t = center for top
  //ey -> b = center for end
  //ex -> l = center for left
  //ex -> r = center for right

	center_x1 = x[m1] + 10;
	center_y1 = y[m1] + 10;

	center_x2 = x[m2] + 10;
	center_y2 = y[m2] + 10;

	float check_x, check_y, check_ix, check_iy;

	if(center_x1 <= center_x2 && center_y1 >= center_y2){

		check_x = center_x2 - center_x1;
		check_y = center_y1 - center_y2;

		check_ix = (ini_x[m2] + 10) - (ini_x[m1] + 10);
		check_iy = (ini_y[m1] + 10) - (ini_y[m2] + 10);

	}else if(center_x1 <= center_x2 && center_y1 < center_y2){

		check_x = center_x2 - center_x1;
		check_y = center_y2 - center_y1;

		check_ix = (ini_x[m2] + 10) - (ini_x[m1] + 10);
		check_iy = (ini_y[m2] + 10) - (ini_y[m1] + 10);

	}else if(center_x1 > center_x2 && center_y1 >= center_y2){

		check_x = center_x1 - center_x2;
		check_y = center_y1 - center_y2;

		check_ix = (ini_x[m1] + 10) - (ini_x[m2] + 10);
		check_iy = (ini_y[m1] + 10) - (ini_y[m2] + 10);

	}else if(center_x1 > center_x2 && center_y1 < center_y2){

		check_x = center_x1 - center_x2;
		check_y = center_y2 - center_y1;

		check_ix = (ini_x[m1] + 10) - (ini_x[m2] + 10);
		check_iy = (ini_y[m2] + 10) - (ini_y[m1] + 10);
	}

	float ang_45, ang_x, ang_y, ang_dst, calc_dst, calc_tfs, dec_tfs, rec_percent, percent_fs, calc_ang_f;
	float percent_ang_x, percent_ang_y, calc_angx, calc_angy, calc_tsfx, calc_tsfy;
	float ang_recover, pi, divAL;
	char mode_ang[1], mode_f[1];

	//start get set transf speed for (per 45 degs x or y)

	mode_f[0] = 'f'; //f -> false force < && t -> true force >=

	if(v[m2] > v[m1]){

		mode_f[0] = 't';
	}

	ang_45 = 45 / 20; //45 graus limit max x y / size x y	

	ang_x = check_x * ang_45; //grau de inclinacao x
	ang_y = check_y * ang_45; //grau de inclinacao y

	pi = 3.1415;
	divAL = check_y / check_x;
    ang_recover = atan (divAL) * 180 / pi;
     
    if(m[m1] == 3 || m[m1] == 2){
     	ang_recover = ang_recover - 90;
    }  

	if(ang_recover <= 45 && m[m1] == 0 || m[m1] == 1){

		ang_dst = ang_recover / 45;
		ang_dst = ang_dst * 100;
		dec_tfs = 100 - ang_dst;

		calc_dst = (v[m1] / 100) * ang_dst;
		calc_tfs = (v[m1] / 100) * dec_tfs;
		mode_ang[0] = 'x';

	}else if(ang_recover > 45 && m[m1] == 0 || m[m1] == 1){
		
		ang_recover = ang_recover - 45;

		ang_dst = ang_recover / 45;
		ang_dst = ang_dst * 100;
		dec_tfs = 100 - ang_dst;

		calc_dst = (v[m1] / 100) * ang_dst;
		calc_tfs = (v[m1] / 100) * dec_tfs;
		
		mode_ang[0] = 'y';		
	}

	if(ang_recover <= 45 && m[m1] == 3 || m[m1] == 2){
		
		ang_dst = ang_recover / 45;
		ang_dst = ang_dst * 100;
	
		dec_tfs = 100 - ang_dst;
		
		calc_dst = (v[m1] / 100) * ang_dst;
		calc_tfs = (v[m1] / 100) * dec_tfs;

		mode_ang[0] = 'y';
	
	}else if(ang_recover > 45 && m[m1] == 3 || m[m1] == 2){ 

		ang_recover = ang_recover - 45;

		ang_dst = ang_recover / 45;
		ang_dst = ang_dst * 100;
		dec_tfs = 100 - ang_dst;

		calc_dst = (v[m1] / 100) * ang_dst;
		calc_tfs = (v[m1] / 100) * dec_tfs;

		mode_ang[0] = 'y';
	}

	//start ta em shock em mais de 10 rolex
	if(px >= py){

		ang_dst = px - py;
		dec_tfs = ang_dst * 100;

		if(ang_45 <= 45){
			
			ang_recover = 100 - dec_tfs;
			calc_dst = (v[m1] / 100) * ang_recover; //wh < hw 

			calc_tfs = (v[m1] / 100) * dec_tfs;
			
		}else{

			ang_recover = 100 - dec_tfs;
			calc_dst = (v[m1] / 100) * dec_tfs; //wh > hw 

			calc_tfs = (v[m1] / 100) * ang_recover;
		}

	}else if(px < py){
		
		ang_dst = py - px;
		dec_tfs = ang_dst * 100;

		if(ang_45 >= 45){
	
			ang_recover = 100 - dec_tfs;			
			calc_dst = (v[m1] / 100) * ang_recover; //wh > hw

			calc_tfs = (v[m1] / 100) * dec_tfs;	
		
		}else{

			ang_recover = 100 - dec_tfs;
			calc_dst = (v[m1] / 100) * ang_recover; //wh < hw 

			calc_tfs = (v[m1] / 100) * dec_tfs;
		
		}
	}
	//end ta em schok e mais de 10 rolex

	calc_tsfx = calc_dst; //val de transf sobre angulo eixo x

	if(m[m2] == 100){

		v[m2] = calc_tfs;
		f[m2] = calc_tfs;
		v[m1] = calc_tsfx; //m1 y

	}/*else{

		v[m1] = calc_tsfy; //m1 y
		v[m2] = calc_tsfx; //m2 x
	}*/
	
	//end transf speed for

	//start mode moviment struct

	//start effect check point x, y

	//start check percent y top or bottom
	if(ey[0] < 485){ //center -

    	calc_df_efy = 465 - ey[0]; // min size (465 px) - size px now
    	percent_efy = (calc_df_efy / 20) * 100;
    	mode_ey[0] = 't';

	}else if(ey[0] > 485){ // center +

    	calc_df_efy = 505 - ey[0]; //max size (505 px) - size px now
    	percent_efy = (calc_df_efy / 20) * 100;
    	mode_ey[0] = 'b';

	}else{

		percent_efy = 0;
		mode_ey[0] = 'n';
	}
	//end check percent y top or bottom

	//start check percent x left or right
	if(ex[0] < 770){ //center x -

		calc_df_efx = 785 - ex[0]; //center pos - pos now x
		percent_efx = (calc_df_efx / 20) * 100; //percentual left
		mode_ex[0] = 'l';

	}else if(ex[0] > 770){ // center x +

		calc_df_efx = 805 - ex[0]; //max size pos - pos now x
		percent_efx = (calc_df_efx / 20) * 100; // percentual right
		mode_ex[0] = 'r';

	}else{

		percent_efx = 0;
		mode_ex[0] = 'n';
	}
	//end check percent x left or right

	//end effect check point x, y
	if(m[m1] == 0){ //-y +x

		if(m[m2] > 3){ //null (moviment 0)

			if(center_x1 <= center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ey[0] == 'n' && mode_ex[0] == 'n'){

					if(check_ix >= check_iy){ //init (dst) pos x > init (dst) pos y

						m[m1] = 0; // +y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 2; //-y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 0; // -y +x

			}else if(center_x1 <= center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 0; //-y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 2; //-y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 3; // -y +x

			}else if(center_x1 > center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 3; // +x +y
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 3; // -y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 2; // -y -x
			}

		}else{

			if(mode_f[0] == 'f'){

			}else{

			}
		}

	}else if(m[m1] == 1){ //+y -x

		if(m[m2] > 3){ //null (moviment 0)

			if(center_x1 >= center_x2 && center_y1 <= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 2; //-y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 3; //+y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 1; // +y -x

			}else if(center_x1 >= center_x2 && center_y1 > center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 1; // +y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 3; // +y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 2; //-y -x

			}else if(center_x1 < center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 2; //-y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 2; //+y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 3; //+y +x

			}

		}else{

			if(mode_f[0] == 'f'){

			}else{

			}

		}

	}else if(m[m1] == 2){ // -y -x

		if(m[m2] > 3){ //null (moviment 0)

			if(center_x1 >= center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 1;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 0;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 2;

			}else if(center_x1 >= center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 2;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 0;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}

				m[m2] = 1;

			}else if(center_x1 < center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 1;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 2;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 0;

			}

		}else{

			if(mode_f[0] == 'f'){

			}else{

			}
		}

	}else if(m[m1] == 3){ // +y +x

		if(m[m2] > 3){ //null (moviment 0)

			if(center_x1 <= center_x2 && center_y1 <= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 0; // -y +x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 1; // +y -x
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}

				m[m2] = 3;

			}else if(center_x1 <= center_x2 && center_y1 > center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					if(check_ix >= check_iy){

						m[m1] = 3;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];

					}else{

						m[m1] = 1;
						ini_x[m1] = x[m1];
						ini_y[m1] = y[m1];
					}

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 0;

			}else if(center_x1 > center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(mode_ex[0] == 'n' && mode_ey[0] == 'n'){

					m[m1] = 3;
					m[m2] = 1;

				}else{

					check_effect_xy(m1, mode_ex, percent_efx, mode_ey, percent_efy, v, f, m);
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}
			}

		}else{

			if(mode_f[0] == 'f'){

			}else{

			}
		}
	}
	//end mode moviment struct

}
