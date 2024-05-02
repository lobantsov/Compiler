#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../LexAnalizator/Lex.h"
class ClassForCreateErorrs
{
protected:
    ClassForCreateErorrs(){}
    static ClassForCreateErorrs* create_erorrs_;
public:
    ClassForCreateErorrs(ClassForCreateErorrs& others) = delete;
    static ClassForCreateErorrs *GetInstance();
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
    void CreateSyntaxError();
    void CreateDeclarationError();
    bool error_status = false;
};
