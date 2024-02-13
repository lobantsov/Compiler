#include <iostream>
#include "SyntaxicAnalization/SynAnalizator.h"
#include "LexAnalizator/LexAnalizator.h"
using namespace std;
int main()
{
	LexAnalizator analizator;
	SynAnalizator *syn_analizator = new SynAnalizator(analizator.readCode());
	analizator.Print();
	if(syn_analizator->MainCheck())
	{
		while (syn_analizator->currentPosition!=syn_analizator->FinalLexConfig.size())
		{
			do
			{
				
			}while (syn_analizator->FinalLexConfig[syn_analizator->currentPosition-1].lexID == 0);	
		}
	}	
}