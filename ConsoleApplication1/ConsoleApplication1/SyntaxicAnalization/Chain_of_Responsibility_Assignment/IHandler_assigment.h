#pragma once
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
using namespace std;
class IHandler_assigment
{
public:
    virtual IHandler_assigment *SetNext(IHandler_assigment *handler) = 0;
    virtual bool Handle(Lex Type) = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    string parent_chain;
    static Lex *tmpLex;
};
