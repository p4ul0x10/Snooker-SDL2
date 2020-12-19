void rendTaco(SDL_Renderer *rendT, float vetX[], float vetY[], float deg, float deg_mode, float df_x, float df_y){

    float x, y;

    x = vetX[15];
    y = vetY[15];
    
    SDL_Surface *image_taco = IMG_Load("assets/images/taco.png");

    SDL_Texture *texture_taco = SDL_CreateTextureFromSurface(rendT, image_taco);
	SDL_FreeSurface(image_taco);

    int cont_px = 0, px = 0;
    float incPx, divAL, divLA, deg_limit, total_deg, div_angulo, bx, by;
    bool stop_px = false, run = true;

	divLA = df_x / df_y; //largura / altura
	divAL = df_y / df_x; //altura / largura

    bx = x + 10;
    by = y + 10;

    SDL_SetRenderDrawColor(rendT, 0, 0, 0, 1);

    //start init calc limit deg
	while (px < 26){

         if(divLA >= 1){ //div largura / altura >= 1 by -> divAL && bx +=1
           
            //start Sets by bx adds
            if(deg_mode == -90 || deg_mode == 180){
                
                by -= divAL;
            
            }else if(deg_mode == 90 || deg_mode == 0){
            
                by += divAL;
            }


            if(deg_mode == 90 || deg_mode == 180){
            
                bx -= 1;
            
            }else if(deg_mode == -90 || deg_mode == 0){
            
                bx += 1;
            }
           
            //end sets px > 1
            //end if px addeds > 1

        }else { //div largura / altura < 1 by -> +=1 && bx divLA

            //start sets by bx divla < 1
            if(deg_mode == -90 || deg_mode == 180){
            
                by -= 1;
            
            }else if(deg_mode == 90 || deg_mode == 0){
            
                by += 1;
            
            }

            if(deg_mode == 90 || deg_mode == 180){
            
                bx -= divLA;
            
            }else if(deg_mode == -90 || deg_mode == 0){
            
                bx += divLA;
            
            }

            //end sets by bc divla < 1
        }

        SDL_Rect pxxx_rect;
		pxxx_rect.w = 1;
		pxxx_rect.h = 1;
		pxxx_rect.x = bx;
		pxxx_rect.y = by;

        SDL_RenderDrawRect(rendT, &pxxx_rect);
        SDL_RenderFillRect(rendT, &pxxx_rect);
		px += 1;

	}
    //end calc limit deg <= 90 graus por mode deg

    if(deg_mode == -90){

        //start div taco / 2 && bola / 2 -> meio
        x = x - 400 / 2; //taco / 2
        x = x + 17 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2

        float ang_t, ang, pi, px_recover_center, px_y_inc, px_y_add, px_x_inc, px_x_add, px_x_central, ang_recover;
        pi = 3.141592; //pi
        ang_t = atan (divAL) * 180 / pi; //total de graus

        if(ang_t <= 45){ //first 45 initial degress

            if(ang_t <= 22.5){ // < 22.5 deg(s)

                 //start y recover center
                 px_recover_center = 76 / 22.5; //3.3333 porcentagem relativa aos primeiros 22.5 graus
                 px_y_add = px_recover_center * ang_t;
                 y = y + px_y_add;
                 //end y recover center

                 //start x recover center
                 px_x_central = 14 / 22.5; //porcentagem relativa aos primeiros 22.5 graus
                 px_x_add = px_x_central * ang_t; //porcentagem relativa * total de angulo de enclinacao
                 x = x + px_x_add;

                 //start add degress 22.5
                 ang = 90+ang_t;
                 deg = -ang;
                 //end add degress 22.5

            }else if(ang_t > 22.5){ //> 22.5 deg(s)

                //start y recover center
                px_recover_center = 63.5 / 22.5; //2.7555;
                px_y_add = px_recover_center * ang_t; //porcentagem relativa * total do angulo de enclinacao
                y = y + 15.5; //recover y 22.5 deg(s) init
                y = y + px_y_add; //add y pos
                //end y recover center

                //start x recover center
                x = x + 15; //recover x relativo 22.5 deg(s) init
                px_x_central = 90 / 45; //porcentagem de px relativo / quantidade de graus
                px_x_inc = ang_t - 22.5; //recover 22.5 degs
                px_x_add = px_x_central * px_x_inc;
                x = x + px_x_add; //recover x relativo 22.5 deg(s) > 22.5 && < 45
                //end x recover center

                //start add degress 45
                ang = 90+ang_t;
                deg = -ang;
                //end add degress 45
            }

             //start border rotation pos x y

            total_deg = ang_t / 4.5; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            //start border rotation y pos - > 45 deg(s) initials
            if(total_deg <= 4){

                x = x - 13;
                y = y + total_deg;
                 
             }else if(total_deg > 4 && total_deg <= 6){

                x = x - 10;
                y = y + total_deg;
        
             }else if(total_deg > 6 && total_deg < 8){

                x = x - 11;
                y = y + total_deg;
                
             }else if(total_deg > 7 && total_deg < 9){

                x = x - 10;
                y = y + total_deg;
                
             }else if(total_deg > 8 && total_deg < 10){

                x = x - 9;
                y = y + total_deg;
                
             }else if(total_deg > 9 && total_deg < 11){

                x = x - 8;
                y = y + total_deg;
                
             }
             //end border rotation y pos

             //end border rotation pos x y
            
        }else if(ang_t > 45){ //graus > 45 ate 90

            if(ang_t <= 67.5){ // graus < 65 || graus < 22.5 relativo

                //start y recover center
                //180 total y
                px_recover_center = 39 / 22.5; //quantidade de px / quantidade de graus
                px_x_inc = ang_t - 45; //recupera quantidade de graus (atual) relativo para 22.5
                px_y_add = px_recover_center * px_x_inc; //quantidade de px * quantidade de graus atual (relativo 22.5)
                //y = y + px_y_add;
                y = y + 144; //recover y first 45 graus
                y = y + px_y_add;

                //start y ajust center 1
                float px_yy, px_yy_inc;
                px_yy = 4 / 22.5;
                px_yy_inc = px_yy * px_x_inc;
                y = y + px_yy_inc;
                //end y ajust center 1
                if(ang_t >= 50 && ang_t < 60){
                    y = y + 1;
                }
                //end y recover center

                //start x recover center
                //112 total x
                x = x + 58; //recover x first 45 graus
                px_x_central = 65 / 22.5; //quantidade de px / quantidade de graus(relativo 22.5)
                px_x_inc = ang_t - 45; //recuperacao de 22.5 relativo a quantidade de graus atual (atual deg - 45)
                px_x_add = px_x_central * px_x_inc; //quantidade de px adds * quantidade de graus atual relativo aos (22.5) adicionais aos 45 finais
                x = x + px_x_add;
                //end x recover center

                //start add degress > 45 && < 65
                ang = 90+ang_t;
                deg = -ang;
                //end add degress > 45 && < 65

            }else if(ang_t > 67.5){ // graus > 65 || graus > 22.5 relativo

                //start y recover center 197 total y
                y = y + 186; //recover y 65 graus initials
                px_recover_center = 15 / 22.5; //quantidade de px / quantidade relativa de graus (22.5)
                px_y_inc = ang_t - 68; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_y_add = px_recover_center * px_y_inc; //quantidade de px * quantidade de graus atual
                y = y + px_y_add; //adiciona y pos
                //end y recover center
                if(ang_t >= 72){
                    y = y + 1.5;
                }
                //start x recover center 200 px total
                x = x + 116.8; //recover x 65 graus initials
                px_x_central = 74 / 22.5; //quantidade de px / graus relativo 22.5
                px_x_inc = ang_t - 65; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_x_add = px_x_central * px_x_inc; //quantidade de px * quantidade atual de graus
                x = x + px_x_add; //adiciona x pos
                //end x recover center

                //start add degress > 65 && <= 90
                ang = 90+ang_t;
                deg = -ang;
                //end add degresss > 65 && <= 90

            }

            //start border rotation pos x y
            float ang_recover_add;
            ang_recover = ang_t - 45; //recupera quantidade de graus para 45 deg(s) max relativo
            total_deg = ang_recover / 8; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            ang_recover_add = 8 - total_deg; //recupera quantidade de graus decrescente relativo maximo ajuste 7 px
           
            //start border rotation x pos -> 45 deg(s) end close 90 deg(s)
            if(total_deg <= 1){

                x = x - ang_recover_add;
                y = y + 9;
             
             }else if(total_deg > 1 && total_deg < 4){

                x = x - ang_recover_add;
                x = x + 1;
                y = y + 11;
             
             }else if(total_deg > 3){

                x = x - ang_recover_add;
                x = x + 3;
                y = y + 11;
              
             }
             //end border rotation pos x y
        }

    }else if(deg_mode == 180){

        x = x + 17 / 2; //bola / 2
        y = y + 20 / 2; //bola / 2
        

        float ang_t, ang, pi, ang_recover, px_recover_center, px_y_inc, px_y_add;
        float incx, addx, recx, px_x_inc, px_x_add, px_x_central;

        pi = 3.1415;
        ang_t = atan (divAL) * 180 / pi;

        ang = 90 + ang_t; 
        ang_recover = 180 - ang; //recupera angulo relativo a 90 graus
        
        if(ang_recover <= 45){

            if(ang_recover <= 7.5){ //45 <= deg (90 ~ 180)

                px_recover_center = 3.5555 * ang_recover;
                x = x + px_recover_center + 0.12 * ang_recover;
                
                y = y - 0.1 * ang_recover; 
                deg = ang;

            }else if(ang_recover > 7.5 && ang_recover <= 15){

                recx = ang_recover - 7.5;

                x = x + 26.6666;
                px_recover_center = 3.4 * recx;
                x = x + px_recover_center;

                y = y - 1;
                px_y_add = 0.55 * recx;
                y = y - px_y_add;

                deg = ang;
            
            }else if(ang_recover > 15 && ang_recover <= 22.5){

                recx = ang_recover - 15;
                
                x = x + 26.6666 * 2;
                px_recover_center = 2.9 * recx;
                x = x + px_recover_center;

                y = y - 6.7;
                px_y_add = 0.85 * recx;
                y = y - px_y_add;
                deg = ang;

            }else if(ang_recover > 22.5 && ang_recover <= 30){

                recx = ang_recover - 22.5;
                
                x = x + 26.35 * 2.9;
                px_recover_center = 3.1 * recx;
                x = x + px_recover_center;

                y = y - 14.7;
                px_y_add = 1.40 * recx;
                y = y - px_y_add;
                deg = ang;
            
            }else if(ang_recover > 30 && ang_recover <= 37.5){

                recx = ang_recover - 30;
                
                x = x + 25 * 4;
                px_recover_center = 2.9 * recx;
                x = x + px_recover_center;

                y = y - 25;
                px_y_add = 2.0 * recx;
                y = y - px_y_add;
                deg = ang;
            
            }else if(ang_recover > 37.5 && ang_recover <= 45){

                recx = ang_recover - 37.5;
                
                x = x + 24.4 * 5;
                px_recover_center = 2.6 * recx;
                x = x + px_recover_center;

                y = y - 39;
                px_y_add = 2.5 * recx;
                y = y - px_y_add;
                deg = ang;
            }
          
            //start border rotate
            float rot_x, calc_rot_y;

            y = y + 10;//top limit borber 
         
            rot_x = 0.177 * ang_recover; //8 px / 45 -> 0.177 * ang recover 
            
            calc_rot_y = 0.066 * ang_recover; // 3 px / 45 -> 0.066 * ang recover 
            
            if(rot_x <= 8){

                x = x + rot_x; // recover x pos
                y = y - calc_rot_y; // recover y pos
            }
            //end border rotate x y
        
        }else if(ang_recover > 45){

           if(ang_recover > 45 && ang_recover <= 52.5){

                recx = ang_recover - 45;

                x = x + 23.65 * 6;
                px_recover_center = 2.3 * recx;
                x = x + px_recover_center;

                y = y - 58.4;
                px_y_add = 2.5 * recx;
                y = y - px_y_add;

                deg = ang;

            }else if(ang_recover > 52.5 && ang_recover <= 60){

                recx = ang_recover - 52.5;

                x = x + 22.7 * 7;
                px_recover_center = 1.8 * recx;
                x = x + px_recover_center;

                y = y - 78.2;
                px_y_add = 2.7 * recx;
                y = y - px_y_add;

                deg = ang;
            
            }else if(ang_recover > 60 && ang_recover <= 67.5){

                recx = ang_recover - 60;

                x = x + 172.4;
                px_recover_center = 1.5 * recx;
                x = x + px_recover_center;

                y = y - 99.75;
                px_y_add = 2.9 * recx;
                y = y - px_y_add;

                deg = ang;
            
            }else if(ang_recover > 67.5 & ang_recover <= 75){

                recx = ang_recover - 67.5;

                x = x + 184;
                px_recover_center = 1.3 * recx;
                x = x + px_recover_center;
            
                y = y - 122;
                px_y_add = 3.4 * recx;
                y = y - px_y_add;
            
                deg = ang;
            
            }else if(ang_recover > 75 && ang_recover <= 82.5){
        
                recx = ang_recover - 75;
            
                x = x + 192;
                px_recover_center = 0.6 * recx;
                x = x + px_recover_center;

                y = y - 147;
                px_y_add = 3.6 * recx;
                y = y - px_y_add;

                deg = ang;

            }else if(ang_recover > 82.5 && ang_recover <= 90){

                recx = ang_recover - 82.5;

                x = x + 196.5;
                px_recover_center = 0.45 * recx;
                x = x + px_recover_center;
                
                y = y - 174;
                px_y_add = 3.3 * recx;
                y = y - px_y_add;

                deg = ang;
            }

            //start border rotate x y 
            float rot_x, calc_rot_y, rec_rot;

            y = y + 8; //top limit borber 45+ y
            x = x + 8; //top limit border 45+ x

            rec_rot = ang_recover - 45; //recover 45 deg (max)

            rot_x = 0.066 * rec_rot; //3 px / 45 -> 0.177 * ang recover 
            
            calc_rot_y = 0.177 * rec_rot; // 8 px / 45 -> 0.066 * ang recover 
            
            if(calc_rot_y <= 8){ //limit rotate (relativo y)

                x = x + rot_x; // recover x pos (rotate)
                y = y - calc_rot_y; // recover y pos (rotate)
            }
            //end border rotate x y
        
        }

    }else if(deg_mode == 90){ 
 
        x = x + 400 / 2; //taco / 2
        x = x + 20 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2
        
        float ang_t, ang, pi, px_recover_center, px_y_inc, px_y_add;
        float px_x_inc, px_x_add, px_x_central, ang_recover;
        
        pi = 3.1415;
        ang_t = atan (divAL) * 180 / pi;

       if(ang_t < 45){


            //x = x - (0.46 * ang_t);
            //y = y - (2.22 * ang_t);
            
            if(ang_t <= 22.5){

                //x = x - 16;
                x = x - (0.6072 * ang_t);
                y = y - (3.45 * ang_t);
                //y = y - 77;

            }else{

                x = x - (0.6072 * 22.5);
                y = y - (3.45 * 22.5);
                
                float rec_45;
                rec_45 = ang_t - 22.5;

                y = y - (2.8 * rec_45); //y = y - 63;
                x = x - (2.0 * rec_45); //x = x - 47;
            }

            //start rotate
            float rot_x, rot_y, rec_rot;

            //y = y - 8;
            x = x + 10;

            rec_rot = 90 - ang_t;

            rot_x = 0.066 * ang_t;
            rot_y = 0.177 * ang_t;

            if(rot_x <= 8){

                x = x - rot_x;
                y = y - rot_y;
            }
            
            //end rotate 
            
            deg = 90-ang_t;
        
        }else if(ang_t > 45){

            float rec_ang_90, rec_45, rec_0;

            //y = y - 140;
            //x = x - 60;

            rec_45 = ang_t - 45;
            
            if(rec_45 <= 22.5){

                y = y - 142.5;
                x = x - 58;

                y = y - 1.45 * rec_45;
                x = x - 3.2 * rec_45;
            
                //rec 22.5
                y = y - (0.53 * rec_45);
                x = x + (0.29 * rec_45);
                //rec 22.5

                deg = 90 - ang_t;

            }else{

                y = y - 142.5;
                x = x - 59;

                rec_0 = rec_45 - 22.5;

                y = y - 1.37 * 22.5;
                x = x - 2.9 * 22.5;

                y = y - 0.65 * 22.5;

                y = y - (0.65 * rec_0);
                x = x - (3.4 * rec_0);

                deg = 90 - ang_t;
            }


            //start rotate
            x = x + 8;
            y = y - 8;
            
            float rot_x, rot_y, rec_rot;

            rot_x = 0.17 * rec_45;
            rot_y = 0.066 * rec_45;

            if(rot_x <= 8){

                x = x - rot_x;
                y = y - rot_y;
            }

            //deg = 90 - ang_t;
            //end rotate
        }

    }else if(deg_mode == 0){

        x = x + 17 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y - 200; //taco / 2
        y = y + 20 / 2; //bola / 2

        float ang_t, ang, pi, ang_recover ,px_recover_center, px_y_inc, px_y_add;
        float px_x_inc, px_x_add, px_x_central;
       
        pi = 3.1415; //pi
        
        ang_t = atan (divAL) * 180 / pi; //quantidade de graus atual sem conversao
        ang = 90-ang_t; //recupera quantidade de graus para octeto atual

        if(ang <= 45){

            if(ang <= 22.5){

                //y = y + 16;
                //x = x - 78;
                float recpx, rpx;

                recpx = 22.5 - ang;
         
                y = y + 0.671 * ang;
                if(ang < 20){
                y = y - 0.145 * ang;
                }
                x = x - 3.46 * ang;
                deg = -ang;
                
            }else{

                y = y + (0.70 * 22.5);
                x = x - (3.48 * 22.5);
                
                float rec_45, rec_0;

                rec_45 = ang - 22.5;
                rec_0 = 45 - ang;
                //y = y + 44;
                //x = x - 64;
                y = y + (1.965 * rec_45);
                if(ang <= 41){
                y = y - (0.139 * rec_45);
                }
                x = x - (2.84 * rec_45);
                deg = -ang;
            }
        
            //
            float rot_x, rot_y;

            y = y - 12;

            rot_x =0.177 * ang;
            rot_y = 0.06 * ang;
        
            if(rot_x <= 8){

                x = x - rot_x;
                if(rot_x >=7.5){
                y = y + rot_y;
                }
            }
            //
        }else if(ang > 45){
        
            if(ang <= 67.5){

                y = y + 57;
                x = x - 142.5;

                float rec_45;
                rec_45 = ang - 45;

                y = y + 2.7 * rec_45; //y = y + 60;
                x = x - 1.9 * rec_45; //40
                deg = -ang;
           
            }else{

                y = y + 122;
                x = x - 185.75;

                float rec_45;
                rec_45 = ang - 67.5;

                y = y + (3.51 * rec_45);
                x = x - (1 * rec_45);
                // y = y + 2.76 * rec_45; //y = y + 60;
                // x = x - 1.9 * rec_45; //40
                deg = -ang;
            }

            
            float rot_x, rot_y, rec_rot;

            rec_rot = ang - 45;
            
            y = y - 7;
            x = x - 8;

            rot_x = 0.066 * rec_rot;
            rot_y = 0.155 * rec_rot;

            if(rot_y <= 7){

                y = y + rot_y;
                x = x - rot_x;
                
            }
            if(rec_rot > 40){
                x = x + 4;
            }
        }

    }
    //end div taco / 2 && bola / 20 -> meio


    SDL_Rect image_taco_rect;
	image_taco_rect.w = 6;
	image_taco_rect.h = 400;
	image_taco_rect.x = x;
	image_taco_rect.y = y;
	SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(rendT, texture_taco, NULL, &image_taco_rect, deg, NULL, flip);
    SDL_DestroyTexture(texture_taco);
}
