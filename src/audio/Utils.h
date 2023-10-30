#pragma once

#include "fmod_studio.hpp"
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