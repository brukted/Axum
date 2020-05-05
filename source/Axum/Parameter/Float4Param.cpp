/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Float4Param.h"

/**
 * Float4Param implementation
 */

 std::array<float,4> Float4Param::GetValue() const{
    return this->value;
 }

 void Float4Param::SetValue(std::array<float,4> value) {
    this->value = value;
 }