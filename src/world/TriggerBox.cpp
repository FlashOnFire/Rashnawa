#include "TriggerBox.h"

TriggerBox::TriggerBox(std::string name, const sf::IntRect rect, const int uses, const int cooldown,
                       const TriggerType type, std::string action,
                       const std::vector<std::string>& args) : name_(std::move(name)),
                                                               rect_(rect),
                                                               uses_(uses),
                                                               cooldown_(cooldown),
                                                               type_(type),
                                                               action_(std::move(action)),
                                                               args_(std::move(args_)) {
}

void TriggerBox::fireEvent(dexode::EventBus event_bus) {
    switch (type_) {
        case TriggerType::MUSIC:
            // TODO actually fire event
            break;
        case TriggerType::WORLD:
            break;
    }
}
