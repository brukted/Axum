/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextParam.h"

/**
 * TextParam implementation
 */

namespace Axum::Parameter {

void TextParam::drawDisplay() { ImGui::InputText(name.c_str(), &value); }

TextParam::TextParam(std::string ID, std::string &_name, std::string &_value)
    : value(_value), Param(ID, _name, "") {}

TextParam::TextParam(std::string ID, const char *_name, const char *_value)
    : value(_value), Param(ID, _name, "") {}

std::string &TextParam::GetValue() { return value; }

void TextParam::SetValue(std::string &_value) { value = _value; }

void TextParam::SetValue(const char *_value) { value.assign(_value); }

} // namespace Axum::Parameter