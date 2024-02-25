#include "VariableHandler.h"

VariableHandler::VariableHandler(vector<Lex> lexes):AbstractHandler(lexes)
{
    FinalLexConfig=lexes;
}

bool VariableHandler::Handle()
{
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==51)
    {
        singletone_currentposition->currentPosition++;
    }
        return AbstractHandler::Handle();
}
