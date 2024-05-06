#include <vector>
#include <string>
#include "Lex.h"
using namespace std;

class LexAnalizator
{
public:
	static vector<string> SingleLexConfig; 

	static vector<string> MultiplyLexConfig; 

	// vector<string> a = {";",":",".","(",")","{","}","<",">","+","-","*","/" ,"=","\""," ",",","[","]","for","or","while","do","of","if","else","switch","case",
	// 									"default","break","function","return","write","read", "bool", "int", "float", "double",
	// 									"string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","==","new"};
	
	static vector<Lex> FinalLexConfig;
	vector<Lex> VariablesTable;
	vector<Lex> ConstantsTable;
	vector<Lex>* readCode();
	void removeElementAfter15(int index);
	void remove15BeforeAndAfterID(int ID);
	void Print();
	void processLexeme(const string& word, int line, const string& orLine);
	bool isVariable(const string& word, const string& orLine);
	bool isConstant(const string& word, const string& orLine);
	bool isQuotedString(const string& word, const string& orLine);
	bool ThisContains(vector<Lex>* tmp, const string& word);
	Lex GetLex(vector<Lex>* tmp, const string& word);
	void CheckConst();
	int checkNumberType(const std::string& s);
};