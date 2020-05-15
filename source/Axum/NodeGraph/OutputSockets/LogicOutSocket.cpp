/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicOutSocket.h"

/**
 * LogicOutSocket implementation
 */

DataType LogicOutSocket::GetType() const
{
    return type;
}

void LogicOutSocket::SetType(DataType type)
{
    type = type;
}