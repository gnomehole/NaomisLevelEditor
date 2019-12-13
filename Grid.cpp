#pragma once
#include "Actor.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <list> 	
#include "Grid.h"

using namespace std;

Grid::Grid()
{
	for (int i = 0; i < x; i++)
	{
		tile[i] = new Tile[y];
	}

}

void Actor::loadTextures()
{
	if (!blankTexture.loadFromFile("SpritesPlatformer/None.png"))
	{
		cout << "Failed to load None.png";
	}
	if (!coinTexture.loadFromFile("SpritesPlatformer/Coin.png"))
	{
		cout << "Failed to load Coin.png";
	}
	if (!doorTexture.loadFromFile("SpritesPlatformer/Door.png"))
	{
		cout << "Failed to load Door.png";
	}
	if (!enemyAliveTexture.loadFromFile("SpritesPlatformer/EnemyAlive.png"))
	{
		cout << "Failed to load EnemyAlive.png";
	}
	if (!enemyDeadTexture.loadFromFile("SpritesPlatformer/EnemyDead.png"))
	{
		cout << "Failed to load EnemyDead.png";
	}
	if (!playerTexture.loadFromFile("SpritesPlatformer/Player.png"))
	{
		cout << "Failed to load Player.png";
	}
	if (!trapTexture.loadFromFile("SpritesPlatformer/Trap.png"))
	{
		cout << "Failed to load Trap.png";
	}
}

void Actor::init(int x, int y)
{
	loadTextures();
	sprite.setPosition(x, y);
	RefreshActor();
}

//not sure if I need to redefine this again? when i use refresh actor
//in the game.cpp i hope it uses the function as its defined here 
void Actor::RefreshActor()
{
	switch (type)
	{
	case Player:
		sprite.setTexture(playerTexture);
		break;
	case Enemy:
		sprite.setTexture(enemyAliveTexture);
		break;
	case Coin:
		sprite.setTexture(coinTexture);
		break;
	case Exit:
		sprite.setTexture(doorTexture);
		break;
	case Trap:
		sprite.setTexture(trapTexture);
		break;
	case None:
		sprite.setTexture(blankTexture);
		break;
	default:
		sprite.setTexture(blankTexture);
		break;
	}
}

void Actor::ChangeActor(Type t)
{
	type = t;
	RefreshActor();
}


void Tile::init(int x, int y)
{
	//load the textures
	loadTextures();
	//set the position of this tile's sprite
	sprite.setPosition(x, y);
	actor.init(x, y);
	refreshTile();
}

void Tile::loadTextures()
{
	if (!blockSkyTexture.loadFromFile("SpritesPlatformer/BlockSky.png"))
	{
		cout << "failed to load BlockSky.png";
	}
	if (!blockPlatformTexture.loadFromFile("SpritesPlatformer/BlockPlatform.png"))
	{
		cout << "failed to load BlockPlatform.png";
	}
	if (!blockLavaTexture.loadFromFile("SpritesPlatformer/BlockLava.png"))
	{
		cout << "failed to load BlockLava.png";
	}
}

bool Tile::mouseOver(sf::Vector2f windPos)
{
	rBounds = sprite.getGlobalBounds();
	if (rBounds.contains(windPos.x, windPos.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tile::refreshTile()
{
	switch (type)
	{
	case Type::Sky:
		sprite.setTexture(blockSkyTexture);
		break;
	case Type::Platform:
		sprite.setTexture(blockPlatformTexture);
		break;
	case Type::Lava:
		sprite.setTexture(blockLavaTexture);
		break;
	}
	actor.RefreshActor();
}

void Tile::ChangeActor(Actor::Type a)
{
	actor.ChangeActor(a);
}


