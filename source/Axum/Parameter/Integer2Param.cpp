/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Integer2Param.h"

/**
 * Integer2Param implementation
 */

 std::array<int,2> Integer2Param::GetValue() const {
    return this->value;
 }

 void Integer2Param::SetValue(std::array<int,2> value) {
    this->value = value;
 }