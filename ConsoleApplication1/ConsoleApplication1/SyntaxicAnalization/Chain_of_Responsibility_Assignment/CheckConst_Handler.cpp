#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckConst_Handler.h"

bool CheckConst_Handler::Handle(Lex Type)
{
    //string vat
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
       LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            return false;
        }
    }
    //char var
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
       LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value.size()==1)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                //must be one symbol
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            return false;
        }
    }
    //simple var
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    
    return AbstractHandler_Assigment::Handle(Type);
}