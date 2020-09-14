/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer2Param.h"

/**
 * Integer2Param implementation
 */

namespace Axum::Parameter {
void Integer2Param::drawDisplay() { return; }

Integer2Param::Integer2Param(std::string ID, std::string &_name,
                             std::array<int, 2> _value)
    : value(_value), Param(ID, _name, "") {}

Integer2Param::Integer2Param(std::string ID, const char *_name,
                             std::array<int, 2> _value)
    : value(_value), Param(ID, _name, "") {}

std::array<int, 2> Integer2Param::GetValue() const { return this->value; }

void Integer2Param::SetValue(std::array<int, 2> _value) {
  this->value = _value;
}

} // namespace Axum::Parameter