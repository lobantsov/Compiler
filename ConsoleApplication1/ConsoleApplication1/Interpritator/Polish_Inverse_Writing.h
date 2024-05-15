#pragma once
#include <stack>
#include <vector>
#include "../LexAnalizator/Lex.h"
#include "../Singletone/SingletoneCurrentposition.h"

class Polish_Inverse_Writing
{
public:
    std::stack<Lex> source_string_stack;
    std::stack<Lex> stack_tmp;
    void FormingSourceLine();
    int getPriority(const string& op);
    bool isOperation(const string& op);
    int PriorityCheck(const string& operator_);
    int iterator=6;
};
