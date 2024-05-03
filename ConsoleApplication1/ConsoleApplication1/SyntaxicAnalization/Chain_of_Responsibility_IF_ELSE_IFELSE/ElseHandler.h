#pragma once
#include "AbstractHandler_if.h"

class ElseHandler:public AbstractHandler_if
{
public:
    bool Handle()override;
};
