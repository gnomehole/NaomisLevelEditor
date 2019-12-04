#pragma once
#include <SFML/Graphics.hpp>
class Actor : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
	}
public:
	sf::Sprite sprite;
	enum Type { None, Enemy, Coin, Player, Trap, Exit };
	Type type;
	sf::Texture doorTexture;
	sf::Texture coinTexture;
	sf::Texture enemyAliveTexture;
	sf::Texture enemyDeadTexture;
	sf::Texture playerTexture;
	sf::Texture trapTexture;
	sf::Texture blankTexture;
	void loadTextures();
	void init(int x, int y);
	void RefreshActor();
	void ChangeActor(Type t);
};
