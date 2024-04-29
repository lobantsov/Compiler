#pragma once
#include "ICommand.h"

class ExitCommand:public ICommand
{
public:
    void Execute() override;
    string GetInfo() override;
};
