#ifndef RASHNAWA_OPTIONSSTATE_H
#define RASHNAWA_OPTIONSSTATE_H
#include <memory>
#include <dexode/EventBus.hpp>

#include "options/OptionDataStructs.h"


class OptionsManager {
public:
    explicit OptionsManager(std::shared_ptr<dexode::EventBus> event_bus);

    [[nodiscard]] SoundOptionData getSoundOptions() const;

    [[nodiscard]] GenericOption getSoundOption(const SoundOptionType& type) const;

    void setSoundOptions(const SoundOptionData& sound_options);

    void setSoundOption(const SoundOptionType& type, GenericOption value);

    [[nodiscard]] GraphicsOptionsData getGraphicsOptionsData() const;

    [[nodiscard]] GenericOption getGraphicsOption(const GraphicsOptionType& type) const;

    void setGraphicsOptionsData(const GraphicsOptionsData& graphics_options_data);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;

    SoundOptionData sound_options_;
    GraphicsOptionsData graphics_options_;
};


#endif //RASHNAWA_OPTIONSSTATE_H
