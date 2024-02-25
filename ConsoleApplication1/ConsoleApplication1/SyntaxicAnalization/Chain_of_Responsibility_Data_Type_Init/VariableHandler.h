#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"

class VariableHandler:public AbstractHandler
{
public:
    VariableHandler(vector<Lex> lexes);
    bool Handle() override;
};
