#pragma once
#include <vector>
#include "IHandler_assigment.h"
#include "../../LexAnalizator/Lex.h"
using namespace std;
class AbstractHandler_Assigment:public IHandler
{
    IHandler *next_handler_;
protected:
public:
    IHandler *SetNext(IHandler *handler) override;
    bool Handle(int TypeID) override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};
