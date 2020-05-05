/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Integer3Param.h"

/**
 * Integer3Param implementation
 */

 std::array<int,3> Integer3Param::GetValue() const {
    return this->value;
 }

 void Integer3Param::SetValue(std::array<int,3> value) {
    this->value = value;
 }