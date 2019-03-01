#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

using namespace sf;

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	SoundBuffer soundBuffer;
	Sound sound;
	//Music music;

	void PlayAudio(String filepath);
	//void OpenMusic(String filepath);
};