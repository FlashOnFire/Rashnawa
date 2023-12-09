#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H


#include <unordered_map>

#include "Entities.h"
#include "Entity.h"

class EntityBuilder {
    EntityBuilder();

private:
    std::unordered_map<Entities, EntityPrototype> entity_prototypes_map;

    void populateEntitiesPrototypeMap();

    std::unique_ptr<Entity> buildEntity(Entities entity);
};


#endif //ENTITYBUILDER_H
