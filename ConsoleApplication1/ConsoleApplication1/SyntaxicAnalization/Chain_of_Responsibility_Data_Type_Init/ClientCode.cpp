#include "ClientCode.h"

ClientCode::ClientCode(vector<Lex> lexes)
{
    variable_handler=new VariableHandler(lexes);
    eaqual_handler=new EaqualHandler(lexes);
    enumeration_handler=new EnumerationHandler(lexes);
    variable_handler->SetNext(eaqual_handler)->SetNext(enumeration_handler);
}

bool ClientCode::CheckDataType()
{
    if(variable_handler->Handle())
        return true;
    return false;
}
