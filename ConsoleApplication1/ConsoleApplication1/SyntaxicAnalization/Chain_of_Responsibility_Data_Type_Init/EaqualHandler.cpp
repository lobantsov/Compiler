#include "EaqualHandler.h"

#include "../../LexAnalizator/LexAnalizator.h"
bool EaqualHandler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        //number data type and let
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID>=33&&
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID<=35||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==38)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
            {
                singletone_currentposition->currentPosition++;
            }
        }
        //string and char and let
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID>=37&&
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID<=38)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                return false;
            }
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
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
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==32||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-2].dataTypeID==38 &&
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
