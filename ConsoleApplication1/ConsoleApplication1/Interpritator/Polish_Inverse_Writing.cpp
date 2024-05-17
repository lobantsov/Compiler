#pragma once
#include "Polish_Inverse_Writing.h"
#include <iostream>
#include <iso646.h>

#include "../LexAnalizator/LexAnalizator.h"

void Polish_Inverse_Writing::FormingSourceLine()
{
    while (iterator < LexAnalizator::FinalLexConfig.size()-1)
    {
        Lex& lex = LexAnalizator::FinalLexConfig[iterator];
        int constantID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 1;
        int variableID = LexAnalizator::SingleLexConfig.size() + LexAnalizator::MultiplyLexConfig.size() + 2;

        bool isOperatorBefore = (iterator > 0) && isOperation(LexAnalizator::FinalLexConfig[iterator - 1].value);
        bool isOperatorAfter = (iterator + 1 < LexAnalizator::FinalLexConfig.size()) && (isOperation(LexAnalizator::FinalLexConfig[iterator + 1].value)||
                                        LexAnalizator::FinalLexConfig[iterator+1].value==")");
        
        if (lex.value == "}") 
        {
            if(!callBack.empty() and callBack.top() != "do_while")
            {
                if (!stack_tmp.empty())
                {
                    stack_tmp.pop();
                }
                if (!stack_tmp.empty() && iterator + 1 < LexAnalizator::FinalLexConfig.size())
                {
                    stack_tmp.pop();
                    callBack.pop();
                }
            }
            else
            {
                Lex command;
                command.lexID = 200;
                command.value = "Command_if";
                source_string_stack.push_back(command);
                stack_tmp.pop();
                stack_tmp.pop();
                callBack.pop();
            }
        }
        if ((lex.lexID == constantID || lex.lexID == variableID) && (isOperatorBefore || isOperatorAfter))
        {
            source_string_stack.push_back(lex);
        }
        else if (isOperation(lex.value))
        {
            if(lex.value =="for" or lex.value=="while" or lex.value=="do_while" or
                lex.value == "write" or lex.value == "read" or lex.value == "if" or lex.value =="else")
            {
                callBack.push(lex.value);
            }
                while (!stack_tmp.empty() && getPriority(stack_tmp.top().value) >= getPriority(lex.value))
                {
                    source_string_stack.push_back(stack_tmp.top());
                    stack_tmp.pop();
                }
                stack_tmp.push(lex);
        }
        else if (lex.value == "(" || lex.value == "{")
        {
            stack_tmp.push(lex);
        }
        else if (lex.value == ")")
        {
            while (!stack_tmp.empty() && (stack_tmp.top().value != "("))
            {
                source_string_stack.push_back(stack_tmp.top());
                stack_tmp.pop();
            }
            stack_tmp.pop();
            if(!stack_tmp.empty())
            {
                if(callBack.top() == "while" or callBack.top() == "if" or callBack.top() == "for")
                {
                    Lex command;
                    command.lexID = 200;
                    command.value = "Command_if";
                    source_string_stack.push_back(command);
                }
                else if(callBack.top()!="do_while")
                {
                    source_string_stack.push_back(stack_tmp.top());
                    stack_tmp.pop();
                    callBack.pop();
                    iterator++;
                }
            }
        }
       
        else if (lex.value == ";")
        {
            if (!stack_tmp.empty())
            {
                if(stack_tmp.top().value == "write" or stack_tmp.top().value == "read")
                {
                    stack_tmp.pop();
                }
                source_string_stack.push_back(stack_tmp.top());
                if(!callBack.empty() and callBack.top() == "for")
                {
                    if(stack_tmp.top().value == "<" or stack_tmp.top().value == "<=" or stack_tmp.top().value == ">"
                        or stack_tmp.top().value == ">=" or stack_tmp.top().value == "==" or stack_tmp.top().value == "!=")
                    {
                        Lex command;
                        command.lexID = 200;
                        command.value = "Command_if";
                        source_string_stack.push_back(command);
                    }
                    else if(stack_tmp.top().value == "++" or stack_tmp.top().value == "--" or
                        stack_tmp.top().value == "**" or stack_tmp.top().value == "+=" or
                        stack_tmp.top().value == "-=" or stack_tmp.top().value == "/=" or
                        stack_tmp.top().value == "*=")
                    {
                        Lex command;
                        command.lexID = 200;
                        command.value = "Command_move";
                        source_string_stack.push_back(command);
                    }
                }
                stack_tmp.pop();
            }
        }
        iterator++;
    }
    
    while (!stack_tmp.empty())
    {
        source_string_stack.push_back(stack_tmp.top());
        stack_tmp.pop();
    }
}

int Polish_Inverse_Writing::getPriority(const string& op)
{
    if (op == "=") return 1;
    if (op == "+" || op == "-") return 2;
    if (op == "++" || op == "--" || op == "**") return 2;
    if (op == "write" || op == "read") return 2;
    if (op == "*" || op == "/") return 3;
    if (op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" ||  op == "!=") return 4;
    if (op == "(" || op == "{" || op == ")" || op == "}") return -1;
    return 0;
}

bool Polish_Inverse_Writing::isOperation(const string& op)
{
    return op == "+" || op == "-" || op == "*" || op == "/" || 
           op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=" ||
           op == "++" || op == "--" || op == "**" ||
           op == "<" || op == ">" || op == "<=" || op == ">=" || op == "=="||  op == "!=" ||
           op == "for" || op == "do_while" || op == "while" || op == "if" || op == "else"||
           op == "write" || op == "read";
}

string Polish_Inverse_Writing::ExecuteStringSyntaxic(const std::string& lexValue)
{
    std::string result = lexValue;
    result.erase(std::remove(result.begin(), result.end(), '\"'), result.end());
    return result;
}