#pragma once
#include <string>
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"
#include "../SingletoneDeclaretedVariables/DeclareredVariables.h"
#include "..//../LexAnalizator/LexAnalizator.h"
using namespace std;
class IHandler
{
public:
    virtual IHandler *SetNext(IHandler *handler) = 0;
    virtual bool Handle(int TypeID) = 0;
    ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
    DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
};
