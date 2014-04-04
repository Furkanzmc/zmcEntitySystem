#include "EntityManager.h"

namespace zmc
{
EntityManager::EntityManager(ComponentManager *componentManager)
    : mLastEntityID(0)
    , mComponentManager(componentManager)
{
}

Entity* EntityManager::createEntity(int numberOfGroupsToAdd, ...)
{
    std::unique_ptr<Entity> entity(new Entity());
    entity->setEntityID(mLastEntityID++);
    int id = entity->getEntityID();
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
    mEntityMap.insert(std::make_pair(id , std::move(entity)));
    return mEntityMap.at(id).get();
}

Entity* EntityManager::getEntity(int entityID)
{
    return mEntityMap.at(entityID).get();
}

Entity* EntityManager::getEntityByCustomIdentifier(int identifier)
{
    Entity *returnEntity = nullptr;
    for (std::pair<const int, std::unique_ptr<Entity>> &pair : mEntityMap) {
        if (pair.second->getCustomIdentifier() == identifier) {
            returnEntity = pair.second.get();
        }
    }
    return returnEntity;
}

int EntityManager::getEntityCount()
{
    return mEntityMap.size();
}

void EntityManager::removeEntity(int entityID)
{
    auto found = mEntityMap.find(entityID);
    //No entity
    if (found == mEntityMap.end())
        return;
    mEntityMap.erase(entityID);
}

void EntityManager::removeEntitiesInGroup(int groupIdentifier)
{
    for (std::pair<const int, std::unique_ptr<Entity>> &pair : mEntityMap) {
        std::vector<int> groups = pair.second->getGroups();
        for (int group : groups) {
            if (group == groupIdentifier)
                mEntityMap.erase(pair.second->getEntityID());
        }
    }
}

std::vector<Entity *> EntityManager::getEntitiesInGroup(int groupIdentifier)
{
    std::vector<Entity*> group;
    for (std::pair<const int, std::unique_ptr<Entity>> &pair : mEntityMap) {
        std::vector<int> groups = pair.second->getGroups();
        for (int groupName : groups) {
            if (groupName == groupIdentifier) {
                group.push_back(mEntityMap.at(pair.second->getEntityID()).get());
            }
        }
    }
    return group;
}
}
