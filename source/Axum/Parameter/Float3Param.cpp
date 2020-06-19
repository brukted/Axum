/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float3Param.h"

/**
 * Float3Param implementation
 */

namespace Axum::Parameter {

Float3Param::Float3Param(unsigned int _uid, std::string &_name,
                         std::array<float, 3> _value)
    : value(_value), Param(_uid, _name) {}

Float3Param::Float3Param(unsigned int _uid, const char *_name,
                         std::array<float, 3> _value)
    : value(_value), Param(_uid, _name) {}

std::array<float, 3> Float3Param::GetValue() const { return this->value; }

void Float3Param::SetValue(std::array<float, 3> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter