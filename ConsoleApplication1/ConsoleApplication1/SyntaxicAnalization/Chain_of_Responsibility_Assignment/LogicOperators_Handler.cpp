#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "LogicOperators_Handler.h"
bool LogicOperators_Handler::Handle(int TypeID)
{
    //<  >
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==8)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(TypeID);
        }
    }
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(TypeID);
        }
        else
        {
            return false;
        }
    }
    return false;
}
