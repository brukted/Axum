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
    : value(_value), Param(ID, _name, "") {}

BooleanParam::BooleanParam(std::string ID, const char *_name, bool _value)
    : value(_value), Param(ID, _name, "") {}

bool BooleanParam::GetValue() const { return this->value; }

void BooleanParam::SetValue(bool _value) {
  this->value = _value;
  this->OnValueChanged.emit();
}

Gtk::Widget *BooleanParam::DrawDisplay() {
  auto checkBox = new Gtk::CheckButton(name);
  checkBox->set_active(GetValue());
  checkBox->signal_clicked().connect([checkBox, this]() {
    if (this->GetValue() != checkBox->get_active())
      this->SetValue(checkBox->get_active());
  });
  checkBox->set_margin_start(20);
  return checkBox;
}

} // namespace Axum::Parameter