#pragma once
#include "ElseHandler.h"
#include "Ifhandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"

class Client_If_Declaratoin
{
public:
    Client_If_Declaratoin();
    bool Check_if();
    Ifhandler *ifhandler;
    Ifhandler *ifhandler2;
    ElseHandler *elsehandler;
    SingletoneCurrentposition* singletone_currentposition=SingletoneCurrentposition::GetInstance();
};
