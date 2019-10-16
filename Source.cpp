#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <list>
#include <functional>
#include "arial.h"

//make sure to add the sfml stuff woopsies

using namespace std;

//setup window size
const int  windowWidth = 1025;
const int windowHeight = 650;

//grid amounts
const int x = 30;
const int y = 20;
//Mouse pos
sf::Vector2f worldPos;

//our tile class, its drawable and has a transform
class Tile : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
	}
public :
	enum Type
	{
		Sky,
		Platform,
		Lava
	};
	//setting our tile to be the sky
	Type type = Tile::Sky;
	sf::Sprite sprite;
	sf::FloatRect rBounds;

	//define colours
	sf::Texture blockSkyTexture;
	sf::Texture blockPlatformTexture;
	sf::Texture blockLavaTexture;

	void init(int x, int y)
	{

		//load textures
		loadTextures();

		//set position of this tiles sprite
		sprite.setPosition(x, y);
		refreshTile();
	}

	void loadTextures()
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

	bool mouseOver(sf::Vector2f windPos)
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

	void refreshTile()
	{
		switch (type)
		{
		case Tile::Sky:
			sprite.setTexture(blockSkyTexture);
			break;
		case Tile::Platform:
			sprite.setTexture(blockPlatformTexture);
			break;
		case Tile::Lava:
			sprite.setTexture(blockLavaTexture);
			break;
		}
	}

	//changing the T variable to what we want it to be? idk imma try understand this more later 
	void ChangeType(Type T)
	{
		type = T;
	}
};


	class Button : public sf::Drawable, public sf::Transformable
	{
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(rect, states);
			target.draw(text, states);
		}


public:
	int textSize = 16;
	float rectOutline = 1;
	sf::RectangleShape rect;
	sf::Font font;
	sf::Text text;
	sf::FloatRect rbounds;

	//initilize button
	Button()
	{
		font.loadFromMemory(&arial_ttf, arial_ttf_size);
		text.setFont(font);
		text.setCharacterSize(textSize);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Regular);
		//set up button visual
		rect.setFillColor(sf::Color::White);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(rectOutline);


	}

	bool mouseOver(sf::Vector2f windPos)
	{
		rbounds = rect.getGlobalBounds();
		if (rbounds.contains(windPos.x, windPos.y))
		{
			rect.setOutlineThickness(2);
			return true;
		}
		else
		{
			rect.setOutlineThickness(rectOutline);
			return false;
		}

	}
	//check to see if button has been clicked
	void checkClick(function<void()>f, sf::Vector2f windPos)
	{
		if (mouseOver(windPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			f();
		}
	}
};
//printing out the tiles
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
		//init
		ToolPanel()
		{
			loadButton.text.setString("Load");
			loadButton.rect.setSize(sf::Vector2f(loadButton.text.getLocalBounds().width + 6,
				loadButton.text.getLocalBounds().height + 6));

			loadButton.rect.setPosition(2, 20);
			loadButton.text.setPosition(loadButton.rect.getPosition().x +
				(loadButton.rect.getSize().x / 2) - (loadButton.text.getLocalBounds().width / 2),
				loadButton.rect.getPosition().y);

			saveButton.text.setString("Save");
			saveButton.rect.setSize(sf::Vector2f(saveButton.text.getLocalBounds().width + 6,
				saveButton.text.getLocalBounds().height + 6));
			saveButton.rect.setSize(sf::Vector2f(saveButton.text.getLocalBounds().width + 6,
				saveButton.text.getLocalBounds().height + 6));
			saveButton.rect.setPosition(2, 45);
			saveButton.text.setPosition(saveButton.rect.getPosition().x +
				(saveButton.rect.getSize().x / 2) - (saveButton.text.getLocalBounds().width / 2),
				saveButton.rect.getPosition().y);

		}
	};
	//saving
	void save(Tile tile[x][y])
	{
	//writing a text file
		ofstream myfile("save.sav");
		if (myfile.is_open())
		{
			cout << "saving tiles \n";

			for (int i = 0; i<x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					switch (tile[i][j].type)
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
				}
				myfile << "\n";
			}
			myfile.close();

		}
	}


	void load(Tile tile[x][y])
	{
	string line;
	ifstream myfile("save.sav");
	if (myfile.is_open())
	{
		int a = 0;
		int b = 0;
		string saveHold;
		while (getline(myfile,line))
		{
			if (b == 0)
			{
				cout << "Loading Tiles\n";
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
						tile[b][a].ChangeType(tile[a][b].Type::Sky);
						break;
					case '1':
						tile[b][a].ChangeType(tile[a][b].Type::Platform);
						break;
					case '3':
						tile[b][a].ChangeType(tile[a][b].Type::Lava);
						break;
					}
					tile[b][a].refreshTile();
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
	void printtoConsole(Tile tile[x][y])
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				switch (tile[i][j].type)
				{
					//dont know why type isnt woprking
				case tile[j][i].Type::Sky:
					cout << "0";
					break;

				case tile[j][i].Type::Platform:
					cout << "1";
					break;

				case tile[j][i].Type::Lava:
					cout << "2";
					break;
				}
				cout << ",";
			}
			cout << "\n";
		}
		cout << "success \n";

	}


int main()
{
	//set up space for tool bar

	ToolPanel tools;
	sf::View toolsView(sf::FloatRect(0, 0.f, windowWidth * 0.045f, windowHeight));
	toolsView.setViewport(sf::FloatRect(0, 0, 0.045f, 1));

	sf::View levelEditView(sf::FloatRect(0, 0.f, windowWidth, windowHeight));
	levelEditView.setViewport(sf::FloatRect(0.03f, 0, 1, 1));

	//setup window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Level Editor", sf::Style::Titlebar | sf::Style::Close);

	Tile::Type curTileType = Tile::Type::Platform;

	Tile tileButton[3];
	for (int i = 0; i < 3; i++)
	{
		tileButton[i].init(10, (32 + 5) * i + 150);
	}
	tileButton[0].type = Tile::Type::Sky;
	tileButton[0].refreshTile();
	tileButton[1].type = Tile::Type::Platform;
	tileButton[1].refreshTile();
	tileButton[2].type = Tile::Type::Lava;
	tileButton[2].refreshTile();
	//not finished



	//setup tiles
	Tile tile[x][y];

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			tile[i][j].init(i * 32 + ((windowWidth / 2) - ((32 * x) / 2)), j * 32);
		}
	}

	//game Loop
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

				//cycle through current tile
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{

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
				}



			}
		}

		//prepare the window for displaying stuff
		window.clear(sf::Color::White);
		window.setView(toolsView);
		//track mouse pos
		worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		//save and load functionality
		tools.saveButton.checkClick(std::bind(save, tile), worldPos);
		tools.loadButton.checkClick(std::bind(load, tile), worldPos);
		//loop the toolbar tiles
		for (int i = 0; i < 3; i++)
		{
			if (tileButton[i].mouseOver(worldPos))
			{
				tileButton[i].sprite.setScale(sf::Vector2f(1.1f, 1.1f));
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					curTileType = tileButton[i].type;
				}
				else
				{
					tileButton[i].sprite.setScale(sf::Vector2f(1.0f, 1.0f));
				}
				window.draw(tileButton[i]);
			}

			

		}
		window.draw(tools);
		window.setView(levelEditView);
		//loop through all tiles to draw change if clicked
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (tile[i][j].mouseOver(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					tile[i][j].ChangeType(curTileType);
				}
				//draw tiles
				tile[i][j].refreshTile();
				window.draw(tile[i][j]);

			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			printtoConsole(tile);
		}

		window.display();
	}
}