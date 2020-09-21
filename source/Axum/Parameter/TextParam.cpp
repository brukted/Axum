/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextParam.h"

/**
 * TextParam implementation
 */

namespace Axum::Parameter {
TextParam::TextParam(std::string_view ID, std::string_view value,
                     std::string_view name, std::string_view description)
    : Param(ID, name, description), value(value) {}

void TextParam::drawDisplay() { ImGui::InputText(name.c_str(), &value);}

std::string_view TextParam::getValue() { return value; }

void TextParam::setValue(std::string_view value) { this->value = value; }

} // namespace Axum::Parameter