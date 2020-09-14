/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "FloatParam.h"

/**
 * FloatParam implementation
 */

namespace Axum::Parameter {

FloatParam::FloatParam(std::string ID, std::string &_name, float _value)
    : value(_value), Param(ID, _name, "") {}

FloatParam::FloatParam(std::string ID, const char *_name, float _value)
    : value(_value), Param(ID, _name, "") {}

float FloatParam::GetValue() const { return this->value; }

void FloatParam::SetValue(float _value) { value = _value; }

void FloatParam::drawDisplay() { return; }

} // namespace Axum::Parameter