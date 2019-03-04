#include "SplashScreen.h"
#include "SceneGraph.h"

#include <SFML/system.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <string>

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Update(/*Time dt*/)
{
	Clock c;
	c.restart();

	SceneGraph splash = SceneGraph();	
	splash.sprite.LoadSprite("../Documents/Import/logo.jpg");
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);
	window.setFramerateLimit(60u);

	Font bluehighway;
	bluehighway.loadFromFile("../Documents/Import/blue highway.ttf");

	Text text;
	text.setFont(bluehighway);
	text.setFillColor(Color::Red);
	text.setCharacterSize(32);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(splash.sprite.image);
		
		float seconds = c.getElapsedTime().asSeconds();
		splash.Update(seconds);

		std::ostringstream oss;
		oss << seconds;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);

		window.display();
	}
}