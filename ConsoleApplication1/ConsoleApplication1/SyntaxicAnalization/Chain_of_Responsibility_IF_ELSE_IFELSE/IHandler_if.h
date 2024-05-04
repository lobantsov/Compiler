#pragma once
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
#include "../SyntaxicAnalizator_MathAndlogicOperator/SyntaxicAnalizator_MathAndlogicOperator.h"
using namespace std;

class IHandler_if
{
protected:
    ~IHandler_if() = default;

public:
    virtual IHandler_if *SetNext(IHandler_if *handler) = 0;
    virtual bool Handle() = 0;
    static bool if_status;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
};
