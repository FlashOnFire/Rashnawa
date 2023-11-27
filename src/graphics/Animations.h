#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H

#include <iostream>


class Animations {
public:
    enum {
        COURSE=0,
        MARCHE=1,
        SAUT=2
    };

    unsigned int NB_FRAME;
    unsigned int FRAME_TIME;
    unsigned int _current_time ;
    unsigned int _current_frame ;
//    enum int type = COURSE;
    std::string texture_name ;


    void update(unsigned int DeltaTime);

    void setFrame();


};


#endif //RASHNAWA_ANIMATIONS_H
