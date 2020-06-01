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
Param &ParamCollection::GetParameter(unsigned int _uid)
{
    for (auto &param : this->Params)
    {
        if (param->getUid() == _uid)
            return *param;
    }
    AX_LOG_CORE_ERROR("Parameter collection name : {},uid {0:d} is requested a non-existent parameter uid : {0:d} ", name, uid, _uid)
    throw "Parameter doesn't exist";
}

Param &ParamCollection::GetParameter(std::string &_name)
{
    for (auto &param : this->Params)
    {
        if ((_name.compare(param->getName().c_str())) == 0)
            return *param;
    }
    AX_LOG_CORE_ERROR("Parameter collection name : {},uid {0:d} is requested a non-existent parameter named {} ", name, uid, _name)
    throw "Parameter doesn't exist";
}
Param &ParamCollection::GetParameter(const char *_name)
{
    for (auto &param : this->Params)
    {
        if ((param->getName().compare(_name)) == 0)
            return *param;
    }
    AX_LOG_CORE_ERROR("Parameter collection name : {},uid {0:d} is requested a non-existent parameter named {} ", name, uid, _name)
    throw "Parameter doesn't exist";
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