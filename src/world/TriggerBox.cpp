#include "TriggerBox.h"

TriggerBox::TriggerBox(std::string name, sf::IntRect rect, TriggerType type, std::string action, std::vector<std::string> args) {
    name_ = name;
    rect_ = rect;
    type_ = type;
    action_ = action;
    args_ = args;
}
