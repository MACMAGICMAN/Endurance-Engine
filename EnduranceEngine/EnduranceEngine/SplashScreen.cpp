#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Update()
{
	Clock c;
	c.restart();

	SceneGraph splash;
	splash.sprite.LoadSprite("../Documents/Import/logo.jpg");
	splash.audio.PlayAudio("../Documents/Import/startup.wav");
	gameObjects.push_back(splash);

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}		
		}

		//draw start
		window.clear();
		
		//draw all sprites
		for (unsigned i = 0; i < gameObjects.size(); i++)
		{
			window.draw(gameObjects[i].sprite.image);
		}
	
		//draw time on screen
		float seconds = c.getElapsedTime().asSeconds();

		if (seconds >= 7) {
			gameObjects.clear();
		}

		window.display();
		//draw end
	}
}