#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype> 
#include <sstream>
#include "Lex.h"
using namespace std;

class LexAnalizator
{
public:

	int VariableIdexator = 0;
	vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
							,"=","\""," ","," };

	vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
										"default","break","function","return","write","read", "long", "int", "float", "double",
										"string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","=="};

	vector<string> a = {";",":",".","(",")","{","}","<",">","+","-","*","/"
		,"=","\""," ","," ,"for","or","while","do","of","if","else","switch","case",
				"default","break","function","return","write","read", "long", "int", "float", "double",
				"string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","=="};
	
	vector<Lex> FinalLexConfig;
	vector<Lex> VariablesTable;
	vector<Lex> ConstantsTable;
	vector<Lex> readCode();
	void removeElementAfter15(int index);
	void remove15BeforeAndAfterID(int ID);
	void Print();
	void processLexeme(const string& word, int line, const string& orLine);
	bool isVariable(const string& word, const string& orLine);
	bool isConstant(const string& word, const string& orLine);
	bool isQuotedString(const string& word, const string& orLine);
	bool ThisContains(vector<Lex>* tmp, const string& word);
	Lex GetLex(vector<Lex>* tmp, const string& word);
};