#ifndef AUDIO_H_
#define AUDIO_H_

#include "CommonFunc.h"

class Audio
{
private:
    Mix_Chunk* chunk_ ;
    Mix_Music* music_ ;

public:
    Audio();
    ~Audio();
    bool InitAudio();
    bool LoadChunk(string path);
    bool LoadMusic(string path);
    void PlayChunk();
    void PlayMusic();

};


#endif // AUDIO_H_
