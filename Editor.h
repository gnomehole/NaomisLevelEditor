#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Tile.h"
#include "Grid.h"

using namespace std;


//Our tile class, it's drawable and has a transform

class ToolPanel : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(loadButton, states);
		target.draw(saveButton, states);
	}
public:
	Button loadButton;
	Button saveButton;
	//Init
	ToolPanel();
};
class EditorClass: public Grid
{
public:
	EditorClass();
	//Track if we are painting with actor or tile
	bool actorNotTile;
	//setup window size
	const int windowWidth = 1025;
	const int windowHeight = 650;

	//Mouse pos
	sf::Vector2f worldPos;
	sf::View toolsView;
	sf::View levelEditView;
	sf::RenderWindow window;
	//set up variable to track selected tile
	Tile::Type curTileType;
	Actor::Type curActorType;
	//setup space for our tool bar
	ToolPanel tools;
	//Set up tiles to select and paint with
	Tile tileButton[9];

	bool Start();
	int Update();

	//printing out the tiles
	void printToConsole(Tile inctile[x][y]);
};