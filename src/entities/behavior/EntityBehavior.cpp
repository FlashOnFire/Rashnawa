#include "EntityBehavior.h"

EntityBehavior::EntityBehavior(std::shared_ptr<dexode::EventBus> event_bus, std::weak_ptr<Entity> entity) : event_bus_(std::move(event_bus)), entity_(std::move(entity)) {
}