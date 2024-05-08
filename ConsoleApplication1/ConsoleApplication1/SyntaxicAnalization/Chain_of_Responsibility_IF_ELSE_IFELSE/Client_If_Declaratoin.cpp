#include "Client_If_Declaratoin.h"
Client_If_Declaratoin::Client_If_Declaratoin()
{
    elsehandler=new ElseHandler();
    ifhandler = new  Ifhandler();
    ifhandler2 = new Ifhandler();
    ifhandler->SetNext(elsehandler)->SetNext(ifhandler2);
}

bool Client_If_Declaratoin::Check_if()
{
    if(ifhandler->Handle())
        return true;
    return false;
}
