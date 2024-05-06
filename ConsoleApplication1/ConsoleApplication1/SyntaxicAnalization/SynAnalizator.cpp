﻿#pragma once
#include "SynAnalizator.h"
#include "SingletoneDeclaretedVariables/DeclareredVariables.h"

SynAnalizator::SynAnalizator()
{
    client_code_declaration =new ClientCode_Declaration();
    client_if_declaratoin_=new Client_If_Declaratoin();
    client_assigment_ = new MainClientAssigment();
}

bool SynAnalizator::OperatorCheck(bool innerCheckStatus)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
    {
        singletone_currentposition->currentPosition++;
    }
    //for
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 19)
    {
        if(ForCheck())
           singletone_currentposition->currentPosition++;
        if(create_erorrs->error_status)
            return false;
    }

    //while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==21)
    {
        if(WhileCheck())
         singletone_currentposition->currentPosition++;
        if(create_erorrs->error_status)
            return false;
    }

    //do_while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==22)
    {
        if(Do_whileCheck())
            singletone_currentposition->currentPosition++;
        if(create_erorrs->error_status)
            return false;
    }

    //if
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        if(client_if_declaratoin_->Check_if())
        {
            singletone_currentposition->currentPosition++;
            while (true)
            {
                if(OperatorCheck(true))
                {
                    break;
                }
                if(create_erorrs->error_status)
                    return false;
            }
        }
    }
    //else
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==25)
    {
        if(client_if_declaratoin_->Check_if())
        {
            singletone_currentposition->currentPosition++;
            while (true)
            {
                if(OperatorCheck(true))
                {
                    break;
                }
                if(create_erorrs->error_status)
                    return false;
            }
        }
    }

    // //switch
    // if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==26)
    // {
    //     singletone_currentposition->currentPosition++;
    //     //switch
    // }

    if(DataTypeCheck())
    {
        singletone_currentposition->currentPosition++;
    }

    if(Assignment(true))
    {
        singletone_currentposition->currentPosition++;
    }
    
    //error out of range
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==6)
    {
        if(!innerCheckStatus)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig.size()-1<=singletone_currentposition->currentPosition)
            {
                singletone_currentposition->currentPosition--;
            }
        }
        return true;
    }
    return false;
    //
}

bool SynAnalizator::MainCheck()
{
    //function
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 30)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //space
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
        singletone_currentposition->currentPosition++;
    else
    {
         create_erorrs->CreateSyntaxError();
        return false;
    }
    //main
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 41)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //(
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 3)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //)
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 4)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 5)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return false;
}

bool SynAnalizator::WhileCheck()
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
        return false;
    }
    if(Assignment(false))
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
        singletone_currentposition->currentPosition++;
        while (true)
        {
            if(OperatorCheck(true))
            {
                break;
            }
            if(create_erorrs->error_status)
                return false;
        }
    }
}

bool SynAnalizator::Do_whileCheck()
{
    singletone_currentposition->currentPosition++;
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==5))
    {
        singletone_currentposition->currentPosition++;
    }
    while (true)
    {
        if(OperatorCheck(true))
        {
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==21)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                return false;
            }

            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
            if(Assignment(false))
            {
                singletone_currentposition->currentPosition++;
            }
            else
            {
                create_erorrs->CreateSyntaxError();
                return false;
            }
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(create_erorrs->error_status)
            return false;
    }
}

bool SynAnalizator::ForCheck()
{
    //add checking data  type in foreach
    int typeLex=-1;
    singletone_currentposition->currentPosition++;
    //(
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(!DataTypeCheck())
    {
        return false;
        //create_erorrs->CreateSyntaxError();
    }

    //branching
    //foreach
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==23)
    {
        //colection
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            return false;
        }
        
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
        {
            Lex tmpLex = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            if(tmpLex.lexID>-1)
            {
                if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-4].dataTypeID==tmpLex.dataTypeID)
                {
                    singletone_currentposition->currentPosition++;
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
        //)
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
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
            singletone_currentposition->currentPosition++;
            while (true)
            {
                if(OperatorCheck(true))
                {
                    break;
                }
                if(create_erorrs->error_status)
                    return false;
            }
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        
    }
    //for
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        singletone_currentposition->currentPosition++;
        // singletone_currentposition->currentPosition++;
        if(Assignment(true))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        
        if(Assignment(true))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
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
            singletone_currentposition->currentPosition++;
            while (true)
            {
                if(OperatorCheck(true))
                {
                    break;
                }
                if(create_erorrs->error_status)
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
        return false;
    }
}

bool SynAnalizator::DataTypeCheck()
 {
     //data type
     //32 - bool
     //33 - int
     //34 - float
     //35 - double
     //36 - string
     //37 - char
     //38 - let
     Lex TypeID;
     singletone_currentposition->currentPosition_backup=singletone_currentposition->currentPosition;
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
     {
         singletone_currentposition->currentPosition++;
     }
     if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID >= 34 && LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID <= 40)
     {
         TypeID=LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition];
         singletone_currentposition->currentPosition_backup=singletone_currentposition->currentPosition;
         singletone_currentposition->currentPosition++;
     }
     else
     {
         //create_erorrs->CreateSyntaxError();
         singletone_currentposition->currentPosition=singletone_currentposition->currentPosition_backup;
         return false;
     }
 
     //space
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
     {
         singletone_currentposition->currentPosition++;
     }
     else
     {
         singletone_currentposition->currentPosition=singletone_currentposition->currentPosition_backup;
         create_erorrs->CreateSyntaxError();
         return false;
     }
     while (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID!=0)
     {
         if(client_code_declaration->CheckDataType(TypeID))
         {
             if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID!=0)
                 singletone_currentposition->currentPosition++;
         }
         else
         {
             singletone_currentposition->currentPosition--;
             break;
         }
     }

    //foreach check variable
    if(singletone_currentposition->currentPosition+2<LexAnalizator::FinalLexConfig.size())
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+2].lexID==23)
        {
            singletone_currentposition->currentPosition++;
            if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
            {
                singletone_currentposition->currentPosition++;
                return true;
            }
        }
    }
    
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 0)
     {
         return true;
     }
     else
     {
         if(!create_erorrs->error_status)
         singletone_currentposition->currentPosition=singletone_currentposition->currentPosition_backup;
         return false;
     }
 }

bool SynAnalizator::Assignment(bool endSigntStatus)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            Lex tmp = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            
            singletone_currentposition->currentPosition++;
             if(client_assigment_->CheckAssigment(tmp, endSigntStatus))
             {
                 return true;
             }
             else
             {
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
        return false;
    }
    
}

void SynAnalizator::Print()
    {
        for (int i = 0; i < LexAnalizator::FinalLexConfig.size(); i++)
        {
            cout << "ID: " << LexAnalizator::FinalLexConfig[i].lexID << '\n';
            cout << "LineN: " << LexAnalizator::FinalLexConfig[i].lexLine << '\n';
            cout << "ValueL: " << LexAnalizator::FinalLexConfig[i].value << '\n';
            cout << "----------------------------------------------" <<'\n';
        }
    }