#include "Audio.h"

Audio::Audio()
{
    chunk_ = NULL;
    music_ = NULL;
}

Audio::~Audio()
{

}

bool Audio::LoadChunk(string path)
{
    chunk_ = Mix_LoadWAV(path.c_str());
    if (chunk_ == NULL)
    {
        cout<< Mix_GetError();
        return false;
    }
    else return true;
}

void Audio::PlayChunk()
{
    if(!Mix_Playing(-1))
    {
        Mix_PlayChannel(-1, chunk_, 0);
    }
}

bool Audio::LoadMusic(string path)
{
    music_ = Mix_LoadMUS(path.c_str());
    if (music_ == NULL)
    {
        cout << Mix_GetError();
        return false;
    }
    else return true;
}

void Audio::PlayMusic()
{
    if (!Mix_PlayingMusic())
    {
        Mix_PlayMusic(music_, 0);
    }
}

bool Audio::InitAudio()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
	{
		cout << Mix_GetError();
		return false;
	}
	else return true;
}


