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

std::vector<int> BaseComponent::getGroups()
{
    return mComponentGroups;
}

void BaseComponent::setGroups(int numberOfGroupsToAdd, ...)
{
    va_list arguments;
    va_start(arguments, numberOfGroupsToAdd);
    for (int x = 0; x < numberOfGroupsToAdd; x++) {
        const int g = va_arg(arguments, int);
        if (isInGroup(g) == false)
            mComponentGroups.push_back(g);
    }
    va_end(arguments);
}

void BaseComponent::setGroups(std::vector<int> groups)
{
    for (int g : groups) {
        if (isInGroup(g) == false)
            mComponentGroups.push_back(g);
    }
}

void BaseComponent::addGroup(int groupIdentifier)
{
    if (isInGroup(groupIdentifier) == false) {
        mComponentGroups.push_back(groupIdentifier);
    }
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
