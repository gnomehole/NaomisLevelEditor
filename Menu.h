#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
#include "Button.h"
//#include "arial.h"



class MenuScreen : public Button
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(LoadEditor, states);
		target.draw(circle, states);
		std::cout << "menu is drawing";
	}
public:
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

	bool Start();
	int Update();
	sf::Vector2f worldPos;
	sf::View MenuView;
	sf::RenderWindow mWindow;





};




