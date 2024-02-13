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
        int VariableIdexator = 2;

    public:
        
        SynAnalizator();
        int currentPosition=0;
        vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
                                    ,"=","\""," " };

        vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
                                            "default","break","function","return","write","read", "long", "int", "float", "double",
                                            "string", "char", "let", "main"};
        vector<Lex> FinalLexConfig;
        bool MainCheck();
        bool DataTypeChreck();
        bool ForCheck();
        SynAnalizator(vector<Lex> lexes);
        bool OperatorCheck();
        void Print();
    };
