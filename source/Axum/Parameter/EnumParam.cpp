/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */

namespace Axum::Parameter {

EnumParam::EnumParam(std::string_view ID, std::map<int, std::string> enums,
                     int value, std::string_view name,
                     std::string_view description)
    : Param(ID, name, description), enums(enums) {
  this->intValue = value;
  strValue = toString(intValue);
}

void EnumParam::setValue(int const key) {
  intValue = key;
  strValue = toString(key);
}

std::string &EnumParam::toString(int const key) {
  return enums.find(key)->second;
}

void EnumParam::drawDisplay() {
  if (ImGui::BeginCombo(name.c_str(), strValue.c_str())) {
    for (auto &_enum : enums) {
      bool isSelected = false;
      ImGui::Selectable(_enum.second.c_str(), &isSelected);
      if (isSelected) {
        setValue(_enum.first);
      }
    }
    ImGui::EndCombo();
  }
}

} // namespace Axum::Parameter