#include "ProxyParam.h"

namespace Axum::Parameter {

void ProxyParam::drawEdit() { return parameter->drawEdit(); }

void ProxyParam::drawDisplay() { return parameter->drawDisplay(); }

Param &ProxyParam::GetParam() { return *parameter; }

ProxyParam::ProxyParam(std::string_view ID, Param *parameter, std::string_view group)
    : parameter(parameter), Param(ID, parameter->name, parameter->description,group) {
}

} // namespace Axum::Parameter