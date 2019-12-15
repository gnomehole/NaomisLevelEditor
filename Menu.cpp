#include "Menu.h"
#include "Button.h"





MenuScreen::MenuScreen()
{

	LoadEditor.text.setString("Load Editor");
	LoadEditor.rect.setSize(sf::Vector2f(LoadEditor.text.getLocalBounds().width + 6, LoadEditor.text.getLocalBounds().height + 6));
	LoadEditor.rect.setPosition(100	, 100);
	LoadEditor.text.setPosition(LoadEditor.rect.getPosition().x +
		(LoadEditor.rect.getSize().x / 2) - (LoadEditor.text.getLocalBounds().width / 2),
		LoadEditor.rect.getPosition().y);
	LoadEditor.rect.setFillColor(sf::Color::Cyan);

	LoadGame.text.setString("Load Game");
	LoadGame.rect.setSize(sf::Vector2f(LoadGame.text.getLocalBounds().width + 6, LoadGame.text.getLocalBounds().height + 6));
	LoadGame.rect.setPosition(300, 100);
	LoadGame.text.setPosition(LoadGame.rect.getPosition().x +
		(LoadGame.rect.getSize().x / 2) - (LoadGame.text.getLocalBounds().width / 2),
		LoadGame.rect.getPosition().y);
	LoadGame.rect.setFillColor(sf::Color::Cyan);
}

void MenuClass::ChangeGameTypetoGame()
{
	WannaGoToGame = true; 
	std::cout << "Game load button working?";
}

MenuClass::MenuClass()
{
	GWannaGotoMenu = true;
	//
	mInt = 0;
}







