#include "VariableHandler.h"
#include "../../LexAnalizator/LexAnalizator.h"

bool VariableHandler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID==-1)
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID=LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
        {
            for (int i=0;i<LexAnalizator::FinalLexConfig.size();i++)
            {
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value==
                    LexAnalizator::FinalLexConfig[i].value)
                    LexAnalizator::FinalLexConfig[i].dataTypeID = TypeID;
            }
            singletone_currentposition->currentPosition++;
        }
    return AbstractHandler::Handle(TypeID);
}
