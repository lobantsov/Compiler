#pragma once
#include "AbstractHandler_Assigment.h"

class ArrayCheck_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(Lex TypeID) override;
};
