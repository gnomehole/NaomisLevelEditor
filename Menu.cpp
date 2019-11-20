#include "Menu.h"
#include "Button.h"





MenuButtons::MenuButtons()
{

	LoadEditor.text.setString("Load Editor");
	LoadEditor.rect.setSize(sf::Vector2f(LoadEditor.text.getLocalBounds().width + 6, LoadEditor.text.getLocalBounds().height + 6));
	LoadEditor.rect.setPosition(100	, 100);
	LoadEditor.text.setPosition(LoadEditor.rect.getPosition().x +
		(LoadEditor.rect.getSize().x / 2) - (LoadEditor.text.getLocalBounds().width / 2),
		LoadEditor.rect.getPosition().y);
	LoadEditor.rect.setFillColor(sf::Color::Cyan);
}






