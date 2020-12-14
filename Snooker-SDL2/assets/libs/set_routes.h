
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
void set_dest_xy(float prox, float limit_prox, int m1, int m2, float px_wh, float px_hw, int m[], float x[], float y[], float ini_x[], float ini_y[], float ax[], float ay[], float v[], float f[]){

	/* 
		find mode X left or X right & Y up or Y down (find 90 degs)
		calc destino (route) x y 
	*/

	float center_x1, center_y1, center_x2, center_y2;

	center_x1 = x[m1] + 10;
	center_y1 = y[m1] + 10;

	center_x2 = x[m2] + 10;
	center_y2 = y[m2] + 10;

	float check_x, check_y, check_ix, check_iy;

	if(center_x1 <= center_x2 && center_y1 >= center_y2){

		check_x = center_x2 - center_x1;
		check_y = center_y1 - center_y2;

		check_ix = ini_x[m2] - ini_x[m1];
		check_iy = ini_y[m1] - ini_y[m2];

	}else if(center_x1 <= center_x2 && center_y1 < center_y2){

		check_x = center_x2 - center_x1;
		check_y = center_y2 - center_y1;

		check_ix = ini_x[m2] - ini_x[m1];
		check_iy = ini_y[m2] - ini_y[m1];

	}else if(center_x1 > center_x2 && center_y1 >= center_y2){

		check_x = center_x1 - center_x2;
		check_y = center_y1 - center_y2;

		check_ix = ini_x[m1] - ini_x[m2];
		check_iy = ini_y[m1] - ini_y[m2];

	}else if(center_x1 > center_x2 && center_y1 < center_y2){

		check_x = center_x1 - center_x2;
		check_y = center_y2 - center_y1;
	
		check_ix = ini_x[m1] - ini_x[m2];
		check_iy = ini_y[m2] - ini_y[m1];
	}

	float ang_45, ang_x, ang_y, calc_dst, calc_fs, rec_percent, percent_fs, calc_ang_f;
	float percent_ang_x, percent_ang_y, calc_angx, calc_angy, calc_tsfx, calc_tsfy;
	char mode_ang[1], mode_f[1];

	//start get set transf speed for (per 45 degs x or y)

	mode_f[0] = 'f'; //f -> false force < && t -> true force >=

	if(v[m2] > v[m1]){

		mode_f[0] = 't';
	}

	ang_45 = 45 / 20; //45 graus limit max x y / size x y

	ang_x = check_x * ang_45; //grau de inclinacao x
	ang_y = check_y * ang_45; //grau de inclinacao y 

	if(ang_x >= ang_y){

		percent_ang_x = (ang_x / 45) * 100; // transf m1
 		percent_ang_y = (ang_y / 45) * 100;
		mode_ang[0] = 'x';

	}else{

		percent_ang_x = (ang_x / 45) * 100; // transf m1
		percent_ang_y = (ang_y / 45) * 100;
		mode_ang[0] = 'y';
	}

	calc_tsfx = (v[m1] / 100) * percent_ang_x; //val de transf sobre angulo eixo x
	calc_tsfy = (v[m1] / 100) * percent_ang_y; //val transf sobre angulo eixo y

	if(mode_ang[0] == 'x'){

		if(m[m2] == 100){

			v[m2] = v[m1] - (0.1 * v[m1]); //vspeed f - ( massa * speed f) 
			f[m2] = v[m1] - (0.1 * v[m1]); //vspeed f - ( massa * speed f) 
			v[m1] = calc_tsfx; //m1 x
		}/*else{

			v[m1] = calc_tsfy; //m1 x
			v[m2] = calc_tsfx; //m2 y
		}*/

	}else if(mode_ang[0] == 'y'){

		if(m[m2] == 100){

			v[m2] = v[m1] - (0.1 * v[m1]);
			f[m2] = v[m1] - (0.1 * v[m1]);
			v[m1] = calc_tsfy; //m1 y
			
		}/*else{

			v[m1] = calc_tsfy; //m1 y
			v[m2] = calc_tsfx; //m2 x
		}*/
	}
	//end transf speed for

	//start mode moviment struct 

	if(m[m1] == 0){ //-y +x

		if(m[m2] > 3){ //null (moviment 0)

			if(center_x1 <= center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){ //init (dst) pos x > init (dst) pos y

					m[m1] = 3; // +y +x 					
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{
					
					m[m1] = 2; //-y -x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}	
				
				m[m2] = 0; // -y +x

			}else if(center_x1 <= center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){
					
					m[m1] = 0; //-y +x 
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{

					m[m1] = 2; //-y -x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 3; // -y +x

			}else if(center_x1 > center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){
				
					m[m1] = 3; // +x +y 
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{
				
					m[m1] = 0; // -y +x
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
				
				if(check_ix >= check_iy){
					
					m[m1] = 2; //-y -x
					ini_x[m1] = x[m1];
					ini_y[m2] = y[m1];
				
				}else{

					m[m1] = 3; //+y +x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}
				
				m[m2] = 1; // +y -x

			}else if(center_x1 >= center_x2 && center_y1 > center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);

				if(check_ix >= check_iy){
					
					m[m1] = 1; // +y -x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{

					m[m1] = 3; // +y +x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 2; //-y -x

			}else if(center_x1 < center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
			
				if(check_ix >= check_iy){
				
					m[m1] = 2; //-y -x 
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				
				}else{

					m[m1] = 1; //+y -x
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
				
				if(check_ix >= check_iy){

					m[m1] = 1;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				
				}else{

					m[m1] = 0;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 2;

			}else if(center_x1 >= center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){

					m[m1] = 2;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				
				}else{
				
					m[m1] = 0;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}
				
				m[m2] = 1;

			}else if(center_x1 < center_x2 && center_y1 >= center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){
					
					m[m1] = 1;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{

					m[m1] = 2;
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
				
				if(check_ix >= check_iy){
					
					m[m1] = 0; // -y +x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				
				}else{

					m[m1] = 1; // +y -x
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 3;

			}else if(center_x1 <= center_x2 && center_y1 > center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				
				if(check_ix >= check_iy){
				
					m[m1] = 3;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];

				}else{

					m[m1] = 1;
					ini_x[m1] = x[m1];
					ini_y[m1] = y[m1];
				}

				m[m2] = 0;

			}else if(center_x1 > center_x2 && center_y1 < center_y2){

				coord_xy(m1, m2, px_wh, px_hw, ax, ay);
				m[m1] = 3;
				m[m2] = 1;
			}

		}else{

			if(mode_f[0] == 'f'){

			}else{

			}
		}
	}
	//end mode moviment struct

}