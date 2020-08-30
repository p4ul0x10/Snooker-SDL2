void loadMesa(SDL_Renderer *renderer)
{
	SDL_Surface *image_mesa = IMG_Load("assets/images/mesa-edt.png");

	SDL_Texture *texture_mesa = SDL_CreateTextureFromSurface(renderer, image_mesa);
	SDL_FreeSurface(image_mesa);

	SDL_Rect image_mesa_rect;
	image_mesa_rect.w = 900;
	image_mesa_rect.h = 540;
	image_mesa_rect.x = 0;
	image_mesa_rect.y = 0;
	SDL_RenderCopy(renderer, texture_mesa, NULL, &image_mesa_rect);
    SDL_DestroyTexture(texture_mesa);
}

void bolaBranca(SDL_Renderer *renderer, float x, float y)
{
	SDL_Surface *image_branca = IMG_Load("assets/images/bm.png");

	SDL_Texture *texture_branca = SDL_CreateTextureFromSurface(renderer, image_branca);
	SDL_FreeSurface(image_branca);


	SDL_Rect image_branca_rect;
	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;

	SDL_RenderCopy(renderer, texture_branca, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_branca);
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

	SDL_Texture *texture_play = SDL_CreateTextureFromSurface(rendPlay, image_branca);
	SDL_FreeSurface(image_branca);

	SDL_Rect image_branca_rect;

	image_branca_rect.w = 20;
	image_branca_rect.h = 20;
	image_branca_rect.x = x;
	image_branca_rect.y = y;
	SDL_RenderCopy(rendPlay, texture_play, NULL, &image_branca_rect);
	SDL_DestroyTexture(texture_play);
}


void rendMiraDest(SDL_Renderer *rendDest, float mouseX, float mouseY){


    SDL_Surface *image_Dest = IMG_Load("assets/images/bm_dest.png");

	SDL_Texture *texture_mira = SDL_CreateTextureFromSurface(rendDest, image_Dest);
	SDL_FreeSurface(image_Dest);

	SDL_Rect image_Dest_rect;

	image_Dest_rect.w = 20;
	image_Dest_rect.h = 20;
	image_Dest_rect.x = mouseX;
	image_Dest_rect.y = mouseY;
	SDL_RenderCopy(rendDest, texture_mira, NULL, &image_Dest_rect);
    SDL_DestroyTexture(texture_mira);
}
