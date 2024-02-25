#include "AbstractHandler.h"
IHandler* AbstractHandler::SetNext(IHandler* handler)
{
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler::Handle()
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle();
    }
    return {};
}

AbstractHandler::AbstractHandler(vector<Lex> lexes)
{
    FinalLexConfig = lexes;
}