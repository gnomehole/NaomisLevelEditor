#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list> 	
#include <functional>
#include "Editor.h"
#include "Game.h"
#include "Menu.h"



using namespace std;


int main()
{

	EditorClass EditorClassholder;
	GameClass MyGameholder;
	MenuClass Menuclassholder;


	enum GameType
	{
		Editor,
		Game,
		Menu
	};
	GameType myGameType = Menu;

	//menu screen with select mode
	//clicking onm a mode 

	switch (myGameType)
	{
	case Menu:


		if (!Menuclassholder.Start())
		{
			return EXIT_FAILURE;

		}
		return Menuclassholder.Update();
		return 0;

	case Editor:
		if (!EditorClassholder.Start())
		{
			return EXIT_FAILURE;
		}
		return EditorClassholder.Update();
		return 0;

	case Game:
		if (!MyGameholder.Start())
		{
			return EXIT_FAILURE;
		}
		return MyGameholder.Update();
		return 0;

	}

	//game loop


	//move to editor case

	//Game Loop

}

bool MenuClass::Start()
{

	//MenuView = sf::View(sf::FloatRect(0, 0.f, mWindowWidth, mWindowHeight));
	//MenuView.setViewport(sf::FloatRect(0.03f, 0, 1, 1));
	Window.create(sf::VideoMode(mWindowWidth, mWindowHeight), "Menu", sf::Style::Titlebar | sf::Style::Close);
	//Window.setView(MenuView);
	//Window.clear(sf::Color::White);


	return true;

}

int MenuClass::Update()
{
	

	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;

			}

			//Prepare the window for displaying stuff
			Window.clear(sf::Color::White);
			//Window.setView(MenuView);

			//mButtons.LoadEditor.checkClick(std::bind(&EditorClass::, this, tile), worldPos);
			worldPos = Window.mapPixelToCoords(sf::Mouse::getPosition(Window), Window.getView());
			Window.draw(mButtons);
		}
		Window.display();
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
		//Save and Load functionality
		tools.saveButton.checkClick(std::bind(&EditorClass::save, this, tile), worldPos);
		tools.loadButton.checkClick(std::bind(&EditorClass::load, this, tile), worldPos);

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
	//LoadLevel("bob",tile);

	//load our tiles here for the games
	return true;
};

int GameClass::Update()
{
	//needs to be in the game while loop
	//NEED DEELTA TIME FOR MOVING YO 
	deltaTime = clock.restart().asSeconds();

	//in the game loop check for collisions
	//if (tile[i][j].type == Tile::Type::Platform)
	//{
	//	Collision pcol = player
	//
	//}
	//run game
	//while (window.isOpen())
	return 0;
};

