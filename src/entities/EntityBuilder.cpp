#include "EntityBuilder.h"
#include "../events/Events.h"

EntityBuilder::EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    populateEntitiesPrototypeMap();
}

void EntityBuilder::populateEntitiesPrototypeMap() {
    entity_prototypes_map_.emplace(Entities::GROUND, EntityPrototype{.name = "ground", .has_animation = false});
    entity_prototypes_map_.emplace(Entities::PLAYER, EntityPrototype{.name = "halteroman", .has_animation = true});
}

std::unique_ptr<Entity> EntityBuilder::buildEntity(Entities entity_type) {
    const auto prototype = entity_prototypes_map_.find(entity_type)->second;
    auto entity = std::make_unique<Entity>(prototype.name, prototype.has_animation);

    if (prototype.has_animation) {
        event_bus_->postpone<Events::AnimationCreated>({entity->getAnimation().value()});
    }

    return entity;
}
