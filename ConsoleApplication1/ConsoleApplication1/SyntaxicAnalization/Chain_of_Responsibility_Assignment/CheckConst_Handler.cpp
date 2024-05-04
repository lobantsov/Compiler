#include "CheckConst_Handler.h"
bool CheckConst_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
       LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
            singletone_currentposition->currentPosition++;
        else
        {
            return false;
        }
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
       LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value.size()==1)
            singletone_currentposition->currentPosition++;
            else
            {
                //must be one symbol
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
            singletone_currentposition->currentPosition++;
        else
        {
            return false;
        }
    }
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
