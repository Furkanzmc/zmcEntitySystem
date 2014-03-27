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
    virtual bool isEnabled();
    /**
     * @brief Returns true if the entity is disabled. Disabled entities can't be processed by the EntitySystem
     * @return
     */
    virtual bool isDisabled();
    /**
     * @brief Set to true to enable the entity, or false to disable it
     * @param enable
     * @return
     */
    virtual void setEnabled(bool enable);
    /**
     * @brief Set the group of the entity. -1 value means the entity has no group
     * @param groupIdentifier
     */
    virtual void setGroup(int groupIdentifier);
    /**
     * @brief Returns a non-zero value if the entity has a group otherwise returns -1
     * @return
     */
    virtual int getGroup();

    virtual void setEntityID(int id);
    virtual int getEntityID() const;
    virtual void setComponentManager(std::shared_ptr<ComponentManager> componentManager);
    virtual std::shared_ptr<ComponentManager> getComponentManager();
    virtual bool hasComponent(int componentType);

protected:
    bool mIsEnabled;
    int mEntityID;
    /**
     * @brief -1 means the entity has no group
     */
    int mEntityGroup;
    std::shared_ptr<ComponentManager> mComponentManager;
};
}
#endif // BASEENTITY_H
