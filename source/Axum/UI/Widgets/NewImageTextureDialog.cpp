#include "NewImageTextureDialog.h"

namespace Axum::UI::Widget {
NewImageTextureDialog::NewImageTextureDialog(
    int *width, int *height, std::array<unsigned char, 4> *color,
    std::string *name)
    : width(width), height(height), color(color), name(name) {
  // @FIXME Width and height spinners doesn't spin
  set_resizable(false);
  auto colorSelection = new Gtk::ColorButton();
  auto *WidthSpinner = new Gtk::SpinButton(Gtk::Adjustment::create(1024,1,2048,512));
  auto *HeightSpinner = new Gtk::SpinButton(Gtk::Adjustment::create(1024,1,2048,512));
  auto *NameEntry = new Gtk::Entry();
  WidthSpinner->set_numeric();
  WidthSpinner->signal_changed().connect(
      [width, WidthSpinner]() { *width = WidthSpinner->get_value_as_int(); });
  HeightSpinner->set_numeric();
  HeightSpinner->signal_changed().connect([height, HeightSpinner]() {
    *height = HeightSpinner->get_value_as_int();
  });
  NameEntry->signal_changed().connect(
      [name, NameEntry]() { *name = NameEntry->get_text(); });
  colorSelection->property_show_editor().set_value(true);
  colorSelection->set_use_alpha(true);
  colorSelection->signal_color_set().connect([color, colorSelection]() {
    auto C = colorSelection->get_rgba();
    *color = {C.get_red() * 255, C.get_green() * 255, C.get_blue() * 255,
              C.get_alpha() * 255};
  });

  auto RootBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 20);

  auto NameHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 20);
  auto NameLabel = new Gtk::Label(_("Texture Name"));
  NameLabel->set_margin_start(20);
  NameHBox->add(*NameLabel);
  NameHBox->add(*NameEntry);
  RootBox->pack_start(*NameHBox, false, false, 0);

  auto ColorAndSizeHBox = new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 20);
  auto SizeVBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 20);

  ColorAndSizeHBox->pack_end(*SizeVBox, false, false, 20);
  ColorAndSizeHBox->pack_end(*colorSelection);

  auto WidthHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
  auto WidthLabel = new Gtk::Label(_("Width"));
  WidthHBox->pack_end(*WidthSpinner);
  WidthHBox->pack_end(*WidthLabel);
  SizeVBox->pack_end(*WidthHBox, false, false);

  auto HeightHBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
  auto HeightLabel = new Gtk::Label(_("Height"));
  HeightHBox->pack_end(*HeightSpinner);
  HeightHBox->pack_end(*HeightLabel);
  SizeVBox->pack_end(*HeightHBox, false, false);

  auto ButtonBox = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
  auto Button = new Gtk::Button();
  Button->set_label(_("Create"));
  Button->signal_button_press_event().connect(
      [this](GdkEventButton *evt) { response(Gtk::RESPONSE_ACCEPT); return true;});
  ButtonBox->pack_end(*Button, false, true);
  ButtonBox->set_margin_end(20);
  ButtonBox->set_margin_bottom(20);
  RootBox->add(*ColorAndSizeHBox);
  RootBox->pack_end(*ButtonBox, false, false);
  this->remove();
  this->add(*RootBox);
  show_all();
}
} // namespace Axum::UI::Widget