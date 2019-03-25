#include "SplashScreen.h"
#include "SceneGraph.h"
#include "PlayerInput.h"

#include <windows.h>
#include <sstream>
#include <string>

PlayerInput* playerInput = new PlayerInput();

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{

}
void SplashScreen::Update(Time dt)
{
	Clock c;
	SceneGraph splash;
	SceneGraph player;
	SceneGraph wall;

	splash.sprite.LoadSprite("../Documents/Import/logo.jpg");
	player.sprite.LoadSprite("../Documents/Import/logo.jpg");
	wall.sprite.LoadSprite("../Documents/Import/logo.jpg");

	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);
	
	player.sprite.image.setPosition(sf::Vector2f(100, 200));
	player.sprite.image.setScale(0.3, 0.3);
	player.sprite.image.setColor(Color::Green);
	wall.sprite.image.setPosition(sf::Vector2f(300, 200));
	wall.sprite.image.setScale(0.3, 0.3);

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
		window.draw(player.sprite.image);
		window.draw(wall.sprite.image);
	

		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		std::ostringstream oss;
		oss << seconds * 1000;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);

		if (seconds * 1000 >= 5) {
			//window.close();
		splash.sprite.image.setScale(0, 0);
		}

		player.keyboard.MovePlayer(event, player.sprite.image, 0.2);
		player.Collision.HandleCollisions(player.sprite.image, wall.sprite.image);
		window.display();
	}


}