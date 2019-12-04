#pragma once
#include "Tile.h"


class Grid
{
	
	public:
		static const int x = 30;
		static const int y = 20;
		Tile tile[x][y];
		void save(Tile inctile[x][y]);
		void load(Tile inctile[x][y]);
};