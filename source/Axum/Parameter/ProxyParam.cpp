#include "ProxyParam.h"

namespace Axum::Parameter {

void ProxyParam::drawEdit() { return parameter->drawEdit(); }

void ProxyParam::drawDisplay() { return parameter->drawDisplay(); }

Param &ProxyParam::GetParam() { return *parameter; }

ProxyParam::ProxyParam(std::string ID, Param *_parameter)
    : parameter(_parameter), Param(ID, _parameter->name, _parameter->group) {}

} // namespace Axum::Parameter