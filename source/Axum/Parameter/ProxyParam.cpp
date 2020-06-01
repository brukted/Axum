#include "ProxyParam.h"

ParamUI ProxyParam::GetEditUI()
{
    return parameter->GetEditUI();
}

ParamUI ProxyParam::GetDisplayUI()
{
    return parameter->GetDisplayUI();
}

Param &ProxyParam::GetParam()
{
    return *parameter;
}

ProxyParam::ProxyParam(unsigned int _uid, Param *_parameter) : parameter(_parameter), Param(_uid) {}