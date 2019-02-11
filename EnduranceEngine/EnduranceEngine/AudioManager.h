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
	//void LoadBackgroundMusic();
	void AssignAudio(String str);
	void PlayAudio();
	void OpenMusic(String str);

protected:

	//SoundBuffer sb;

};