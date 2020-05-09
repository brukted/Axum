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
        if (param.uid == uid)
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