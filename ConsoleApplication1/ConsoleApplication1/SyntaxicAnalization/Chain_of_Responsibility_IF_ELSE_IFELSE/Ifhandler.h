#pragma once
#include "AbstractHandler_if.h"

class Ifhandler:public AbstractHandler_if
{
public:
    bool Handle()override;
};
