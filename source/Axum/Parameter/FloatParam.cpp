/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "FloatParam.h"

/**
 * FloatParam implementation
 */

namespace Axum::Parameter {

FloatParam::FloatParam(std::string_view ID, float value, std::string_view name,
                       std::string_view description, std::string_view group)
    : value(value), Param(ID, name, description, group) {}

float FloatParam::getValue() const { return this->value; }

void FloatParam::setValue(float _value) {
  value = _value;
  valueChanged();
}

void FloatParam::drawDisplay() { return; }

} // namespace Axum::Parameter