#include "EnumerationHandler.h"
#include "VariableHandler.h"

EnumerationHandler::EnumerationHandler(vector<Lex> lexes):AbstractHandler(lexes)
{
    FinalLexConfig=lexes;
}

bool EnumerationHandler::Handle()
{
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==16)
    {
        return true;
    }
    else
    {
        return AbstractHandler::Handle();
    }
}
