void rendTaco(SDL_Renderer *rendT, float vetX[], float vetY[], float deg, float deg_mode, float df_x, float df_y){


    float x, y;

    x = vetX[15];
    y = vetY[15];
    
    SDL_Surface *image_taco = IMG_Load("assets/images/taco.png");

    SDL_Texture *texture_taco = SDL_CreateTextureFromSurface(rendT, image_taco);
	SDL_FreeSurface(image_taco);

    int cont_px = 0;
    int px = 0;
    float incPx, divAL, divLA, deg_limit, total_deg, div_angulo;
    float bx, by;
    bool stop_px = false, run = true;

	divLA = df_x / df_y; //largura / altura
	divAL = df_y / df_x; //altura / largura

    bx = x+10;
    by = y+10;

    SDL_SetRenderDrawColor(rendT, 0, 0, 0, 1);

    //start init calc limit deg
	while (px < 16)
	{
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
        pi = 3.1415; //pi
        ang_t = atan (divAL) * 180 / pi; //total de graus

        if(round(ang_t) <= 45){ //first 45 initial degress

            if(round(ang_t) <= 22.5){ // < 22.5 deg(s)

                 //start y recover center
                 px_recover_center = 75 / 22.5; //3.3333 porcentagem relativa aos primeiros 22.5 graus
                 px_y_add = px_recover_center * ang_t;
                 y = y + px_y_add;
                 //end y recover center

                 //start x recover center
                 px_x_central = 10 / 22.5; //porcentagem relativa aos primeiros 22.5 graus
                 px_x_add = px_x_central * ang_t; //porcentagem relativa * total de angulo de enclinacao
                 x = x + px_x_add;

                 //start ajust center x
                 float px_xx, px_xx_inc;
                 px_xx_inc = 5 / 22.5;
                 px_xx = px_xx_inc * ang_t;
                 x = x + px_xx;
                 //end ajust center x

                 //start add degress 22.5
                 ang = 90+ang_t;
                 deg = -ang;
                 //end add degress 22.5

            }else if(round(ang_t) > 22.5){ //> 22.5 deg(s)

                if(ang_t > 40){
                    //SDL_Quit();
                }
                //start y recover center
                px_recover_center = 62 / 22.5; //2.7555;
                px_y_add = px_recover_center * ang_t; //porcentagem relativa * total do angulo de enclinacao
                y = y + 17; //recover y 22.5 deg(s) init
                y = y + px_y_add; //add y pos
                //end y recover center

                //start x recover center
                x = x + 15; //recover x relativo 22.5 deg(s) init
                px_x_central = 47 / 45; //porcentagem de px relativo / quantidade de graus
                px_x_inc = ang_t - 22.5; //recover 22.5 degs
                px_x_add = px_x_central * px_x_inc;
                x = x + px_x_add; //recover x relativo 22.5 deg(s) > 22.5 && < 45
                x = x + 1.1111*px_x_add; //recover x 25 px / 22.5 deg(s)

                 //end ajust center x

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
                 y = y + 1;
             }else if(total_deg > 4 && total_deg <= 6){

                x = x - 11;
                y = y + total_deg;
                 y = y + 1;
             }else if(total_deg > 6 && total_deg < 8){

                x = x - 10;
                y = y + total_deg;
                y = y + 1;
             }else if(total_deg > 7 && total_deg < 9){

                x = x - 11;
                y = y + total_deg;
                y = y + 1;
             }else if(total_deg > 8 && total_deg < 10){

                x = x - 12;
                y = y + total_deg;
                y = y + 2;
             }else if(total_deg > 9 && total_deg < 11){

                x = x - 12;
                y = y + total_deg;
                y = y - 3;
             }
             //end border rotation y pos

             //end border rotation pos x y

        }else if(round(ang_t) > 45){ //graus > 45 ate 90

            if(round(ang_t) <= 67.5){ // graus < 65 || graus < 22.5 relativo

                //start y recover center
                //180 total y
                px_recover_center = 37 / 22.5; //quantidade de px / quantidade de graus
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

                //end y recover center

                //start x recover center
                //112 total x
                x = x + 56; //recover x first 45 graus
                px_x_central = 59 / 22.5; //quantidade de px / quantidade de graus(relativo 22.5)
                px_x_inc = ang_t - 45; //recuperacao de 22.5 relativo a quantidade de graus atual (atual deg - 45)
                px_x_add = px_x_central * px_x_inc; //quantidade de px adds * quantidade de graus atual relativo aos (22.5) adicionais aos 45 finais
                x = x + px_x_add;//55;
                //x = x + 112;
                //start ajust center x
                 float px_xx, px_xx_inc;
                 px_xx_inc = 2 / 22.5;
                 px_xx = px_xx_inc * ang_t;
                 x = x + px_xx;
                //end x recover center

                //start add degress > 45 && < 65
                ang = 90+ang_t;
                deg = -ang;
                //end add degress > 45 && < 65

            }else if(round(ang_t) > 67.5){ // graus > 65 || graus > 22.5 relativo

                if(ang_t > 70){
                    //SDL_Quit();
                }
                //start y recover center 197 total y
                y = y + 182; //recover y 65 graus initials
                px_recover_center = 20 / 22.5; //quantidade de px / quantidade relativa de graus (22.5)
                px_y_inc = ang_t - 65; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_y_add = px_recover_center * px_y_inc; //quantidade de px * quantidade de graus atual
                y = y + px_y_add; //adiciona y pos
                //end y recover center

                //start x recover center 200 px total
                x = x + 116; //recover x 65 graus initials
                px_x_central = 84 / 22.5; //quantidade de px / graus relativo 22.5
                px_x_inc = ang_t - 65; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_x_add = px_x_central * px_x_inc; //quantidade de px * quantidade atual de graus
                x = x + px_x_add; //adiciona x pos

                div_angulo = 10 / 22.5; //10 px(raio) / quantidade de vezes relativo a (22.5 graus)
                deg_limit = px_x_inc * div_angulo; //quantidade de px * divisao total do raio(10) / 22.5 (vezes)
                x = x - deg_limit; //recover x center px relativo(raio de px)
                //end x recover center

                //start add degress > 65 && <= 90
                ang = 90+ang_t;
                deg = -ang;
                //end add degresss > 65 && <= 90

            }

            //start border rotation pos x y
            float ang_recover_add;
            ang_recover = ang_t - 45; //recupera quantidade de graus para 45 deg(s) max relativo
            total_deg = ang_recover / 7; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            ang_recover_add = 7 - total_deg; //recupera quantidade de graus decrescente relativo maximo ajuste 7 px
            x = x + 2;
            //y = y + 1;
            //start border rotation x pos -> 45 deg(s) end close 90 deg(s)
             if(total_deg <= 1){

                x = x - ang_recover_add;
                y = y + 8;
                y = y + 1;
             }else if(total_deg > 1 && total_deg < 4){

                x = x - ang_recover_add;
                y = y + 10;
                y = y + 1;
             }else if(total_deg > 3){

                x = x - ang_recover_add;
                y = y + 11;
                y = y + 1;

             }
             //end border rotation pos x y
        }

    }else if(deg_mode == 180){

        x = x + 17 / 2; //bola / 2
        y = y + 20 / 2; //bola / 2
        //y = y + 10;

        float ang_t, ang, pi, ang_recover, px_recover_center, px_y_inc, px_y_add, px_x_inc, px_x_add, px_x_central;
        pi = 3.1415;
        ang_t = atan (divAL) * 180 / pi;
        ang = 90+ang_t;
        ang_recover = 180 - ang; //recupera angulo relativo a 90 graus

        if(round(ang) <= 135){ //> 45 degs last 45 deg(s)

            if(round(ang) <= 112.5){ //< 22.5 degs - > 90 max (final)

            //start x recover center
            x = x + 184.5; //recover x center <= 65 deg(s) initials
            px_x_central = 112.5 - ang; //recupera quantidade de graus atual relativo
            px_x_inc = 15.5 / 22.5; //quantidade de px restante / quantidade total de graus relativo
            px_x_add = px_x_inc * px_x_central; //quantidade de px * quantidade de graus relativo (22.5)
            x = x + px_x_add; //adiciona x pos
            //x = x + 200;
            //end x recover center

            //start y recover center
            y = y - 122; //recover y center <= 65 deg(s) inititals
            px_recover_center = 112.5 - ang; //recupera quantidade de graus relativo (22.5)
            px_y_inc = 78 / 22.5; //quantidade de px total / quantidade relativa de graus max (22.5)
            px_y_add = px_y_inc * px_recover_center; //quantidade de px relativo * quantidade de graus relativo max 22.5
            y = y - px_y_add; //adiciona y pos
            //end y recover center

            //start add deg(s)
            deg = ang;
            //end add deg(s)

            }else if(round(ang) > 112.5){ // > 22.5 degs - > 65 max total
                //SDL_Quit();
                //start recover x center
                x = x + 107; //recover x 45 degs initials
                px_x_central = 157 - ang; //recupera quantidade de graus relativo
                px_x_inc = 37.5 / 22.5; //quantidade de px eixo x  / quantidade total relativo 22.5
                px_x_add = px_x_inc * px_x_central; //quantidade px eixo x * quantidade de graus
                x = x + px_x_add; //incrementa x pos 110
                //end recover x center

                //start recover y center
                y = y - 57; //recover y 45 degs initials
                px_recover_center = 135 - ang; //recupera quantidade de graus relativa
                px_y_inc = 68 / 22.5; //quantidade de px / quantidade de graus relativo
                px_y_add = px_x_inc * px_recover_center; //quantidade de px * quantidade de graus
                y = y - px_y_add; //adiciona y px
                //y = y - 30;
                float px_incy, px_ycenter, px_addy, px_yrec;
                px_yrec = 112.5 - ang; //quantidade de graus relativa 22.5
                px_ycenter = 30 / 22.5; //quantidade de px / quantidade de graus
                px_incy = px_ycenter * px_recover_center; // quantidade de px * quantidade de graus
                y = y - px_incy; //adiciona y px
                //end recover y center

                //start deg(s) add
                deg = ang;
                //end deg(s) add
            }

            //start border rotation y x pos
            float ang_recover_add;
            ang_recover = 135 - ang; //recupera quantidade de graus atual max relativo 45 graus
            total_deg = ang_recover / 7; //quantidade de graus recuperado / quantidade relativa maxima da borda
            ang_recover_add = 7 - total_deg; //quantidade de px relativa - resultado da divisao de graus pelos px

            //start border rotation y pos -> 45 deg(s) finals
            if(ang_recover <= 1){
                x = x + 9;
                y = y + ang_recover_add;
            }else if(ang_recover > 1 && ang_recover < 4){
                x = x + 10;
                y = y + ang_recover_add;
            }else if(ang_recover > 3){
                x = x + 13;
                y = y + ang_recover_add;
            }
            //end border rotation y pos
            //end border rotation y x pos

        }else if(round(ang) > 135){ //> 45 degs

            if(round(ang) <= 157.5){ //> 22.5 deg(s) && <= 45

            //start x recover center
            x = x + 75; //recover 22.5 x initials
            px_x_central = 157.5 - ang; //recupera quantidade de graus relativo a 22.5
            px_x_inc = 67 / 22.5; //quantidade de px / quantidade de graus relativo max 22.5
            px_x_add = px_x_inc * px_x_central; //quantidade de px * quantidade de graus
            x = x + px_x_add; //add recover x center
            //end x recover center

            //start y recover center
            y = y - 15; //recover y center 22.5 deg(s) initials
            px_recover_center = 157.5 - ang; //recupera quantidade de graus relativo a 22.5
            px_y_inc = 44 / 22.5; //quantidade de px / quantidade de graus ativo max 22.5
            px_y_add = px_y_inc * px_recover_center; //quantidade de px * quantidade de graus
            y = y - px_y_add; //add recover y center
            //end y recover center

            //start add deg(s)
            deg = ang;
            //end add deg(s)
            }else if(round(ang) > 157.5){ //< 22.5 deg(s)

                //y = y - 15;
                //x = x + 75;
                //start x recover center
                float incx, addx, recx;
                incx = 7 / 22.5; //recupera porcentagem relativa ao centro eixo (x)
                addx = ang_t - 90; //recupera graus ate 90 relativo a 180
                recx = addx*3.1222; //recupera centro eixo x -> incrementa quantidade de px a cada alteração de graus
                x = x - recx; //incrementa nova posição eixo x relativo graus
                x = x - incx*addx; //incrementa nova posicao eixo x relativo aos 22.5 graus / 45
                //end x recover center

                //start y recover center
                px_recover_center = ang_t - 90; //recupera quantidade de graus
                px_y_inc = 15 / 22.5; //quantidade de px relativo a 22.5 graus
                px_y_add = px_y_inc * px_recover_center; //quantidade de px * quantidade de graus
                y = y + px_y_add; //incrementa nova posicao eixo y

                //start add deg(s)
                deg = ang;
                //end add deg(s)
            }

            //start border rotation pos x y

            total_deg = ang_recover / 4.5; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            //start border rotation x -> 45 deg(s) initials
             if(total_deg <= 4){

                x = x + total_deg;
                y = y + 12;
                //x = x - 2;
             }else if(total_deg > 4 && total_deg <= 6){

                x = x + total_deg;
                y = y + 11;
                x = x - 2;
             }else if(total_deg > 6 && total_deg < 8){

                x = x + total_deg;
                y = y + 11;
                x = x - 1;
             }else if(total_deg > 7 && total_deg < 9){

                x = x + total_deg;
                y = y + 10;
                x = x - 2;
             }else if(total_deg > 8 && total_deg < 10){

                x = x + total_deg;
                y = y + 6;
                x = x - 2;
             }else if(total_deg > 9 && total_deg < 11){

                x = x + total_deg;
                y = y + 10;
                x = x - 2;
             }

             //end border rotation pos x y
        }

    }else if(deg_mode == 90){

        x = x + 400 / 2; //taco / 2
        x = x + 20 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y + 20 / 2; //bola / 2
        //x = x + 10;

        float ang_t, ang, pi, px_recover_center, px_y_inc, px_y_add, px_x_inc, px_x_add, px_x_central, ang_recover;
        pi = 3.1415;
        ang_t = atan (divAL) * 180 / pi;

        if(round(ang_t) <= 45){ //<= 45 first 45 deg(s) initials

            if(round(ang_t) <= 22.5){ //<= 22.5 deg(s) initials

                //start recover y deg(s) addeds
                px_recover_center = 75 / 22.5; //3.3333 porcentagem relativa aos primeiros 22.5 graus
                px_y_add = px_recover_center * ang_t; //quantidade de px * quantidade de graus atual max 22.5
                y = y - px_y_add; //add y pos
                //end recover y deg(s) addeds

                 //start recover x center
                 px_x_central = 10 / 22.5; //porcentagem relativa aos primeiros 22.5 graus
                 px_x_add = px_x_central * ang_t; //porcentagem relativa * total de angulo de enclinacao
                 x = x - px_x_add; //add x pos

                 //start ajust center x
                 float px_xx, px_xx_inc;
                 px_xx_inc = 7 / 22.5; //quantidade px -> recover center
                 px_xx = px_xx_inc * ang_t; //quantidade px * quantidade angulo atual max 22.5
                 x = x - px_xx; //add x pos
                 //end ajust center x
                 //end recover x center

                //start add deg(s)
                ang = 90-ang_t;
                deg = ang;
                //end add deg(s)

            }else if(round(ang_t) > 22.5){ //> 22.5 deg(s) && <= 45
                if(ang_t > 24){
                    //SDL_Quit();
                }
                //start recover y center
                px_recover_center = 62 / 22.5; //quantidade px / quantidade de graus
                px_y_add = px_recover_center * ang_t; //quantidade px * quantidade de graus atual
                y = y - 16; //recover y relativo 22.5 graus initials
                y = y - px_y_add; //add y pos
                //end recover y center

                //start recover x center
                x = x - 15; //recover x relativo 22.5 deg(s) init
                px_x_central = 47 / 45; //porcentagem de px relativo / quantidade de graus
                px_x_inc = ang_t - 22.5; //recover 22.5 degs
                px_x_add = px_x_central * px_x_inc;
                x = x - px_x_add; //recover x relativo 22.5 deg(s) > 22.5 && < 45
                x = x - 1.1111*px_x_add; //recover x 25 px / 22.5 deg(s)
                //end recover x center
                //ajust pending

                //start add deg(s)
                ang = 90-ang_t;
                deg = ang;
                //end add deg(s)
            }

            //start border rotation 45 deg(s) initials
            total_deg = ang_t / 7; //recupera quantidade relativa de px (incremento rotacao), pelo resultado da divisao total 90 / 20 = 4.5
            //start bordar y pos rotacao
            if(total_deg <= 4){
                x = x + 11;
                y = y - total_deg;
            }else if(total_deg > 4 && total_deg < 7){
                x = x + 12;
                y = y - total_deg;
            }else if(total_deg > 6 && total_deg < 8){
                x = x + 13;
                y = y - total_deg;
                y = y - 2.5;
            }
            //end borda y pos rotacao
            //end border rotation

        }else if(round(ang_t) > 45){ // > 45 deg(s) && <= 90 deg(s)
           //SDL_Quit();

            if(round(ang_t) <= 67.5){ //< 22.5 first 22.5 deg(s) relativo a >= 45 deg(s)

            //start recover y center
            px_recover_center = 43 / 22.5; //quantidade de px / quantidade de graus
            px_y_inc = ang_t - 35; //recupera quantidade de graus (atual) relativo para 22.5
            px_y_add = px_recover_center * px_y_inc; //quantidade de px * quantidade de graus atual (relativo 22.5)
            //y = y + px_y_add;
            y = y - 123; //recover y first 45 graus
            y = y - px_y_add; //add y pos

            //start y ajust center 1
            float px_yy, px_yy_inc;

            px_yy = 7 / 22.5; //quantidade px relativo -> center
            px_yy_inc = px_yy * px_x_inc; //quantidade px * quantidade graus atual
            //y = y - px_yy_inc; //add y pos
            //end y ajust center 1
            //end recover y center

            //start recover x center
            x = x - 59; //recover x first 45 graus
            px_x_central = 59 / 22.5; //quantidade de px / quantidade de graus(relativo 22.5)
            px_x_inc = ang_t - 45; //recuperacao de 22.5 relativo a quantidade de graus atual (atual deg - 45)
            px_x_add = px_x_central * px_x_inc; //quantidade de px adds * quantidade de graus atual relativo aos (22.5) adicionais aos 45 finais
            x = x - px_x_add;//add x pos
            //end recover x center
            //start ajust x center
            float px_xx, px_xx_inc;
            px_xx_inc = 7 / 22.5;
            px_xx = px_xx_inc * px_x_inc;
            x = x - px_xx;
            //end ajust x center

            //start add deg(s)
            ang = 90-ang_t;
            deg = ang;
            //end add deg(s)

            }else if(round(ang_t) > 67.5){ // > 67.5 final 22.5 graus finais relativo max 90

                //start recover y center
                y = y - 180; //recover y 65 graus initials
                px_recover_center = 17 / 22.5; //quantidade de px / quantidade relativa de graus (22.5)
                px_y_inc = ang_t - 67.5; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_y_add = px_recover_center * px_y_inc; //quantidade de px * quantidade de graus atual
                y = y - px_y_add; //adiciona y pos
                //end recover y center

                //start recover x center
                x = x - 126; //recover x 65 graus initials
                px_x_central = 84 / 22.5; //quantidade de px / graus relativo 22.5
                px_x_inc = ang_t - 67.5; //recuperacao da quantidade atual de graus (relativo 22.5)
                px_x_add = px_x_central * px_x_inc; //quantidade de px * quantidade atual de graus
                x = x - px_x_add; //adiciona x pos

                div_angulo = 10 / 22.5; //10 px(raio) / quantidade de vezes relativo a (22.5 graus)
                deg_limit = px_x_inc * div_angulo; //quantidade de px * divisao total do raio(10) / 22.5 (vezes)
                x = x + deg_limit; //recover x center px relativo(raio de px)
                //end recover x center
                //ajust center
                //start add deg(s)
                ang = 90 - ang_t;
                deg = ang;
                //end add deg(s)
            }

            //start margin rotation x 45 deg(s) finals
            float ang_recover_add;
            ang_recover = ang_t - 45; //recupera quantidade de graus para 45 deg(s) max relativo
            total_deg = ang_recover / 7; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            ang_recover_add = total_deg; //recupera quantidade de graus decrescente relativo maximo ajuste 7 px

            //ajust recover center x pos
            if(round(ang_t) <= 67.5){
                 x = x + 7;
            }else{
                 x = x + 6;
            }
            //end ajust recover center x pos

            //start border rotation x pos -> 45 deg(s) end close 90 deg(s)
             if(total_deg <= 1){

                x = x - ang_recover_add;
                y = y - 8;

             }else if(total_deg > 1 && total_deg < 4){

                x = x - ang_recover_add;
                y = y - 13;

             }else if(total_deg > 3){

                x = x - ang_recover_add;
                y = y - 16;

             }
             //end border rotation x pos 90 deg(s) completos
            //end margin rotation 45 deg(s) finals
        }

    }else if(deg_mode == 0){

        x = x + 17 / 2; //bola / 2
        y = y - 400 / 2; //taco / 2
        y = y - 200; //taco / 2
        y = y + 20 / 2; //bola / 2

        float ang_t, ang, pi, ang_recover ,px_recover_center, px_y_inc, px_y_add, px_x_inc, px_x_add, px_x_central;
        pi = 3.1415; //pi
        ang_t = atan (divAL) * 180 / pi; //quantidade de graus atual sem conversao
        ang = 90-ang_t; //recupera quantidade de graus para octeto atual

        if(round(ang_t) <= 45){ //final 45 deg(s) initials > 90

            if(round(ang_t) <= 22.5){ //> 22.5 deg(s) & <= 45

            //start recover y center
            y = y + 125; //recover y center
            px_recover_center = 22.5 - ang_t; //recupera quantidade total de graus para (22.5) graus relativo
            px_x_inc = 75 / 22.5; //quantidade total px / quantidade relativa de graus
            px_x_add = px_x_inc * px_recover_center; //quantidade total px * quantidade atual total graus
            y = y + px_x_add;//add y pos
            //end recover y center

            //start recover x center
            x = x - 185; //recover x center
            px_x_central = 22.5 - ang_t; //recupera quantidade de atual de graus relativo 22.5
            px_x_inc = 13 / 22.5; //quantidade de px / quantidade relativa de graus max 22.5
            px_x_add = px_x_inc * px_x_central; //quantidade de px * quantidade de graus relativo 22.5
            x = x - px_x_add; //add x pos
            //end recover x center

            //start add deg(s)
            deg = -ang;
            //end add  deg(s)

            }else if(round(ang_t) > 22.5){ //> 22.5 && <= 45 deg(s) first 45 initials > 45

                //start recover y center
                y = y + 60; //124 recover total y center
                px_recover_center = 45 - ang_t; //recupera quantidade de graus atual (relativo para max 22.5) graus
                px_y_inc = 64 / 22.5; //quantidade total de px relativo / quantidade max de graus 22.5
                px_y_add = px_y_inc * px_recover_center; //quantidade de px * quantide total de graus relativa
                y = y + px_y_add; //64 px_y_add;
                //end recover y center

                //start recover x center
                x = x - 145; //recover total x center
                px_x_central = 45 - ang_t; //recupera quantidade de graus atual (relativo para max 22.5)  graus
                px_x_inc = 38 / 22.5; //quantidade total px / quantidade relativa max graus( 22.5)
                px_x_add = px_x_inc * px_x_central; //quantidade de px * quantidade total atual de graus
                x = x - px_x_add; //add x pos
                //end recover x center

                //start add deg(s)
                deg = -ang;
                //end add deg(s)
            }

            //start border rotation y x pos
            float ang_recover_add;
            ang_recover = 45 - ang_t; //recupera quantidade de graus atual max relativo 45 graus
            total_deg = ang_recover / 6.42; //quantidade de graus recuperado / quantidade relativa maxima da borda
            ang_recover_add = 7 - total_deg; //quantidade de px relativa - resultado da divisao de graus pelos px

            //start border rotation y pos -> 45 deg(s) finals
            //y = y - 7;
            y = y - 2;
            if(total_deg <= 1){
                x = x - 8;
                y = y - ang_recover_add;
            }else if(total_deg > 1 && total_deg < 4){
                x = x - 13;
                y = y - ang_recover_add;
            }else if(total_deg > 3){
                x = x - 14;
                y = y - ang_recover_add;
            }
            //end border rotation y pos

        }else if(round(ang_t) > 45){ //< 45 deg(s) && <= 45 deg(s) final

            if(round(ang_t) < 67.5){ //> 22.5 deg(s) relativo <= 45 initials

                //start recover y center
                y = y + 15; //recover y center relativo first 22.5 deg(s) init(s)
                px_recover_center = 67.5 - ang_t; //recupera quantidade de graus atual para (22.5 relativo)
                px_y_inc = 50 / 22.5; //quantitade total de px / quantidade total de graus relativo (22.5)
                px_y_add = px_y_inc * px_recover_center; //quantidade px total relativo max 22.5 * quantidade de graus atual
                y = y + px_y_add; //add center

                //start ajust center y
                float px_yy, px_yy_inc;
                px_yy = 7 / 22.5; //quantidade de px / quantidade de px relativo max 22.5
                px_yy_inc = px_yy * px_recover_center; //quantidade de px * quantidade atual total de graus
                y = y - px_yy_inc; //add y pos
                //end recover y center

                //start recover x center
                x = x - 140; //recupera quantidade de graus relativa 45 deg(s) init
                px_x_central = ang_t - 45; //recupera quantidade de graus atual (relativo 22.5)
                px_x_inc = 60 / 22.5; //quantidade de px total relativa / quantidade maxima de graus 22.5
                px_x_add = px_x_inc * px_x_central; //quantidade total relativa de px / quantidade de graus atual
                x = x + px_x_add;//px_x_add; //add x pos
                //end recover x center

                //start ajust center x
                float px_xx, px_xx_inc;
                px_xx_inc = 3 / 22.5;
                px_xx = px_xx_inc * px_x_central;
                x = x + px_xx;
                //x = x - 7;
                //end ajust center x
                //start add deg(s)
                deg = -ang;
                //end add deg(s)

            }else if(round(ang_t) >= 67.5){ // < 22.5 deg(s) first 22.5

                if(round(ang_t) < 70){
                    //SDL_Quit();
                    x = x + 3.5;
                }
                //start recover y center
                px_recover_center = 90 - ang_t; //recupera quantidade de graus relativo max 22.5
                px_y_inc = 15 / 22.5; //quantidade de px relativo primeiros 22.5 deg(s)
                px_y_add = px_y_inc * px_recover_center; //quantidade de px * quantidade de graus atual recuperado max 22.5
                y = y + px_y_add; //add y pos
                //end recover y center

                //start recover x center
                //x = x - 80; //recover x center <= 65 deg(s) initials
                //px_x_central = 67.5 - ang; //recupera quantidade de graus atual relativo
                px_x_central = 90 - ang_t; //recupera quantidade de graus relativo max 22.5
                px_x_inc = 80 / 22.5; //quantidade de px restante / quantidade total de graus relativo
                px_x_add = px_x_inc * px_x_central; //quantidade de px * quantidade de graus relativo (22.5)
                x = x - px_x_add; //adiciona x pos
                //x = x + 2;
                //start ajust x center 1
                float px_xx, px_xx_inc, px_center_degs;
                px_center_degs = 90 - ang_t; //recupera quantidade de graus atual (max 22.5)
                px_xx_inc = 2 / 22.5; //quantidade px / quantidade relativa maxima de graus
                px_xx = px_xx_inc * px_recover_center; //quantidade de px * quantidade de graus atual
                x = x + px_xx; //add x pos
                //end ajust x center 1

                //end recover x center

                //start add deg(s)
                deg = -ang;
                //end add deg(s)
            }

            //start border rotation 45 deg(s) inits
            ang_recover = 90 - ang_t;
            total_deg = ang_recover / 4.5; //quantidade atual de deg(s) / unidade de medida px -> converte quantidade degs -> quantidade px
            //start border rotation x -> 45 deg(s) initials

             if(total_deg <= 4){

                x = x - total_deg;
                y = y - 12;

             }else if(total_deg > 4 && total_deg <= 6){

                x = x - total_deg;
                y = y - 10;

             }else if(total_deg > 6 && total_deg < 8){

                x = x - total_deg;
                y = y - 10;

             }else if(total_deg > 7 && total_deg < 9){

                x = x - total_deg;
                y = y - 11;

             }else if(total_deg > 8 && total_deg < 10){

                x = x - total_deg;
                y = y - 12;

             }else if(total_deg > 9 && total_deg < 11){

                x = x - total_deg;
                y = y - 8;
             }

            //end border rotation 45 deg(s) inits
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
