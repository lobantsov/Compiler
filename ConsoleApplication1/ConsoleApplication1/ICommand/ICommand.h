#pragma once
#include <string>
using namespace std;
class ICommand
{
public:
    virtual string GetInfo() = 0;
    virtual void Execute()=0;
    virtual ~ICommand() {}
};
