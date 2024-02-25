#pragma once
#include <string>
#include "../../Singletone/SingletoneCurrentposition.h"
using namespace std;
class IHandler
{
public:
    virtual IHandler *SetNext(IHandler *handler) = 0;
    virtual bool Handle() = 0;
};
