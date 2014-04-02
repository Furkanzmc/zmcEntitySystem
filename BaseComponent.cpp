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

std::vector<int> BaseComponent::getGroups()
{
    return mComponentGroups;
}

void BaseComponent::setGroups(int numberOfGroupsToAdd, ...)
{
    va_list arguments;
    va_start(arguments, numberOfGroupsToAdd);
    for (int x = 0; x < numberOfGroupsToAdd; x++)
        mComponentGroups.push_back(va_arg(arguments, int));
    va_end(arguments);
}

void BaseComponent::setGroups(std::vector<int> groups)
{
    mComponentGroups = groups;
}

bool BaseComponent::isInGroup(int groupIdentifier)
{
    bool exists = false;
    if (std::find(mComponentGroups.begin(), mComponentGroups.end(), groupIdentifier) != mComponentGroups.end())
        exists = true;
    return exists;
}

bool BaseComponent::isInAnyGroup()
{
    return mComponentGroups.size() > 0;
}

int BaseComponent::getType()
{
    return mComponentType;
}
}
