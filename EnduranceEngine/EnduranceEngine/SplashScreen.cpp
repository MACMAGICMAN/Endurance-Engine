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
	SceneGraph background;
	SceneGraph player;
	SceneGraph wall;

	//Sprite Files
	splash.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	background.sprite.LoadSprite("../Documents/Import/back_Game.jpg");
	wall.sprite.LoadSprite("../Documents/Import/back_Logo.jpg");
	player.sprite.LoadSprite("../Documents/Import/player_Sprite.png");

	//Audio Files
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(1280, 720), "Splash screen test"/*, Style::None*/);
	
	wall.sprite.image.setPosition(sf::Vector2f(300, 200));
	wall.sprite.image.setScale(0.3, 0.3);

	player.sprite.image.setPosition(sf::Vector2f(300, 200));
	player.sprite.image.setScale(0.1, 0.1);

	//background.sprite.image.setPosition(sf::Vector2f(300, 200));
	//background.sprite.image.setScale(1, 1);

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
			//playerInput->MovePlayer(event, splash.sprite.image);
		}
		splash.keyboard.MovePlayer(event, player.sprite.image, 0.5, window);
		splash.Collision.CollideWithPlayer(player.sprite.image, wall.sprite.image);
		window.clear();

	

		window.draw(background.sprite.image);
		window.draw(wall.sprite.image);
		window.draw(player.sprite.image);
		window.draw(splash.sprite.image);

		
		//window.setFramerateLimit(50);
		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		std::ostringstream oss;
		oss << seconds * 1000;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);

		if (seconds * 1000 >= 1) {
			//window.close();
		splash.sprite.image.setScale(0, 0);
		//RenderWindow window(VideoMode(background.sprite.texture.getSize().x, background.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);
		
		}
		window.display();

	}




}