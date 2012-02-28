#ifndef EVENTS_H
#define EVENTS_H
#include "SDL.h"
#include "Movement.h"
#include "Inventory.h"

class Events
{
	public:
		Events();
		void gameEvents(SDL_Event &event,Movement &move,Inventory &i);
		bool getGameState();
	private:
		bool gameRunning;
};



#endif