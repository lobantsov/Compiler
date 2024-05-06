#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckVar_Handler.h"
bool CheckVar_Handler::Handle(Lex Type)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            if(tmpLex.dataTypeID==Type.dataTypeID)
            {
                return true;
            }
        }
        else
        {
            create_erorrs->error_status=true;
            return false;
        }
    }
    return AbstractHandler_Assigment::Handle(Type);
}