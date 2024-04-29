#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"


class EnumerationHandler:public AbstractHandler
{
public:
    bool Handle(int TypeID) override;
};
