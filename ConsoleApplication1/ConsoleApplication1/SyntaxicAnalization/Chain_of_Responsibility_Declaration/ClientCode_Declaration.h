﻿#pragma once
#include "EaqualHandler.h"
#include "EnumerationHandler.h"
#include "VariableHandler.h"

class ClientCode_Declaration
{
public:
    ClientCode_Declaration();
    bool CheckDataType(Lex TypeID);
    VariableHandler *variable_handler;
    EnumerationHandler *enumeration_handler;
    EaqualHandler *eaqual_handler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};