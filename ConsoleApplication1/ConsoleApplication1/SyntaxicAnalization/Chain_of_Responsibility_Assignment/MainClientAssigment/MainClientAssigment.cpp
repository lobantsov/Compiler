#include "MainClientAssigment.h"
MainClientAssigment::MainClientAssigment()
{
    incrementa_client = new Incrementa_Client();
    logic_client = new Logic_Client();
    math_client = new Math_Client();
    initialization_handler = new Initialization_Handler();
    math_client->SetNext(incrementa_client)->SetNext(logic_client)->SetNext(initialization_handler);
}

bool MainClientAssigment::CheckAssigment(int TypeId)
{
    singletone_currentposition->currentPosition_backup=singletone_currentposition->currentPosition;
    if(math_client->Handle(TypeId))
        return true;
    else
    {
        singletone_currentposition->currentPosition = singletone_currentposition->currentPosition_backup;
        return false;
    }
}
