#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

#include <iostream>


using namespace std;


/******************d�claration des vconstantesL******/


const int WINDOWS_W = 640;
const int WINDOWS_H = 470;



// v�rifie si les rectangles de positions se touchent
bool Collision_Rect(SDL_Rect posa, SDL_Rect posb)
{
	if (posa.x + posa.w < posb.x)	return false;	//non
	if (posa.x > posb.x + posb.w)	return false;

	if (posa.y + posa.h < posb.y)	return false;
	if (posa.y > posb.y + posb.h)	return false;

	return true;				//il y a  collission
}






int main(int argc, char** argv)
{
	// creation de la fenetre et du rendu et de l'event pour les touches

	SDL_Event event;  // pour d�celer un ev�nement
	SDL_Window* fenetre = NULL; // d�claration du pointeur de fenetre
	SDL_Renderer* renderer = NULL;

	/******************initialisation des compososant SDL******/
	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "�chec de l'initialisation de la SDL " << SDL_GetError();
		system("pause");
		return -1;
	}


	/* Cr�ation de la fen�tre */

	fenetre = SDL_CreateWindow("NOM DE LA FENETRE ICI", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WINDOWS_W, WINDOWS_H, SDL_WINDOW_SHOWN);

	if (fenetre == NULL)

	{
		cout << "Erreur de cr�ation de la fen�tre: " << SDL_GetError();
		system("pause");
	}

	renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)

	{
		cout << "Erreur de cr�ation du render: " << SDL_GetError();
		system("pause");
		return EXIT_FAILURE;
	}




	int frame = 0;



	bool quit = false;

	bool m_touches[SDL_NUM_SCANCODES];


	// Initialisation du tableau m_touches[]

	for (int i(0); i < SDL_NUM_SCANCODES; i++)
		m_touches[i] = false;


	while (quit == false)
	{
		// place � true toutes les touches enfonc�es et � false les touches relach�es
		//*****************rien � faire dans cette boucle ********* voir en dessous les if
		while (SDL_PollEvent(&event))
		{
			//Si une touche a ete pressee 
			switch (event.type)
			{
			case SDL_KEYDOWN:
				m_touches[event.key.keysym.scancode] = true; // place cette touche � true
				break;										// la vitesse sera ajust�e dans les if plus bas


															// Cas d'une touche rel�ch�e on replace � 0 la vitesse

			case SDL_KEYUP:
				m_touches[event.key.keysym.scancode] = false;// place cette touche � false
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_UP:
					break;
				case SDL_SCANCODE_DOWN:
					break;
				case SDL_SCANCODE_LEFT:
					break;
				case SDL_SCANCODE_RIGHT:
					break;
				default: break;
				}
				break;

				// Cas de la fermeture de la fen�tre

			case SDL_WINDOWEVENT:

				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
					quit = true;

				break;


			default:
				break;
			}

		}// fin while pollevent  VOTRE TRAVAIL COMMMENCE ICI



		//** pr�sentation de l'�cran et pause pour voir l'image (rien � faire ici)
		SDL_RenderPresent(renderer);
		SDL_Delay(100);//pause 
					   //*****

					   // fin de boucle quit==false. On retourne au d�but de boucle


	}
	// Destruction du renderer, de la fen�tre et des images : (rien � faire ici)
	try {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
		SDL_DestroyWindow(fenetre);
		fenetre = NULL;

		/// TODO : Ajouter les appels pour la lib�ration de la m�moire



	}
	catch (exception ee)
	{

	}
	// quitter SDL
	SDL_Quit();




	return 0;
}
