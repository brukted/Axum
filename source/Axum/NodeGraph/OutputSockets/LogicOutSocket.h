/**
 * Project Material Lab
 * @author Bruk Tedla
 */

#ifndef _LOGICOUTSOCKET_H
#define _LOGICOUTSOCKET_H

#include "../OutputSocket.h"
#include "../InputSockets/LogicInSocket.h"

class LogicOutSocket : public OutputSocket
{
private:
    /**
     * @brief Name of the variable output is stored in 
     * 
     */
    std::string variableName{"  ", 2};
    DataType type = DataType::int1;

public:
    DataType GetType() const;

    void SetType(DataType type);
};

#endif //_LOGICOUTSOCKET_H
