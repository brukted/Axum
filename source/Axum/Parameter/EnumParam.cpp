/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */
EnumParam::EnumParam(std::map<int, std::string> _enums, unsigned int _uid)
{
    this->enums = std::move(_enums);
    this->uid = _uid;
    value = enums.begin()->first;
}

int EnumParam::SetValue() const
{
    return this->value;
}

void EnumParam::SetValue(int key)
{
    this->value = key;
}

std::string &EnumParam::ToValue(int key)
{
    return this->enums[key];
}