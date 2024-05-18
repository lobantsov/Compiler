#pragma once
#include <stack>
#include <vector>
#include "../LexAnalizator/Lex.h"
#include "../Singletone/SingletoneCurrentposition.h"

class Polish_Inverse_Writing
{
public:
    std::vector<Lex> source_string_stack;
    std::stack<Lex> stack_tmp;
    std::stack<string> callBack;
    stack<Lex> tmpVectorForMovingSomeOperators;
    
    void FormingSourceLine();
    int getPriority(const string& op);
    bool isOperation(const string& op);
    string ExecuteStringSyntaxic(const string& lexValue);
    void set_right_place_into_source_line_for_math_operators(const Lex& op);
    bool IsLogicOperator(const Lex& op);
    bool IsMathOperator(const Lex& lex);
    Lex CreateNewComand(const string& typeComand);
    int mathOperatorPushBack=0;
    int addingIntoTmpIncrementaStack=0;
    int iterator=6;
    bool forOperator=true;
};
