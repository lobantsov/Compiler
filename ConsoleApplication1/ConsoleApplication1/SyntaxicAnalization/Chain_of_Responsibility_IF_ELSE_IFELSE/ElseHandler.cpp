﻿#include "ElseHandler.h"

bool ElseHandler::Handle()
{
    if(IHandler_if::if_status)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==25)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
            {
                singletone_currentposition->currentPosition++;
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }

                if(_syntaxicAnalizator_MathAndlogicOperator->ConditionCheck(true))
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }

                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
                {
                   // if(OperatorCheck())
                    {
                        singletone_currentposition->currentPosition;
                        return true;
                    }
                    //else
                    {
                        create_erorrs->CreateSyntaxError();
                        return false;
                    }
                }
            }

            
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
            {
                // if(OperatorCheck())
                {
                    singletone_currentposition->currentPosition++;
                }
                // else
                {
                    return false;
                }
            }
        }
    }
    return AbstractHandler_if::Handle();
}
