/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerParam.h"

/**
 * IntegerParam implementation
 */

IntegerParam::IntegerParam(unsigned int _uid)
{
    uid = _uid;
}

int IntegerParam::GetValue() const
{
    return this->value;
}

void IntegerParam::SetValue(int value)
{
    this->value = value;
}