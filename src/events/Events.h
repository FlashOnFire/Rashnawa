#ifndef RASHNAWA_EVENTS_H
#define RASHNAWA_EVENTS_H


#include <memory>

#include "../screens/Screens.h"
#include "Keybinds.h"
#include "../graphics/Animations.h"
#include "../storage/options/OptionDataStructs.h"

namespace Events {
    struct CloseGame {
    };

    struct EscapeBtn {
    };

    struct ChangeScreen {
        Screens from;
        Screens to;
    };

    struct PlayerAction {
        Keybinds keybinds;
    };

    struct AnimationCreated {
        std::weak_ptr<Animation> animation;
    };

    namespace Options {
        struct SoundOptionChangeEvent {
            SoundOptionType type;
            GenericOption value;
        };

        struct GraphicsOptionChangeEvent {
            SoundOptionType type;
            GenericOption value;
        };
    }

    namespace Triggers {
        namespace Music {
            struct TriggerMusicStartEvent {
            };

            struct TriggerMusicStopEvent {
            };

            struct TriggerMusicParameterSetEvent {
                std::string parameter_name;
                float value;
            };

            struct TriggerMusicGlobalParameterSetEvent {
                std::string parameter_name;
                float value;
            };
        }

        namespace World {
            struct TriggerRoomChangeEvent {
                std::string room;
            };

            struct TriggerZoneChangeEvent {
                std::string zone;
                std::string room;
            };
        }
    }
}


#endif //RASHNAWA_EVENTS_H
