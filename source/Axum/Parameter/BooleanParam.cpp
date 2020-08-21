/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "BooleanParam.h"

/**
 * BooleanParam implementation
 */

namespace Axum::Parameter {

BooleanParam::BooleanParam(std::string ID, std::string &_name, bool _value)
    : value(_value), Param(ID, _name,"") {}

BooleanParam::BooleanParam(std::string ID, const char *_name, bool _value)
    : value(_value), Param(ID, _name,"") {}

bool BooleanParam::GetValue() const { return this->value; }

void BooleanParam::SetValue(bool _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

Gtk::Widget *BooleanParam::DrawDisplay() { return new Gtk::Box(); }

} // namespace Axum::Parameter