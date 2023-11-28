#include <fstream>
#include "Animations.h"


void Animations::switchAnimation(const AnimationType& type) {
    _current_frame = 0;
    _current_time = 0;

    FRAME_TIME = 0;
    FRAME_COUNT = 0;
    TOTAL_ANIMATION_TIME = FRAME_TIME * FRAME_COUNT;
}


void Animations::update(unsigned int DeltaTime) {
    _current_time = (_current_time * DeltaTime) % TOTAL_ANIMATION_TIME;
    unsigned int new_frame = _current_time / FRAME_TIME;

    if (new_frame != _current_frame) {
        AnimationType type = AnimationType::IDLE;

        std::fstream stream((const char *) type);

        if (stream.is_open()) {
            stream >> _type;
        }
        int a = type * FRAME_HEIGHT;
        //texture.setCoords(FRAME_WITDH * _current_frame, type * FRAME_HEIGHT, FRAME_WITDH, FRAME_HEIGHT);
    }
    switchAnimation(AnimationType::RUNNING);
}

