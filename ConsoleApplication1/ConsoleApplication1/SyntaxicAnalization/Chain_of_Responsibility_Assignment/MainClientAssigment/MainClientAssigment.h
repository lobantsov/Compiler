#pragma once
#include "../Initialization_Handler.h"
#include "../Client_Handler/Incrementa_Client.h"
#include "../Client_Handler/Logic_Client.h"
#include "../Client_Handler/Math_Client.h"


class MainClientAssigment
{
public:
    MainClientAssigment();
    bool CheckAssigment(Lex Type);
    Math_Client *math_client;
    Logic_Client *logic_client;
    Incrementa_Client *incrementa_client;
    Initialization_Handler *initialization_handler;
    End_Handler *end_handler;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};
