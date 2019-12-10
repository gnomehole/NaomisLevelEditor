#pragma once
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include <iostream>
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
		target.draw(actor, states);
		//std::cout << "are tiles drawing?";
	}

	enum Type
	{
		Sky,
		Platform,
		Lava
	};
	Actor actor;
	//setting our tile to be sky
	Type type;
	//sf::RectangleShape shape;
	sf::Sprite sprite;
	sf::FloatRect rBounds;

	//define textures
	sf::Texture blockSkyTexture;
	sf::Texture blockPlatformTexture;
	sf::Texture blockLavaTexture;

	void init(int x, int y);
	void loadTextures();

	bool mouseOver(sf::Vector2f windPos);

	void refreshTile();
	//direct call to change actor 
	//saves time as we'll use tile.changeactor instead of tile.actor.changeactor
	void ChangeActor(Actor::Type a);
	void ChangeType(Type t);
};

