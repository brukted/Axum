/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "TextParam.h"

/**
 * TextParam implementation
 */

namespace Axum::Parameter {

Gtk::Widget *TextParam::DrawDisplay() {
  auto box = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,20);
  auto label = new Gtk::Label(name);
  auto entry = new Gtk::Entry();
  label->set_margin_start(20);
  entry->set_text(value);
  entry->signal_changed().connect([this, entry]() {
   if (entry->get_text() != this->GetValue())
      this->SetValue(entry->get_text().c_str());
  });
  OnValueChanged.connect(
      [this, entry]() { entry->set_text(this->GetValue()); });
  box->pack_start(*label, Gtk::PACK_SHRINK);
  box->pack_start(*entry, Gtk::PACK_EXPAND_WIDGET);
  return box;
}

TextParam::TextParam(std::string ID, std::string &_name, std::string &_value)
    : value(_value), Param(ID, _name,"") {}

TextParam::TextParam(std::string ID, const char *_name, const char *_value)
    : value(_value), Param(ID, _name,"") {}

std::string &TextParam::GetValue() { return this->value; }

void TextParam::SetValue(std::string &_value) {
  value = _value;
  OnValueChanged.emit();
}

void TextParam::SetValue(const char *_value) {
  value.assign(_value);
  OnValueChanged.emit();
}

} // namespace Axum::Parameter