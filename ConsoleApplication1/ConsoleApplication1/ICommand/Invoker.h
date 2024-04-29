#pragma once
#include <memory>
#include <vector>

#include "ICommand.h"

class Invoker
{
private:
    std::vector<std::unique_ptr<ICommand>> commands_;
public:
    void AddCommand(std::unique_ptr<ICommand> command);
    void ShowCommandMenu();
    int GetUserChoice();
    void Run();
    void ExecuteCommand(int index);
};
