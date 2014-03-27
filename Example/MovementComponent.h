#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H
#include "BaseComponent.h"

class MovementComponent : public zmc::BaseComponent
{
public:
    MovementComponent(float x, float y, int compoenentType);
    float posx;
    float posy;
    void setPosition(float x, float y);
    void move(float x, float y);
};

#endif // MOVEMENTCOMPONENT_H
