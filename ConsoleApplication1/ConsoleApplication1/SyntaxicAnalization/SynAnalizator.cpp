#include "SynAnalizator.h"

 std::vector<Lex> SynAnalizator::CreatedLexemus;

SynAnalizator::SynAnalizator()
{
    client_code =new ClientCode();
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
    
    if(CollectionDeclaration())
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
        if(LexAnalizator::FinalLexConfig.size()>singletone_currentposition->currentPosition)
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
         if(client_code->CheckDataType(TypeID))
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
         singletone_currentposition->currentPosition=currentLex;
         return false;
     }
 }

bool SynAnalizator::CollectionInitialization(int TypeID, int currentLex, int currentLexPosition)
{
    //=
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        //new
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //space
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //type
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==TypeID)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //[
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //]
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
           // LexAnalizator::FinalLexConfig[currentLex].array=1;
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
    }
}

//for array check? delete!
void SynAnalizator::FindCollection()
{
    for (int i=0;i<LexAnalizator::FinalLexConfig.size();i++)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value == LexAnalizator::FinalLexConfig[i].value)
        {
           if(LexAnalizator::FinalLexConfig[i].array>-1)
           {
               LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID=LexAnalizator::FinalLexConfig[i].dataTypeID;
               LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].array=LexAnalizator::FinalLexConfig[i].array;
               break;
           }
        }
    }
}

//for array? modernizate
bool SynAnalizator::CollectionDeclaration()
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
    int currentLex=-1;
    int currentLexPosition=singletone_currentposition->currentPosition;
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
    {
        singletone_currentposition->currentPosition++;
    }
    FindCollection();
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].array>-1)
    {
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //new
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==52)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //space
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //type
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition-4].dataTypeID)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //[
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
            return false;
        }
        //]
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
        {
           // LexAnalizator::FinalLexConfig[currentLex].array=1;
            singletone_currentposition->currentPosition++;
        }
        else
        {
            singletone_currentposition->currentPosition=currentLexPosition;
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
    
    if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID >= 34 && LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID <= 40)
    {
        TypeID=LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID;
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition+2].dataTypeID=LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID;
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //create_erorrs->CreateSyntaxError();
        singletone_currentposition->currentPosition=currentLexPosition;
        return false;
    }
 
    //space
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        singletone_currentposition->currentPosition=currentLexPosition;
        create_erorrs->CreateSyntaxError();
        return false;
    }

    //var
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID ==
        LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        currentLex=singletone_currentposition->currentPosition;
        singletone_currentposition->currentPosition++;
    }
    else
    {
        singletone_currentposition->currentPosition=currentLexPosition;
        return false;
    }
    //[
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==17)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        singletone_currentposition->currentPosition=currentLexPosition;
        return false;
    }
    //]
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==18)
    {
        LexAnalizator::FinalLexConfig[currentLex].array=0;
        singletone_currentposition->currentPosition++;
        CollectionInitialization(TypeID,currentLex, currentLexPosition);
    }
    else
    {
        singletone_currentposition->currentPosition=currentLex;
        return false;
    }
    //;
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        singletone_currentposition->currentPosition=currentLex;
        return false;
    } 
    
}

bool SynAnalizator::Assignment()
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(VarCheckConteining())
        {
            singletone_currentposition->currentPosition++;
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

    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        return false;
    }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        return false;
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
}

bool SynAnalizator::VarCheckConteining()
{
    Lex foundLex;
    for (const auto& lex : CreatedLexemus)
    {
        if (lex.lexID == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID &&
            lex.value == LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value)
        {
            foundLex = lex;
            break;
        }
    }
    if(foundLex.dataTypeID!=-1)
    {
        return true;
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