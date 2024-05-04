#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "MathOperators_Handler.h"
bool MathOperators_Handler::Handle(int TypeID)
{
    //+-*/
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==9||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==10||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==11||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==12)
    {
       singletone_currentposition->currentPosition++;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
