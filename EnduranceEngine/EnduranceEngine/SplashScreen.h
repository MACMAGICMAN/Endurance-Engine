#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "SceneGraph.h"
#include "PlayerInput.h"
#include "Menu.h"

#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace sf;

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	void SpawnBullet(Sprite &p, Sprite &b, RenderWindow &w);
	void Update();

	std::vector<SceneGraph> gameObjects;
};