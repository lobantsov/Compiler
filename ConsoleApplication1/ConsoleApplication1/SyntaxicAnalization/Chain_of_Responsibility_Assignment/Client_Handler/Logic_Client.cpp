#include "Logic_Client.h"
Logic_Client::Logic_Client()
{
    logic_operators_handler = new LogicOperators_Handler();
    check_const_handler = new CheckConst_Handler();
    check_var_handler = new CheckVar_Handler();
    end_handler = new End_Handler();
    logic_operators_handler->SetNext(check_const_handler)->SetNext(check_var_handler)->SetNext(end_handler);
}

bool Logic_Client::Handle(int TypeID)
{
    if(logic_operators_handler->Handle(TypeID))
        singletone_currentposition->currentPosition++;
    return AbstractHandler_Assigment::Handle(TypeID);
}

