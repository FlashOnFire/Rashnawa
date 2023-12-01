#ifndef RASHNAWA_EVENTS_H
#define RASHNAWA_EVENTS_H


#include <memory>

#include "../screens/Screens.h"
#include "Keybinds.h"
#include "../graphics/Animations.h"

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
}


#endif //RASHNAWA_EVENTS_H
