#ifndef RASHNAWA_TRIGGERBOX_H
#define RASHNAWA_TRIGGERBOX_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <dexode/EventBus.hpp>
#include <dexode/eventbus/Bus.hpp>

enum class TriggerType {
    MUSIC,
    WORLD,
};

class TriggerBox {
public:
    TriggerBox(std::string name, sf::IntRect rect, int uses, int cooldown, TriggerType type, std::string action,
               const std::vector<std::string>& args);

    inline static std::unordered_map<std::string, TriggerType> const trigger_type_map_ = {
        {"music", TriggerType::MUSIC},
        {"world", TriggerType::WORLD},
    };

private:
    std::string name_;
    sf::IntRect rect_;
    int uses_;
    int cooldown_;

    TriggerType type_;
    std::string action_;
    std::vector<std::string> args_;

    void fireEvent(dexode::EventBus event_bus);
};


#endif //RASHNAWA_TRIGGERBOX_H
