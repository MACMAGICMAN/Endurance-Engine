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

	void PlayAudio(String filepath);
	//void OpenMusic(String filepath);

	SoundBuffer soundBuffer;
	Sound sound;
	//Music music;
};