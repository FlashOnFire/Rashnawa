#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H

#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>


class Animation {
public:

    Animation(const std::string& fileName);

    std::vector<unsigned int> FRAME_PER_TIMELINE;
    sf::Vector2i _lenght_width = sf::Vector2i(0, 0); //pour stocker la taille des frames
    unsigned int _frame_time = 1000; //temps de frame
    unsigned int _total_animation_time = 0; // _frame_time * FRAME_PER_TIMELINE.at(0);
    unsigned int _current_timeline = 0; //indice de la timeline dans notre vecteur
    unsigned int _current_frame = 0; //frame active
    unsigned int _current_time = 0; //temps qui passe dans l'animation


    void setTimeline(unsigned int new_timeline); //reset les frames et change la timeline

    void update(unsigned int deltaTime);


};


#endif //RASHNAWA_ANIMATIONS_H
