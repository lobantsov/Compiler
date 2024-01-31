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
        void CreateError();

    public:

        SynAnalizator();
        vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
                                    ,"=","\""," " };

        vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
                                            "default","break","function","return","write","read", "long", "int", "float", "double",
                                            "string", "char", "let", ""};
        vector<Lex> FinalLexConfig;
        bool MainCheck();
        SynAnalizator(vector<Lex> lexes);
        void Print();
    };
