#pragma once
#include "AbstractHandler.h"
#include "../../Singletone/SingletoneCurrentposition.h"

class EaqualHandler:public AbstractHandler
{
public:
    bool Handle(Lex TypeID) override;
};
