#include "AbstractHandler.h"
IHandler* AbstractHandler::SetNext(IHandler* handler)
{
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler::Handle(int TypeID)
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle(TypeID);
    }
    return {};
}
