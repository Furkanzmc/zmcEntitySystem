#include "ShipEntity.h"

ShipEntity::ShipEntity()
    : texture()
{
    if (texture.loadFromFile("/home/furkan/Pictures/SpaceShooter/PNG/playerShip1_blue.png")) {
        setTexture(texture);
    }
}

ShipEntity::~ShipEntity()
{
}

void ShipEntity::update()
{
    //Get the component by entity ID and update it.
    MovementComponent *component = getComponentManager()->getComponentOfEntity<MovementComponent>(getEntityID());
    if (component) {
        component->posx += 1;
        component->posy += 1;
        setPosition(component->posx, component->posy);
    }
}
