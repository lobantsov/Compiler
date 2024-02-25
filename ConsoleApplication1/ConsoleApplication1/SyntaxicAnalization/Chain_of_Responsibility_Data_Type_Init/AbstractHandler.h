#pragma once
#include <vector>
#include "IHandler.h"
#include "../../LexAnalizator/Lex.h"
using namespace std;
class AbstractHandler:public IHandler
{
    IHandler *next_handler_;
protected:
    AbstractHandler(vector<Lex> lexes);
public:
    vector<Lex> FinalLexConfig;
    AbstractHandler() : next_handler_(nullptr){}
    IHandler *SetNext(IHandler *handler) override;
    bool Handle() override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
};
