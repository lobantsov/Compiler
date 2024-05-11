#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "LogicOperators_Handler.h"
bool LogicOperators_Handler::Handle(Lex Type)
{
    //<  >
    if(Type.dataTypeID>=35&&Type.dataTypeID<=37)
    {
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
    }
    //==
    if(Type.dataTypeID>=34&&Type.dataTypeID<=39)
    {
        //
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==51)
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
    else
    {
        return false;
    }
}
