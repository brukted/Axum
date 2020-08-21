/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "FloatParam.h"

/**
 * FloatParam implementation
 */

namespace Axum::Parameter {

FloatParam::FloatParam(std::string ID, std::string &_name, float _value)
    : value(_value), Param(ID, _name,"") {}

FloatParam::FloatParam(std::string ID, const char *_name, float _value)
    : value(_value), Param(ID, _name,"") {}

float FloatParam::GetValue() const { return this->value; }

void FloatParam::SetValue(float _value) {
  value = _value;
  OnValueChanged.emit();
}

Gtk::Widget *FloatParam::DrawDisplay() {
  auto box = new Gtk::Box(Gtk::Orientation::ORIENTATION_VERTICAL);
  auto label = new Gtk::Label(name);
  auto entry = new Gtk::Entry();
  entry->set_input_purpose(Gtk::INPUT_PURPOSE_NUMBER);
  entry->signal_changed().connect([this, entry]() {
    auto value = std::stof(entry->get_text());
    if (value != this->GetValue())
      this->SetValue(value);
  });
  OnValueChanged.connect(
      [this, entry]() { entry->set_text(std::to_string(this->GetValue())); });
  box->pack_start(*label, Gtk::PACK_SHRINK);
  box->pack_start(*entry, Gtk::PACK_EXPAND_WIDGET);
  return box;
}

} // namespace Axum::Parameter