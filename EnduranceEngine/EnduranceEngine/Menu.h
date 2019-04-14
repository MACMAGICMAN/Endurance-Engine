#pragma once
#include "UserInterface.h"
#include"SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4

using namespace sf;

class Menu {
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow &window);
	void clear(RenderWindow &window);
	void show(RenderWindow &window);
	void back(RenderWindow &window);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }
	
private:
	int selectedItemIndex;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};