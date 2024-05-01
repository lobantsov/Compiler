#include "VariableHandler.h"
#include "../SynAnalizator.h"

bool VariableHandler::Handle(int TypeID)
{
    Lex foundLex;
    for (const auto& lex : SynAnalizator::CreatedLexemus)
    {
        if (lex.lexID == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID &&
            lex.value == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value) {
            foundLex = lex;
            break;
            }
    }
    
    if (foundLex.lexID<0)
    {
        if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == -1)
            if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1)
            {
                for (int i = 0; i < LexAnalizator::FinalLexConfig.size(); i++)
                {
                    if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value == LexAnalizator::FinalLexConfig[i].value)
                    {
                        LexAnalizator::FinalLexConfig[i].dataTypeID = TypeID;
                        SynAnalizator::CreatedLexemus.push_back(LexAnalizator::FinalLexConfig[i]);
                        break;
                    }
                }
                singletone_currentposition->currentPosition++;
            }
    }
    else
    {
        //error
    }
    return AbstractHandler::Handle(TypeID);
}