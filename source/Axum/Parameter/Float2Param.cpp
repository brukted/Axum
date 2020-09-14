/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float2Param.h"

/**
 * Float2Param implementation
 */

namespace Axum::Parameter {

Float2Param::Float2Param(std::string ID, std::string &_name,
                         std::array<float, 2> _value)
    : value(_value), Param(ID, _name, "") {}

Float2Param::Float2Param(std::string ID, const char *_name,
                         std::array<float, 2> _value)
    : value(_value), Param(ID, _name, "") {}

std::array<float, 2> Float2Param::GetValue() const { return this->value; }

void Float2Param::SetValue(std::array<float, 2> _value) {
  this->value = _value;
}

void Float2Param::drawDisplay() { return; }

} // namespace Axum::Parameter