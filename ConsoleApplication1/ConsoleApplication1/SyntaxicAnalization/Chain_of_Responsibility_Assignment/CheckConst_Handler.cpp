#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckConst_Handler.h"

bool CheckConst_Handler::Handle(Lex Type)
{
    //string vat
    if(Type.dataTypeID==38||Type.dataTypeID==40)
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
            return true;
        }
        else
        {
            return false;
        }
    }
    //char var
    if(Type.dataTypeID==39||Type.dataTypeID==40)
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
            return true;
        }
        else
        {
            return false;
        }
    }
    //number var
    if(Type.dataTypeID>=35&&Type.dataTypeID<=37||Type.dataTypeID==40)
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        return true;
    }
    //bool
    if(Type.dataTypeID==34||Type.dataTypeID==40)
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            return true;
        }
    
    return AbstractHandler_Assigment::Handle(Type);
}