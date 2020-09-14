/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float4Param.h"

/**
 * Float4Param implementation
 */

namespace Axum::Parameter {
void Float4Param::drawDisplay() { return; }

Float4Param::Float4Param(std::string ID, std::string &_name,
                         std::array<float, 4> _value)
    : value(_value), Param(ID, _name, "") {}

Float4Param::Float4Param(std::string ID, const char *_name,
                         std::array<float, 4> _value)
    : value(_value), Param(ID, _name, "") {}

std::array<float, 4> Float4Param::GetValue() const { return this->value; }

void Float4Param::SetValue(std::array<float, 4> _value) {
  this->value = _value;
}

} // namespace Axum::Parameter