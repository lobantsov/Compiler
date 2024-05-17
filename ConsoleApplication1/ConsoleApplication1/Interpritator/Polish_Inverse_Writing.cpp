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

        if ((lex.lexID == constantID || lex.lexID == variableID) && (isOperatorBefore || isOperatorAfter))
        {
            if(!callBack.empty() and callBack.top() == "for" and IsLogicOperator(source_string_stack[source_string_stack.size()-2]))
            {
                tmpVectorForMovingSomeOperators.push(CreateNewComand("Move"));
                tmpVectorForMovingSomeOperators.push(lex);
                addingIntoTmpIncrementaStack++;
            }
            else
            {
                source_string_stack.push_back(lex);
            }
        }
        else if(lex.value == "(" or lex.value == "{")
        {
            stack_tmp.push(lex);
        }
        //operators
        else if(isOperation(lex.value))
        {
            //math and logic operators
            if (IsLogicOperator(lex) or IsMathOperator(lex) or lex.value == "=")
            {
                set_right_place_into_source_line_for_math_operators(lex);
            }
            //check write operator
            else if(lex.value == "write")
            {
                //skip ( and write
                iterator++;
                iterator++;
                //string or char data type
                if(LexAnalizator::FinalLexConfig[iterator].dataTypeID==381 or LexAnalizator::FinalLexConfig[iterator].dataTypeID == 391)
                {
                    //create new lex without " "
                   Lex tmp;
                    tmp.value = ExecuteStringSyntaxic(LexAnalizator::FinalLexConfig[iterator].value);
                    tmp.lexLine = LexAnalizator::FinalLexConfig[iterator].lexLine;
                    tmp.dataTypeID = LexAnalizator::FinalLexConfig[iterator].dataTypeID;
                    source_string_stack.push_back(tmp);
                    source_string_stack.push_back(lex);

                    //skip )
                    iterator++;
                }
                else
                {
                    source_string_stack.push_back(LexAnalizator::FinalLexConfig[iterator]);
                    source_string_stack.push_back(lex);

                    //skip )
                    iterator++;
                }
            }
            //check read
            else if(lex.value=="read")
            {
                //skip ( and write
                iterator++;
                iterator++;
                
                source_string_stack.push_back(LexAnalizator::FinalLexConfig[iterator]);
                source_string_stack.push_back(lex);

                //skip )
                iterator++;
            }
            //loop
            else if(lex.value=="for" or lex.value=="while")
            {
                callBack.push(lex.value);
                stack_tmp.push(lex);
            }
        }
        else if(lex.value==")")
        {
            while (stack_tmp.top().value!="(")
            {
                source_string_stack.push_back(stack_tmp.top());
                stack_tmp.pop();
            }
            stack_tmp.pop();
        }
        else if(lex.value=="}")
        {
            while (stack_tmp.top().value!="{")
            {
                stack_tmp.pop();
            }
            stack_tmp.pop();

            while (addingIntoTmpIncrementaStack!=0)
            {
                source_string_stack.push_back(tmpVectorForMovingSomeOperators.top());
                tmpVectorForMovingSomeOperators.pop();
                addingIntoTmpIncrementaStack--;
            }
            
            callBack.pop();
        }
        else if(lex.value==";")
        {
            //check math singt
            if(mathOperatorPushBack > 0)
            {
                while (mathOperatorPushBack!=0)
                {
                    source_string_stack.push_back(stack_tmp.top());
                    stack_tmp.pop();
                    mathOperatorPushBack--;
                }
            }
            //check callBack
            if(!callBack.empty())
            {
                if(callBack.top()=="for")
                {
                    //check i<10
                    if(IsLogicOperator(source_string_stack[source_string_stack.size()-1]))
                    {
                        source_string_stack.push_back(CreateNewComand("Condition"));
                    }
                    //check and add to tmp stack i++
                    else if(IsMathOperator(source_string_stack[source_string_stack.size()-1]))
                    {
                        Lex tmp = tmpVectorForMovingSomeOperators.top();
                        tmpVectorForMovingSomeOperators.pop();
                        tmpVectorForMovingSomeOperators.push(source_string_stack[source_string_stack.size()-1]);
                        source_string_stack.pop_back();
                        tmpVectorForMovingSomeOperators.push(tmp);
                        addingIntoTmpIncrementaStack++;
                        addingIntoTmpIncrementaStack++;
                    }
                }
            }
        }
        iterator++;
    }
}

int Polish_Inverse_Writing::getPriority(const string& op)
{
    if (op == "=" || op == "+=" || op == "-=" || op == "*=" || op == "/=") return 1; // Присвоєння
    if (op == "<" || op == ">" || op == "<=" || op == ">=" || op == "==" || op == "!=") return 4; // Порівняння
    if (op == "+" || op == "-") return 5; // Додавання та віднімання
    if (op == "*" || op == "/") return 6; // Множення та ділення
    if (op == "++" || op == "--" || op == "**") return 7; // Інкремент, декремент, степінь
    if (op == "(" || op == "{" || op == ")" || op == "}") return -1; // Дужки
    return 0; // За замовчуванням
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

void Polish_Inverse_Writing::set_right_place_into_source_line_for_math_operators(const Lex& op)
{
    int priority = getPriority(op.value);

    while (!stack_tmp.empty() && getPriority(stack_tmp.top().value) >= priority)
    {
        source_string_stack.push_back(stack_tmp.top());
        stack_tmp.pop();
        mathOperatorPushBack--;
    }
    stack_tmp.push(op);
    mathOperatorPushBack++;
}

bool Polish_Inverse_Writing::IsLogicOperator(const Lex& lex)
{
    if (lex.value == "==" || lex.value == "<=" || lex.value == "<" || lex.value == ">=" || lex.value == ">" || lex.value == "!=")
    return true;
    return false;
}

bool Polish_Inverse_Writing::IsMathOperator(const Lex& lex)
{
    if (lex.value == "+" || lex.value == "-" || lex.value == "*" || lex.value == "/"
                    || lex.value == "++" || lex.value == "--" || lex.value == "**" ||
                lex.value == "+=" || lex.value == "-=" || lex.value == "/=" || lex.value == "*=")
    return true;
    return false;
}

Lex Polish_Inverse_Writing::CreateNewComand(const string& typeComand)
{
    Lex tmp;
    if (typeComand == "Condition")
    {
        tmp.value = "Command_if";
        tmp.lexID = 200;
    }
    else if(typeComand == "Move")
    {
        tmp.value = "Command_move";
        tmp.lexID = 201;
    }
    return tmp;
}