#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "Equal_Handler.h"
bool Equal_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        //+-*/
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==9||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==10||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==11||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==12)
        {
            singletone_currentposition->currentPosition++;
        }
        return true;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
