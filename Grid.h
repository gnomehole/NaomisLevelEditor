#pragma once
#include "Tile.h"
#include "Game.h"


class Grid : public Tile : public GameClass
{
	
	public:

		const static int x = 30;
		const static int y = 20;
		const int windowWidth = 1025;
		const int windowHeight = 650;
		sf::Vector2f worldPos;

		Tile** tile = new Tile* [x];
		void save(Tile** inctile);
		void load(Tile** inctile);
		
		Grid();
		
};