
void count_units(SDL_Renderer *rendImg, float x[], float y[], int cont_units[], int cont_ball[], char mode_player[]){

	int deg = 0, units = 0, p_width_x = 15, m_width_x = 15;
	int cont_p = 0, cont_m = 0;

	SDL_Surface *Surface;
    SDL_Texture *Texture;
	SDL_RendererFlip flip_x = SDL_FLIP_HORIZONTAL;
	SDL_Rect Texture_rect;

    Texture_rect.w = 15;
    Texture_rect.h = 15;
    
    //start player img
    SDL_Rect Texture_p;
    Texture_p.w = 60;
    Texture_p.h = 10;
    Surface = IMG_Load("assets/images/player.png");
	Texture_p.x = 5;
	Texture_p.y = 470;

	Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
	SDL_FreeSurface(Surface);

	SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_p, deg, NULL, 0);
	SDL_DestroyTexture(Texture);
	//end player img
	
	//start machine img
	SDL_Rect Texture_m;
	Texture_m.w = 60;
	Texture_m.h = 10;
	Surface = IMG_Load("assets/images/machine.png");
	Texture_m.x = 5;
	Texture_m.y = 488;

	Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
	SDL_FreeSurface(Surface);

	SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_m, deg, NULL, 0);
	SDL_DestroyTexture(Texture);
	//end machine img

	while(units <= 15){

		if(mode_player[1] == '7'){

			if(cont_ball[units] <= 7 && x[units] != 0 && y[units] != 0){
				
				cont_p++;
				
				if(cont_ball[units] == 1){
					Surface = IMG_Load("assets/images/b1.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 2){
					Surface = IMG_Load("assets/images/b2.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 3){
					Surface = IMG_Load("assets/images/b3.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 4){
					Surface = IMG_Load("assets/images/b4.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 5){
					Surface = IMG_Load("assets/images/b5.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 6){
					Surface = IMG_Load("assets/images/b6.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 7){
					Surface = IMG_Load("assets/images/b7.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

			if(cont_ball[units] >= 9 && x[units] != 0 && y[units] != 0){

				cont_m++;
				
				if(cont_ball[units] == 9){
					Surface = IMG_Load("assets/images/b9.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 10){
					Surface = IMG_Load("assets/images/b10.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 11){
					Surface = IMG_Load("assets/images/b11.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 12){
					Surface = IMG_Load("assets/images/b12.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 13){
					Surface = IMG_Load("assets/images/b13.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 14){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 15){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

		}else if(mode_player[1] == '9'){

			if(cont_ball[units] >= 9 && x[units] != 0 && y[units] != 0){

				cont_p++;
				
				if(cont_ball[units] == 9){
					Surface = IMG_Load("assets/images/b9.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 10){
					Surface = IMG_Load("assets/images/b10.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 11){
					Surface = IMG_Load("assets/images/b11.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 12){
					Surface = IMG_Load("assets/images/b12.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 13){
					Surface = IMG_Load("assets/images/b13.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 14){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 15){
					Surface = IMG_Load("assets/images/b14.png");
					Texture_rect.x = 60+15*cont_p;
					Texture_rect.y = 470;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}

			if(cont_ball[units] <= 7 && x[units] != 0 && y[units] != 0){

				cont_m++;

				if(cont_ball[units] == 1){
					Surface = IMG_Load("assets/images/b1.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 2){
					Surface = IMG_Load("assets/images/b2.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 3){
					Surface = IMG_Load("assets/images/b3.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 4){
					Surface = IMG_Load("assets/images/b4.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 5){
					Surface = IMG_Load("assets/images/b5.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 6){
					Surface = IMG_Load("assets/images/b6.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}else if(cont_ball[units] == 7){
					Surface = IMG_Load("assets/images/b7.png");
					Texture_rect.x = 60+15*cont_m;
					Texture_rect.y = 488;

					Texture = SDL_CreateTextureFromSurface(rendImg, Surface);
					SDL_FreeSurface(Surface);

					SDL_RenderCopyEx(rendImg, Texture, NULL, &Texture_rect, deg, NULL, flip_x);
					SDL_DestroyTexture(Texture);
				}
			}
		}

		units++;
	}
}