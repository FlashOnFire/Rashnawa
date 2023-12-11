#include "TriggerBox.h"

TriggerBox::TriggerBox(std::string name, const sf::IntRect rect, const int uses, const int cooldown,
                       const TriggerType type, Events::Triggers::TriggerAction action,
                       const std::vector<std::string> &args) : name_(std::move(name)),
                                                               rect_(rect),
                                                               uses_(uses),
                                                               cooldown_(cooldown),
                                                               type_(type),
                                                               action_(action),
                                                               args_(std::move(args_)) {
}

void TriggerBox::fireEvent(dexode::EventBus event_bus) {
    switch (type_) {
        case TriggerType::SOUND:
            switch (action_.sound) {
                case Events::Triggers::TriggerSoundAction::START:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicStartEvent>({.name = args_[0]});
                    break;
                case Events::Triggers::TriggerSoundAction::STOP:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicStopEvent>({});
                    break;
                case Events::Triggers::TriggerSoundAction::SET:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicParameterSetEvent>(
                            {.parameter_name = args_[0], .value = stof(args_[1])});
                    break;
                case Events::Triggers::TriggerSoundAction::GLOBAL_SET:
                    event_bus.postpone<Events::Triggers::Sound::TriggerMusicGlobalParameterSetEvent>(
                            {.parameter_name = args_[0], .value = stof(args_[1])});
                    break;
            }
            break;
        case TriggerType::WORLD:
            switch (action_.world) {
                case Events::Triggers::TriggerWorldAction::ZONE_CHANGE:
                    event_bus.postpone<Events::Triggers::World::TriggerZoneChangeEvent>(
                            {.zone = args_[0], .room = args_[1]});
                    break;
                case Events::Triggers::TriggerWorldAction::ROOM_CHANGE:
                    event_bus.postpone<Events::Triggers::World::TriggerRoomChangeEvent>({.room = args_[0]});
                    break;
            }
            break;
        case TriggerType::CUTSCENE:
            switch (action_.cutscene) {
                case Events::Triggers::TriggerCutsceneAction::START:
                    event_bus.postpone<Events::Triggers::Cutscene::TriggerCutsceneStartEvent>({.cutscene_name = args_[0]});
                    break;
                case Events::Triggers::TriggerCutsceneAction::SKIP:
                    event_bus.postpone<Events::Triggers::Cutscene::TriggerCutsceneSkipEvent({});
                    break;
            }
            break;
    }
}
