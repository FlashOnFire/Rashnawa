#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H


#include <unordered_map>

#include "Entities.h"
#include "Entity.h"
#include "dexode/EventBus.hpp"

class EntityBuilder {
public:
    explicit EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;
    std::unordered_map<Entities, EntityPrototype> entity_prototypes_map_;

    void populateEntitiesPrototypeMap();

    std::unique_ptr<Entity> buildEntity(Entities entity_type);
};


#endif //ENTITYBUILDER_H
