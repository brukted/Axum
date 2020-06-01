/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#include "LogicInSocket.h"

/**
 * LogicInSocket implementation
 */

DataType LogicInSocket::GetType() const
{
    return type;
}

void LogicInSocket::SetType(DataType _type)
{
    type = _type;
}