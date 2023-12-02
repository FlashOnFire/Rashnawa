#ifndef RASHNAWA_AUDIO_UTILS_HPP
#define RASHNAWA_AUDIO_UTILS_HPP

#include "FMOD/fmod_studio.h"
#include <iostream>

namespace Audio {
    static void ErrCheck(FMOD_RESULT result) {
        if (result != FMOD_OK) {
            std::cout << "FMOD error! (" << result << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
} // Audio

#endif //RASHNAWA_AUDIO_UTILS_HPP
