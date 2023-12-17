#include "ModifyingMusicData.h"

void ModifyingMusicData(const short int buffer[], const int buffersize,
                        short int modified[]) {
  for (int i = 0; i < buffersize; ++i) {
    modified[2 * i] = buffer[i];
    modified[2 * i + 1] = buffer[i];
  }
}
