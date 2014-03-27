#include "MovementComponent.h"

MovementComponent::MovementComponent(float x, float y, int compoenentType)
    : BaseComponent(compoenentType)
    , posx(x)
    , posy(y)
{
}

void MovementComponent::setPosition(float x, float y)
{
    posx = x;
    posy = y;
}

void MovementComponent::move(float x, float y)
{
    posx += x;
    posy += y;
}
