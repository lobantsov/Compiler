#include <iostream>
#include "SyntaxicAnalization/SynAnalizator.h"
#include "LexAnalizator/LexAnalizator.h"
using namespace std;
int main()
{
	LexAnalizator analizator;
	SynAnalizator *syn_analizator = new SynAnalizator(analizator.readCode());
	//analizator.Print();
	if(syn_analizator->MainCheck()&&syn_analizator->DataTypeChreck())
	syn_analizator->Print();
	
}