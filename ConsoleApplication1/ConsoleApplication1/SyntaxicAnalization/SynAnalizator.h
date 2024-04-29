#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../SpawnErrors/ClassForCreateErorrs.h"
#include "Chain_of_Responsibility_Data_Type_Init/ClientCode.h"
#include "SyntaxicAnalizator_MathAndlogicOperator/SyntaxicAnalizator_MathAndlogicOperator.h"
using namespace std;

    class SynAnalizator
    {
        SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
        ClassForCreateErorrs *create_erorrs = new ClassForCreateErorrs();
        ClientCode *client_code;
        SyntaxicAnalizator_MathAndlogicOperator *_syntaxicAnalizator_MathAndlogicOperator = new SyntaxicAnalizator_MathAndlogicOperator();
        
    public:
        
        SynAnalizator();
      
        bool MainCheck();
        bool DataTypeCheck();
        bool KomaCheck();
        bool ForCheck();
        //bool SelfMathAdiction();
        bool OperatorCheck();
        //bool MathOperatorCheck();
        void Print();
    };
