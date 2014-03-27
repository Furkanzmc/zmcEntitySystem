#ifndef BASEENTITY_H
#define BASEENTITY_H
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief The BaseEntity class: All entity classes must inherit this class
 */
namespace zmc
{
class ComponentManager;
class BaseComponent;

class BaseEntity
{
public:
    BaseEntity();
    virtual ~BaseEntity();
    /**
     * @brief Returns true if the entity is enabled. Enabled entities can be processed by the EntitySystem
     * @return
     */
    bool isEnabled();
    /**
     * @brief Returns true if the entity is disabled. Disabled entities can't be processed by the EntitySystem
     * @return
     */
    bool isDisabled();
    /**
     * @brief Set to true to enable the entity, or false to disable it
     * @param enable
     * @return
     */
    void setEnabled(bool enable);
    /**
     * @brief Set the group of the entity. -1 value means the entity has no group
     * @param groupIdentifier
     */
    void setGroup(int groupIdentifier);
    /**
     * @brief Returns a non-zero value if the entity has a group otherwise returns -1
     * @return
     */
    int getGroup();

    void setEntityID(int id);
    int getEntityID() const;
    void setComponentManager(ComponentManager *componentManager);
    ComponentManager *getComponentManager();
    bool hasComponent(int componentType);

private:
    bool mIsEnabled;
    int mEntityID;
    /**
     * @brief -1 means the entity has no group
     */
    int mEntityGroup;
    ComponentManager *mComponentManager;
};
}
#endif // BASEENTITY_H
