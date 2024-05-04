#include "Incrementa_Client.h"
Incrementa_Client::Incrementa_Client()
{
    end_handler = new End_Handler();
    incrementa_operators_handler = new IncrementaOperators_Handler();
    incrementa_operators_handler->SetNext(end_handler);
}

bool Incrementa_Client::Handle(int TypeID)
{
    if(incrementa_operators_handler->Handle(TypeID))
        singletone_currentposition->currentPosition++;
    return AbstractHandler_Assigment::Handle(TypeID);
}

