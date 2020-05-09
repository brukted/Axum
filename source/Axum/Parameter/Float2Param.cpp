/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float2Param.h"

/**
 * Float2Param implementation
 */

std::array<float, 2> Float2Param::GetValue() const
{
   return this->value;
}

void Float2Param::SetValue(std::array<float, 2> value)
{
   this->value = value;
}
