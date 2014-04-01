#include "ShipEntitySystem.h"

ShipEntitySystem::ShipEntitySystem()
{
}

ShipEntitySystem::~ShipEntitySystem()
{

}

bool ShipEntitySystem::checkForProcessing()
{
    return true;
}

void ShipEntitySystem::setRequiredComponentTypes(std::vector<int> requiredComponentTypes)
{
    setRequiredComponents(requiredComponentTypes);
}

void ShipEntitySystem::processEntity(BaseEntity &entity)
{
    dynamic_cast<ShipEntity*>(&entity)->update();
}
