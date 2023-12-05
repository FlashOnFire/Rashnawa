#ifndef RASHNAWA_SOUNDOPTIONS_H
#define RASHNAWA_SOUNDOPTIONS_H


#include <memory>
#include <SFML/Graphics/Texture.hpp>

#include "../storage/OptionsManager.h"
#include "objects/OptionsCategory.h"

class SoundOptions final : public OptionsCategory {
public:
    SoundOptions(std::shared_ptr<OptionsManager> options_manager,
                 std::shared_ptr<sf::Texture> slider_texture, std::shared_ptr<sf::Texture> slider_knob_texture);

    void updateComponentsTransform() override;

private:
    std::shared_ptr<OptionsManager> options_manager_;

    const std::shared_ptr<sf::Texture> slider_texture_;
    const std::shared_ptr<sf::Texture> slider_knob_texture_;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_SOUNDOPTIONS_H
