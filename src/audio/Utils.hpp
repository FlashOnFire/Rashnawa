#ifndef RASHNAWA_AUDIO_UTILS_HPP
#define RASHNAWA_AUDIO_UTILS_HPP

#include "FMOD/fmod_studio.hpp"
#include <iostream>

namespace Audio {

    struct EventInstanceDeleter {
        void operator()(FMOD::Studio::EventInstance *p) const { p->release(); }
    };

    static void ErrCheck(FMOD_RESULT result) {
        if (result != FMOD_OK) {
            std::cout << "FMOD error! (" << result << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

} // Audio

#endif //RASHNAWA_AUDIO_UTILS_HPP