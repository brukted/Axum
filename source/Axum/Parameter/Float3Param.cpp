/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float3Param.h"

/**
 * Float3Param implementation
 */

std::array<float, 3> Float3Param::GetValue() const
{
   return this->value;
}

void Float3Param::SetValue(std::array<float, 3> value)
{
   this->value = value;
}