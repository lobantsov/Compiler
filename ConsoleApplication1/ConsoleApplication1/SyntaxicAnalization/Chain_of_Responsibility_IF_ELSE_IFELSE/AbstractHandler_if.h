#pragma once
#include "IHandler_if.h"    
#include <vector>

#include "../Chain_of_Responsibility_Assignment/MainClientAssigment/MainClientAssigment.h"
#include "../SyntaxicAnalizator_MathAndlogicOperator/SyntaxicAnalizator_MathAndlogicOperator.h"

using namespace std;
class AbstractHandler_if:public IHandler_if
{
    IHandler_if *next_handler_;
protected:
public:
    IHandler_if *SetNext(IHandler_if *handler) override;
    bool Handle() override;
    SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
    SyntaxicAnalizator_MathAndlogicOperator *_syntaxicAnalizator_MathAndlogicOperator = new SyntaxicAnalizator_MathAndlogicOperator();
    MainClientAssigment *client_assigment = new MainClientAssigment();
};
