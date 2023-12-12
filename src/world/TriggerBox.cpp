#include "TriggerBox.h"

TriggerBox::TriggerBox(std::string name, const sf::IntRect rect, const int uses, const int cooldown,
                       const TriggerType type, Events::Triggers::TriggerAction action,
                       const std::vector<std::string> &args) : name_(std::move(name)),
                                                               rect_(rect),
                                                               uses_(uses),
                                                               cooldown_(cooldown),
                                                               type_(type),
                                                               action_(action),
                                                               args_(args) {
}

void TriggerBox::fireEvent(dexode::EventBus event_bus) {
    switch (type_) {
        case TriggerType::SOUND:
            switch (action_.sound) {
                using enum Events::Triggers::TriggerSoundAction;

                case START:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicStartEvent>({.name = args_[0]});
                    break;
                case STOP:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicStopEvent>({});
                    break;
                case PARAMETER_SET:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicParameterSetEvent>(
                            {.parameter_name = args_[0], .value = stof(args_[1])});
                    break;
                case GLOBAL_PARAMETER_SET:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicGlobalParameterSetEvent>(
                            {.parameter_name = args_[0], .value = stof(args_[1])});
                    break;
            }
            break;
        case TriggerType::WORLD:
            switch (action_.world) {
                using enum Events::Triggers::TriggerWorldAction;

                case ZONE_CHANGE:
                    event_bus.postpone<Events::Triggers::World::TriggerZoneChangeEvent>(
                            {.zone = args_[0], .room = args_[1]});
                    break;
                case ROOM_CHANGE:
                    event_bus.postpone<Events::Triggers::World::TriggerRoomChangeEvent>({.room = args_[0]});
                    break;
            }
            break;
        case TriggerType::CUTSCENE:
            switch (action_.cutscene) {
                using enum Events::Triggers::TriggerCutsceneAction;

                case START:
                    event_bus.postpone<Events::Triggers::Cutscene::TriggerCutsceneStartEvent>({.cutscene_name = args_[0]});
                    break;
                case SKIP:
                    event_bus.postpone<Events::Triggers::Cutscene::TriggerCutsceneSkipEvent>({});
                    break;
            }
            break;
    }
}

TriggerType TriggerBox::getTriggerType() const {
    return type_;
}

Events::Triggers::TriggerAction TriggerBox::getAction() const {
    return action_;
}

std::vector<std::string> TriggerBox::getArgs() const {
    return args_;
}