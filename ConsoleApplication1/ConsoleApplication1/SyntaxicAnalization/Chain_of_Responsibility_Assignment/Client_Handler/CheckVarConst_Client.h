#pragma once
#include "../CheckConst_Handler.h"
#include "../CheckVar_Handler.h"

class CheckVarConst_Client
{
public:
    CheckVarConst_Client();
    bool Check_var_const(Lex Type);
    CheckConst_Handler* check_const_handler;
    CheckVar_Handler* check_var_handler;
};
