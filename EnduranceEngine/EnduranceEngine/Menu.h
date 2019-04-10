#pragma once
#include "UserInterface.h"
#include"SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void clear(sf::RenderWindow &window);
	void show(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }
	
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};