﻿#pragma once
#include "AbstractHandler_Assigment.h"

class End_Handler:public AbstractHandler_Assigment
{
public:
    bool Handle(int TypeID) override;
};
