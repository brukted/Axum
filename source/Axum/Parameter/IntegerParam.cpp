/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "IntegerParam.h"

/**
 * IntegerParam implementation
 */

namespace Axum::Parameter {
  Gtk::Widget* IntegerParam::DrawDisplay() 
  {
    return new Gtk::Box();
  }


IntegerParam::IntegerParam(std::string ID, std::string &_name, int _value)
    : value(_value), Param(ID, _name,"") {}

IntegerParam::IntegerParam(std::string ID, const char *_name, int _value)
    : value(_value), Param(ID, _name,"") {}

int IntegerParam::GetValue() const { return this->value; }

void IntegerParam::SetValue(int _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

} // namespace Axum::Parameter