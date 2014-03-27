#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "BaseEntity.h"
#include <map>
#include <memory>

/**
 * @brief The EntityManager class: It manages the removal, creation and processing of the entities.
 */
namespace zmc
{
class EntityManager
{
public:
    explicit EntityManager(ComponentManager *componentManager);
    ~EntityManager();
    template <class E>
    /**
     * @brief Creates an entity with the default component manager and gives it a unique ID. If you don't want any group, just pass -1
     * @param groupIdentifier
     * @return
     */
    E* createEntity(int groupIdentifier)
    {
        std::unique_ptr<BaseEntity> entity(new E());
        entity->setEntityID(mLastEntityID++);
        entity->setGroup(groupIdentifier);
        entity->setComponentManager(mComponentManager);
        mEntityMap.insert(std::make_pair(mLastEntityID , std::move(entity)));
        return dynamic_cast<E*>(mEntityMap.at(mLastEntityID).get());
    }

    /**
     * @brief Returns a pointer to the entity with the specified ID. Template is used for dynamic casting
     * @param entityID
     * @return
     */
    template <class Entity>
    BaseEntity* getEntity(int entityID)
    {
        return dynamic_cast<Entity*>(mEntityMap.at(entityID).get());
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
    std::vector<BaseEntity*> getEntitiesInGroup(int groupIdentifier);

private:
    int mLastEntityID;
    std::map<int, std::unique_ptr<BaseEntity>> mEntityMap;
    ComponentManager *mComponentManager;
};
}
#endif // ENTITYMANAGER_H
