#include "SplashScreen.h"
#include "SceneGraph.h"

#include <windows.h>
#include <sstream>
#include <string>

SplashScreen::SplashScreen()
{

}

SplashScreen::~SplashScreen()
{

}

void TestAudio()
{	
	SoundBuffer buffer;
	if (!buffer.loadFromFile("../Documents/Import/startup.wav")) {
		buffer.loadFromFile("../Documents/Import/startup.wav");
	}
	Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	OutputDebugString("TestAudio called.\n");
}

void SplashScreen::Update(Time dt)
{
	Clock c;
	SceneGraph splash;
	splash.sprite.LoadSprite("../Documents/Import/logo.jpg");
	splash.audio.AssignAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);

	Font bluehighway;
	bluehighway.loadFromFile("../Documents/Import/blue highway.ttf");

	Text text;
	text.setFont(bluehighway);
	text.setFillColor(Color::Red);
	text.setCharacterSize(32);

	TestAudio();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(splash.sprite.image);

		c.restart();
		dt += c.getElapsedTime();
		float seconds = dt.asSeconds();

		std::ostringstream oss;
		oss << seconds * 1000;
		std::string s(oss.str());

		text.setString(s);
		window.draw(text);

		if (seconds * 1000 >= 5) {
			window.close();
		}
		window.display();
	}
}