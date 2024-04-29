#pragma once
#include "ICommand.h"

class PrintCommand:public ICommand
{
public:
    void Execute() override;
    string GetInfo() override;
};
