/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "EnumParam.h"

/**
 * EnumParam implementation
 */

namespace Axum::Parameter {

EnumParam::EnumParam(std::string ID, std::string &_name,
                     std::map<int, std::string> _enums, int _value)
    : enums(_enums), value(_value), Param(ID,_name,"") {}

EnumParam::EnumParam(std::string ID, const char *_name,
                     std::map<int, std::string> _enums, int _value)
    : enums(_enums), value(_value), Param(ID,_name,"") {}

int EnumParam::SetValue() const { return value; }

int EnumParam::GetValue() const { return value; }

void EnumParam::SetValue(int key) {
  value = key;
  OnValueChanged.emit();
}

std::string &EnumParam::ToString(int key) { return enums[key]; }

Gtk::Widget *EnumParam::DrawDisplay() { return new Gtk::Box(); }

} // namespace Axum::Parameter