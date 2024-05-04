#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckVar_Handler.h"
bool CheckVar_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //error not created var
            return false;
        }
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
