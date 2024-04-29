#include "SynAnalizator.h"


SynAnalizator::SynAnalizator()
{
    client_code =new ClientCode();
}

bool SynAnalizator::OperatorCheck()
{
    //for
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 17)
    {
        if(ForCheck())
            return true;
    }

    //while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==19)
    {
        singletone_currentposition->currentPosition++;
        //while
    }

    //do_while
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==20)
    {
        singletone_currentposition->currentPosition++;
        //do_while
    }

    //if
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==22)
    {
        singletone_currentposition->currentPosition++;
        //if
    }

    //switch
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //switch
    }

    if(DataTypeCheck())
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
        create_erorrs->CreateSyntaxError();
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
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 28)
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
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 39)
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
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==15)
    {
        singletone_currentposition->currentPosition++;
    }
    if (LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID >= 32 && LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID <= 38)
    {
        TypeID=LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID;
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //create_erorrs->CreateSyntaxError();
        return false;
    }

    //space
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
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
            create_erorrs->CreateSyntaxError();
            break;
        }
    }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID == 0)
    {
        return true;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
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
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==21)
    {
        //colection
        singletone_currentposition->currentPosition++;
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
        singletone_currentposition->currentPosition++;
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