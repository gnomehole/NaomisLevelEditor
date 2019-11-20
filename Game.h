#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>


using namespace std;

struct Collision
{
	bool hit;
	sf::Vector2f dir;
};

class Player
{
	public:
	//basic infor
	int lives = 3;
	bool isDead = false;
	int coins = 0;

	sf::FloatRect nextRect;

	sf::Vector2f nextPos;

	sf::Vector2f velocity;

	bool grounded;
	float speed;
	float jumpspeed;
	float radius;
	Collision CollisionCheck(sf::Vector2f otherPos, float otherRadius);
	void Refresh();


};

class Enemy
{
public:
	bool isDead = false;
	//what it looks like
	//collision (based off sf::sprite)

};

class GameClass
{
public:
	bool Start();
	int Update();

	//saving a number to a file should be able to apply the same logic i did with save tiles 
	void SaveScore();
	void ResetLevel();
	//throw to a game over screen and quit program on button press
	void GameOver();

};