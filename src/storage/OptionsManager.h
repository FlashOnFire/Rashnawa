#ifndef RASHNAWA_OPTIONSSTATE_H
#define RASHNAWA_OPTIONSSTATE_H
#include <memory>
#include <dexode/EventBus.hpp>

#include "options/OptionDataStructs.h"

const std::string OPTIONS_FILE_NAME = "options.txt";

class OptionsManager {
public:
    explicit OptionsManager(std::shared_ptr<dexode::EventBus> event_bus);

    void loadOptionsSnapshot();

    void saveOptionsSnapshot() const;

    [[nodiscard]] SoundOptionData getSoundOptions() const;

    [[nodiscard]] GenericOption getSoundOption(const SoundOptionType& type) const;

    void setSoundOptions(const SoundOptionData& sound_options);

    void setSoundOption(const SoundOptionType& type, const GenericOption &value);

    [[nodiscard]] GraphicsOptionsData getGraphicsOptionsData() const;

    [[nodiscard]] GenericOption getGraphicsOption(const GraphicsOptionType& type) const;

    void setGraphicsOptionsData(const GraphicsOptionsData& graphics_options_data);

    [[nodiscard]] OptionsSnapshot getOptionsSnapshot() const;

    void setOptionsSnapshot(const OptionsSnapshot& options_snapshot);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;

    OptionsSnapshot options_snapshot_;
};


#endif //RASHNAWA_OPTIONSSTATE_H
