#include "ComponentManager.h"

namespace zmc
{
BaseEntity::BaseEntity()
    : mIsEnabled(true)
    , mEntityID(-1)
    , mComponentManager(nullptr)
{

}

BaseEntity::~BaseEntity()
{

}

bool BaseEntity::isEnabled()
{
    return mIsEnabled;
}

bool BaseEntity::isDisabled()
{
    return !mIsEnabled;
}

void BaseEntity::setEnabled(bool enable)
{
    mIsEnabled = enable;
}

void BaseEntity::setGroups(int numberOfGroupsToAdd, ...)
{
    va_list arguments;
    va_start(arguments, numberOfGroupsToAdd);
    for (int x = 0; x < numberOfGroupsToAdd; x++) {
        const int g = va_arg(arguments, int);
        if (isInGroup(g) == false)
            mEntityGroups.push_back(g);
    }
    va_end(arguments);
}

void BaseEntity::setGroups(std::vector<int> groups)
{
    for (int g : groups) {
        if (isInGroup(g) == false)
            mEntityGroups.push_back(g);
    }
}

void BaseEntity::addGroup(int groupIdentifier)
{
    if (isInGroup(groupIdentifier) == false) {
        mEntityGroups.push_back(groupIdentifier);
    }
}

const std::vector<int> &BaseEntity::getGroups()
{
    return mEntityGroups;
}

bool BaseEntity::isInGroup(int groupIdentifier)
{
    bool exists = false;
    if (std::find(mEntityGroups.begin(), mEntityGroups.end(), groupIdentifier) != mEntityGroups.end())
        exists = true;
    return exists;
}

bool BaseEntity::isInAnyGroup()
{
    return mEntityGroups.size() > 0;
}

void BaseEntity::setEntityID(int id)
{
    //If ID is already set, do nothing
    if (mEntityID != -1)
        return;
    mEntityID = id;
}

int BaseEntity::getEntityID() const
{
    return mEntityID;
}

void BaseEntity::setComponentManager(ComponentManager *componentManager)
{
    if (mComponentManager != nullptr)
        return;
    mComponentManager = componentManager;
}

zmc::ComponentManager *BaseEntity::getComponentManager()
{
    return mComponentManager;
}

bool BaseEntity::hasComponent(int componentType)
{
    return mComponentManager->hasComponent(mEntityID, componentType);
}
}
