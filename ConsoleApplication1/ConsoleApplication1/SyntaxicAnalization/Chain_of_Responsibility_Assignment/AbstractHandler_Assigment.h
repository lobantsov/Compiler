#pragma once
#include <vector>
#include "IHandler_assigment.h"
#include "../../LexAnalizator/Lex.h"
using namespace std;
class AbstractHandler_Assigment:public IHandler_assigment
{
    IHandler_assigment *next_handler_;
protected:
public:
    IHandler_assigment *SetNext(IHandler_assigment *handler) override;
    bool Handle(int TypeID) override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};
