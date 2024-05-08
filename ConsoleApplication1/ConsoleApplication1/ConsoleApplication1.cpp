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
	
	SingletoneCurrentposition *aa = SingletoneCurrentposition::GetInstance();
	DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();

	invoker.AddCommand(make_unique<PrintCommand>(print_command));
	invoker.AddCommand(make_unique<ExitCommand>(exit_command));
	
	LexAnalizator *analizator=new LexAnalizator();
	string path[]={
	"C:\\Users\\loban\\OneDrive\\Desktop\\declaratoion.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\DoWhileOperator.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\ForOperator.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\Foreach.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\Assigment.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\if.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\IfElse.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\IfElseIf.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\WhileOperator.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\write.txt",
	"C:\\Users\\loban\\OneDrive\\Desktop\\read.txt"
	};
	
	for(const string &a : path)
	{
		analizator->readCode(a);
		
		SynAnalizator *syn_analizator = new SynAnalizator();

		cout<<"Do check- "<<a<<endl;
		if(syn_analizator->MainCheck())
		{
			while (SingletoneCurrentposition::currentPosition<LexAnalizator::FinalLexConfig.size())
			{
				if(syn_analizator->OperatorCheck(false))
				{
					//analizator->Print();
					cout<<a<<"- checked"<<endl;
					break;
				}
				if(create_erorrs->error_status)
				{
					cout<<"Error hear:"<<a<<endl;
					break;
				}
			}
		}
		cout<<endl;
		LexAnalizator::FinalLexConfig.clear();
		aa->currentPosition=0;
		declarered_variables_->CreatedLexemus.clear();
		create_erorrs->error_status=false;
	}
}