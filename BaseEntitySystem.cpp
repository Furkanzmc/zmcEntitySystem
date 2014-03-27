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
    for (BaseEntity *entity : mEntityVector) {
        processEntity(*entity);
    }
}

void BaseEntitySystem::begin()
{

}

void BaseEntitySystem::end()
{

}

bool BaseEntitySystem::checkForEntity(BaseEntity &entity)
{
    //If the mRequiredComponentTypes is empty that means this system can take any component and process them
    if (mRequiredComponentTypes.size() == 0)
        return true;
    bool isEligible = false;
    std::vector<BaseComponent*> vector = entity.getComponentManager()->getComponentsOfEntity(entity.getEntityID());
    int numberOfElligableComponents = 0;
    for (BaseComponent *component : vector) {
        for (int componentType : mRequiredComponentTypes) {
            if (component->getType() == componentType)
                numberOfElligableComponents++;
        }
    }
    isEligible = numberOfElligableComponents > 0;
    return isEligible;
}

void BaseEntitySystem::removeEntityFromSystem(BaseEntity &entity)
{
    mEntityVector.erase(std::find(std::begin(mEntityVector), std::end(mEntityVector), &entity));
}

void BaseEntitySystem::addEntity(BaseEntity &entity)
{
    //If the entity doesn't have the required components, do nothing
    if (checkForEntity(entity) == false)
        return;
    mEntityVector.push_back(&entity);
}
}
