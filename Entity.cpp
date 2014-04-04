#include "ComponentManager.h"

namespace zmc
{
Entity::Entity()
    : mIsEnabled(true)
    , mEntityID(-1)
    , mComponentManager(nullptr)
{

}

Entity::~Entity()
{

}

bool Entity::isEnabled()
{
    return mIsEnabled;
}

bool Entity::isDisabled()
{
    return !mIsEnabled;
}

void Entity::setEnabled(bool enable)
{
    mIsEnabled = enable;
}

void Entity::setGroups(int numberOfGroupsToAdd, ...)
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

void Entity::setGroups(std::vector<int> groups)
{
    for (int g : groups) {
        if (isInGroup(g) == false)
            mEntityGroups.push_back(g);
    }
}

void Entity::addGroup(int groupIdentifier)
{
    if (isInGroup(groupIdentifier) == false) {
        mEntityGroups.push_back(groupIdentifier);
    }
}

const std::vector<int> &Entity::getGroups()
{
    return mEntityGroups;
}

bool Entity::isInGroup(int groupIdentifier)
{
    bool exists = false;
    if (std::find(mEntityGroups.begin(), mEntityGroups.end(), groupIdentifier) != mEntityGroups.end())
        exists = true;
    return exists;
}

bool Entity::isInAnyGroup()
{
    return mEntityGroups.size() > 0;
}

void Entity::setEntityID(int id)
{
    //If ID is already set, do nothing
    if (mEntityID != -1)
        return;
    mEntityID = id;
}

int Entity::getEntityID() const
{
    return mEntityID;
}

void Entity::setComponentManager(ComponentManager *componentManager)
{
    if (mComponentManager != nullptr)
        return;
    mComponentManager = componentManager;
}

zmc::ComponentManager *Entity::getComponentManager()
{
    return mComponentManager;
}

bool Entity::hasComponent(int componentType)
{
    return mComponentManager->hasComponent(mEntityID, componentType);
}

void Entity::setCustomIdentifier(int identifier)
{
    mCustomIndentifier = identifier;
}

int Entity::getCustomIdentifier()
{
    return mCustomIndentifier;
}
}
