#include "ComponentManager.h"

namespace zmc
{
ComponentManager::ComponentManager()
{
}

void ComponentManager::addComponent(int entityID, std::unique_ptr<BaseComponent> compoenent)
{
    mComponentsMap.insert(std::make_pair(entityID, std::move(compoenent)));
    compoenent.reset();

}

void ComponentManager::removeComponent(int componentType)
{
    for (std::pair<const int, std::unique_ptr<BaseComponent>> &pair : mComponentsMap) {
        if (pair.second->getType() == componentType)
            mComponentsMap.erase(pair.first);
    }
}

void ComponentManager::removeComponent(int entityID, int componentType)
{
    for (std::pair<const int, std::unique_ptr<BaseComponent>> &pair : mComponentsMap) {
        if (pair.first == entityID && pair.second->getType() == componentType)
            mComponentsMap.erase(pair.first);
    }
}

void ComponentManager::removeComponentOfEntity(int componentType, BaseEntity &entity)
{
    mComponentsMap.erase(std::begin(mComponentsMap), std::find_if(std::begin(mComponentsMap), std::end(mComponentsMap),
    [&componentType, entity](std::pair<const int, std::unique_ptr<BaseComponent>> &pair) {
        return pair.second->getType() == componentType && pair.first == entity.getEntityID();
    }));
}

void ComponentManager::removeComponentsOfEntity(BaseEntity &entity)
{
    for (std::pair<const int, std::unique_ptr<BaseComponent>> &pair : mComponentsMap) {
        if (pair.first == entity.getEntityID()) {
            mComponentsMap.erase(entity.getEntityID());
        }
    }
}

std::vector<BaseComponent*> ComponentManager::getComponentsOfEntity(int entityID)
{
    std::vector<BaseComponent*> components;
    for (std::pair<const int, std::unique_ptr<BaseComponent>> &pair : mComponentsMap) {
        if (pair.first == entityID) {
            components.push_back(pair.second.get());
        }
    }
    return components;
}

void ComponentManager::clean()
{
    mComponentsMap.erase(std::begin(mComponentsMap), std::end(mComponentsMap));
}

bool ComponentManager::hasComponent(int entityID, int componentType)
{
    bool has = false;
    for (std::pair<const int, std::unique_ptr<BaseComponent>> &pair : mComponentsMap) {
        if (pair.first == entityID && pair.second->getType() == componentType) {
            has = true;
            break;
        }
    }
    return has;
}
}
