#pragma once
#include "AbstractHandler_Assigment.h"

class ArrayAssingment_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex Type) override;
};
