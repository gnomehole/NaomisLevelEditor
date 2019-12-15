//#pragma once
#include "Menu.h"
#include "Editor.h"
#include "Game.h"

class GameState : MenuClass, EditorClass, GameClass
{
	//does this need to be at the end? idk

public:
	bool Start();

	int Update();

//	bool running;

	EditorClass EditorMode;
	GameClass MyGameMode;
	MenuClass MenuMode;
	
	enum GameType
	{
		Menu,
		Editor,
		Game,
		//	Loader
	};

	GameType myGameType;

	//ok so when i was calling it here it wouldn't let me make an object of the gamestate in main. 
	GameState();

};
