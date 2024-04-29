#include "PrintCommand.h"
#include <iostream>
#include "../LexAnalizator/LexAnalizator.h"
using namespace std;
void PrintCommand::Execute()
{
    cout << "Vector content:"<<"\n";
    for (Lex value : LexAnalizator::FinalLexConfig)
    {
        cout << "ID: " << value.lexID << endl;
        cout << "LineN: " << value.lexLine << endl;
        cout << "ValueL: " << value.value << endl;
        cout << "----------------------------------------------" << endl;
    }
    cout << endl;
}
string PrintCommand::GetInfo()
{
    return "Print vector of lex";
}


