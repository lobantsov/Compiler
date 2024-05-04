#include "MainClientAssigment.h"
MainClientAssigment::MainClientAssigment()
{
    incrementa_client = new Incrementa_Client();
    logic_client = new Logic_Client();
    math_client = new Math_Client();
    math_client->SetNext(incrementa_client)->SetNext(logic_client);
}

bool MainClientAssigment::CheckAssigment(int TypeId)
{
    if(math_client->Handle(TypeId))
        return true;
    return false;
}
