#include "Game.h"


using namespace std;

GameClass::GameClass() {
	
	//setup window size
	const int gwindowWidth = 1025;
	const int gwindowHeight = 650;
	gravity = 0.5;
	friction = 10.0f;

	Tile tile[x][y];

	void save(Tile inctile[x][y]);
	void load(Tile inctile[x][y]);
}
//void GameClass::LoadLevel(string levelName, Tile inctile[x][y])
//{
//	string line;
//	ifstream myfile("save.sav");
//	if (myfile.is_open())
//	{
//		int a = 0;
//		int b = 0;
//		string saveHold;
//		while (getline(myfile, line))
//		{
//			if (b == 0)
//			{
//				cout << "Loading Tiles \n";
//			}
//			if (b < x)
//			{
//				for (int i = 0; i < line.size(); i++)
//				{
//					switch (line[i])
//					{
//					case ',':
//						a += 1;
//						break;
//					case '0':
//						inctile[b][a].ChangeType(inctile[a][b].Type::Sky);
//						break;
//					case '1':
//						inctile[b][a].ChangeType(inctile[a][b].Type::Platform);
//						break;
//					case '2':
//						inctile[b][a].ChangeType(inctile[a][b].Type::Lava);
//						break;
//					}
//					inctile[b][a].refreshTile();
//				}
//			}
//			else if (b >= x)
//			{
//				//check the first two letter on lines after the tiles are loaded
//				//this is where we begin loading actors
//				string lineHold = line;
//				int curStart;
//				int curEnd = 0;
//				string posString;
//				if (line[0] == 'C' && line[1] == 'o')
//				{
//					cout << "Loading Coins \n";
//					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
//					{
//						curStart = lineHold.find('(');
//						curEnd = lineHold.find(')');
//
//						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
//						cout << "Loaded Coin at: " << posString << "\n";
//						string xStr = posString.substr(0, posString.find(','));
//						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
//						cout << "x = " << xStr << ", y = " << yStr << "\n";
//						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Coin);
//
//						lineHold[curStart] = '<';
//						lineHold[curEnd] = '>';
//					}
//				}
//				else if (line[0] == 'E' && line[1] == 'n')
//				{
//					cout << "Loading Enemies \n";
//					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
//					{
//						curStart = lineHold.find('(');
//						curEnd = lineHold.find(')');
//
//						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
//						cout << "Loaded Enemy at: " << posString << "\n";
//						string xStr = posString.substr(0, posString.find(','));
//						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
//						cout << "x = " << xStr << ", y = " << yStr << "\n";
//						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Enemy);
//
//						lineHold[curStart] = '<';
//						lineHold[curEnd] = '>';
//					}
//				}
//				else if (line[0] == 'T' && line[1] == 'r')
//				{
//					cout << "Loading Traps \n";
//					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
//					{
//						curStart = lineHold.find('(');
//						curEnd = lineHold.find(')');
//
//						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
//						cout << "Loaded Trap at: " << posString << "\n";
//						string xStr = posString.substr(0, posString.find(','));
//						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
//						cout << "x = " << xStr << ", y = " << yStr << "\n";
//						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Trap);
//
//						lineHold[curStart] = '<';
//						lineHold[curEnd] = '>';
//					}
//				}
//				else if (line[0] == 'E' && line[1] == 'x')
//				{
//					cout << "Loading Exit \n";
//					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
//					{
//						curStart = lineHold.find('(');
//						curEnd = lineHold.find(')');
//
//						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
//						cout << "Loaded Exit at: " << posString << "\n";
//						string xStr = posString.substr(0, posString.find(','));
//						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
//						cout << "x = " << xStr << ", y = " << yStr << "\n";
//						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Exit);
//
//						lineHold[curStart] = '<';
//						lineHold[curEnd] = '>';
//					}
//				}
//				else if (line[0] == 'P' && line[1] == 'l')
//				{
//					cout << "Loading Player \n";
//					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
//					{
//						curStart = lineHold.find('(');
//						curEnd = lineHold.find(')');
//
//						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
//						cout << "Loaded Player at: " << posString << "\n";
//						string xStr = posString.substr(0, posString.find(','));
//						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
//						cout << "x = " << xStr << ", y = " << yStr << "\n";
//						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Player);
//
//						lineHold[curStart] = '<';
//						lineHold[curEnd] = '>';
//					}
//				}
//			}
//			b += 1;
//			a = 0;
//		}
//		myfile.close();
//		cout << "File Loaded \n";
//	}
//	else
//	{
//		cout << "Unable to open file \n";
//	}
//}



Collision Player::CollisionCheck(sf::Vector2f otherPos, float otherRadius)
{
	Collision col;
	float deltaX = (nextPos.x + radius) - (otherPos.x + otherRadius);
	float deltaY = (nextPos.y + radius) - (otherPos.y + otherRadius);

	float intersectX = abs(deltaX) - (otherRadius + radius);
	float intersectY = abs(deltaY) - (otherRadius + radius);

	float xDist = abs(nextPos.x - otherPos.x);
	float yDist = abs(nextPos.y - otherPos.y);
	float distance = sqrt(xDist * xDist + yDist * yDist);


	

	col.hit = (distance < radius + otherRadius);
	//col.hit = (intersectX)
	if (col.hit)
	{
		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				col.dir = sf::Vector2f(intersectX, 0.0f);
			}
			else
			{
				col.dir = sf::Vector2f(-intersectX, 0.0f);
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				col.dir = sf::Vector2f(0.0f, intersectY);
			}
			else
			{
				col.dir = sf::Vector2f(0.0f, -intersectY);
			}
		}
	}
	else
	{
		col.dir = sf::Vector2f(0.0f, 0.0f);
	}
	return	col;
}





/*
moving right 
player.velocity.x += player.speed * deltaTime;

use -player.speed to move the opposite direction 

if (!player.vel;ocity.y <1.0f)
{
	player.velocity.y = -gravity * delta
}
{
player.velocity.y += -gravity * 
}

friction!!

if(player.grounded)
{

if (abs(player.velocity.x) > 0.01f)
{
player.velocity.x -= friction * deltaTime;

}
}


*/

Player::Player() {
	lives = 3;
	coins = 0;
	isDead = false;
	// this is just used to see if the player can jump or not
	grounded = false;
	// this is a base value used to base the players acceleration off of.
	speed = 2.5f;
	// this is the same thing but for jumping.
	jumpSpeed = 0.42f;
	//this value is used for detecting collisions.
	radius = 16;
	// this is used to give the player character smooth physics.
	velocity = sf::Vector2f(0, 0);
}

void Player::Refresh()
{
	Actor::RefreshActor();
	velocity = sf::Vector2f(0.0f, 0.0f);
	nextPos = getPosition();
}

