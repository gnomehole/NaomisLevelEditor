#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
#include "Editor.h"
#include "Game.h"
#include "Menu.h"
#include "Grid.h"




using namespace std;

//does this need to return an int?
int main()
{

	EditorClass EditorMode;
	//works fine if i get rid of this game mode class instance in the source cpp
	GameClass MyGameMode;
	MenuClass MenuMode;

	//doesn't work if i just get rid of the game case 
	enum GameType
	{
		Menu,
		Editor,
		Game
	};
	GameType myGameType = Game;

	//menu screen with select mode
	//clicking onm a mode 

	switch (myGameType)
	{
	case Menu:


		if (!MenuMode.Start())
		{
			return EXIT_FAILURE;
		
		}
		return MenuMode.Update();
		return 0;

	case Editor:
		if (!EditorMode.Start())
		{
			return EXIT_FAILURE;
		}
		return EditorMode.Update();
		return 0;

	case Game:
		if (!MyGameMode.Start())
		{
			return EXIT_FAILURE;
		}
		return MyGameMode.Update();
		return 0;

	}

	//game loop


	//move to editor case

	//Game Loop

	//??
	return 0;

}

bool MenuClass::Start()
{
	int	mWindowWidth = 720;
	int	mWindowHeight = 650;
	//MenuView = sf::View(sf::FloatRect(0, 0.f, mWindowWidth, mWindowHeight));
	//MenuView.setViewport(sf::FloatRect(0.03f, 0, 1, 1));
	mWindow.create(sf::VideoMode(mWindowWidth, mWindowHeight), "Menu", sf::Style::Titlebar | sf::Style::Close);
	//Window.setView(MenuView);
	//Window.clear(sf::Color::White);


	return true;

}

int MenuClass::Update()
{
	

	while (mWindow.isOpen())
	{
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mWindow.close();
				break;

			}

			//Prepare the window for displaying stuff
			mWindow.clear(sf::Color::White);
			//Window.setView(MenuView);

			//mButtons.LoadEditor.checkClick(std::bind(&EditorClass::, this, tile), worldPos);
			worldPos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow), mWindow.getView());
			mWindow.draw(mScreen);
		}
		mWindow.display();
	}
	return 0;

//	std::getline(std::cin, debug);
//	return 0;
}

bool EditorClass::Start()
{
	toolsView = sf::View(sf::FloatRect(0, 0.f, windowWidth * 0.045f, windowHeight));
	toolsView.setViewport(sf::FloatRect(0, 0, 0.045f, 1));

	

	levelEditView = sf::View(sf::FloatRect(0, 0.f, windowWidth, windowHeight));
	levelEditView.setViewport(sf::FloatRect(0.03f, 0, 1, 1)); 

	//Setup Window
	window.create(sf::VideoMode(windowWidth, windowHeight), "Level Editor", sf::Style::Titlebar | sf::Style::Close);

	//set up variable to track selected tile
	curTileType = Tile::Type::Platform;
	curActorType = Actor::Type::Coin;


	for (int i = 0; i < 9; i++)
	{
		tileButton[i].init(10, (32 + 5) * i + 150);
	}
	tileButton[0].type = Tile::Type::Sky;
	tileButton[0].refreshTile();
	tileButton[1].type = Tile::Type::Platform;
	tileButton[1].refreshTile();
	tileButton[2].type = Tile::Type::Lava;
	tileButton[2].refreshTile();
	tileButton[3].actor.type = Actor::Type::Coin;
	tileButton[3].refreshTile();
	tileButton[4].actor.type = Actor::Type::Enemy;
	tileButton[4].refreshTile();
	tileButton[5].actor.type = Actor::Type::Exit;
	tileButton[5].refreshTile();
	tileButton[6].actor.type = Actor::Type::Player;
	tileButton[6].refreshTile();
	tileButton[7].actor.type = Actor::Type::Trap;
	tileButton[7].refreshTile();
	tileButton[8].actor.type = Actor::Type::None;
	tileButton[8].refreshTile();


	//init tiles
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tile[i][j].init(i * 32 + ((windowWidth / 2) - ((32 * x) / 2)), j * 32);
		}
	}

	load(tile);

	return true;
}

int EditorClass::Update()
{
	
	//game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

				//cycle for current tile
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
					//pressed T
				case sf::Keyboard::T:
					switch (curTileType)
					{
					case Tile::Type::Sky:
						curTileType = Tile::Type::Platform;
						break;
					case Tile::Type::Platform:
						curTileType = Tile::Type::Lava;
						break;
					case Tile::Type::Lava:
						curTileType = Tile::Type::Sky;
						break;
					}
					break;
				}
			}
		}
		//Prepare the window for displaying stuff
		window.clear(sf::Color::White);
		window.setView(toolsView);
		//Track mouse position


		//ned to accoun t for the toolbar here for tools
		worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView());
		worldPos.x = worldPos.x - (windowWidth * 0.045f);

		//Save and Load functionality
		tools.saveButton.checkClick(std::bind(&Grid::save, this, tile), worldPos);
		tools.loadButton.checkClick(std::bind(&Grid::load, this, tile), worldPos);

		//loop the toolbar tiles
		for (int i = 0; i < 9; i++)
		{
			if (tileButton[i].mouseOver(worldPos))
			{
				tileButton[i].sprite.setScale(sf::Vector2f(1.1f, 1.1f));
				tileButton[i].actor.sprite.setScale(sf::Vector2f(1.1f, 1.1f));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (i < 3)
					{
						actorNotTile = false;
						curTileType = tileButton[i].type;
					}
					else
					{
						actorNotTile = true;
						curActorType = tileButton[i].actor.type;
					}
				}
			}
			else
			{
				tileButton[i].sprite.setScale(sf::Vector2f(1.0f, 1.0f));

				tileButton[i].actor.sprite.setScale(sf::Vector2f(1.0f, 1.0f));
			}
			//draw the tiles in the same loop we check them
			//the fewer loops, the better
			window.draw(tileButton[i]);
		}
		window.draw(tools);
		window.setView(levelEditView);

		//loop through all tiles to draw
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				//check for click
				if (tile[i][j].mouseOver(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (!actorNotTile)
					{
						//return the opposite of the current type (flip flop)
						tile[i][j].ChangeType(curTileType);
					}
					else
					{
						tile[i][j].actor.ChangeActor(curActorType);
					}


				}
				//draw tiles
				tile[i][j].refreshTile();
				window.draw(tile[i][j]);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			printToConsole(tile);
		}
		//last but not least draw everything to screen
		window.display();
	}
	return 0;
}

bool GameClass::Start()
{
	//setup game
	//
	//load();
	GameView = sf::View(sf::FloatRect(0, 0.f, windowWidth, windowHeight));
	GameView.setViewport(sf::FloatRect(0.03f, 0, 1, 1));

	gWindow.create(sf::VideoMode(windowWidth, windowHeight), "My Cool Game", sf::Style::Titlebar | sf::Style::Close);
	//load our tiles here for the games
	init(x,y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tile[i][j].init(i * 32 + ((windowWidth / 2) - ((32 * x) / 2)), j * 32);
		}
	}
	load(tile);
	return true;
};

int GameClass::Update()
{
	// game loop
		while (gWindow.isOpen())
		{
			deltaTime = clock.restart().asSeconds();
			gWindow.clear(sf::Color::White);
			sf::Event event;
			while (gWindow.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					gWindow.close();
					break;

					//cycle for current til
				}
				

				//gWindow.draw(grid);

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (player.grounded)
				{
					player.velocity.x += player.speed * deltaTime;
				}
				else
				{
					player.velocity.x += player.speed / 3 * deltaTime;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (player.grounded)
				{
					player.velocity.x -= player.speed * deltaTime;
				}
				else
				{
					player.velocity.x -= player.speed / 3 * deltaTime;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (player.grounded)
				{
					player.grounded = false;
					player.velocity.x += player.speed * deltaTime;
				}
			}
			//Friction
			if (player.grounded)
			{
				if (abs(player.velocity.x) > 0.05f)
				{
					player.velocity.x - +friction * deltaTime * (sign(player.velocity.x));
				}
				else
				{
					player.velocity.x = 0.0f;
				}

			}
		//maxiumim horizontal absolute velocity.
			if (abs(player.velocity.x)>0.6f)
			{
				player.velocity.x = 0.06f * sign(player.velocity.x);
			}
			//max verti velocity adding gravity to the player

			if (player.velocity.y < 1.0f)
			{
				player.velocity.y += gravity * deltaTime;
			}
			else if(player.velocity.y < -1.0f)
			{
				player.velocity.y = -1.0f;
			}
			//here is the players potential position if they aren't obstructed 
			player.nextPos = player.getPosition() + player.velocity;

			//projecting the "hitbox" of the player for it's next potential position.
			player.nextRect = sf::FloatRect(player.nextPos, sf::Vector2f(32.f, 32.f));
			//set grounded to false here because it will be set to true when we are on the ground
			gWindow.setView(GameView);
			//world position for ui 
			worldPos = gWindow.mapPixelToCoords(sf::Mouse::getPosition(gWindow), gWindow.getView());
			//Prepare the window for displaying stuff
	
			
			
			//loop through all tiles to draw
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					tile[i][j].refreshTile();
					gWindow.draw(tile[i][j]);

					//check for colisions
					if (tile[i][j].type == Tile::Type::Platform)
					{
						//check collision
						Collision pcol = player.CollisionCheck(tile[i][j].sprite.getGlobalBounds());
						if (pcol.hit)
						{
							//hit something vertically
							if (pcol.dir.x == 0)
							{
								if (pcol.dir.y >= 0.0f)
								{
									//we're on top of the tile
									player.nextPos.y = tile[i][j].sprite.getGlobalBounds().top - 32 - 0.1f;

									player.grounded = true;
									player.velocity.y = 0.0f;
								}
								else
								{
									player.grounded = false;
									player.nextPos.y = tile[i][j].sprite.getGlobalBounds().top + tile[i][j].sprite.getGlobalBounds().height + 0.01f;
									player.velocity.y = 0.0f;
								}
							}
							else //horizontal
							{
								//right side
								if (pcol.dir.x >= 0.0f)
								{
									//we want to stop not move to next tile
									player.nextPos.x = tile[i][j].sprite.getGlobalBounds().left - 32;
									player.velocity.x = 0.0f;

								}
								else //left side
								{
									player.nextPos.x = tile[i][j].sprite.getGlobalBounds().left + tile[i][j].sprite.getGlobalBounds().width;
									player.velocity.x = 0.0f;

								}
							}
						}

					}

				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				printToConsole(tile);
			}
			//last but not least draw everything to screen
		
			player.setPosition(player.nextPos);
			gWindow.draw(player);

			//last but not least draw everything to screen
			
			//last but not least draw everything to screen
			gWindow.display();
		}
	return 0;
};

