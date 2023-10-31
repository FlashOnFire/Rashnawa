#ifndef RASHNAWA_BASICSCREEN_H
#define RASHNAWA_BASICSCREEN_H

#include <memory>

#include <SFML/Graphics.hpp>

class BasicScreen {
public:
    virtual ~BasicScreen();

    virtual void update(const sf::Event &e);
    virtual void render(std::shared_ptr<sf::RenderWindow>, const sf::Font &font) const;

protected:
    BasicScreen() = default;
};


#endif //RASHNAWA_BASICSCREEN_H
