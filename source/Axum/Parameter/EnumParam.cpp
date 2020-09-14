/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */

namespace Axum::Parameter {

EnumParam::EnumParam(std::string ID, std::string _name,
                     std::map<int, std::string> _enums, int intValue)
    : Param(ID, _name, ""), enums(_enums) {
  this->intValue = intValue;
  strValue = ToString(intValue);
}

void EnumParam::SetValue(int const key) {
  intValue = key;
  strValue = ToString(key);
}

std::string &EnumParam::ToString(int const key) {
  return enums.find(key)->second;
}

void EnumParam::drawDisplay() {
  if (ImGui::BeginCombo(name.c_str(), strValue.c_str())) {
    for (auto &_enum : enums) {
      bool isSelected = false;
      ImGui::Selectable(_enum.second.c_str(), &isSelected);
      if (isSelected) {
        SetValue(_enum.first);
      }
    }
    ImGui::EndCombo();
  }
}

} // namespace Axum::Parameter