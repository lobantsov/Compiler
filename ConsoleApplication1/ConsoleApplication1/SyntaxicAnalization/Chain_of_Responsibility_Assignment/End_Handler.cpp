#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "End_Handler.h"
bool End_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
