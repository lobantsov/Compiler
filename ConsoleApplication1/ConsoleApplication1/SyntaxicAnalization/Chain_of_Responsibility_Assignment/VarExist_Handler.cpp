#include "VarExist_Handler.h"
bool VarExist_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
           return true;
        }
        else
        {
            return false;
        }
    }
     return AbstractHandler_Assigment::Handle(TypeID);
}
