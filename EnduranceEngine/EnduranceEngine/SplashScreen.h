#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class SplashScreen {
public:
	SplashScreen();
	~SplashScreen();
	void Update(Time dt);
};