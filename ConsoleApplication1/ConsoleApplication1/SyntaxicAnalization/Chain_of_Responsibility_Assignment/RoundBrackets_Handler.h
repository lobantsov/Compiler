﻿#pragma once
#include <stack>

#include "AbstractHandler_Assigment.h"

class RoundBrackets_Handler:public AbstractHandler_Assigment
{
public:
    std::vector<Lex> result;
    std::stack<Lex> operation;
    bool Handle(Lex Type) override;
    bool Translate(std::string line);
    bool IsTokenValid(const std::string& s, Lex& lex);
    bool IsNumber(const std::string& s);
    bool IsVariable(const std::string& s);
    int Priority(const Lex& lex);
};
