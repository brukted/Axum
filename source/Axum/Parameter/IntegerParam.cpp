/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerParam.h"

/**
 * IntegerParam implementation
 */

namespace Axum::Parameter {
void IntegerParam::drawDisplay() { return; }

IntegerParam::IntegerParam(std::string_view ID, int value,
                           std::string_view name, std::string_view description, std::string_view group)
    : Param(ID, name, description, group), value(value) {}

int IntegerParam::getValue() const { return value; }

void IntegerParam::setValue(int _value) {
  value = _value;
  valueChanged();
}

} // namespace Axum::Parameter