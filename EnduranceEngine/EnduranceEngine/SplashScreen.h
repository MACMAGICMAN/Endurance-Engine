#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	void bulletSpawn(sf::Sprite &p, sf::Sprite &b, RenderWindow &w);
	void Update();
	
};