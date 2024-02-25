#include "SynAnalizator.h"

SynAnalizator::SynAnalizator(vector<Lex> lexes)
{
    FinalLexConfig = lexes;
    client_code =new ClientCode(lexes);
}

bool SynAnalizator::OperatorCheck()
{
    //for
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 17)
    {
        singletone_currentposition->currentPosition++;
        if(ForCheck()) return true;
    }

    //while
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==19)
    {
        singletone_currentposition->currentPosition++;
        //while
    }

    //do_while
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==20)
    {
        singletone_currentposition->currentPosition++;
        //do_while
    }

    //if
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==22)
    {
        singletone_currentposition->currentPosition++;
        //if
    }

    //switch
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==24)
    {
        singletone_currentposition->currentPosition++;
        //switch
    }

    //=
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    {
        singletone_currentposition->currentPosition++;
        //=
    }
    return false;
    //
}

bool SynAnalizator::MainCheck()
{
    //function
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 28)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //space
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
        singletone_currentposition->currentPosition++;
    else
    {
         create_erorrs->CreateSyntaxError();
        return false;
    }
    //main
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 39)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //(
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 3)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //)
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 4)
        singletone_currentposition->currentPosition++;
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //{
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 5)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return false;
}

bool SynAnalizator::DataTypeCheck()
{
    //data type
    //33 - int
    //34 - float
    //35 - double
    //36 - string
    //37 - char
    //38 - let
    singletone_currentposition->currentPosition++;
    int TypeID;
    if (FinalLexConfig[singletone_currentposition->currentPosition].lexID >= 33 && FinalLexConfig[singletone_currentposition->currentPosition].lexID <= 38)
    {
        TypeID=FinalLexConfig[singletone_currentposition->currentPosition].lexID;
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }

    //space
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 15)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }

    //var
    // if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    // {
    //     FinalLexConfig[singletone_currentposition->currentPosition].dataTypeID=TypeID;
    //     singletone_currentposition->currentPosition++;
    // }
    // //;
    // if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 0)
    // {
    //     singletone_currentposition->currentPosition++;
    //     return true;
    // }
    // //доробити !!!
    // else if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==13)
    // {
    //     singletone_currentposition->currentPosition++;
    //     if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+2)
    //     {
    //         singletone_currentposition->currentPosition++;
    //     }
    //     else
    //     {
    //         create_erorrs->CreateSyntaxError();
    //         return false;
    //     }
    //     if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==16)
    //     {
    //         //,
    //         while (singletone_currentposition->currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[singletone_currentposition->currentPosition].lexID == 16)
    //         {
    //             singletone_currentposition->currentPosition ++;
    //             //,
    //             if(singletone_currentposition->currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[singletone_currentposition->currentPosition+1].lexID == 16 &&
    //                 FinalLexConfig[singletone_currentposition->currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1)//var    
    //             {
    //                 singletone_currentposition->currentPosition++;
    //             }
    //             else if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1 &&//var
    //                     FinalLexConfig[singletone_currentposition->currentPosition+1].lexID==0)//;
    //             {
    //                 singletone_currentposition->currentPosition++;
    //                 break;
    //             }
    //             else
    //             {
    //                 create_erorrs->CreateDeclarationError();
    //                 return false;
    //             }
    //         }
    //     }
    // }
    // else
    // {
    //     create_erorrs->CreateDeclarationError();
    //     return false;
    // }
    while (FinalLexConfig[singletone_currentposition->currentPosition].lexID!=0)
    {
        if(client_code->CheckDataType())
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            break;
        }
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID == 0)
    {
        singletone_currentposition->currentPosition++;
        return true;
    }
    return false;
}

bool SynAnalizator::ForCheck()
{
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==3)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(DataTypeCheck())
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }

    //branching
    //foreach
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==21)
    {
        //colection
        singletone_currentposition->currentPosition++;
        if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        //)
        if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==5)
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
    else if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        singletone_currentposition->currentPosition++;
        if(ConditionCheck())
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        if(DicremetnORIncrementCheck()||SelfMathAdiction())
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateSyntaxError();
            return false;
        }
        if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
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

bool SynAnalizator::ConditionCheck()
{
    //<,>,<=,>=,==
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||FinalLexConfig[singletone_currentposition->currentPosition].lexID==8||
        FinalLexConfig[singletone_currentposition->currentPosition].lexID==47||FinalLexConfig[singletone_currentposition->currentPosition].lexID==48||
        FinalLexConfig[singletone_currentposition->currentPosition].lexID==49)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1||
        FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
}

bool SynAnalizator::DicremetnORIncrementCheck()
{
    //var
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //++,--,**
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==40||FinalLexConfig[singletone_currentposition->currentPosition].lexID==41||
        FinalLexConfig[singletone_currentposition->currentPosition].lexID==42)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
}

bool SynAnalizator::SelfMathAdiction()
{
    //var
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        singletone_currentposition->currentPosition++;        
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    //+=,-=,*=,/=
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==43||FinalLexConfig[singletone_currentposition->currentPosition].lexID==44||
        FinalLexConfig[singletone_currentposition->currentPosition].lexID==45||FinalLexConfig[singletone_currentposition->currentPosition].lexID==46)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        create_erorrs->CreateSyntaxError();
        return false;
    }
}

void SynAnalizator::Print()
{
    for (int i = 0; i < FinalLexConfig.size(); i++)
    {
        cout << "ID: " << FinalLexConfig[i].lexID << '\n';
        cout << "LineN: " << FinalLexConfig[i].lexLine << '\n';
        cout << "ValueL: " << FinalLexConfig[i].value << '\n';
        cout << "----------------------------------------------" <<'\n';
    }
}
