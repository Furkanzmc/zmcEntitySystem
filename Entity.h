#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief The Entity class: All entity classes must inherit this class
 */
namespace zmc
{
class ComponentManager;

class Entity
{
public:
    Entity();
    virtual ~Entity();
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
     * @brief This overwrites the existing groups that the entity has
     * @param groupIdentifier
     */
    void setGroups(int numberOfGroupsToAdd, ...);
    void setGroups(std::vector<int> groups);
    /**
     * @brief Adds a group to the already existing groups
     * @param groupIdentifier
     */
    void addGroup(int groupIdentifier);
    /**
     * @brief Returns the groups that the entity has
     * @return
     */
    const std::vector<int>& getGroups();
    /**
     * @brief Returns true if the enitity is in the specified group
     * @param groupIdentifier
     * @return
     */
    bool isInGroup(int groupIdentifier);
    /**
     * @brief Returns true if the entity is in any groups
     * @return
     */
    bool isInAnyGroup();

    /**
     * @brief This function is called by the EntityManager and cannot be called again after the ID has been set
     * @param id
     */
    void setEntityID(int id);
    int getEntityID() const;
    void setComponentManager(ComponentManager *componentManager);
    ComponentManager *getComponentManager();
    bool hasComponent(int componentType);

private:
    bool mIsEnabled;
    int mEntityID;
    /**
     * @brief Empty means the entity has no group
     */
    std::vector<int> mEntityGroups;
    ComponentManager *mComponentManager;
};
}
#endif // ENTITY_H
