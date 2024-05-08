#include "ArrayCheck_Handler.h"

#include "../../LexAnalizator/LexAnalizator.h"

bool ArrayCheck_Handler::Handle(Lex TypeID)
{
    //new
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID=TypeID.dataTypeID)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID==351)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
        else
        {
            return false;
        }
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
