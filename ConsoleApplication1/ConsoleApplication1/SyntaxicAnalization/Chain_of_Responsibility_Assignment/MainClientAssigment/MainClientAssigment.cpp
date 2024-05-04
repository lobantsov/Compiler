﻿#include "MainClientAssigment.h"

#include "../../../LexAnalizator/LexAnalizator.h"

MainClientAssigment::MainClientAssigment()
{
    incrementa_client = new Incrementa_Client();
    logic_client = new Logic_Client();
    math_client = new Math_Client();
    initialization_handler = new Initialization_Handler();
    end_handler=new End_Handler();
    math_client->SetNext(incrementa_client)->SetNext(logic_client)->SetNext(initialization_handler);
}

bool MainClientAssigment::CheckAssigment(Lex Type)
{
    singletone_currentposition->currentPosition_backup=singletone_currentposition->currentPosition;
    if(math_client->Handle(Type))
    {
        if(end_handler->Handle(Type))
        return true;
        else
        {
            //missing ;
            return false;
        }
    }
    else
    {
        singletone_currentposition->currentPosition = singletone_currentposition->currentPosition_backup;
        return false;
    }
}
