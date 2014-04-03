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
    Entity* createEntity(int numberOfGroupsToAdd, ...);

    /**
     * @brief Returns a pointer to the entity with the specified ID. Template is used for dynamic casting
     * @param entityID
     * @return
     */
    Entity* getEntity(int entityID);

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
