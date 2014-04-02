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

void ShipEntitySystem::processEntity(BaseEntity &entity)
{
    dynamic_cast<ShipEntity*>(&entity)->update();
}
