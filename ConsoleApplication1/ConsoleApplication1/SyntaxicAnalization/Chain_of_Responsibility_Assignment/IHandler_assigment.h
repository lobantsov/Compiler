#pragma once

#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
using namespace std;
class IHandler_assigment
{
public:
    virtual IHandler_assigment *SetNext(IHandler_assigment *handler) = 0;
    virtual bool Handle(int TypeID) = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
};
