#include "BaseEntitySystem.h"
#include "ComponentManager.h"

namespace zmc
{
BaseEntitySystem::BaseEntitySystem()
{
}

BaseEntitySystem::~BaseEntitySystem()
{

}

void BaseEntitySystem::process()
{
    if (checkForProcessing()) {
        begin();
        processEntities();
        end();
    }
}

void BaseEntitySystem::processEntities()
{
    for (Entity *entity : mEntityVector) {
        if (entity->isEnabled())
            processEntity(*entity);
    }
}

void BaseEntitySystem::begin()
{

}

void BaseEntitySystem::end()
{

}

bool BaseEntitySystem::checkForEntity(Entity &entity)
{
    //If the mRequiredComponentTypes and mRequiredGroups are empty that means this system can take any component and process them
    if (mRequiredComponentTypes.size() == 0 && mRequiredGroups.size() == 0)
        return true;
    bool isEligible = false;
    if (mRequiredComponentTypes.size() > 0) {
        const std::vector<BaseComponent*> vector = entity.getComponentManager()->getComponentsOfEntity(entity.getEntityID());
        int numberOfElligableComponents = 0;
        for (BaseComponent *component : vector) {
            for (int componentType : mRequiredComponentTypes) {
                if (component->getType() == componentType)
                    numberOfElligableComponents++;
            }
        }
        isEligible = numberOfElligableComponents > 0;
    }
    if (mRequiredGroups.size() > 0) {
        const std::vector<int> vector = entity.getGroups();
        int numberOfElligableGroups = 0;
        for (int group : vector) {
            for (int requiredGroups : mRequiredGroups) {
                if (group == requiredGroups)
                    numberOfElligableGroups++;
            }
        }
        isEligible = numberOfElligableGroups > 0 && isEligible;
    }
    return isEligible;
}

void BaseEntitySystem::removeEntityFromSystem(Entity &entity)
{
    mEntityVector.erase(std::find(std::begin(mEntityVector), std::end(mEntityVector), &entity));
}

void BaseEntitySystem::addEntity(Entity &entity)
{
    //If the entity doesn't have the required components and groups, do nothing
    if (checkForEntity(entity) == false)
        return;
    mEntityVector.push_back(&entity);
}

void BaseEntitySystem::setRequiredComponents(std::vector<int> requiredComponentTypes)
{
    mRequiredComponentTypes = requiredComponentTypes;
}

void BaseEntitySystem::setRequiredGroups(std::vector<int> requiredGroups)
{
    mRequiredGroups = requiredGroups;
}
}
