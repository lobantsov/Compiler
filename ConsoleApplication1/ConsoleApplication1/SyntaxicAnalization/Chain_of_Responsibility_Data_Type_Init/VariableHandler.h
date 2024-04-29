#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"

class VariableHandler:public AbstractHandler
{
public:
    bool Handle(int type_id)override;
};
