#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "Entity.h"
#include <map>
#include <memory>
#include <cassert>

/**
 * @brief The EntityManager class: It manages the removal, creation and processing of the entities.
 */
namespace zmc
{
class EntityManager
{
public:
    explicit EntityManager(ComponentManager *componentManager);
    /**
     * @brief Creates an entity with the default component manager and gives it a unique ID. If you don't want any group, just pass -1
     * @param groupIdentifier
     * @return
     */
    template <class E>
    E * const createEntity(int numberOfGroupsToAdd, ...)
    {
        std::unique_ptr<E> entity(new E());
        entity->setEntityID(mLastEntityID++);
        std::vector<int> groups;
        if (numberOfGroupsToAdd > 0) {
            va_list arguments;
            va_start(arguments, numberOfGroupsToAdd);
            for (int x = 0; x < numberOfGroupsToAdd; x++)
                groups.push_back(va_arg(arguments, int));
            va_end(arguments);
            entity->setGroups(groups);
        }
        entity->setComponentManager(mComponentManager);
        mEntityMap.insert(std::make_pair(mLastEntityID , std::move(entity)));
        assert((void*)dynamic_cast<E*>(mEntityMap.at(mLastEntityID).get()) && "Member does not point to the wanted type!");
        return static_cast<E*>(mEntityMap.at(mLastEntityID).get());
    }

    /**
     * @brief Returns a pointer to the entity with the specified ID. Template is used for dynamic casting
     * @param entityID
     * @return
     */
    template <class Entity>
    Entity* const getEntity(int entityID)
    {
        assert((void*)dynamic_cast<Entity*>(mEntityMap.at(entityID).get()) && "Member does not point to the wanted type!");
        return static_cast<Entity*>(mEntityMap.at(entityID).get());
    }

    /**
     * @brief Returns the number of entites in the manager
     * @return
     */
    int getEntityCount();
    /**
     * @brief Removes the entity with the specified ID
     * @param entityID
     */
    void removeEntity(int entityID);
    /**
     * @brief Removes all of the entities that are in the specified group
     * @param groupIdentifier
     */
    void removeEntitiesInGroup(int groupIdentifier);
    /**
     * @brief Removes all of the entities that are in the specified group
     * @param groupIdentifier
     * @return
     */
    std::vector<Entity*> getEntitiesInGroup(int groupIdentifier);

private:
    int mLastEntityID;
    /**
     * @brief int --> Entity ID
     */
    std::map<int, std::unique_ptr<Entity>> mEntityMap;
    ComponentManager *mComponentManager;
};
}
#endif // ENTITYMANAGER_H
