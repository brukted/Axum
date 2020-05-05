/**
 * Project Material Lab
 * @author Bruk Tedla
 */


#include "Integer4Param.h"

/**
 * Integer4Param implementation
 */

std::array<int,4> Integer4Param::GetValue() const{
    return this->value;
}

void Integer4Param::SetValue(std::array<int,4> value) {
    this->value = value;
}