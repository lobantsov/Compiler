#include "SynAnalizator.h"

SynAnalizator::SynAnalizator(vector<Lex> lexes)
{
    FinalLexConfig = lexes;
}

bool SynAnalizator::OperatorCheck()
{
    //for
    if(FinalLexConfig[currentPosition].lexID == 17)
    {
        currentPosition++;
        if(ForCheck()) return true;
    }

    //while
    if(FinalLexConfig[currentPosition].lexID==19)
    {
        currentPosition++;
        //while
    }

    //do_while
    if(FinalLexConfig[currentPosition].lexID==20)
    {
        currentPosition++;
        //do_while
    }

    //if
    if(FinalLexConfig[currentPosition].lexID==22)
    {
        currentPosition++;
        //if
    }

    //switch
    if(FinalLexConfig[currentPosition].lexID==24)
    {
        currentPosition++;
        //switch
    }

    //=
    if(FinalLexConfig[currentPosition].lexID==13)
    {
        currentPosition++;
        //=
    }
    return false;
    //
}

bool SynAnalizator::MainCheck()
{
    //function
    if(FinalLexConfig[currentPosition].lexID == 28)
        currentPosition++;
    else
    {
        CreateSyntaxError();
        return false;
    }
    //space
    if(FinalLexConfig[currentPosition].lexID == 15)
        currentPosition++;
    else
    {
        CreateSyntaxError();
        return false;
    }
    //main
    if(FinalLexConfig[currentPosition].lexID == 39)
        currentPosition++;
    else
    {
        CreateSyntaxError();
        return false;
    }
    //(
    if(FinalLexConfig[currentPosition].lexID == 3)
        currentPosition++;
    else
    {
        CreateSyntaxError();
        return false;
    }
    //)
    if(FinalLexConfig[currentPosition].lexID == 4)
        currentPosition++;
    else
    {
        CreateSyntaxError();
        return false;
    }
    //{
    if(FinalLexConfig[currentPosition].lexID == 5)
    {
        currentPosition++;
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
    currentPosition++;
    int TypeID;
    if (FinalLexConfig[currentPosition].lexID >= 33 && FinalLexConfig[currentPosition].lexID <= 38)
    {
        TypeID=FinalLexConfig[currentPosition].lexID;
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }

    //space
    if(FinalLexConfig[currentPosition].lexID == 15)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }

    //var
    if(FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        FinalLexConfig[currentPosition].dataTypeID=TypeID;
        currentPosition++;
    }
    //;
    if(FinalLexConfig[currentPosition].lexID == 0)
    {
        currentPosition++;
        return true;
    }
    //доробити !!!
    else if(FinalLexConfig[currentPosition].lexID==13)
    {
        currentPosition++;
        if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+2)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        if(FinalLexConfig[currentPosition].lexID==16)
        {
            //,
            while (currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[currentPosition].lexID == 16)
            {
                currentPosition ++;
                //,
                if(currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[currentPosition+1].lexID == 16 &&
                    FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1)//var    
                {
                    currentPosition++;
                }
                else if(FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+1 &&//var
                        FinalLexConfig[currentPosition+1].lexID==0)//;
                {
                    currentPosition++;
                    break;
                }
                else
                {
                    CreateDeclarationError();
                    return false;
                }
            }
        }
    }
    else
    {
        CreateDeclarationError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID == 0)
    {
        currentPosition++;
        return true;
    }
    return false;
}

bool SynAnalizator::ForCheck()
{
    if(FinalLexConfig[currentPosition].lexID==3)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(DataTypeCheck())
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }

    //branching
    //foreach
    if(FinalLexConfig[currentPosition].lexID==21)
    {
        //colection
        currentPosition++;
        if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        //)
        if(FinalLexConfig[currentPosition].lexID==4)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        if(FinalLexConfig[currentPosition].lexID==5)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
    }
    //for
    else if(FinalLexConfig[currentPosition].lexID==0)
    {
        currentPosition++;
        if(ConditionCheck())
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        if(DicremetnORIncrementCheck()||SelfMathAdiction())
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        if(FinalLexConfig[currentPosition].lexID==4)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
    }
}

bool SynAnalizator::ConditionCheck()
{
    //<,>,<=,>=,==
    if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID==7||FinalLexConfig[currentPosition].lexID==8||
        FinalLexConfig[currentPosition].lexID==47||FinalLexConfig[currentPosition].lexID==48||FinalLexConfig[currentPosition].lexID==49)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1||
        FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+2)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
}

bool SynAnalizator::DicremetnORIncrementCheck()
{
    //var
    if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    //++,--,**
    if(FinalLexConfig[currentPosition].lexID==40||FinalLexConfig[currentPosition].lexID==41||FinalLexConfig[currentPosition].lexID==42)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
}

bool SynAnalizator::SelfMathAdiction()
{
    //var
    if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+1)
    {
        currentPosition++;        
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    //+=,-=,*=,/=
    if(FinalLexConfig[currentPosition].lexID==43||FinalLexConfig[currentPosition].lexID==44||FinalLexConfig[currentPosition].lexID==45||
        FinalLexConfig[currentPosition].lexID==46)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
    if(FinalLexConfig[currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }
}

void SynAnalizator::CreateSyntaxError()
{
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Syntax error"<<'\n';
    cout << "The reason: '" << FinalLexConfig[currentPosition].value <<
        "' is not recognized as the name of a statement, function, or other part of a program" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << FinalLexConfig[currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}

void SynAnalizator::CreateDeclarationError()
{
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Declaration Error"<<'\n';
    cout << "The reason: '" << FinalLexConfig[currentPosition].value <<
        "' an error was found when compiling the program in the variable declaration" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << FinalLexConfig[currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
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
