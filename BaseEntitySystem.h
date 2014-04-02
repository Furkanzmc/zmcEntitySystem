#ifndef BASEENTITYSYSTEM_H
#define BASEENTITYSYSTEM_H
#include "BaseEntity.h"

/**
 * @brief The BaseEntitySystem class: Inherit this class to use it to manipulate your entities as you wish. You can create a system to
 * only process a certain group of entities.
 * A system can
 */
namespace zmc
{
class BaseEntitySystem
{
public:
    BaseEntitySystem();
    virtual ~BaseEntitySystem();
    /**
     * @brief Use this function to process your entites. This function calls begin(); and end(); and your processEntities(); function.
     */
    void process();
    void removeEntityFromSystem(BaseEntity &entity);
    void addEntity(BaseEntity &entity);
    void setRequiredComponents(std::vector<int> requiredComponentTypes);

protected:
    /**
     * @brief Called when the process begins
     */
    virtual void begin();
    /**
     * @brief Called when the process ends
     */
    virtual void end();
    /**
     * @brief Returns true if the system should be processed, false if not.
     * @return Bool
     */
    virtual bool checkForProcessing() = 0;
    /**
     * @brief Checks if the entity has the necessay components for this entity system
     * @return
     */
    bool checkForEntity(BaseEntity &entity);
    virtual void processEntity(BaseEntity &entity) = 0;

private:
    std::vector<BaseEntity*> mEntityVector;
    /**
     * @brief If the mRequiredComponentTypes is empty that means this system can take any component and process them
     */
    std::vector<int> mRequiredComponentTypes;

private:
    /**
     * @brief Implement this functon for the entity system to work.
     * Process the entities to your will.
     */
    void processEntities();
};
}
#endif // BASEENTITYSYSTEM_H
