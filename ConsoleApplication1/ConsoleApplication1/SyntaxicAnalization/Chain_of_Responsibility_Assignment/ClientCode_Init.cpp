#include "ClientCode_Init.h"
ClientCode_Init::ClientCode_Init()
{
    eaqual_handler=new EaqualHandler();
    enumeration_handler=new EnumerationHandler();
    eaqual_handler->SetNext(enumeration_handler);
}

bool ClientCode_Init::CheckDataAssignment(int TypeID)
{
    if(eaqual_handler->Handle(TypeID))
        return true;
    return false;
}