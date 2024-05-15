#pragma once
#include "Polish_Inverse_Writing.h"
#include "../LexAnalizator/LexAnalizator.h"

void Polish_Inverse_Writing::FormingSourceLine()
{
    while (iterator < LexAnalizator::FinalLexConfig.size())
    {
        Lex& lex = LexAnalizator::FinalLexConfig[iterator];
        int constantID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1;
        int variableID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2;

        bool isOperatorBefore = (iterator > 0) && isOperation(LexAnalizator::FinalLexConfig[iterator - 1].value);
        bool isOperatorAfter = (iterator + 1 < LexAnalizator::FinalLexConfig.size()) && (isOperation(LexAnalizator::FinalLexConfig[iterator + 1].value)||
                                                                                            LexAnalizator::FinalLexConfig[iterator+1].value==")");

        if ((lex.lexID == constantID || lex.lexID == variableID) && (isOperatorBefore || isOperatorAfter))
        {
            source_string_stack.push(lex);
        }
        else if (isOperation(lex.value))
        {
            while (!stack_tmp.empty() && getPriority(stack_tmp.top().value) >= getPriority(lex.value))
            {
                source_string_stack.push(stack_tmp.top());
                stack_tmp.pop();
            }
            stack_tmp.push(lex);
        }
        else if (lex.value == "(" || lex.value == "{")
        {
            stack_tmp.push(lex);
        }
        else if (lex.value == ")" || lex.value == "}")
        {
            while (!stack_tmp.empty() && (stack_tmp.top().value != "(" && stack_tmp.top().value != "{"))
            {
                source_string_stack.push(stack_tmp.top());
                stack_tmp.pop();
            }
            if (!stack_tmp.empty()) stack_tmp.pop(); // Remove the opening bracket from the stack
        }
        else if (lex.value == ";")
        {
            if (!stack_tmp.empty())
            {
                source_string_stack.push(stack_tmp.top());
                stack_tmp.pop();
            }
        }
        iterator++;
    }

    
    while (!stack_tmp.empty())
    {
        source_string_stack.push(stack_tmp.top());
        stack_tmp.pop();
    }
}
int Polish_Inverse_Writing::getPriority(const string& op) {
    if (op == "=") return 1;
    if (op == "+" || op == "-") return 2;
    if (op == "*" || op == "/") return 3;
    if (op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==") return 4;
    if (op == "(" || op == "{" || op == ")" || op == "}") return -1;
    return 0;
}
bool Polish_Inverse_Writing::isOperation(const string& op) {
    return op == "+" || op == "-" || op == "*" || op == "/" || 
           op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=" ||
           op == "++" || op == "--" || op == "**" ||
           op == "<" || op == ">" || op == "<=" || op == ">=" || op == "=="||
           op == "for" || op == "do" || op == "while" || op == "if" || op == "else"||
           op == "write" || op == "read";
}