#ifndef SHIPENTITY_H
#define SHIPENTITY_H
#include "BaseEntity.h"
#include "MovementComponent.h"
#include "ComponentManager.h"
#include <SFML/Graphics.hpp>

class ShipEntity : public zmc::BaseEntity, public sf::Sprite
{
public:
    ShipEntity();
    ~ShipEntity();
    void update();

private:
    sf::Texture texture;
};

#endif // SHIPENTITY_H
