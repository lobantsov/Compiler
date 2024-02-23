#pragma once
#include "iostream"
#include "vector"
#include "../LexAnalizator/Lex.h"
#include <windows.h>
using namespace std;

    class SynAnalizator
    {
    private:
        void CreateSyntaxError();
        void CreateDeclarationError();

    public:
        
        SynAnalizator();
        int currentPosition=0;
        vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
                            ,"=","\""," ","," };

        vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
                                            "default","break","function","return","write","read", "long", "int", "float", "double",
                                            "string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","=="};
        vector<Lex> FinalLexConfig;
        bool MainCheck();
        bool DataTypeCheck();
        bool KomaCheck();
        bool ForCheck();
        bool ConditionCheck();
        bool DicremetnORIncrementCheck();
        bool SelfMathAdiction();
        SynAnalizator(vector<Lex> lexes);
        bool OperatorCheck();
        void Print();
    };
