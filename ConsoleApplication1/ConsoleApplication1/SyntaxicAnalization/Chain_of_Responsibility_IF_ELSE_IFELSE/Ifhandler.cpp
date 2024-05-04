#include "Ifhandler.h"

bool Ifhandler::Handle()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //(
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;

        }
        //condition check
        if(_syntaxicAnalizator_MathAndlogicOperator->ConditionCheck(true))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
        {
            if_status=true;
          return true;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;
        }
    }
    return AbstractHandler_if::Handle();
}