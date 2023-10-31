#ifndef RASHNAWA_BASICSCREEN_H
#define RASHNAWA_BASICSCREEN_H

#include <memory>
#include <SFML/Graphics.hpp>

class BasicScreen {
public:
    virtual void update(int deltaT);
    virtual void render(std::shared_ptr<sf::RenderWindow>) const;

protected:
    BasicScreen() = default;
};


#endif //RASHNAWA_BASICSCREEN_H
