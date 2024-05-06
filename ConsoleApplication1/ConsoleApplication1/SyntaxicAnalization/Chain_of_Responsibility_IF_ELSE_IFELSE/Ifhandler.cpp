#include "Ifhandler.h"

bool Ifhandler::Handle()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //(
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;

        }
        //var
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+
                LexAnalizator::MultiplyLexConfig.size()+1)
        {
            Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
            {
                if(check_var_const_client->Check_var_const(tmpLex))
                    singletone_currentposition->currentPosition++;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
        //const
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+
                LexAnalizator::MultiplyLexConfig.size()+2)
        {
            if(check_var_const_client->Check_var_const(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
                singletone_currentposition->currentPosition++;
        }
            
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;
        }
        //condition check
        if(client_assigment->CheckAssigment(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition], false))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
        {
            if_status=true;
          return true;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            if_status=false;
            return false;
        }
    }
    return AbstractHandler_if::Handle();
}