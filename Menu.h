#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
//#include "arial.h"




class Menubuttons
{

};

class MenuClass
{

public: 
	std:: string debug;
	const int windowWidth = 1080;
	const int windowHeight = 720;

	bool Start();
	int Update();
	sf::Vector2f worldPos;
	sf::View MenuView;
	sf::RenderWindow Window;





};



