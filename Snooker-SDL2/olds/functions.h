void loadMesa(SDL_Renderer *renderer)
{
	SDL_Surface *image_mesa = IMG_Load("assets/images/mesa-edt.png");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image_mesa);
	SDL_FreeSurface(image_mesa);

	SDL_Rect image_mesa_rect;
	image_mesa_rect.w = 900;
	image_mesa_rect.h = 540;
	image_mesa_rect.x = 0;
	image_mesa_rect.y = 0;
	SDL_RenderCopy(renderer, texture, NULL, &image_mesa_rect);
}

void loadTriangulo(SDL_Renderer *rendTri, bool status_tri){

	int vetN[15], vetX[15], vetY[15], vetP[7], vetI[8], vB;
	//start triangulo inicial
    SDL_Surface *triImg = IMG_Load("assets/images/b1.jpeg");
	SDL_Texture *texture_b = SDL_CreateTextureFromSurface(rendTri, triImg);
	SDL_FreeSurface(triImg);
	SDL_Rect triImg_rect;
	triImg_rect.w = 20;
	triImg_rect.h = 20;
	triImg_rect.y = 217.5;
	triImg_rect.x = 600;
	//end triangulo inicial
    if(status_tri == false){

		for(vB = 0; vB < 15; vB++){

			vetN[vB] = vB; //vetor numero total bolas
			if(vB == 0){
				SDL_Surface *triImg = IMG_Load("assets/images/b1.png");
				SDL_Texture *texture_b = SDL_CreateTextureFromSurface(rendTri, triImg);
				SDL_FreeSurface(triImg);
				SDL_RenderCopy(rendTri, texture_b, NULL, &triImg_rect);
				vetX[vB] = triImg_rect.x; //vetor x pos
				vetY[vB] = triImg_rect.y; //vetor y pos
				vetI[vB] = vB+1; //vetor bolas impar
			}else if(vB > 0 && vB < 3){

				if(vB == 1){

					triImg_rect.y = 205;
					triImg_rect.x += 20;
					SDL_Surface *image_b2 = IMG_Load("assets/images/b2.png");
					SDL_Texture *texture_b2 = SDL_CreateTextureFromSurface(rendTri, image_b2);
					SDL_FreeSurface(image_b2);
					SDL_RenderCopy(rendTri, texture_b2, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 2){

					triImg_rect.y = 230;
					SDL_Surface *image_b3 = IMG_Load("assets/images/b3.png");
					SDL_Texture *texture_b3 = SDL_CreateTextureFromSurface(rendTri, image_b3);
					SDL_FreeSurface(image_b3);
					SDL_RenderCopy(rendTri, texture_b3, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}

			}else if(vB > 2 && vB <= 5){

				if(vB == 3){

					triImg_rect.y = 192.5;
					triImg_rect.x += 20;
					SDL_Surface *image_b4 = IMG_Load("assets/images/b4.png");
					SDL_Texture *texture_b4 = SDL_CreateTextureFromSurface(rendTri, image_b4);
					SDL_FreeSurface(image_b4);
					SDL_RenderCopy(rendTri, texture_b4, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 4){

					triImg_rect.y = 217.5;
					SDL_Surface *image_b5 = IMG_Load("assets/images/b5.png");
					SDL_Texture *texture_b5 = SDL_CreateTextureFromSurface(rendTri, image_b5);
					SDL_FreeSurface(image_b5);
					SDL_RenderCopy(rendTri, texture_b5, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 5){

					triImg_rect.y = 242.5;
					SDL_Surface *image_b6 = IMG_Load("assets/images/b6.png");
					SDL_Texture *texture_b6 = SDL_CreateTextureFromSurface(rendTri, image_b6);
					SDL_FreeSurface(image_b6);
					SDL_RenderCopy(rendTri, texture_b6, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}

			}else if(vB > 5 && vB < 10){

				if(vB == 6){

					triImg_rect.y = 180;
					triImg_rect.x += 20;
					SDL_Surface *image_b7 = IMG_Load("assets/images/b7.png");
					SDL_Texture *texture_b7 = SDL_CreateTextureFromSurface(rendTri, image_b7);
					SDL_FreeSurface(image_b7);
					SDL_RenderCopy(rendTri, texture_b7, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 7){
					triImg_rect.y = 205;
					SDL_Surface *image_b8 = IMG_Load("assets/images/b8.png");
					SDL_Texture *texture_b8 = SDL_CreateTextureFromSurface(rendTri, image_b8);
					SDL_FreeSurface(image_b8);
					SDL_RenderCopy(rendTri, texture_b8, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 8){
					triImg_rect.y = 230;
					SDL_Surface *image_b9 = IMG_Load("assets/images/b9.png");
					SDL_Texture *texture_b9 = SDL_CreateTextureFromSurface(rendTri, image_b9);
					SDL_FreeSurface(image_b9);
					SDL_RenderCopy(rendTri, texture_b9, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 9){
					triImg_rect.y = 255;
					SDL_Surface *image_b6 = IMG_Load("assets/images/b10.png");
					SDL_Texture *texture_b6 = SDL_CreateTextureFromSurface(rendTri, image_b6);
					SDL_FreeSurface(image_b6);
					SDL_RenderCopy(rendTri, texture_b6, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}

			}else{

				if(vB == 10){
					triImg_rect.y = 167.5;
					triImg_rect.x += 20;
					SDL_Surface *image_b11 = IMG_Load("assets/images/b11.png");
					SDL_Texture *texture_b11 = SDL_CreateTextureFromSurface(rendTri, image_b11);
					SDL_FreeSurface(image_b11);
					SDL_RenderCopy(rendTri, texture_b11, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 11){
					triImg_rect.y = 192.5;
					SDL_Surface *image_b12 = IMG_Load("assets/images/b12.png");
					SDL_Texture *texture_b12 = SDL_CreateTextureFromSurface(rendTri, image_b12);
					SDL_FreeSurface(image_b12);
					SDL_RenderCopy(rendTri, texture_b12, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 12){
					triImg_rect.y = 217.5;
					SDL_Surface *image_b7 = IMG_Load("assets/images/b13.png");
					SDL_Texture *texture_b7 = SDL_CreateTextureFromSurface(rendTri, image_b7);
					SDL_FreeSurface(image_b7);
					SDL_RenderCopy(rendTri, texture_b7, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}else if(vB == 13){
					triImg_rect.y = 242.5;
					SDL_Surface *image_b7 = IMG_Load("assets/images/b14.png");
					SDL_Texture *texture_b7 = SDL_CreateTextureFromSurface(rendTri, image_b7);
					SDL_FreeSurface(image_b7);
					SDL_RenderCopy(rendTri, texture_b7, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetP[vB] = vB+1; //vetor bolas par
				}else if(vB == 14){
					triImg_rect.y = 267.5;
					SDL_Surface *image_b7 = IMG_Load("assets/images/b15.png");
					SDL_Texture *texture_b7 = SDL_CreateTextureFromSurface(rendTri, image_b7);
					SDL_FreeSurface(image_b7);
					SDL_RenderCopy(rendTri, texture_b7, NULL, &triImg_rect);
					vetX[vB] = triImg_rect.x; //vetor x pos
					vetY[vB] = triImg_rect.y; //vetor y pos
					vetI[vB] = vB+1; //vetor bolas impar
				}
			}
		}
	}
}

void bolaBranca(SDL_Renderer *renderer, int x, int y, int deg)
{
	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;
	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;

	SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(renderer, texture, NULL, &image_branca_rect, 0, NULL, flip);
}

/*void genMira(SDL_Renderer *rendMira, int x, int y, int pos_taco, int typeP, int bx)
{
	int addPx = 0, limitPx, limitP1, restX, divALInt;
	float vx, vy, divAL, divLA, auxpx, incPx, divDf;
	vx = bx + 10;
	vy = y;

	if (pos_taco == 1 || pos_taco == 4)
	{
		if (pos_taco == 1)
		{
			limitPx = y - 50; //rest calc
		}
		else
		{
			limitPx = 340 - y;
		}
		x += 10;
		if (x > bx)
		{
			restX = x - bx; //distancia
		}
		else
		{
			restX = bx - x;
		}
		divLA = restX - limitPx; //dst - alt
		divAL = limitPx / restX; //div alt x dst
		divALInt = limitPx / restX;
		incPx = limitPx / divAL; //div alt x px
		divDf = limitPx - restX; //alt - dst
		SDL_SetRenderDrawColor(rendMira, 255, 255, 255, 1);

		if (divALInt % 2 != 0 && divAL != 1 && divAL >= 1)
		{
			auxpx = divAL / limitPx;
			auxpx *= divDf;
			auxpx *= incPx;
			//	incPx += auxpx;
		}
		while (addPx < incPx)
		{
			if (divAL >= 1 && divAL < 2)
			{
				if (divALInt % 2 != 0)
				{
					if (x > bx)
					{
						if (addPx % divALInt == 0)
						{
							if (pos_taco == 1)
							{
								vy -= divALInt;
								vx += divAL;
							}
							else
							{
								vy += divALInt;
								vx -= divAL;
							}
						}
					}
					else
					{
						if (addPx % divALInt == 0)
						{
							if (pos_taco == 1)
							{
								vy -= divALInt;
								vx -= divAL;
							}
							else
							{
								vy += divALInt;
								vx -= divAL;
							}
						}
					}
				}
			}
			else
			{
				if (x > bx)
				{
					if (addPx > 1 && addPx % divALInt == 0)
					{
						if (pos_taco == 1)
						{
							vy -= divALInt;
							vx += 1;
						}
						else
						{
							vy += divALInt;
							vx -= 1;
						}
					}
				}
				else
				{
					if (addPx > 1 && addPx % divALInt == 0)
					{
						if (pos_taco == 1)
						{
							vy -= divALInt;
							vx -= 1;
						}
						else
						{
							vy += divALInt;
							vx += 1;
						}
					}
				}
			}

			SDL_Rect pxxx_rect;
			pxxx_rect.w = 4;
			pxxx_rect.h = 4;
			pxxx_rect.x = vx;
			pxxx_rect.y = vy;

			SDL_RenderDrawRect(rendMira, &pxxx_rect);
			SDL_RenderFillRect(rendMira, &pxxx_rect);
			addPx++;
		}
	}
	else if (pos_taco == 2 || pos_taco == 3)
	{
	}
}*/

void posTaco(SDL_Renderer *rendTaco, float x, float y, int deg, float mAng, float angInc, float mouseX, float mouseY)
{
	SDL_Surface *image_taco = IMG_Load("assets/images/taco.png");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(rendTaco, image_taco);
	SDL_FreeSurface(image_taco);

	if (mAng != 0)
	{

		if (angInc <= 90)
		{

	  	x = x;
	  	y = y;

		}
		else if (angInc > 90 && angInc <= 180)
		{
			x = x;
			y = y;
		}
		else if (angInc > 180 && angInc <= 270)
		{
			x = x;
			y = y;

		}
		else if (angInc > 270 && angInc <= 360)
		{
			x = x;
			y = y;

		}
	}

	SDL_Rect image_taco_rect;
	image_taco_rect.w = 6;
	image_taco_rect.h = 400;
	image_taco_rect.x = x;
	image_taco_rect.y = y;
	SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(rendTaco, texture, NULL, &image_taco_rect, deg, NULL, flip);
}

void rendFor(SDL_Renderer *rendForca, int f)
{
	SDL_SetRenderDrawColor(rendForca, 255, 255, 255, 1);

	int forca = 0, conty, y = 455, add_b = 5;

	if(f > 0){
		for (forca = 0; forca < f; forca++)
		{
			y += add_b;
			SDL_Rect f_rect;

			f_rect.w = 30;
			f_rect.h = 7;
			f_rect.x = 810;
			f_rect.y = y;

			SDL_RenderDrawRect(rendForca, &f_rect);
			SDL_RenderFillRect(rendForca, &f_rect);

		}
	}
}

void playJogada(SDL_Renderer *rendPlay, int x, int y, int deg_cont)
{
	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(rendPlay, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;

	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;
	SDL_RenderCopy(rendPlay, texture, NULL, &image_branca_rect);
}


void rendMiraDest(SDL_Renderer *rendDest, float mouseX, float mouseY){


    SDL_Surface *image_Dest = IMG_Load("assets/images/bm_dest.png");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(rendDest, image_Dest);
	SDL_FreeSurface(image_Dest);

	SDL_Rect image_Dest_rect;

	image_Dest_rect.w = 20;
	image_Dest_rect.h = 20;
	image_Dest_rect.x = mouseX;
	image_Dest_rect.y = mouseY;
	SDL_RenderCopy(rendDest, texture, NULL, &image_Dest_rect);

}
