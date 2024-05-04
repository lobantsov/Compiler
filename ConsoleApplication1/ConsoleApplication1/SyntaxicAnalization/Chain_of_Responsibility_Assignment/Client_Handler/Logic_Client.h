#pragma once
#include "../AbstractHandler_Assigment.h"
#include "../CheckConst_Handler.h"
#include "../CheckVar_Handler.h"
#include "../End_Handler.h"
#include "../LogicOperators_Handler.h"

class Logic_Client:public AbstractHandler_Assigment
{
public:
    Logic_Client();
    LogicOperators_Handler *logic_operators_handler;
    CheckVar_Handler *check_var_handler;
    CheckConst_Handler *check_const_handler;
    End_Handler *end_handler;
    bool Handle(int TypeID) override;
};
