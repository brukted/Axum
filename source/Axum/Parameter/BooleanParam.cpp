/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */

bool BooleanParam::GetValue() const
{
    return this->value;
}

void BooleanParam::SetValue(bool value)
{
    this->value = value;
}