#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H
/**
 * @brief The BaseComponent class: All component classes must inherit this class
 */
namespace zmc
{
class BaseComponent
{
public:
    BaseComponent(int componentType);
    virtual ~BaseComponent();
    bool canBeRemoved();
    void removeComponent();
    /**
     * @brief Returns a non-zero number if the component has a group
     */
    int getGroup();
    void setGroup(int groupIdentifier);
    int getType();

private:
    bool mCanBeRemoved = false;
    int mComponentGroup = -1;
    int mComponentType;
};
}
#endif // BASECOMPONENT_H
