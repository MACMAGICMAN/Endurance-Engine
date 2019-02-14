#include "AudioManager.h"

SoundBuffer soundBuffer;
Sound sound;
Music music;

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

/*void AudioManager::LoadBackgroundMusic()
{
	SoundBuffer sb;
	sb.loadFromFile("../Documents/Import/startup.wav");

	Sound sound;
	sound.setBuffer(sb);
	sound.play();
}*/

void AudioManager::AssignAudio(String str)
{
	if (!soundBuffer.loadFromFile(str)) {
		soundBuffer.loadFromFile(str);
	}

	sound.setBuffer(soundBuffer);
	sound.play();
}

void AudioManager::OpenMusic(String str)
{
	Music song;
	song.openFromFile(str);
	song.play();
}

void AudioManager::PlayAudio()
{
	Sound sound;
	//sound.setBuffer(sb);
	sound.play();
}