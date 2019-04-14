#include "stdafx.h"
#include "Menu.h"



Menu::Menu(float width, float height)
{
	font.loadFromFile("../Documents/Import/blue highway.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 6.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setString("How to Play");
	menu[1].setPosition(sf::Vector2f(width / 6.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Blue);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 6.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	 
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Blue);
	menu[3].setString("Back");
	menu[3].setPosition(sf::Vector2f(width / 6.5, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	selectedItemIndex = 0;
	
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
		
	}
}

void Menu::clear(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i].setString("");
	}
}

void Menu::show(sf::RenderWindow & window)
{
	menu[0].setString("Play");
	menu[1].setString("How to Play");
	menu[2].setString("Exit");
}

void Menu::back(sf::RenderWindow & window)
{
	menu[3].setString("Back");
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::White);
	}
}
