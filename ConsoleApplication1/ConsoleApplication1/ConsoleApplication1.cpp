#include <iostream>

#include "ICommand/ExitCommand.h"
#include "ICommand/Invoker.h"
#include "ICommand/PrintCommand.h"
#include "SyntaxicAnalization/SynAnalizator.h"
using namespace std;
int main()
{
	string command;
	Invoker invoker;
	PrintCommand print_command;
	ExitCommand exit_command;
	ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
	
	invoker.AddCommand(make_unique<PrintCommand>(print_command));
	invoker.AddCommand(make_unique<ExitCommand>(exit_command));
	
	LexAnalizator *analizator=new LexAnalizator();
	analizator->readCode();
	SynAnalizator *syn_analizator = new SynAnalizator();
	
	if(syn_analizator->MainCheck())
	{
		while (SingletoneCurrentposition::currentPosition<LexAnalizator::FinalLexConfig.size())
		{
			if(syn_analizator->OperatorCheck(false))
			{
				analizator->Print();
				break;
			}
			if(create_erorrs->error_status)
				break;
		}
	}
}