#include "AbstractHandler_Assigment.h"
IHandler* AbstractHandler_Assigment::SetNext(IHandler* handler)
{
    this->next_handler_ = handler;
    return handler;
}

bool AbstractHandler_Assigment::Handle(int TypeID)
{
    if (this->next_handler_)
    {
        return this->next_handler_->Handle(TypeID);
    }
    return {};
}
