#include "BaseComponent.h"

namespace zmc
{
BaseComponent::BaseComponent(int componentType)
    : mComponentType(componentType)
{

}

BaseComponent::~BaseComponent()
{

}

bool BaseComponent::canBeRemoved()
{
    return mCanBeRemoved;
}

void BaseComponent::removeComponent()
{
    mCanBeRemoved = true;
}

int BaseComponent::getGroup()
{
    return mComponentGroup;
}

void BaseComponent::setGroup(int groupIdentifier)
{
    mComponentGroup = groupIdentifier;
}

int BaseComponent::getType()
{
    return mComponentType;
}
}
