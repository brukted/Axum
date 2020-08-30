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
                     std::map<int, std::string> _enums, int _value)
    : Param(ID, _name, ""), enums(_enums) {
  this->value = _value;
}

void EnumParam::SetValue(int const key) {
  value = key;
  OnValueChanged.emit();
}

std::string &EnumParam::ToString(int const key) {
  return enums.find(key)->second;
}

Gtk::Widget *EnumParam::DrawDisplay() {
  auto box = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 20);
  auto dropDown = new Gtk::ComboBoxText();
  auto label = new Gtk::Label(name);
  box->add(*label);
  box->add(*dropDown);
  for (auto const &[key, val] : enums) {
    dropDown->append(val);
  }
  int i = 0;
  for (auto const [key, val] : enums) {
    if (key == GetValue()) {
      dropDown->set_active(i);
      break;
    }
    i = 1 + i;
  }
  auto &enumsRef = enums;
  dropDown->signal_changed().connect([this, &enumsRef, dropDown]() {
    auto it = enumsRef.begin();
    for (auto i = 0; i < dropDown->get_active_row_number(); i++) {
      it++;
    }
    if (this->GetValue() != it->first) {
      this->SetValue(it->first);
    }
  });
  label->set_margin_start(20);
  return box;
}
} // namespace Axum::Parameter