﻿#pragma once
#include "../AbstractHandler_Assigment.h"
#include "../End_Handler.h"
#include "../IncrementaOperators_Handler.h"

class Incrementa_Client:public AbstractHandler_Assigment
{
public:
    Incrementa_Client();
    IncrementaOperators_Handler *incrementa_operators_handler;
    bool Handle(Lex Type) override;
};
