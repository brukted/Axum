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
