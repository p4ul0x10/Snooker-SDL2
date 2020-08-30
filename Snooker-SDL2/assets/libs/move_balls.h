//move balls functions

void check_moviments(SDL_Renderer *moveRend, int vetor_x[], int vetor_y[], float bx, float by){

    int cont;
    float bx_center, by_center, bx_rest, by_rest, vety_center, vetx_center;
    bool checked = false;
    //start size bolls
    SDL_Rect triImg_rect;
    triImg_rect.w = 20;
    triImg_rect.h = 20;
    //ens size bolls

    by_center = round(by) + 10; //center y white boll
    bx_center = round(bx) + 10; //center x white boll

    for(cont = 0; cont < 15; cont++){

        vety_center = round(vetor_y[cont]) + 10;// + 10; //center y all
        vetx_center = round(vetor_x[cont]) + 10;// + 20; //center x all

        //check if xy_center white bol > vetor xy center
        if(bx_center >= vetx_center && by_center >= vety_center){ //300 >= 310
            by_rest = by - vety_center; //total restante da diferencia entre bola branca e vetor geral
            bx_rest = bx_center - vetx_center;
        }/*else if(bx_center >= vetx_center && by_center < vety_center){ //else vetor xy all > while bol
            by_rest = vety_center - by; //total restante da diferencia entre bola branca e vetor geral
            bx_rest = vetx_center - bx_center;
        }*/

        //start check colisao
        if(bx_rest <= 20 && by_rest <= 20){ //check colisao quando x center > x center vetor && quantidade restante <= 20 tamanho total bola
            SDL_Quit();

        }
        //end check colisao
        triImg_rect.x = vetor_x[cont];
        triImg_rect.y = vetor_y[cont];
        SDL_Surface *triImg = IMG_Load("assets/images/b1.png");
        SDL_Texture *texture_b = SDL_CreateTextureFromSurface(moveRend, triImg);
        SDL_FreeSurface(triImg);
        SDL_RenderCopy(moveRend, texture_b, NULL, &triImg_rect);
        SDL_DestroyTexture(texture_b);

    }
}

void loadTriangulo(SDL_Renderer *rendTri, bool status_tri, bool action, float mouseX, float mouseY, float bx, float by){

	int vetN[15], vetX[15], vetY[15], vetP[7], vetI[8], vB;
	float bx_center, by_center, mouseX_center, mouseY_center;

    //start center positions x y -> center mira
	bx_center = bx + 10;
	by_center = by + 10;
	mouseX_center = mouseX + 10;
	mouseY_center = mouseY + 10;
    //end ceter positions x y -> center mira

	//start triangulo inicial
    SDL_Surface *triImg = IMG_Load("assets/images/b1.jpeg");
	SDL_Texture *texture_b = SDL_CreateTextureFromSurface(rendTri, triImg);
	SDL_FreeSurface(triImg);
	SDL_Rect triImg_rect;
	triImg_rect.w = 20;
	triImg_rect.h = 20;
	triImg_rect.y = 217.5;
	triImg_rect.x = 700;
	//end triangulo inicial

    if(status_tri == false){

		for(vB = 0; vB < 15; vB++){

			vetN[vB] = vB; //vetor numero total bolas
			if(vB == 0){
				SDL_Surface *triImg = IMG_Load("assets/images/b1.png");
				SDL_Texture *texture_b = SDL_CreateTextureFromSurface(rendTri, triImg);
				SDL_FreeSurface(triImg);
				//SDL_RenderCopy(rendTri, texture_b, NULL, &triImg_rect);
				SDL_DestroyTexture(texture_b);
				vetX[vB] = triImg_rect.x; //vetor x pos
				vetY[vB] = triImg_rect.y; //vetor y pos
				vetI[vB] = vB+1; //vetor bolas impar
			}else if(vB > 0 && vB < 3){

				if(vB == 1){

					triImg_rect.y = 207.5;
					triImg_rect.x += 17.5;
					SDL_Surface *image_b2 = IMG_Load("assets/images/b2.png");
					SDL_Texture *texture_b2 = SDL_CreateTextureFromSurface(rendTri, image_b2);
					SDL_FreeSurface(image_b2);
					//SDL_RenderCopy(rendTri, texture_b2, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b2);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 2){

					triImg_rect.y = 227.5;
					SDL_Surface *image_b3 = IMG_Load("assets/images/b3.png");
					SDL_Texture *texture_b3 = SDL_CreateTextureFromSurface(rendTri, image_b3);
					SDL_FreeSurface(image_b3);
					//SDL_RenderCopy(rendTri, texture_b3, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b3);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}

			}else if(vB > 2 && vB <= 5){

				if(vB == 3){

					triImg_rect.y = 197.5;
					triImg_rect.x += 17.5;
					SDL_Surface *image_b4 = IMG_Load("assets/images/b4.png");
					SDL_Texture *texture_b4 = SDL_CreateTextureFromSurface(rendTri, image_b4);
					SDL_FreeSurface(image_b4);
					//SDL_RenderCopy(rendTri, texture_b4, NULL, &triImg_rect);
                    SDL_DestroyTexture(texture_b4);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 4){

					triImg_rect.y = 217.5;
					SDL_Surface *image_b5 = IMG_Load("assets/images/b5.png");
					SDL_Texture *texture_b5 = SDL_CreateTextureFromSurface(rendTri, image_b5);
					SDL_FreeSurface(image_b5);
					//SDL_RenderCopy(rendTri, texture_b5, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b5);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 5){

					triImg_rect.y = 237.5;
					SDL_Surface *image_b6 = IMG_Load("assets/images/b6.png");
					SDL_Texture *texture_b6 = SDL_CreateTextureFromSurface(rendTri, image_b6);
					SDL_FreeSurface(image_b6);
                    //SDL_RenderCopy(rendTri, texture_b6, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b6);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}

			}else if(vB > 5 && vB < 10){

				if(vB == 6){

					triImg_rect.y = 187.5;
					triImg_rect.x += 17.5;
					SDL_Surface *image_b7 = IMG_Load("assets/images/b7.png");
					SDL_Texture *texture_b7 = SDL_CreateTextureFromSurface(rendTri, image_b7);
					SDL_FreeSurface(image_b7);
					//SDL_RenderCopy(rendTri, texture_b7, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b7);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 7){
					triImg_rect.y = 207.5;
					SDL_Surface *image_b8 = IMG_Load("assets/images/b8.png");
					SDL_Texture *texture_b8 = SDL_CreateTextureFromSurface(rendTri, image_b8);
					SDL_FreeSurface(image_b8);
					//SDL_RenderCopy(rendTri, texture_b8, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b8);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 8){
					triImg_rect.y = 227.5;
					SDL_Surface *image_b9 = IMG_Load("assets/images/b9.png");
					SDL_Texture *texture_b9 = SDL_CreateTextureFromSurface(rendTri, image_b9);
					SDL_FreeSurface(image_b9);
					//SDL_RenderCopy(rendTri, texture_b9, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b9);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 9){
					triImg_rect.y = 247.5;
					SDL_Surface *image_b10 = IMG_Load("assets/images/b10.png");
					SDL_Texture *texture_b10 = SDL_CreateTextureFromSurface(rendTri, image_b10);
					SDL_FreeSurface(image_b10);
					//SDL_RenderCopy(rendTri, texture_b10, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b10);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}

			}else{

				if(vB == 10){
					triImg_rect.y = 177.5;
					triImg_rect.x += 17.5;
					SDL_Surface *image_b11 = IMG_Load("assets/images/b11.png");
					SDL_Texture *texture_b11 = SDL_CreateTextureFromSurface(rendTri, image_b11);
					SDL_FreeSurface(image_b11);
					//SDL_RenderCopy(rendTri, texture_b11, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b11);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 11){
					triImg_rect.y = 197.5;
					SDL_Surface *image_b12 = IMG_Load("assets/images/b12.png");
					SDL_Texture *texture_b12 = SDL_CreateTextureFromSurface(rendTri, image_b12);
					SDL_FreeSurface(image_b12);
					//SDL_RenderCopy(rendTri, texture_b12, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b12);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 12){
					triImg_rect.y = 217.5;
					SDL_Surface *image_b13 = IMG_Load("assets/images/b13.png");
					SDL_Texture *texture_b13 = SDL_CreateTextureFromSurface(rendTri, image_b13);
					SDL_FreeSurface(image_b13);
					//SDL_RenderCopy(rendTri, texture_b13, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b13);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 13){
					triImg_rect.y = 237.5;
					SDL_Surface *image_b14 = IMG_Load("assets/images/b14.png");
					SDL_Texture *texture_b14 = SDL_CreateTextureFromSurface(rendTri, image_b14);
					SDL_FreeSurface(image_b14);
					//SDL_RenderCopy(rendTri, texture_b14, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b14);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 14){
					triImg_rect.y = 257.5;
					SDL_Surface *image_b15 = IMG_Load("assets/images/b15.png");
					SDL_Texture *texture_b15 = SDL_CreateTextureFromSurface(rendTri, image_b15);
					SDL_FreeSurface(image_b15);
					//SDL_RenderCopy(rendTri, texture_b15, NULL, &triImg_rect);
					SDL_DestroyTexture(texture_b15);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}
			}
		}

		//vetx -> vetor x pos | vety -> vetor y pos
        check_moviments(rendTri, vetX, vetY, bx, by); //check movements function

		/*if(action == true){
            float mira_rec_y_up, mira_rec_y_down, vet_y_center, vety_recalc_up, vety_recalc_down;

            mira_rec_y_up = bx_center - 10;
            mira_rec_y_down = by_center + 10;

            for(int m = 0; m < 15; m++){

                vet_y_center = vetY[m] + 10;

                vety_recalc_up = vet_y_center - 10;
                vety_recalc_down = vet_y_center + 10;

                if(bx > 600 && bx >= vetX[m]){
                    SDL_Quit();
                }
            }
        }*/
	}/*else if(status_tri == true){

        float center_x, center_y, aux_vet_x, aux_vet_y;
        float vetBx[15], vetBy[15];
        center_x = mouseX + 10;
        center_y = mouseY + 10;

        SDL_SetRenderDrawColor(rendTri, 0, 0, 0, 1);
        //start aling center pos x y balls
        for(int p = 0; p < 15; p++){

            aux_vet_x = vetX[p];
            aux_vet_y = vetY[p];

            aux_vet_x += 10;
            aux_vet_y += 10;

            vetBx[p] = aux_vet_x;
            vetBy[p] = aux_vet_y;

            SDL_Rect pxx_rect;

            pxx_rect.h = 4;
            pxx_rect.w = 4;
            pxx_rect.x = aux_vet_x;
            pxx_rect.y = aux_vet_y;

            SDL_RenderDrawRect(rendTri, &pxx_rect);
            SDL_RenderFillRect(rendTri, &pxx_rect);

        }
        //end aling center pos x y balls

	}*/
}

//move balls functions

