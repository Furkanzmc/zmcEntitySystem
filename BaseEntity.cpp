#include "ComponentManager.h"

namespace zmc
{
BaseEntity::BaseEntity()
    : mIsEnabled(true)
    , mEntityID(-1)
    , mEntityGroup(-1)
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

void BaseEntity::setGroup(int groupIdentifier)
{
    mEntityGroup = groupIdentifier;
}

int BaseEntity::getGroup()
{
    return mEntityGroup;
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
