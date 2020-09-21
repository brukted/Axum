#include "ProxyParam.h"

namespace Axum::Parameter {

void ProxyParam::drawEdit() { return parameter->drawEdit(); }

void ProxyParam::drawDisplay() { return parameter->drawDisplay(); }

Param &ProxyParam::GetParam() { return *parameter; }

ProxyParam::ProxyParam(std::string_view ID, Param *parameter)
    : parameter(parameter), Param(ID, parameter->name, parameter->description) {
}

} // namespace Axum::Parameter