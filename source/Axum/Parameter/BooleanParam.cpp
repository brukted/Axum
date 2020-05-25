/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */
BooleanParam::BooleanParam(unsigned int _uid, std::string &_name, bool _value) : value(_value), Param(_uid, _name) {}

BooleanParam::BooleanParam(unsigned int _uid, const char *_name, bool _value) : value(_value), Param(_uid, _name) {}

bool BooleanParam::GetValue() const
{
    return this->value;
}

void BooleanParam::SetValue(bool value)
{
    this->value = value;
    this->OnValueChanged.emit();
}