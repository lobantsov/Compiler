#include "SynAnalizator.h"

bool SynAnalizator::MainCheck()
{
    //function
    if(FinalLexConfig[currentPosition].lexID == 27)
        currentPosition++;
    else
    {
        CreateError();
        return false;
    }
    //space
    if(FinalLexConfig[currentPosition].lexID == 15)
        currentPosition++;
    else
    {
        CreateError();
        return false;
    }
    //main
    if(FinalLexConfig[currentPosition].lexID == 40)
        currentPosition++;
    else
    {
        CreateError();
        return false;
    }
    //(
    if(FinalLexConfig[currentPosition].lexID == 3)
        currentPosition++;
    else
    {
        CreateError();
        return false;
    }
    //)
    if(FinalLexConfig[currentPosition].lexID == 4)
        currentPosition++;
    else
    {
        CreateError();
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

SynAnalizator::SynAnalizator(vector<Lex> lexes)
{
    FinalLexConfig = lexes;
}

void SynAnalizator::CreateError()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout << "The term: '" << FinalLexConfig[currentPosition].value <<
        "' is not recognized as the name of a statement, function, or other part of a program" << endl;
    cout << "Check the spelling of the code and try again" << endl;
    cout << "Line error: " << FinalLexConfig[currentPosition].lexLine << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}

void SynAnalizator::Print()
{
    for (int i = 0; i < FinalLexConfig.size(); i++)
    {
        cout << "ID: " << FinalLexConfig[i].lexID << endl;
        cout << "LineN: " << FinalLexConfig[i].lexLine << endl;
        cout << "ValueL: " << FinalLexConfig[i].value << endl;
        cout << "----------------------------------------------" << endl;
    }
}
