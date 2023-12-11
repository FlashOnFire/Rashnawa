#ifndef RASHNAWA_TRIGGERBOX_H
#define RASHNAWA_TRIGGERBOX_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <dexode/EventBus.hpp>
#include <dexode/eventbus/Bus.hpp>
#include "../events/Events.h"

enum class TriggerType {
    SOUND,
    WORLD,
    CUTSCENE
};

class TriggerBox {
public:
    TriggerBox(std::string name, sf::IntRect rect, int uses, int cooldown, TriggerType type,
               Events::Triggers::TriggerAction action, const std::vector<std::string>& args);

    inline static std::unordered_map<std::string, TriggerType> const trigger_type_map_ = {
        {"music", TriggerType::SOUND},
        {"world", TriggerType::WORLD},
    };

    inline static std::unordered_map<std::string, Events::Triggers::TriggerSoundAction> const trigger_sound_action_map_ = {
            {"start", Events::Triggers::TriggerSoundAction::START},
            {"stop", Events::Triggers::TriggerSoundAction::STOP},
            {"set", Events::Triggers::TriggerSoundAction::SET},
            {"set", Events::Triggers::TriggerSoundAction::GLOBAL_SET}
    };

    inline static std::unordered_map<std::string, Events::Triggers::TriggerWorldAction> const trigger_world_action_map_ = {
            {"zone_change", Events::Triggers::TriggerWorldAction::ZONE_CHANGE},
            {"room_change", Events::Triggers::TriggerWorldAction::ROOM_CHANGE},
    };

    inline static std::unordered_map<std::string, Events::Triggers::TriggerCutsceneAction> const trigger_cutscene_action_map_ = {
            {"start", Events::Triggers::TriggerCutsceneAction::START},
            {"start", Events::Triggers::TriggerCutsceneAction::SKIP}
    };

private:
    std::string name_;
    sf::IntRect rect_;
    int uses_;
    int cooldown_;

    TriggerType type_;
    Events::Triggers::TriggerAction action_;
    std::vector<std::string> args_;

    void fireEvent(dexode::EventBus event_bus);
};


#endif //RASHNAWA_TRIGGERBOX_H
