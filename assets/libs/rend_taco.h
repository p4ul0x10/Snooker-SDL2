void rendTaco(SDL_Renderer *rendT, float vetX[], float vetY[], float deg, float deg_mode, float df_x, float df_y, float c_px[], float c_py[]){

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
    while (px < 826){

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

        SDL_RenderFillRect(rendT, &pxxx_rect);
        px += 1;

    }
    //end calc limit deg <= 90 graus por mode deg
    float rsen, rcos, ang_t, ang, pi;
    float px_recover_center, px_y_inc, px_y_add, px_x_inc, px_x_add;
    float circle_ang, px_x_central, rot_x, rot_y;

   
    if(deg_mode == -90){
        
        x = x - 400 / 2; //taco / 2
        x = x + 17 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2

        pi = 3.141592; //pi
        
        ang_t = atan (divAL) * 180 / pi; //total de graus

        circle_ang = 0.1;
        rot_x = circle_ang * ang_t;
        rcos = cos (rot_x);
        rsen = sin (rot_x);

        ang = 90 + ang_t;
        
        px_x_add = 200 / 90;
        px_y_add = 190 / 90;

       if(ang_t <= 90){ 
            
            float max_rec, rec_ang, p_x1, p_x2, p_y;
            
            if(ang_t <= 20){ 

                x = x - 13;
                x = x + divAL * ang_t; //200;
                x = x + 0.36 * ang_t;

                y = y + 3.7 * ang_t; //190;
                
                deg = -ang;
            
            }else if(ang_t > 20 && ang_t <= 30){

                x = x + 2;
                y = y + 74;

                rec_ang = ang_t - 20;

                y = y + 3.1 * rec_ang;
                x = x + 1.4 * rec_ang;
               
                deg = -ang;

            }else if(ang_t > 30 && ang_t <= 40){

                x = x + 16;
                y = y + 105;

                rec_ang = ang_t - 30;

                y = y + 3.3 * rec_ang;
                x = x + 2.35 * rec_ang;

                deg = -ang;
            
            }else if(ang_t > 40 && ang_t <= 45){

                x = x + 39.5;
                y = y + 138;

                rec_ang = ang_t - 40;

                y = y + 2.6 * rec_ang;
                x = x + 2.5 * rec_ang;

                deg = -ang;

            }else if(ang_t > 45 && ang_t <= 55){

                x = x + 52;
                y = y + 151;

                rec_ang = ang_t - 45;

                y = y + 2.3 * rec_ang;
                x = x + 2.7 * rec_ang;

                deg = -ang;

            }else if(ang_t > 55 && ang_t <= 65){

                x = x + 79;
                y = y + 174;

                rec_ang = ang_t - 55;

                y = y + 1.8 * rec_ang;
                x = x + 3.2 * rec_ang;

                deg = -ang;

            }else if(ang_t > 65 && ang_t <= 75){

                x = x + 111;
                y = y + 192;

                rec_ang = ang_t - 65;

                y = y + 1.3 * rec_ang;
                x = x + 3.4 * rec_ang;

                deg = -ang;

            }else if(ang_t > 75 && ang_t <= 85){

                x = x + 145;
                y = y + 205;

                rec_ang = ang_t - 75;

                y = y + 0.6 * rec_ang;
                x = x + 3.7 * rec_ang;

                deg = -ang;

            }else if(ang_t > 85){

                x = x + 182;
                y = y + 210;

                rec_ang = ang_t - 85;

                x = x + 3.5 * rec_ang;

                deg = -ang;

            }/*else if(ang_t > 40 && ang_t <= 45){

                y = y + 138.5;
                x = x + 39;

                rec_ang = ang_t - 40;
                
                y = y + (13.5 / 5) * rec_ang;
                x = x + (15 / 5) * rec_ang;
                deg = -ang;
           
            }else if(ang_t > 45 && ang_t <= 65){

                y = y + 138.5;
                x = x + 39;
                
                y = y + 14.8;
                x = x + 13;

                rec_ang = ang_t - 45;

                y = y + (41 / 20) * rec_ang;
                x = x + (60 / 20) * rec_ang;
                deg = -ang;
            
            }else if(ang_t > 65 && ang_t <= 85){

                y = y + 194.3;
                x = x + 113;

                rec_ang = ang_t - 65;

                x = x + (77 / 20) * rec_ang;
                y = y + (16.7 / 20) * rec_ang;
                x = x + 0.45 * rec_ang;
                deg = -ang;

            }else if(ang_t > 85){

                y = y + 211;
                x = x + 183;

                rec_ang = ang_t - 85;

                x = x + 3.5 * rec_ang;
                deg = -ang; 
            }*/
            
        }       

    }else if(deg_mode == 180){

        x = x + 1 / 2; //bola / 2
        x = x + 8;
        y = y + 22;
        float rcos, rsen, ang_t, ang, pi, ang_recover, px_recover_center;
        float rec_ang, max_rec, incx, addx, recx, px_x_inc, px_x_add, px_x_central;

        pi = 3.1415;
        ang_recover = atan (divAL) * 180 / pi;
       
        ang = 90 + ang_recover; 
        ang_t = 90 - ang_recover; //recupera angulo relativo a 90 graus
        
        rcos = cos (ang_recover * pi / 180);
        rsen = sin (ang_recover * pi / 180);
        
        if(ang_t <= 20){ 

            x = x + 3.6 * ang_t;
            y = y - divLA*2 * ang_t; //190;
            
            deg = ang;

        }else if(ang_t > 20 && ang_t <= 40){

            x = x + 73;
            y = y - 8;            
            y = y - divLA * ang_t; //190;
            
            rec_ang = ang_t - 20;
            x = x + 3.1*rec_ang;
            y = y - 0.4*rec_ang;

            deg = ang;

        }else if(ang_t > 40 && ang_t <= 45){

            x = x + 135;
            y = y - 16;            
            y = y - divLA * ang_t;
            
            rec_ang = ang_t - 40;
            x = x + 2.8 * rec_ang;
            y = y - 0.3 * rec_ang;
            
            deg = ang;

        }else if(ang_t > 45 && ang_t <= 55){

            x = x + 149;
            y = y - 17.5;
            y = y - 46;

            rec_ang = ang_t - 45;

            x = x + 2.3 * rec_ang;
            y = y - divLA *2* rec_ang;
            deg = ang;

        }else if(ang_t > 55 && ang_t <= 65){

            x = x + 172;
            y = y - 17.5;
            y = y - 72;

            rec_ang = ang_t - 55;
            x = x + 2 * rec_ang;
            y = y - 1.2 * rec_ang;
            y = y - divLA * rec_ang;
            deg = ang;

        }else if(ang_t > 65 && ang_t <= 75){

            y = y - 122.5;
            x = x + 191;

            rec_ang = ang_t - 65;
            x = x + 1.2 * rec_ang;
            y = y - 3.4 * rec_ang;

            deg = ang; 
        
        }else if(ang_t > 75 && ang_t <= 85){

            y = y - 156.5;
            x = x + 204;

            rec_ang = ang_t - 75;
            x = x + 0.5 * rec_ang;
            y = y - 3.5 * rec_ang;

            deg = ang;

        }else if(ang_t > 85){

            y = y - 191.5;
            x = x + 209;
            
            rec_ang = ang_t - 85;

            y = y - 3.6 * rec_ang;
            deg = ang;
        }
            

    }else if(deg_mode == 90){ 
 
        x = x + 400 / 2; //taco / 2
        x = x + 17 / 2; //bola / 2 
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2
        
        float ang_t, ang, pi, px_recover_center, px_y_inc, px_y_add;
        float max_rec, rec_ang, px_x_inc, px_x_add, px_x_central, ang_recover;
        
        pi = 3.1415;
        ang_t = atan (divAL) * 180 / pi;
        rcos = cos (ang_t * pi / 180);
        rsen = sin (ang_t * pi / 180);
        
        if(ang_t <= 35){

            max_rec = 45 - ang_t; 

            px_y_inc = 3 / 45;
            px_y_add = 140 / 45;
        
            y = y - 3.11 * ang_t;
            y = y - 0.299 * ang_t;
            y = y - (rsen / 7) * ang_t;
           
            x = x - divAL * ang_t; //58
            x = x + 11;
            x = x - 0.22 * ang_t;

            x = x - (rsen / 3) * ang_t;
            
            deg = 90 - ang_t;
        
        }else if(ang_t > 35 && ang_t <= 45){

            y = y - 120;
            x = x - 27;
            rec_ang = ang_t - 35;

            y = y - 2.7 * rec_ang;
            x = x - 2.3 * rec_ang;

            deg = 90 - ang_t;

        }else if(ang_t > 45 && ang_t <= 55){

            y = y - 149;
            x = x - 50;

            rec_ang = ang_t - 45;

            y = y - 2.43 * rec_ang;
            x = x - 3 * rec_ang;

            deg = 90 - ang_t;

        }else if(ang_t > 55 && ang_t <= 65){

            y = y - 173.3;
            x = x - 80;

            rec_ang = ang_t - 55;

            y = y - 1.85 * rec_ang;
            x = x - 3.2 * rec_ang;

            deg = 90 - ang_t;
        
        }else if(ang_t > 65 && ang_t <= 75){

            y = y - 191.8;
            x = x - 112;

            rec_ang = ang_t - 65;

            y = y - 1.2 * rec_ang;
            x = x - 3.5 * rec_ang;

            deg = 90 - ang_t;
        
        }else if(ang_t > 75 && ang_t <= 85){

            y = y - 204.5;
            x = x - 147;

            rec_ang = ang_t - 75;

            y = y - 0.65 * rec_ang;
            x = x - 3.5 * rec_ang;
            deg = 90 - ang_t;
        
        }else if(ang_t > 85){

            y = y - 211;
            x = x - 182;
            
            rec_ang = ang_t - 85;

            x = x - 3.6 * rec_ang;

            deg = 90 - ang_t;
        }

    }else if(deg_mode == 0){

        x = x + 16.5 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y - 200; //taco / 2

        float rsen, rcos, ang_t, rec_0, rec_ang, ang, pi, ang_recover, px_recover_center;
        float px_x_inc, px_y_inc, px_x_add, px_x_central;
        
        pi = 3.1415; //pi
        
        ang_t = atan (divAL) * 180 / pi; //quantidade de graus atual sem conversao
        rcos = cos (ang_t * pi / 180);
        rsen = sin (ang_t * pi / 180);

        ang = 90-ang_t; //recupera quantidade de graus para octeto atual
        
        if(ang <= 10){

            y = y - 1.5;
            y = y + 0.3 * ang;
            x = x - 3.6 * ang;

            deg = -ang;
            
        }else if(ang > 10 && ang <= 30){

            y = y + 2.5;
            x = x - 36;

            rec_ang = ang - 10;

            px_y_inc = 24.5 / 20;
            px_x_inc = 70 / 20;
           
            y = y + divLA * 2 * rec_ang;
            x = x - 3.5 * rec_ang;

            deg = -ang;
        
        }else if(ang > 30 && ang <= 40){

            y = y + 27;
            x = x - 105;
            
            rec_ang = ang - 30;

            px_y_inc = 23 / 10;
            px_x_inc = 32 / 10;

            y = y + px_y_inc * rec_ang;
            x = x - px_x_inc * rec_ang;

            deg = -ang;
        
        }else if(ang > 40 && ang <= 45){

            y = y + 50;
            x = x - 138;

            rec_ang = ang - 40;

            px_y_inc = 12 / 5;
            px_x_inc = 10 / 5;

            y = y + px_y_inc * rec_ang;
            x = x - px_x_inc * rec_ang;

            deg = -ang;
        
        }else if(ang > 45 && ang <= 55){

            y = y + 59;
            x = x - 148;

            rec_ang = ang - 45;

            y = y + 2.75 * rec_ang; 
            x = x - 2.5 * rec_ang;
            
            deg = -ang;
        
        }else if(ang > 55 && ang <= 65){

            y = y + 86.5;
            x = x - 173;

            rec_ang = ang - 55;

            y = y + 3.2 * rec_ang;
            x = x - 1.8 * rec_ang;

            deg = -ang;
        
        }else if(ang > 65 && ang <= 75){

            y = y + 118.5;
            x = x - 191;

            rec_ang = ang - 65;

            y = y + 3.7 * rec_ang;
            x = x - 1.35 * rec_ang;
            
            deg = -ang;
        
        }else if(ang > 75 && ang <= 85){

            y = y + 155.5;
            x = x - 204.5;

            rec_ang = ang - 75;
        
            y = y + 3.6 * rec_ang;
            x = x - 0.7 * rec_ang;
            
            deg = -ang;
        
        }else if(ang > 85){

            y = y + 191.5;
            x = x - 211.5;

            rec_ang = ang - 85;

            y = y + 4 * rec_ang;

            deg = -ang;
        }

    }
    //end div taco / 2 && bola / 20 -> meio

    /*SDL_Rect pxy_rect;
    pxy_rect.w = 2;
    pxy_rect.h = 2;
    pxy_rect.x = x+200;
    pxy_rect.y = y+200;

    SDL_RenderDrawRect(rendT, &pxy_rect);
    SDL_RenderFillRect(rendT, &pxy_rect);*/

    SDL_Rect image_taco_rect;
    image_taco_rect.w = 6;
    image_taco_rect.h = 400;
    image_taco_rect.x = x;
    image_taco_rect.y = y;
    SDL_RendererFlip flip = SDL_FLIP_VERTICAL;

    SDL_RenderCopyEx(rendT, texture_taco, NULL, &image_taco_rect, deg, NULL, flip);
    SDL_DestroyTexture(texture_taco);
}
