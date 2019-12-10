#include "Editor.h"
#include "Tile.h"

using namespace std;

EditorClass::EditorClass() {
	
	//Track if we are painting with actor or tile
	actorNotTile = false;
	//setup window size

	curActorType = Actor::Type::None;
	curTileType = Tile::Type::Sky;



}



void Tile::ChangeType(Type t)
{
	type = t;
}



ToolPanel::ToolPanel()
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
	saveButton.rect.setPosition(2, 45);
	saveButton.text.setPosition(saveButton.rect.getPosition().x +
		(saveButton.rect.getSize().x / 2) - (saveButton.text.getLocalBounds().width / 2),
		saveButton.rect.getPosition().y);
}


void EditorClass::printToConsole(Tile** inctile)
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