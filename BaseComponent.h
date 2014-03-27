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
    virtual bool canBeRemoved();
    virtual void removeComponent();
    /**
     * @brief Returns a non-zero number if the component has a group
     */
    virtual int getGroup();
    virtual void setGroup(int groupIdentifier);
    virtual int getType();

private:
    bool mCanBeRemoved = false;
    int mComponentGroup = -1;
    int mComponentType;
};
}
#endif // BASECOMPONENT_H
