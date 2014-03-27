#include "EntityManager.h"

namespace zmc
{
EntityManager::EntityManager(std::shared_ptr<ComponentManager> componentManager)
    : mLastEntityID(0)
    , mComponentManager(componentManager)
{
}

EntityManager::~EntityManager()
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
    for (std::pair<const int, std::unique_ptr<BaseEntity>> &pair : mEntityMap) {
        if (pair.second->getGroup() == groupIdentifier)
            mEntityMap.erase(pair.second->getEntityID());
    }
}

std::vector<BaseEntity *> EntityManager::getEntitiesInGroup(int groupIdentifier)
{
    std::vector<BaseEntity*> group;
    for (std::pair<const int, std::unique_ptr<BaseEntity>> &pair : mEntityMap) {
        if (pair.second->getGroup() == groupIdentifier) {
            group.push_back(mEntityMap.at(pair.second->getEntityID()).get());
        }
    }
    return group;
}
}
