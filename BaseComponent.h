#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H
#include <vector>
#include <algorithm>
/**
 * @brief The BaseComponent class: All component classes must inherit this class
 */
namespace zmc
{
class BaseComponent
{
public:
    explicit BaseComponent(int componentType);
    virtual ~BaseComponent();
    /**
     * @brief Returns the groups that the cmponent has
     */
    std::vector<int> getGroups();
    void setGroups(int numberOfGroupsToAdd, ...);
    void setGroups(std::vector<int> groups);
    /**
     * @brief Returns true if the component is in the specified group
     * @param groupIdentifier
     * @return
     */
    bool isInGroup(int groupIdentifier);
    /**
     * @brief Returns true if the component is in any groups
     * @return
     */
    bool isInAnyGroup();
    int getType();

private:
    bool mCanBeRemoved = false;
    std::vector<int> mComponentGroups;
    int mComponentType;
};
}
#endif // BASECOMPONENT_H
