#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../LexAnalizator/Lex.h"
class ClassForCreateErorrs
{
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
public:
    void CreateSyntaxError();
    void CreateDeclarationError();
    vector<Lex> FinalLexConfig;
    ClassForCreateErorrs(vector<Lex> lexes);
};
