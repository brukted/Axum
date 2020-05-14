/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "ParamCollection.h"

/**
 * ParamCollection implementation
 * 
 * List of parameters.
 */

/**
 * @param id
 * @return *Param
 */
Param &ParamCollection::GetParameter(unsigned int uid)
{
    for (auto &param : this->Params)
    {
        if (param.getUid() == uid)
            return param;
    }
}

Param &ParamCollection::GetParameter(std::string &name)
{
    for (auto &param : this->Params)
    {
        if ((name.compare(param.getName().c_str())) == 0)
            return param;
    }
}
Param &ParamCollection::GetParameter(const char *name)
{
    for (auto &param : this->Params)
    {
        if ((param.getName().compare(name)) == 0)
            return param;
    }
}
/**
 * @param Parameter
 */
void ParamCollection::AddParameter(Param Parameter)
{
    this->Params.push_back(Parameter);
}