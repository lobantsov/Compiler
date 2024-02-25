#include "ClassForCreateErorrs.h"
using namespace std;

ClassForCreateErorrs::ClassForCreateErorrs(vector<Lex> lexes)
{
    FinalLexConfig=lexes;
}

void ClassForCreateErorrs::CreateSyntaxError()
{
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Syntax error"<<'\n';
    cout << "The reason: '" << FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' is not recognized as the name of a statement, function, or other part of a program" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}

void ClassForCreateErorrs::CreateDeclarationError()
{
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Declaration Error"<<'\n';
    cout << "The reason: '" << FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' an error was found when compiling the program in the variable declaration" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}