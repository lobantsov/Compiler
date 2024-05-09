#pragma once
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../Chain_of_Responsibility_Assignment/Client_Handler/CheckVarConst_Client.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
using namespace std;

class IHandler_if
{
protected:
    ~IHandler_if() = default;

public:
    virtual IHandler_if *SetNext(IHandler_if *handler) = 0;
    virtual bool Handle() = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    CheckVarConst_Client*check_var_const_client=new CheckVarConst_Client();
};
