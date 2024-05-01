#pragma once
#include "EaqualHandler.h"
#include "EnumerationHandler.h"
#include "VariableHandler.h"

class ClientCode
{
public:
    ClientCode();
    bool CheckDataType(int TypeID);
    VariableHandler *variable_handler;
    EnumerationHandler *enumeration_handler;
    EaqualHandler *eaqual_handler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};