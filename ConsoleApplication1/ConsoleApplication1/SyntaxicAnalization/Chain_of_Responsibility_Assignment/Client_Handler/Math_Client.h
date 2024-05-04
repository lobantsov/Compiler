#pragma once
#include "../CheckConst_Handler.h"
#include "../CheckVar_Handler.h"
#include "../End_Handler.h"
#include "../MathOperators_Handler.h"
#include "../../Chain_of_Responsibility_Data_Type_Init/EaqualHandler.h"

class Math_Client:public AbstractHandler_Assigment
{
public:
    Math_Client();
    bool Handle(int TypeID) override;
    EaqualHandler *eaqual_handler;
    CheckVar_Handler *check_var_handler;
    CheckConst_Handler *check_const_handler;
    MathOperators_Handler *math_operators_handler;
    End_Handler *end_handler;
};
