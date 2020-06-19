/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerParam.h"

/**
 * IntegerParam implementation
 */

namespace Axum::Parameter {

IntegerParam::IntegerParam(unsigned int _uid, std::string &_name, int _value)
    : value(_value), Param(_uid, _name) {}

IntegerParam::IntegerParam(unsigned int _uid, const char *_name, int _value)
    : value(_value), Param(_uid, _name) {}

int IntegerParam::GetValue() const { return this->value; }

void IntegerParam::SetValue(int _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter