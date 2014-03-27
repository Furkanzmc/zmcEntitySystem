#ifndef SHIPENTITYSYSTEM_H
#define SHIPENTITYSYSTEM_H
#include "BaseEntitySystem.h"
#include "ShipEntity.h"
using namespace zmc;

class ShipEntitySystem : public BaseEntitySystem
{
public:
    ShipEntitySystem();
    ~ShipEntitySystem();
    virtual void setRequiredComponentTypes(std::vector<int> requiredComponentTypes);

private:
    virtual bool checkForProcessing();
    virtual void processEntity(zmc::BaseEntity &entity);
};

#endif // SHIPENTITYSYSTEM_H
