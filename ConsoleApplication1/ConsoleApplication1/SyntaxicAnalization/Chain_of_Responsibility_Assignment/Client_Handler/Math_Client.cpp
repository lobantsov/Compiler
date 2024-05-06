#include "Math_Client.h"

#include "../../../LexAnalizator/LexAnalizator.h"

Math_Client::Math_Client()
{
    check_const_handler = new CheckConst_Handler();
    check_var_handler = new CheckVar_Handler();
    eaqual_handler = new Equal_Handler();
    math_operators_handler = new MathOperators_Handler();
    end_handler = new End_Handler();
    check_var_handler->SetNext(check_const_handler)->SetNext(math_operators_handler)->SetNext(end_handler);
}

bool Math_Client::Handle(Lex Type)
{
    if(eaqual_handler->Handle(Type))
    {
        while(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID!=0)
        {
            if(check_var_handler->Handle(Type))
            {
                singletone_currentposition->currentPosition++;
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
                {
                    singletone_currentposition->currentPosition--;
                    return true;
                }
            }
        }
    }
    return AbstractHandler_Assigment::Handle(Type);
}