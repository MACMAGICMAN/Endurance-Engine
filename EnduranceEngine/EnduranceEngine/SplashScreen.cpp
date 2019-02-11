#include "SplashScreen.h"
#include "SceneGraph.h"

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
	splash.audio.AssignAudio("../Documents/Import/startup.wav");

	RenderWindow window(VideoMode(splash.sprite.texture.getSize().x, splash.sprite.texture.getSize().y), "Splash screen test"/*, Style::None*/);

	Font bluehighway;
	bluehighway.loadFromFile("../Documents/Import/blue highway.ttf");

	Text text;
	text.setFont(bluehighway);
	text.setFillColor(Color::Red);
	text.setCharacterSize(32);

	/*SoundBuffer buffer;
	if (!buffer.loadFromFile("../Documents/Import/startup.wav")) {
		buffer.loadFromFile("../Documents/Import/startup.wav");
	}

	Sound sound;
	sound.setBuffer(buffer);
	sound.play();*/


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

		ostringstream oss;
		oss << seconds * 1000;
		string s(oss.str());

		text.setString(s);
		window.draw(text);

		if (seconds * 1000 >= 2) {
			window.close();
		}

		window.display();
	}
}