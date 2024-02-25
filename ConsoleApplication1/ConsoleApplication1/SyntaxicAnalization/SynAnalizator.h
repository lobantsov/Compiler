#pragma once
#include "iostream"
#include "vector"
#include "../LexAnalizator/Lex.h"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../SpawnErrors/ClassForCreateErorrs.h"
#include "Chain_of_Responsibility_Data_Type_Init/ClientCode.h"
using namespace std;

    class SynAnalizator
    {
    public:
        
        SynAnalizator();
        SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
        // int currentPosition=0;
        vector<string> SingleLexConfig{ ";",":",".","(",")","{","}","<",">","+","-","*","/"
                            ,"=","\""," ","," };

        vector<string> MultiplyLexConfig{ "for","or","while","do","of","if","else","switch","case",
                                            "default","break","function","return","write","read", "long", "int", "float", "double",
                                            "string", "char", "let", "main","++","--","**","+=","-=","*=","/=","<=",">=","=="};
        vector<Lex> FinalLexConfig;
        ClassForCreateErorrs *create_erorrs = new ClassForCreateErorrs(FinalLexConfig);
        ClientCode *client_code;
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
