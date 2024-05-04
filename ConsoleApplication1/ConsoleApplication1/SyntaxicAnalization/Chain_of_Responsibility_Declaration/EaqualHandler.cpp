#pragma once
#include "EaqualHandler.h"
#include "../../LexAnalizator/LexAnalizator.h"
bool EaqualHandler::Handle(int TypeID)
{
    //array
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].array=0;
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        //array new
        // if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-3].array==0)
        // {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
            {
                singletone_currentposition->currentPosition++;
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==TypeID)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                if(!LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
            }
            // else
            // {
            //     create_erorrs->CreateSyntaxError();
            //     return false;
            // }
           
        // }
        singletone_currentposition->currentPosition++;
        //number data type and let
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID>=35&&
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID<=37||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==40)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==
                LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
            {
                singletone_currentposition->currentPosition++;
            }
        }
        //string and char and let
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID>=39&&
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID<=40)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                return false;
            }
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==54)
            {
                singletone_currentposition->currentPosition++;
            }
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                return false;
            }
        }
        //bool,let
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==34||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==40 &&
                (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="1"||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="0"||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="true"||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value=="false"))
        {
            singletone_currentposition->currentPosition++;
        }
    }
    return AbstractHandler::Handle(TypeID);
}
