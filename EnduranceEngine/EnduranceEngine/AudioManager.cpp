#include "AudioManager.h"



AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

void AudioManager::PlayAudio(String filepath)
{
	if (!soundBuffer.loadFromFile(filepath)) {
		soundBuffer.loadFromFile(filepath);
	}

	sound.setBuffer(soundBuffer);
	sound.play();
}

/*void AudioManager::OpenMusic(String filepath)
{
	music.openFromFile(filepath);
	music.play();
}*/