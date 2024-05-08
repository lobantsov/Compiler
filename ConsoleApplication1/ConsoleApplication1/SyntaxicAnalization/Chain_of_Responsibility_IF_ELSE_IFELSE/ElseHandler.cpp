#include "ElseHandler.h"

bool ElseHandler::Handle()
{
    if(if_status)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==25)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
            {
                singletone_currentposition->currentPosition++;
            
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
                {
                    return AbstractHandler_if::Handle();
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
    }
    return false;
}
