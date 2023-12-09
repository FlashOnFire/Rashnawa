#include "EntityBuilder.h"

EntityBuilder::EntityBuilder() {
    populateEntitiesPrototypeMap();
}

void EntityBuilder::populateEntitiesPrototypeMap() {
    entity_prototypes_map.emplace(Entities::GROUND, EntityPrototype{.name = "ground", .hasAnimation = false});
    // TODO add other entities
}


