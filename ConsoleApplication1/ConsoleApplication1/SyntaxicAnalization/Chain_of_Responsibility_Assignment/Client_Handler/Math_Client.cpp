#include "Math_Client.h"
Math_Client::Math_Client()
{
    check_const_handler = new CheckConst_Handler();
    check_var_handler = new CheckVar_Handler();
    eaqual_handler = new EaqualHandler();
    math_operators_handler = new MathOperators_Handler();
    end_handler = new End_Handler();
    check_var_handler->SetNext(check_const_handler)->SetNext(math_operators_handler)->SetNext(end_handler);
}

bool Math_Client::Handle(int TypeID)
{
    if(eaqual_handler->Handle(TypeID))
    {
        if(check_var_handler->Handle(TypeID))
            singletone_currentposition->currentPosition++;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
