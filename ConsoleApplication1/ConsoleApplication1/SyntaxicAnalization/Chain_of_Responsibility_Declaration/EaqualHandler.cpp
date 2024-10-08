﻿#pragma once
#include "EaqualHandler.h"
#include "../../LexAnalizator/LexAnalizator.h"
bool EaqualHandler::Handle(Lex TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateDeclarationError();
            return false;
        }
    }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        //array
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-4].array==1)
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
            {
                singletone_currentposition->currentPosition++;
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateDeclarationError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == TypeID.lexID)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateDeclarationError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateDeclarationError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateDeclarationError();
                    return false;
                }
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateDeclarationError();
                    return false;
                }
            }
        }

        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+
            LexAnalizator::MultiplyLexConfig.size()+2 || LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
        {
            switch (TypeID.lexID)
            {
                //int
            case 35:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
                //flaot
            case 36:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 361)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
                //double
            case 37:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351||
                LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 361)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
                //string
            case 38:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 14)
                {
                    singletone_currentposition->currentPosition++;
                    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+
                        LexAnalizator::MultiplyLexConfig.size()+2))
                    {
                        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 381)
                        {
                            singletone_currentposition->currentPosition++;
                            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 14)
                                singletone_currentposition->currentPosition++;
                            else
                            {
                                create_erorrs->CreateSyntaxError();
                                return false;
                            }
                        }
                        else
                        {
                            create_erorrs->CreateSyntaxError();
                            return false;
                        }
                    }
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
                //char
            case 39:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 2)
                {
                    singletone_currentposition->currentPosition++;
                    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+
                        LexAnalizator::MultiplyLexConfig.size()+2 && LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value.size()==1)
                    {
                        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 391)
                        {
                            singletone_currentposition->currentPosition++;
                            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 2)
                                singletone_currentposition->currentPosition++;
                            else
                            {
                                create_erorrs->CreateSyntaxError();
                                return false;
                            }
                        }
                        else
                        {
                            create_erorrs->CreateSyntaxError();
                            return false;
                        }
                    }
                    else
                    {
                        create_erorrs->CreateSyntaxError();
                        return false;
                    }
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
                //bool
            case 34:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 341)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
                break;
            }
        }
        
        else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+
            LexAnalizator::MultiplyLexConfig.size()+1)
        {
            if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
            {
                Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
                if(tmpLex.dataTypeID == TypeID.lexID)
                {
                    singletone_currentposition->currentPosition++;
                }
                else
                {
                    create_erorrs->CreateSyntaxError();
                    return false;
                }
            }
        }
    }
    return AbstractHandler::Handle(TypeID);
}