#include "EntityManager.h"

namespace zmc
{
EntityManager::EntityManager(ComponentManager *componentManager)
    : mLastEntityID(0)
    , mComponentManager(componentManager)
{
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
