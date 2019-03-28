#pragma once
#include <SFML/Graphics.hpp>
#include "SceneGraph.h"
#include <vector>

using namespace sf;

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	void Update();

	std::vector<SceneGraph> gameObjects;
};