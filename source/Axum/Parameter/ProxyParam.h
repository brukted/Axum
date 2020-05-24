#ifndef __PROXYPARAM_H__
#define __PROXYPARAM_H__

#include "Param.h"

/**
 * @brief A parameter that provides access to another parameter
 * 
 */
class ProxyParam : public Param
{
private:
    Param *parameter;

public:
    virtual ParamUI GetEditUI() override;

    virtual ParamUI GetDisplayUI() override;

    /**
     * @brief Get the underlying parameter
     * 
     * @return Param& a reference to the underlying object
     */
    Param &GetParam();
};
#endif // __PROXYPARAM_H__