#include "World.h"

#include <utility>

World::World(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    entity_builder_ = std::make_shared<EntityBuilder>(event_bus_);
    std::cout << "Created World!" << std::endl;
}

std::shared_ptr<Room> World::getCurrentRoom() const {
    return current_room_;
}

void World::load(const std::string &zone_name, const std::string &room_name) {
    current_room_ = std::make_shared<Room>(zone_name, room_name, entity_builder_);
    loaded_rooms_.push_back(current_room_);

    for (auto triggers = current_room_->getTriggers(); const auto &current_trigger: *triggers) {
        if (current_trigger->getTriggerType() == TriggerType::WORLD &&
            current_trigger->getAction().world == Events::Triggers::TriggerWorldAction::ROOM_CHANGE) {
            loaded_rooms_.emplace_back(
                    std::make_shared<Room>(zone_name, current_trigger->getArgs()[0], entity_builder_));
        }
    }

    std::cout << "Room loaded!" << std::endl;
}