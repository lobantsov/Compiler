﻿#include "SynAnalizator.h"

#include "SingletoneDeclaretedVariables/DeclareredVariables.h"

SynAnalizator::SynAnalizator()
{
    client_code_declaration =new ClientCode_Declaration();
    client_code_init = new ClientCode_Init();
}

bool SynAnalizator::OperatorCheck()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
    {
        singletone_currentposition->currentPosition++;
    }
    //for
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 19)
    {
        if(ForCheck())
            return true;
    }

    //while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==21)
    {
        singletone_currentposition->currentPosition++;
        //while
    }

    //do_while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==22)
    {
        singletone_currentposition->currentPosition++;
        //do_while
    }

    //if
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //if
    }

    //switch
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==26)
    {
        singletone_currentposition->currentPosition++;
        //switch
    }

    if(DataTypeCheck())
    {
        singletone_currentposition->currentPosition++;
    }

    if(Assignment())
    {
        singletone_currentposition->currentPosition++;
    }
    
    if(_syntaxicAnalizator_MathAndlogicOperator->MathOperatorCheck())
    {
        singletone_currentposition->currentPosition++;
    }
    else if(_syntaxicAnalizator_MathAndlogicOperator->SelfMathAdiction())
    {
        singletone_currentposition->currentPosition++;
    }
    else if(_syntaxicAnalizator_MathAndlogicOperator->ConditionCheck())
    {
        singletone_currentposition->currentPosition++;
    }
    else if(_syntaxicAnalizator_MathAndlogicOperator->IncrementAndDicremental())
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        // create_erorrs->CreateSyntaxError();
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==6)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig.size()-1>singletone_currentposition->currentPosition)
        {
            singletone_currentposition->currentPosition++;
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

bool SynAnalizator::ForCheck()
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
            singletone_currentposition->currentPosition++;
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
            if(OperatorCheck())
            {
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
    //for
    else if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        singletone_currentposition->currentPosition++;
        // singletone_currentposition->currentPosition++;
        if(_syntaxicAnalizator_MathAndlogicOperator->ConditionCheck())
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        
        if(_syntaxicAnalizator_MathAndlogicOperator->IncrementAndDicremental()||
            _syntaxicAnalizator_MathAndlogicOperator->SelfMathAdiction())
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
            while(true)
            {
                if(OperatorCheck())
                {
                    return true;
                }
                // else
                // {
                //     create_erorrs->CreateSyntaxError();
                //     return false;
                // }
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
     int TypeID;
     int currentLex=singletone_currentposition->currentPosition;
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
     {
         singletone_currentposition->currentPosition++;
     }
     if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID >= 34 && LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID <= 40)
     {
         TypeID=LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID;
         currentLex=singletone_currentposition->currentPosition;
         singletone_currentposition->currentPosition++;
     }
     else
     {
         //create_erorrs->CreateSyntaxError();
         singletone_currentposition->currentPosition=currentLex;
         return false;
     }
 
     //space
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
     {
         singletone_currentposition->currentPosition++;
     }
     else
     {
         singletone_currentposition->currentPosition=currentLex;
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
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+2].lexID==23)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
            return true;
        }
    }
    
     if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 0)
     {
         return true;
     }
     else
     {
         if(!create_erorrs->error_status)
         singletone_currentposition->currentPosition=currentLex;
         return false;
     }
 }

bool SynAnalizator::Assignment()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            Lex tmp = declarered_variables_->ContainingLexGetLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]);
            singletone_currentposition->currentPosition++;
             if(client_code_init->CheckDataType(tmp.dataTypeID))
             {
                 return true;
             }
        }
        else
        {
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