/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _FUNCTIONINSOCKET_H
#define _FUNCTIONINSOCKET_H

#include "../InputSocket.h"

enum class DataType
{
    boolean,
    float1,
    float2,
    float3,
    float4,
    int1,
    int2,
    int3,
    int4,
    text
};

class FunctionInSocket : public InputSocket
{
private:
    DataType type = DataType::int1;

public:
    DataType GetType() const;

    void SetType(DataType type);
};

#endif //_FUNCTIONINSOCKET_H
