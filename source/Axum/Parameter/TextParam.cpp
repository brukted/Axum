/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextParam.h"

/**
 * TextParam implementation
 */

namespace Axum::Parameter {

TextParam::TextParam(unsigned int _uid, std::string &_name, std::string &_value)
    : value(_value), Param(_uid, _name) {}

TextParam::TextParam(unsigned int _uid, const char *_name, const char *_value)
    : value(_value), Param(_uid, _name) {}

std::string &TextParam::GetValue() { return this->value; }

void TextParam::SetValue(std::string &_value) { this->value = _value; }

void TextParam::setValue(const char *_name) {
  this->value.assign(_name);
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter