#pragma once
#include "AbstractHandler_Assigment.h"

class CheckVar_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};
