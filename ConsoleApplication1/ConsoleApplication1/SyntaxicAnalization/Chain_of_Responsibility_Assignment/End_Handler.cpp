#include "End_Handler.h"
bool End_Handler::Handle(int TypeID)
{
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        singletone_currentposition->currentPosition++;
    }
    return AbstractHandler_Assigment::Handle(TypeID);
}
