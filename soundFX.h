#ifndef SOUNDFX_H
#define SOUNDFX_H
#include <vector>
#include <SDL.h>
#include <SDL_mixer.h>

// In this demo, we use Mix_Music *Mix_LoadMUS(const char *file)
// Where file is the name of the music file to use. 
//
// SDL_mixer supports music and sound samples from the following formats:
// - WAVE/RIFF (.wav)
// - AIFF (.aiff)
// - VOC (.voc)
// - MOD (.mod .xm .s3m .669 .it .med and more) using included mikmod
// - MIDI (.mid) using timidity or native midi hardware
// - OggVorbis (.ogg) requiring ogg/vorbis libraries on system
// - MP3 (.mp3) requiring SMPEG library on system
// - also any command-line player, which is not mixed by SDL_mixer...
//   that requires a command to play with.

class SDLSoundFX {
public:
  SDLSoundFX();
  ~SDLSoundFX();

  //void startMusic();
  //void stopMusic();      // stop all sounds
  void operator[](int);  // play the indexed sound
private:
  int volume;
  int currentSound;

  int audioRate;
  int audioChannels;
  int audioBuffers;
  std::vector<Mix_Chunk*> sounds;
  std::vector<int> channels;
  SDLSoundFX(const SDLSoundFX&);
  SDLSoundFX& operator=(const SDLSoundFX&);
}; 

#endif