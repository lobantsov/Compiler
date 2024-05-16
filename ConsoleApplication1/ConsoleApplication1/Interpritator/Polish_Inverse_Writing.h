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
    
    void FormingSourceLine();
    int getPriority(const string& op);
    bool isOperation(const string& op);
    string ExecuteStringSyntaxic(const string& lexValue);
    int PriorityCheck(const string& operator_);
    int iterator=6;
};
