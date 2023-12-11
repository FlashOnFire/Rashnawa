#include "World.h"

World::World(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(event_bus) {
    entity_builder_ = std::make_shared<EntityBuilder>(event_bus_);
}

void World::load(std::string zone_name, std::string room_name) {
    loaded_rooms_.push_back(std::make_unique<Room>(zone_name, room_name, entity_builder_));
}