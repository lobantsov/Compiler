#include "ExitCommand.h"

#include <iostream>

void ExitCommand::Execute()
{
    cout << "Exiting program...\n";
    exit(0);
}
string ExitCommand::GetInfo()
{
    return "Exit application";
}

