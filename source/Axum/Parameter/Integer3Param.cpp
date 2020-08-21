/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer3Param.h"

/**
 * Integer3Param implementation
 */

namespace Axum::Parameter {
Gtk::Widget *Integer3Param::DrawDisplay() { return new Gtk::Box(); }

Integer3Param::Integer3Param(std::string ID, std::string &_name,
                             std::array<int, 3> _value)
    : value(_value), Param(ID, _name,"") {}

Integer3Param::Integer3Param(std::string ID, const char *_name,
                             std::array<int, 3> _value)
    : value(_value), Param(ID, _name,"") {}

std::array<int, 3> Integer3Param::GetValue() const { return this->value; }

void Integer3Param::SetValue(std::array<int, 3> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter