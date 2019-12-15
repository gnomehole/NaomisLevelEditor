#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
#include "Button.h"
//#include "Game.h"
//#include "arial.h"



class MenuScreen : public Button
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(LoadEditor, states);
		target.draw(LoadGame, states);
		target.draw(circle, states);
		//std::cout << "menu is drawing";
	}
public:
	Button LoadGame;
	Button LoadEditor;
	Button circle;
	//Init
	MenuScreen();
};

class MenuClass 
{

public: 
	int	mWindowWidth;
	int	mWindowHeight;
	MenuScreen	mScreen;
	std:: string debug;

	//GameClass Gtype;
	//using this int to change the enum in the gamestate class when we click on buttons in the menu
	int mInt;

	bool Start();
	int Update();

	bool WannaGoToGame;
	bool WannaGoToEditor;

	void ChangeGameTypetoGame();
	//int ChangeGameTypetoEditor;
	sf::Vector2f worldPos;
	sf::View MenuView;
	sf::RenderWindow mWindow;

	bool GWannaGotoMenu;

	MenuClass();



};




