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
	splash.sprite.LoadSprite("../Documents/Import/logo.jpg");
	splash.spriteTwo.LoadSprite("../Documents/Import/logo.jpg");
	splash.audio.PlayAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);
	
	splash.spriteTwo.image.setPosition(sf::Vector2f(300, 200));
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
			splash.keyboard.MovePlayer(event, splash.sprite.image, 6);
			splash.Collision.CollideWithPlayer(splash.sprite.image, splash.spriteTwo.image);
		
		}
		window.clear();
		
		window.draw(splash.sprite.image);
		window.draw(splash.spriteTwo.image);
	
		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		std::ostringstream oss;
		oss << seconds * 1000;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);

		//if (seconds * 1000 >= 5) {
		//	window.close();
		//}
		window.display();
	}


}