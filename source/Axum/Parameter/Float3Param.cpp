/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Float3Param.h"

/**
 * Float3Param implementation
 */

namespace Axum::Parameter {

Float3Param::Float3Param(std::string ID, std::string &_name,
                         std::array<float, 3> _value)
    : value(_value), Param(ID, _name,"") {}

Float3Param::Float3Param(std::string ID, const char *_name,
                         std::array<float, 3> _value)
    : value(_value), Param(ID, _name,"") {}

std::array<float, 3> Float3Param::GetValue() const { return value; }

void Float3Param::SetValue(std::array<float, 3> _value) {
  value = _value;
  OnValueChanged.emit();
}
Gtk::Widget *Float3Param::DrawDisplay() { return new Gtk::Box(); }

} // namespace Axum::Parameter