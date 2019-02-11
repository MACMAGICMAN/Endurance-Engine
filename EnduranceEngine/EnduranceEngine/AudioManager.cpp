#include <SFML/Audio.hpp>

#include "AudioManager.h"

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

void AudioManager::LoadBackgroundMusic()
{
	SoundBuffer sb;
	sb.loadFromFile("../Documents/Import/startup.wav");

	Sound sound;
	sound.setBuffer(sb);
	sound.play();
}