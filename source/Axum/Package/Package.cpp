/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Package.h"

/**
 * Package implementation
 * 
 * Easily Serializable Data Type containing all infos about the current session
 */

/**
 * @param UUID
 * @return *Resource
 */
Resource &Package::GetResource(unsigned int uid)
{
    for (auto &var : this->Resources)
    {
        if (var.uid == uid)
            return var;
    }
}