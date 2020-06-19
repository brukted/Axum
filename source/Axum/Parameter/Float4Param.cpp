/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float4Param.h"

/**
 * Float4Param implementation
 */

namespace Axum::Parameter {

Float4Param::Float4Param(unsigned int _uid, std::string &_name,
                         std::array<float, 4> _value)
    : value(_value), Param(_uid, _name) {}

Float4Param::Float4Param(unsigned int _uid, const char *_name,
                         std::array<float, 4> _value)
    : value(_value), Param(_uid, _name) {}

std::array<float, 4> Float4Param::GetValue() const { return this->value; }

void Float4Param::SetValue(std::array<float, 4> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter