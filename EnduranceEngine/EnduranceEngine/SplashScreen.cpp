#include "SplashScreen.h"

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update()
{
	RenderWindow window(VideoMode(750, 750), "Splash screen test");
	
	Texture t;
	t.loadFromFile("../Documents/Import/logo.jpg");

	Sprite logo;
	logo.setTexture(t);

	//Font f;
	//f.loadFromFile("..Documents/Import/blue highway.ttf");

	Clock c;
	Time deltaTime = c.getElapsedTime();
	float seconds = deltaTime.asSeconds();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(logo);
		window.display();
	}
}