#pragma once
#include "../Client_Handler/Incrementa_Client.h"
#include "../Client_Handler/Logic_Client.h"
#include "../Client_Handler/Math_Client.h"

class MainClientAssigment
{
public:
    MainClientAssigment();
    bool CheckAssigment(int TypeId);
    Math_Client *math_client;
    Logic_Client *logic_client;
    Incrementa_Client *incrementa_client;
};
