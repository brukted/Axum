/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */

namespace Axum::Parameter {

BooleanParam::BooleanParam(std::string ID, std::string &_name, bool _value)
    : value(_value), Param(ID, _name, "") {}

BooleanParam::BooleanParam(std::string ID, const char *_name, bool _value)
    : value(_value), Param(ID, _name, "") {}

bool BooleanParam::GetValue() const { return this->value; }

void BooleanParam::SetValue(bool _value) { this->value = _value; }

void BooleanParam::drawDisplay() { ImGui::Checkbox(name.c_str(), &value); }

} // namespace Axum::Parameter