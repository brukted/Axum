#include "ProxyParam.h"

namespace Axum::Parameter {

Gtk::Widget *ProxyParam::DrawEdit() { return parameter->DrawEdit(); }

Gtk::Widget *ProxyParam::DrawDisplay() { return parameter->DrawDisplay(); }

Param &ProxyParam::GetParam() { return *parameter; }

ProxyParam::ProxyParam(std::string ID, Param *_parameter)
    : parameter(_parameter), Param(ID,_parameter->name,_parameter->Group) {}

} // namespace Axum::Parameter