/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Package.h"

/**
 * Package implementation
 * 
 * Easily Seriliazible Data Type containg all infos about the currrent session
 */


/**
 * @param UUID
 * @return *Resource
 */
Resource& Package::GetResource(unsigned int uid) {
for(auto &var : this->Resources)
{
    if(var.uid == uid) return var;
}
}