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

ParamCollection::ParamCollection(unsigned int _uid, const char *_name) : Param(_uid, _name) {}

ParamCollection::ParamCollection(unsigned int _uid, std::string &_name) : Param(_uid, _name) {}

/**
 * @param id
 * @return *Param
 */
Param &ParamCollection::GetParameter(unsigned int uid)
{
    for (auto &param : this->Params)
    {
        if (param->getUid() == uid)
            return *param;
    }
}

Param &ParamCollection::GetParameter(std::string &name)
{
    for (auto &param : this->Params)
    {
        if ((name.compare(param->getName().c_str())) == 0)
            return *param;
    }
}
Param &ParamCollection::GetParameter(const char *name)
{
    for (auto &param : this->Params)
    {
        if ((param->getName().compare(name)) == 0)
            return *param;
    }
}
/**
 * @param Parameter
 */
void ParamCollection::AddParameter(Param *parameter)
{
    this->Params.push_back(parameter);
}

unsigned int ParamCollection::GenerateUid()
{
    return ++lastUid;
}