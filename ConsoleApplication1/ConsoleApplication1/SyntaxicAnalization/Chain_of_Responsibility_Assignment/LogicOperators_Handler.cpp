#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "LogicOperators_Handler.h"
bool LogicOperators_Handler::Handle(Lex Type)
{
    //<  >
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||
    LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==8)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
        return AbstractHandler_Assigment::Handle(Type);
    }
    //
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
        {
            singletone_currentposition->currentPosition++;
            return AbstractHandler_Assigment::Handle(Type);
        }
        else
        {
            return false;
        }
    }
    return false;
}
