#pragma once
#include "ClassForCreateErorrs.h"
#include "../LexAnalizator/LexAnalizator.h"
using namespace std;

ClassForCreateErorrs* ClassForCreateErorrs::create_erorrs_= nullptr;;

ClassForCreateErorrs *ClassForCreateErorrs::GetInstance()
{
    if(create_erorrs_==nullptr){
        create_erorrs_ = new ClassForCreateErorrs();
    }
    return create_erorrs_;
}

void ClassForCreateErorrs::CreateSyntaxError()
{
    error_status=true;
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Syntax error"<<'\n';
    cout << "The reason: '" << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' is not recognized as the name of a statement, function, or other part of a program" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}

void ClassForCreateErorrs::CreateDeclarationError()
{
    error_status=true;
    const HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_INTENSITY);

    cout<<"Declaration Error"<<'\n';
    cout << "The reason: '" << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].value <<
        "' an error was found when compiling the program in the variable declaration" << '\n';
    cout << "Check the spelling of the code and try again" << '\n';
    cout << "Line error: " << LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexLine << '\n';

    SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        
    MessageBox(NULL, L"An error was detected in the code", L"Error", MB_OK | MB_ICONERROR);
}