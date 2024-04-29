#include "Invoker.h"
#include <iostream>

void Invoker::ExecuteCommand(int index)
{
    if (index >= 0 && index < commands_.size())
    {
        commands_[index]->Execute();
    }
    else
    {
        cout << "Invalid command index.\n";
    }
}

void Invoker::AddCommand(std::unique_ptr<ICommand> command)
{
    commands_.push_back(move(command));
}
void Invoker::ShowCommandMenu()
{
    cout << "Available commands:\n";
    for (size_t i = 0; i < commands_.size(); ++i) {
        cout << i << ": " << commands_[i]->GetInfo() << endl;
    }
}

int Invoker::GetUserChoice()
{
    int choice;
    cout << "Enter command index: ";
    cin >> choice;
    return choice;
}
void Invoker::Run() {
    while (true)
    {
        ShowCommandMenu();
        int choice = GetUserChoice();
        
        ExecuteCommand(choice);
        
        if (choice == 1)
        {
            break;
        }
    }
}


