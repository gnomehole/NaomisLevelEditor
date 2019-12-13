#include "Game.h"


using namespace std;

GameClass::GameClass() {
	
	//setup window size
	//GWannaGotoMenu = true;
	gravity = 3.0f;
	friction = 1.5f;

	//grid.setPosition(0, 0);


	//save(Tile inctile[x][y]);
	//load(Tile inctile[x][y]);
}
//void GameClass::LoadLevel()
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



Collision Player::CollisionCheck(sf::FloatRect other)
{
	Collision col;
	float deltaX = (nextPos.x - (nextRect.width / 2)) - (other.left - other.width / 2);
	float deltaY = (nextPos.y - (nextRect.width / 2)) - (other.top - other.height / 2);

	float intersectX = abs(deltaX) - ((other.width / 2) + (nextRect.width / 2));
	float intersectY = abs(deltaY) - ((other.height / 2) + (nextRect.height / 2));

	col.hit = (intersectX < 0.0f && intersectY < 0.0f);

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

Player::Player() {
	lives = 3;
	coins = 0;
	isDead = false;
	
	// this is just used to see if the player can jump or not
	//grounded = true;
	// this is a base value used to base the players acceleration off of.
	speed = 2.5f;
	// this is the same thing but for jumping.
	jumpSpeed = 0.45f;
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

sf::Vector2f Player::getPosition()
{
	return sprite.getPosition();
}
void Player::setPosition(sf::Vector2f v)
{
	sprite.setPosition(v);
}
void Player::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

int sign(int x)
{
	return (x > 0) - (x < 0);
}
int sign(float x)
{
	return (x > 0.0f) - (x < 0.0f);
}

void GameClass::gSave(Tile** inctile)
{
	//writing to a text file
	ofstream myfile("save.sav");
	list<sf::Vector2i> coinPos;
	list<sf::Vector2i> enemyPos;
	list<sf::Vector2i> trapPos;
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;


	if (myfile.is_open())
	{
		cout << "saving Tiles \n";
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				switch (inctile[i][j].type)
				{
				case Tile::Type::Sky:
					myfile << "0";
					break;
				case Tile::Type::Platform:
					myfile << "1";
					break;
				case Tile::Type::Lava:
					myfile << "2";
					break;
				}
				myfile << ",";

				switch (inctile[i][j].actor.type)
				{
				case Actor::Type::Coin:
					coinPos.push_back(sf::Vector2i(i, j));
					break;
				case Actor::Type::Enemy:
					enemyPos.push_back(sf::Vector2i(i, j));
					break;
				case Actor::Type::Trap:
					trapPos.push_back(sf::Vector2i(i, j));
					break;
				case Actor::Type::Player:
					playerPos = sf::Vector2i(i, j);
					break;
				case Actor::Type::Exit:
					exitPos = sf::Vector2i(i, j);
					break;
				}
			}
			myfile << "\n";
		}
		//Loop through all the lists, add them to save file, then add player and exit pos
		//coins
		if (!coinPos.empty())
		{
			cout << "Saving Coins \n";
			myfile << "Coin";
			list<sf::Vector2i>::iterator cIt;
			for (cIt = coinPos.begin(); cIt != coinPos.end(); cIt++)
			{
				//access through the iterator
				sf::Vector2i curCoinPos = sf::Vector2i(cIt->x, cIt->y);

				//print contents
				cout << "Saving coin at: " << curCoinPos.x << ',' << curCoinPos.y << "\n";

				//save to file
				myfile << '(' << curCoinPos.x << ',' << curCoinPos.y << ')';
			}
			myfile << "\n";
		}

		//enemies
		if (!enemyPos.empty())
		{
			cout << "Saving Enemies \n";
			myfile << "Enemy";
			list<sf::Vector2i>::iterator eIt;
			for (eIt = enemyPos.begin(); eIt != enemyPos.end(); eIt++)
			{
				//access through the iterator
				sf::Vector2i curEnemyPos = sf::Vector2i(eIt->x, eIt->y);

				//print contents
				cout << "Saving enemy at: " << curEnemyPos.x << ',' << curEnemyPos.y << "\n";

				//save to file
				myfile << '(' << curEnemyPos.x << ',' << curEnemyPos.y << ')';
			}
			myfile << "\n";
		}
		//traps
		if (!trapPos.empty())
		{
			cout << "Saving Traps \n";
			myfile << "Trap";
			list<sf::Vector2i>::iterator tIt;
			for (tIt = trapPos.begin(); tIt != trapPos.end(); tIt++)
			{
				//access through the iterator
				sf::Vector2i curTrapPos = sf::Vector2i(tIt->x, tIt->y);

				//print contents
				cout << "Saving trap at: " << curTrapPos.x << ',' << curTrapPos.y << "\n";

				//save to file
				myfile << '(' << curTrapPos.x << ',' << curTrapPos.y << ')';
			}
			myfile << "\n";
		}

		//Saving player
		cout << "Saving Player at: " << playerPos.x << ',' << playerPos.y << "\n";
		myfile << "Player" << '(' << playerPos.x << ',' << playerPos.y << ')' << "\n";

		//saving exit
		cout << "Saving Exit at: " << exitPos.x << ',' << exitPos.y << "\n";
		myfile << "Exit" << '(' << exitPos.x << ',' << exitPos.y << ')' << "\n";

		myfile.close();
		cout << "file saved \n";
	}
	else
	{
		cout << "Can't open save file \n";
	}
}

void GameClass::gLoad(Tile** inctile)
{
	string line;
	ifstream myfile("save.sav");
	if (myfile.is_open())
	{
		int a = 0;
		int b = 0;
		string saveHold;
		while (getline(myfile, line))
		{
			if (b == 0)
			{
				cout << "Loading Tiles \n";
			}
			if (b < x)
			{
				for (int i = 0; i < line.size(); i++)
				{
					switch (line[i])
					{
					case ',':
						a += 1;
						break;
					case '0':
						inctile[b][a].ChangeType(inctile[a][b].Type::Sky);
						break;
					case '1':
						inctile[b][a].ChangeType(inctile[a][b].Type::Platform);
						break;
					case '2':
						inctile[b][a].ChangeType(inctile[a][b].Type::Lava);
						break;
					}
					inctile[b][a].refreshTile();
				}
			}
			else if (b >= x)
			{
				//check the first two letter on lines after the tiles are loaded
				//this is where we begin loading actors
				string lineHold = line;
				int curStart;
				int curEnd = 0;
				string posString;
				if (line[0] == 'C' && line[1] == 'o')
				{
					cout << "Loading Coins \n";
					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
					{
						curStart = lineHold.find('(');
						curEnd = lineHold.find(')');

						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
						cout << "Loaded Coin at: " << posString << "\n";
						string xStr = posString.substr(0, posString.find(','));
						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
						cout << "x = " << xStr << ", y = " << yStr << "\n";
						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Coin);

						lineHold[curStart] = '<';
						lineHold[curEnd] = '>';
					}
				}
				else if (line[0] == 'E' && line[1] == 'n')
				{
					cout << "Loading Enemies \n";
					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
					{
						curStart = lineHold.find('(');
						curEnd = lineHold.find(')');

						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
						cout << "Loaded Enemy at: " << posString << "\n";
						string xStr = posString.substr(0, posString.find(','));
						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
						cout << "x = " << xStr << ", y = " << yStr << "\n";
						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Enemy);

						lineHold[curStart] = '<';
						lineHold[curEnd] = '>';
					}
				}
				else if (line[0] == 'T' && line[1] == 'r')
				{
					cout << "Loading Traps \n";
					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
					{
						curStart = lineHold.find('(');
						curEnd = lineHold.find(')');

						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
						cout << "Loaded Trap at: " << posString << "\n";
						string xStr = posString.substr(0, posString.find(','));
						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
						cout << "x = " << xStr << ", y = " << yStr << "\n";
						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Trap);

						lineHold[curStart] = '<';
						lineHold[curEnd] = '>';
					}
				}
				else if (line[0] == 'E' && line[1] == 'x')
				{
					cout << "Loading Exit \n";
					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
					{
						curStart = lineHold.find('(');
						curEnd = lineHold.find(')');

						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
						cout << "Loaded Exit at: " << posString << "\n";
						string xStr = posString.substr(0, posString.find(','));
						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
						cout << "x = " << xStr << ", y = " << yStr << "\n";
						inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Exit);

						lineHold[curStart] = '<';
						lineHold[curEnd] = '>';
					}
				}
				else if (line[0] == 'P' && line[1] == 'l')
				{
					cout << "Loading Player \n";
					while (curEnd < lineHold.length() && lineHold.find('(') != string::npos)
					{
						curStart = lineHold.find('(');
						curEnd = lineHold.find(')');

						posString = lineHold.substr(curStart + 1, curEnd - (curStart + 1));
						cout << "Loaded Player at: " << posString << "\n";
						string xStr = posString.substr(0, posString.find(','));
						string yStr = posString.substr(posString.find(',') + 1, posString.length() - 1);
						cout << "x = " << xStr << ", y = " << yStr << "\n";
						//inctile[stoi(xStr)][stoi(yStr)].actor.ChangeActor(Actor::Type::Player);

						player.type = Actor::Type::Player;
						player.init(stoi(xStr) * 32 + ((windowWidth / 2) - ((32 * x) / 2)), stoi(yStr) * 32);
						player.startPos = sf::Vector2f(stoi(xStr) * 32 + ((windowWidth / 2) - ((32 * x) / 2)), stoi(yStr) * 32);
						player.setPosition(player.startPos);

						lineHold[curStart] = '<';
						lineHold[curEnd] = '>';
					}
				}
			}
			b += 1;
			a = 0;
		}
		myfile.close();
		cout << "File Loaded \n";
	}
	else
	{
		cout << "Unable to open file \n";
	}
}

void GameClass::printToConsole(Tile** inctile)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			switch (tile[i][j].type)
			{
			case inctile[j][i].Type::Sky:
				cout << "0";
				break;
			case inctile[j][i].Type::Platform:
				cout << "1";
				break;
			case inctile[j][i].Type::Lava:
				cout << "2";
				break;
			}
			cout << ",";
		}
		cout << "\n";
	}
	cout << "success \n";
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

