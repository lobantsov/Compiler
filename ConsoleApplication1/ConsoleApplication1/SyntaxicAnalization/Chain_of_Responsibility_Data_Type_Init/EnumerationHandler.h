#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"
#include "../../SpawnErrors/ClassForCreateErorrs.h"


class EnumerationHandler:public AbstractHandler
{
public:
    EnumerationHandler(vector<Lex> lexes);
    bool Handle() override;
};
