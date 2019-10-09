#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <list>

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
public:
	//checking to see if the tile is a ground or not
	bool isGroundtile = false;

	//sf:: rectangle shape <-- draw a shape here if the sprites arent working 

	//defining the sprites 
	sf::Sprite sprite;

	sf::FloatRect rBounds;

	//define colours
	sf::Texture blockSkyTexture;
	sf::Texture blockPlatformTexture;

	void init(int x, int y)
	{

		//load textures
		loadTextures();

		//set position of this tiles sprite
		sprite.setPosition(x, y);
		ChangeType(false);
	}

	void loadTextures()
	{
		if (!blockSkyTexture.loadFromFile("SpritesPlatformer/BlockSky.png"))
		{
			cout << "failed to load BlockSky.png";

		}
		if (!blockPlatformTexture.loadFromFile("PlatformerSprites/BlockPlatform.png"))
		{
			cout << "failed to load BlockPlatform.png";

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

	void ChangeType(bool isGround)
	{
		isGroundtile = isGround;
		if (isGroundtile)
		{
			sprite.setTexture(blockPlatformTexture);
		}
		else
		{
			sprite.setTexture(blockSkyTexture);
		}
	}
};

//printing out the tiles
void printtoConsole(Tile tile[x][y])
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (tile[i][j].isGroundtile)
			{
				cout << "1";
			}
			else {
				cout << "0";
			}
			cout << ",";
		}
		cout << "\n";
	}
	cout << "success \n";

}


int main()
{
	//setup window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Level Editor", sf::Style::Titlebar | sf::Style::Close);
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

			}
		}
		//prepare the window for displaying stuff
		window.clear(sf::Color::White);

		worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		//loop through all tiles to draw change if clicked
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (tile[i][j].mouseOver(worldPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					tile[i][j].ChangeType(!tile[i][j].isGroundtile);
				}
				window.draw(tile[i][j]);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			printtoConsole(tile);
		}

		window.display();

	}


};