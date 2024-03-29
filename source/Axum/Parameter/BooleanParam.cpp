/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */

namespace Axum::Parameter {

BooleanParam::BooleanParam(std::string_view ID, bool value,
                           std::string_view name, std::string_view description, std::string_view group)
    : Param(ID, name, description,group), value(value) {}

bool BooleanParam::getValue() const { return value; }

void BooleanParam::setValue(bool _value) {
  value = _value;
  valueChanged();
}

void BooleanParam::drawDisplay() { ImGui::Checkbox(name.c_str(), &value); }

} // namespace Axum::Parameter