/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */

namespace Axum::Parameter {

BooleanParam::BooleanParam(std::string_view ID, bool value, std::string_view name,
                           std::string_view description)
    : Param(ID, name, description), value(value) {}

bool BooleanParam::getValue() const { return value; }

void BooleanParam::setValue(bool value) { this->value = value; }

void BooleanParam::drawDisplay() { ImGui::Checkbox(name.c_str(), &value); }

} // namespace Axum::Parameter