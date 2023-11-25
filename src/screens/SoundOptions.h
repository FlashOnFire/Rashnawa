#ifndef RASHNAWA_SOUNDOPTIONS_H
#define RASHNAWA_SOUNDOPTIONS_H


#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include "objects/OptionsCategory.h"

class SoundOptions : public OptionsCategory {
public:
    SoundOptions(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> sliderKnobTexture);

    void updateComponentsTransform() override;

private:
    const std::shared_ptr<sf::Texture> _sliderTexture;
    const std::shared_ptr<sf::Texture> _sliderKnobTexture;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_SOUNDOPTIONS_H
