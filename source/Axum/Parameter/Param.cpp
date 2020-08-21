/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "Param.h"

/**
 * Param implementation
 *
 */

namespace Axum::Parameter {

Param::Param(std::string ID, const std::string &_name,std::string group = "") : ID(ID), name(_name),Group(group) {}

Param::Param(std::string ID, const char *_name,std::string group = "") : ID(ID), name(_name),Group(group) {}

Gtk::Widget *Param::Draw() {
  if (IsEditMode)
    return DrawEdit();
  else
    return DrawDisplay();
}

Gtk::Widget *Param::DrawDisplay() { return new Gtk::Box(); }

Gtk::Widget *Param::DrawEdit() { return new Gtk::Box(); }

} // namespace Axum::Parameter