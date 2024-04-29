#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../LexAnalizator/Lex.h"
class ClassForCreateErorrs
{
public:
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
    void CreateSyntaxError();
    void CreateDeclarationError();
};
