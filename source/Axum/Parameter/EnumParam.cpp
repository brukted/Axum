/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */
EnumParam::EnumParam(std::map<int, std::string> enums)
{
    this->enums = std::move(enums);
}

int EnumParam::GetKey() const
{
    return this->value;
}

void EnumParam::SetKey(int key)
{
    this->value = key;
}

std::string &EnumParam::ToValue(int key)
{
    return this->enums[key];
}