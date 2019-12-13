#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
#include <Windows.h>
#include "Editor.h"
#include "Game.h"
#include "Menu.h"
#include "Grid.h"





using namespace std;

int main()
{

	EditorClass EditorMode;
	//works fine if i get rid of this game mode class instance in the source cpp
	GameClass MyGameMode;
	MenuClass MenuMode;

	enum GameType
	{
		Menu,
		Editor,
		Game,
	//	Loader
	};
	GameType myGameType;
	GameType curGameType;

	int curInt;
	curInt = MenuMode.mInt;

	myGameType = (GameType)curInt;

	//eehh i need to do it a different way 
	//conditions for the game type switch
	//if (MenuMode.GWannaGotoMenu == true && MenuMode.WannaGoToEditor == false && MenuMode.WannaGoToGame == false)
	//{
	//	curGameType = Menu;
	//	MenuMode.GWannaGotoMenu == false;
	//	//cout << "I wanna o to menu :(";
	//}
	//if (MenuMode.GWannaGotoMenu == false && MenuMode.WannaGoToEditor == false && MenuMode.WannaGoToGame == true )
	//{
	//	curGameType = Game;
	//	//cout << "I wanna o to menu :(";
	//}


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
//uuugh that wa sa bad idea
//case Loader:
//	curGameType = myGameType;
//	return 0;
//
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
	GWannaGotoMenu = false;
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
			mScreen.LoadGame.checkClick(std::bind(&MenuClass::ChangeGameTypetoGame, this), worldPos);
			//mButtons.LoadEditor.checkClick(std::bind(&EditorClass::, this, tile), worldPos);
			worldPos = mWindow.mapPixelToCoords(sf::Mouse::getPosition(mWindow), mWindow.getView());
			mWindow.draw(mScreen);
		}
		if (mInt == 2.0f)
		{
			main();
			return mInt;
			return 0;
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

	eLoad(tile);

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
		tools.saveButton.checkClick(std::bind(&EditorClass::eSave, this, tile), worldPos);
		tools.loadButton.checkClick(std::bind(&EditorClass::eLoad, this, tile), worldPos);

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
	//mClass.GWannaGotoMenu = false;
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
	//set grounded to false here because it will be set to true when we are on the ground
	player.grounded = false;
	gLoad(tile);
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
			
			KeyReleased = false;

			//PLAYER MOVEMENT & PHYSICS
			if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)
			{
				SkiddingRight = true;
				MovingRight = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				SkiddingRight = false;
				MovingRight = true;
				if (player.grounded)
				{
					player.velocity.x +=  +player.speed* 5  * deltaTime;
				}
				else
				{
					player.velocity.x += + player.speed / 3 * deltaTime;
				}
				//cout << player.velocity.x, player.velocity.y;
			}
			if (SkiddingRight == true)
			{

				// right friction
				player.velocity.x = player.velocity.x - 0.2f;
				SkiddingRight = false;
			}
			if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::A)
			{
				SkiddingLeft = true;
				MovingLeft = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				SkiddingLeft = false;
				MovingLeft= true;
				if (player.grounded)
				{
					player.velocity.x -=  player.speed * 5 * deltaTime;
				}
				else
				{
					player.velocity.x -=  player.speed / 3 * deltaTime;
				}
				
				//cout << player.velocity.x, player.velocity.y;
			}
			if (SkiddingLeft == true)
			{

				// right friction
				player.velocity.x = player.velocity.x + 0.2f;
				SkiddingLeft = false;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (player.grounded)
				{
					player.velocity.y -= 3.f + player.speed * deltaTime;
					player.grounded = false;
				
				
					cout << "jumpin";

				}
				//cout << player.velocity.x, player.velocity.y;
			}
			//max horizontal velocity
			//gotta use the sign thing here ? i think
			if (player.velocity.x > 5.f)
			{
				player.velocity.x = 5.f;
			}
			if (player.velocity.x < -5.f)
			{
				player.velocity.x = -5.f;
			}
			if (abs(player.velocity.x) < 1.0f && SkiddingRight == false && MovingRight == false && SkiddingLeft == false && MovingLeft == false)
				{
					player.velocity.x = 0.0f;
				}
			if (!player.velocity.y > -.5f)
				{
					player.velocity.y += gravity * 2 * deltaTime;
					//cout << player.velocity.y;
				}
			else if (player.velocity.y > 1.0f)
				{
					player.velocity.y = 1.0f;
				}
			
			//respwaning the player at the starting point if they die and still have lives left
			if (player.isDead == true && player.lives > -1.0f)
			{
				player.velocity.x = 0.f;
				player.velocity.y = 0.f;
				player.nextPos = player.startPos;
				player.isDead = false;
				--player.lives;
			}
			else {  //here is the players potential position if they aren't obstructed 
				player.nextPos = player.getPosition() + player.velocity;
			}
			if (player.isDead == true && player.lives < 1.0f)
			{
				mClass.mInt = 0;
				main();
				cout << "wanna go to the menu";
				return mInt;
				;
			}


			//projecting the "hitbox" of the player for it's next potential position.
			player.nextRect = sf::FloatRect(player.nextPos, sf::Vector2f(32.f, 32.f));
			gWindow.setView(GameView);
			//world position for ui 
			//WorldPos = gWindow.mapPixelToCoords(sf::Mouse::getPosition(gWindow), gWindow.getView());
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
									//cout << "ow my butt";
								}
								else
								{
									player.grounded = false;
									player.nextPos.y = tile[i][j].sprite.getGlobalBounds().top + tile[i][j].sprite.getGlobalBounds().height + 0.01f;
									player.velocity.y = 0.0f;
									//cout << "ow my head";
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
									cout << "right col";

								}
								else //left side
								{
									player.nextPos.x = tile[i][j].sprite.getGlobalBounds().left + tile[i][j].sprite.getGlobalBounds().width;
									player.velocity.x = 0.0f;
									cout << "left col";
								}
							}
						}

					}

					if (tile[i][j].type == Tile::Type::Lava)
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
									//player.nextPos.y = tile[i][j].sprite.getGlobalBounds().top - 32 - 0.1f;
									player.isDead = true;
									cout << "ow my butt";
								}
							}
						}
						
					}

				}
			}

			
			//testing grounded collision
			//bool b = player.grounded;
			//std::cout << std::boolalpha << b;


			//last but not least draw everything to screen
		
			player.setPosition(player.nextPos);
			gWindow.draw(player);

			//last but not least draw everything to screen
			
			//last but not least draw everything to screen
			gWindow.display();
		}
	return 0;
};

