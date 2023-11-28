#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H

#include <iostream>


class Animations {
public:
    enum AnimationType {
        IDLE=0,
        RUNNING=1,
        WALKING=2
    };

    unsigned int FRAME_COUNT = 2;
    unsigned int FRAME_TIME = 1000;
    unsigned int FRAME_WITDH = 88;
    unsigned int FRAME_HEIGHT = 88;
    unsigned int TOTAL_ANIMATION_TIME = FRAME_TIME*FRAME_COUNT;
    unsigned int _current_time = 0;
    unsigned int _current_frame = 0;


    std::string _types[5] = {"IDLE", "RUNNING", "WALKING"};
    std::string _type = _types[1] ;

    void switchAnimation(const AnimationType& type);

    void update(unsigned int DeltaTime);



};


#endif //RASHNAWA_ANIMATIONS_H
