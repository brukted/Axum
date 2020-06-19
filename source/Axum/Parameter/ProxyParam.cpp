#include "ProxyParam.h"

namespace Axum::Parameter {

void ProxyParam::DrawEdit(UI::Widget::ParamUI *ui) {
  return parameter->DrawEdit(ui);
}

void ProxyParam::DrawDisplay(UI::Widget::ParamUI *ui) {
  return parameter->DrawDisplay(ui);
}

Param &ProxyParam::GetParam() { return *parameter; }

ProxyParam::ProxyParam(unsigned int _uid, Param *_parameter)
    : parameter(_parameter), Param(_uid) {}

} // namespace Axum::Parameter