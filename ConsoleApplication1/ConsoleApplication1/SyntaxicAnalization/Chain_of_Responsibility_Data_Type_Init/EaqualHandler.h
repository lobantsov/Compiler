#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"

class EaqualHandler:public AbstractHandler
{
public:
    EaqualHandler(vector<Lex> lexes);
    bool Handle() override;
};
