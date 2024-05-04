#include "EaqualHandler.h"
#include "EnumerationHandler.h"
#include "VariableHandler.h"
#pragma once

class ClientCode_Init
{
public:
    ClientCode_Init();
    bool CheckDataAssignment(int TypeID);
    EnumerationHandler *enumeration_handler;
    EaqualHandler *eaqual_handler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};
