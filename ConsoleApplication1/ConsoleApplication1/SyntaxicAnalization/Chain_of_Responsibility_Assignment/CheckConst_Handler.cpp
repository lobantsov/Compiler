#pragma once
#include "..//..//LexAnalizator/LexAnalizator.h"
#include "CheckConst_Handler.h"

bool CheckConst_Handler::Handle(Lex Type)
{
    //string vat
    // if(Type.dataTypeID==38||Type.dataTypeID==40)
    //     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
    //     {
    //         singletone_currentposition->currentPosition++;
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
    //        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    // //char var
    // if(Type.dataTypeID==39||Type.dataTypeID==40)
    //     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
    //     {
    //         singletone_currentposition->currentPosition++;
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
    //        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    //         {
    //             if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value.size()==1)
    //             {
    //                 singletone_currentposition->currentPosition++;
    //             }
    //             else
    //             {
    //                 //must be one symbol
    //                 create_erorrs->CreateSyntaxError();
    //                 return false;
    //             }
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    // //number var
    // if(Type.dataTypeID>=35&&Type.dataTypeID<=37||Type.dataTypeID==40)
    //     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
    //     LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    //     {
    //         return true;
    //     }
    // //bool
    // if(Type.dataTypeID==34||Type.dataTypeID==40)
    //     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
    //     LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    //     {
    //         return true;
    //     }
    //
    // if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    // {
    //     singletone_currentposition->currentPosition++;
    //     //array
    //     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
    //     {
    //         singletone_currentposition->currentPosition++;
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         else
    //         {
    //             create_erorrs->CreateDeclarationError();
    //             return false;
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == TypeID.lexID)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         else
    //         {
    //             create_erorrs->CreateDeclarationError();
    //             return false;
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         else
    //         {
    //             create_erorrs->CreateDeclarationError();
    //             return false;
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         else
    //         {
    //             create_erorrs->CreateDeclarationError();
    //             return false;
    //         }
    //         if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
    //         {
    //             singletone_currentposition->currentPosition++;
    //         }
    //         else
    //         {
    //             create_erorrs->CreateDeclarationError();
    //             return false;
    //         }
    //     }

    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==15)
    {
        singletone_currentposition->currentPosition++;
    }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+
            LexAnalizator::MultiplyLexConfig.size()+2 || LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==14||
            LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==2)
        {
            switch (Type.dataTypeID)
            {
                //int
            case 35:
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID == 351)
                {
                    singletone_currentposition->currentPosition++;
                    return true;
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
                    return true;
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
                    return true;
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
                            {
                                singletone_currentposition->currentPosition++;
                                return true;
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
                            {
                                singletone_currentposition->currentPosition++;
                                return true;
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
                    return true;
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
            //check this sentence
            Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            if(tmpLex.dataTypeID == Type.lexID)
            {
                singletone_currentposition->currentPosition++;
                return true;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
        }
    
    return AbstractHandler_Assigment::Handle(Type);
}