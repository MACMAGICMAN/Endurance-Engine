#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SceneGraph.h"
#include "SplashScreen.cpp"
#include "Actor.h"

class PlayerInput {
public:
	PlayerInput();
	~PlayerInput();

	void Update();
};