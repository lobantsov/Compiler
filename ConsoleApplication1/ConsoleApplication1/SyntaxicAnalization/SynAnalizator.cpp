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
        return false;
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

bool SynAnalizator::DataTypeChreck()
{
    //data type
    //32 - int
    //33 - float
    //34 - double
    //35 - string
    //36 - char
    //37 - let
    if (FinalLexConfig[currentPosition].lexID >= 32 && FinalLexConfig[currentPosition].lexID <= 37)
    {
        currentPosition++;
    }
    else
    {
        CreateSyntaxError();
        return false;
    }

    //space
    // skipping spaces
    if(FinalLexConfig[currentPosition].lexID == 15)
    {
        while (currentPosition < FinalLexConfig.size() && FinalLexConfig[currentPosition].lexID == 15)
        {
            currentPosition++;
        }
    }
    else
    {
        CreateSyntaxError();
        return false;
    }

    //var
    if(FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+VariableIdexator)
    {
        currentPosition++;
        VariableIdexator++;
    }
    if(FinalLexConfig[currentPosition].lexID == 0)
    {
        currentPosition++;
        return true;
    }
    else if(FinalLexConfig[currentPosition].lexID==16)
    {
        while (currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[currentPosition].lexID == 16)
        {
            currentPosition ++;
            while (currentPosition < FinalLexConfig.size() && FinalLexConfig[currentPosition].lexID == 15)
            {
                currentPosition++;
            }  
            if(currentPosition + 1 < FinalLexConfig.size() && FinalLexConfig[currentPosition+1].lexID == 16 &&
                FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+VariableIdexator)    
            {
                currentPosition++;
                VariableIdexator++;
            }
            else if(FinalLexConfig[currentPosition].lexID == SingleLexConfig.size()+MultiplyLexConfig.size()+VariableIdexator &&
                    FinalLexConfig[currentPosition+1].lexID==0)
            {
                currentPosition++;
                VariableIdexator++;
                break;
            }
            else
            {
                CreateDeclarationError();
                return false;
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
    if(FinalLexConfig[currentPosition].lexID==MultiplyLexConfig.size()+SingleLexConfig.size()+VariableIdexator)
    {
        currentPosition++;
        VariableIdexator++;
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
        if(FinalLexConfig[currentPosition].lexID==SingleLexConfig.size()+MultiplyLexConfig.size()+VariableIdexator)
        {
            currentPosition++;
            VariableIdexator++;
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
        //;
        if(FinalLexConfig[currentPosition].lexID==0)
        {
            currentPosition++;
        }
        else
        {
            CreateSyntaxError();
            return false;
        }
        //if(FinalLexConfig[currentPosition].lexID==)
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
