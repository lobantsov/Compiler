#pragma once
#include "iostream"
#include "vector"
#include "../LexAnalizator/Lex.h"
#include <windows.h>
using namespace std;

    class SynAnalizator
    {
    private:
        int currentPosition=0;
        void CreateSyntaxError();
        void CreateDeclarationError();
        int VariableIdexator = 2;

    public:
        
        SynAnalizator();
        vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
                                    ,"=","\""," " };

        vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
                                            "default","break","function","return","write","read", "long", "int", "float", "double",
                                            "string", "char", "let", "main"};
        vector<Lex> FinalLexConfig;
        bool MainCheck();
        bool DataTypeChreck();
        SynAnalizator(vector<Lex> lexes);
        void Print();
    };
