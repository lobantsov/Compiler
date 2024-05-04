#include "Incrementa_Client.h"
Incrementa_Client::Incrementa_Client()
{
    end_handler = new End_Handler();
    incrementa_operators_handler = new IncrementaOperators_Handler();
    incrementa_operators_handler->SetNext(end_handler);
}

bool Incrementa_Client::Handle(Lex Type)
{
    if(incrementa_operators_handler->Handle(Type))
        return true;
    return AbstractHandler_Assigment::Handle(Type);
}

