/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Integer4Param.h"

/**
 * Integer4Param implementation
 */

namespace Axum::Parameter {
Gtk::Widget *Integer4Param::DrawDisplay() { return new Gtk::Box(); }

Integer4Param::Integer4Param(std::string ID, std::string &_name,
                             std::array<int, 4> _value)
    : value(_value), Param(ID, _name,"") {}

Integer4Param::Integer4Param(std::string ID, const char *_name,
                             std::array<int, 4> _value)
    : value(_value), Param(ID, _name,"") {}

std::array<int, 4> Integer4Param::GetValue() const { return this->value; }

void Integer4Param::SetValue(std::array<int, 4> _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter