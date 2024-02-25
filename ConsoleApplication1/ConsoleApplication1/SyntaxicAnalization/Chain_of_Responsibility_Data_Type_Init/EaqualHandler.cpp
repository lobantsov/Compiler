#include "EaqualHandler.h"
EaqualHandler::EaqualHandler(vector<Lex> lexes):AbstractHandler(lexes)
{
    FinalLexConfig=lexes;
}

bool EaqualHandler::Handle()
{
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
        {
            return true;
        }
            return false;
    }
    else
    {
        return AbstractHandler::Handle();
    }
}
