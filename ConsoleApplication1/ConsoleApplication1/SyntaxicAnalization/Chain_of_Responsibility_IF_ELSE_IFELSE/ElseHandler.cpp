#include "ElseHandler.h"

bool ElseHandler::Handle()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==25)
    {
        singletone_currentposition->currentPosition++;
        
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
            {
                return true;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
        {
            return true;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
    }
    return AbstractHandler_if::Handle();
}
