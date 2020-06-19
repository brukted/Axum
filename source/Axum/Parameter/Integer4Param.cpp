/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer4Param.h"

/**
 * Integer4Param implementation
 */

namespace Axum::Parameter {

Integer4Param::Integer4Param(unsigned int _uid, std::string &_name,
                             std::array<int, 4> _value)
    : value(_value), Param(_uid, _name) {}

Integer4Param::Integer4Param(unsigned int _uid, const char *_name,
                             std::array<int, 4> _value)
    : value(_value), Param(_uid, _name) {}

std::array<int, 4> Integer4Param::GetValue() const { return this->value; }

void Integer4Param::SetValue(std::array<int, 4> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter