#include <iostream>
#include "SDL/include/SDL.h"
#pragma comment (lib, "SDL/SDL2main.lib")
#pragma comment (lib, "SDL/SDL2.lib")
using namespace std;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) //if SDL initializes correctly, it returns a 0. If it doesn't, it returns a 1.
	{
		SDL_Log("SDL was unable to iniatialize because %s", SDL_GetError()); //SDL_Log is like a print_f, and SDL_GetError gives the error of why that happens
		return 1; // to finish the program.
	}

	SDL_Window *window = SDL_CreateWindow("windowtest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 620, 480, 0); //PREGUNTA:::: perque 0? que fa SDL_WINDOW_OPENGL? (estava en el codi d'exemple)
	//PREGUNTA::::perque el punter ha de ser de class SDL_Window? que fa aquest punter?
	if (window == NULL)
	{
		SDL_Log("Window was unable to be created because %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0); //Aquí crea el renderer. 
	if (renderer == NULL)
	{
		SDL_Log("Renderer was unable to be created because %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}
	

	//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);  //triar el color amb el que es farà l'acció (rgb)
	//SDL_RenderClear(renderer); //pinta la pantalla sencera del color que hem seleccionat
	//SDL_RenderPresent(renderer); //fins ara tots els canvis s'estavan fent a la "reraguarda", això actualitza el renderer i ho mostra


	int moveright = 1;
	

	SDL_Rect rectangle;
	rectangle.x = 200; //posicio de X
	rectangle.y = 170; //posicio de Y
	rectangle.w = 150; //width del rectangle
	rectangle.h = 100; //height del rectangle

	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//SDL_RenderFillRect(renderer, &rectangle); //Aixo rellena el nostre rectangle en el renderer //PREGUNTA::::perque fica &rectangle?
	//SDL_RenderPresent(renderer); //torna a actualitzar els canvis que haviem realitzat.

	while (1) //aixo es el loop dels frames
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); //selecciona el color blau
		SDL_RenderClear(renderer); //fica els fons de color blau
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //selecciona el color vermell

		if (rectangle.x > 620)
		{
			moveright = 0;
		}
		if (rectangle.x < 0)
		{
			moveright = 1;
		}

		if (moveright == 1)
		{
			rectangle.x++;
		}
		if (moveright == 0)
		{
			rectangle.x--;
		}
		
		SDL_RenderFillRect(renderer, &rectangle); //omple el rectangle de color vermell
		SDL_RenderPresent(renderer); //actualitza el renderer

	}

	SDL_DestroyRenderer(renderer); //destruir el renderer per estalviar memoria suposo
	SDL_DestroyWindow(window); //destruir la finestra
	SDL_Quit(); //to quit SDL
	return 0;
}
