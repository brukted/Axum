/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer3Param.h"

/**
 * Integer3Param implementation
 */

namespace Axum::Parameter {

Integer3Param::Integer3Param(unsigned int _uid, std::string &_name,
                             std::array<int, 3> _value)
    : value(_value), Param(_uid, _name) {}

Integer3Param::Integer3Param(unsigned int _uid, const char *_name,
                             std::array<int, 3> _value)
    : value(_value), Param(_uid, _name) {}

std::array<int, 3> Integer3Param::GetValue() const { return this->value; }

void Integer3Param::SetValue(std::array<int, 3> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter