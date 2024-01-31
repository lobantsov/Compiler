#include <iostream>
#include "SyntaxicAnalization/SynAnalizator.h"
#include "LexAnalizator/LexAnalizator.h"
using namespace std;
int main()
{
	LexAnalizator *analizator = new LexAnalizator();
	SynAnalizator *syn_analizator = new SynAnalizator(analizator->readCode());
	if(syn_analizator->MainCheck())
	syn_analizator->Print();
}