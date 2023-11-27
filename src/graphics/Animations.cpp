//
// Created by tristantrad on 24/11/23.
//

#include "Animations.h"

void Animations::update(unsigned int DeltaTime) {
    int newframe;
    newframe = (_current_time + DeltaTime) % (NB_FRAME * FRAME_TIME);
    if (newframe < _current_frame || newframe >= _current_frame+FRAME_TIME) {

    }
}

void Animations::setFrame(int frame) {

}


