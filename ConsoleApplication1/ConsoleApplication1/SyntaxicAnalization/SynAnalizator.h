#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../SpawnErrors/ClassForCreateErorrs.h"
#include "Chain_of_Responsibility_Data_Type_Init/ClientCode_Declaration.h"
#include "Chain_of_Responsibility_Data_Type_Init/ClientCode_Init.h"
#include "SingletoneDeclaretedVariables/DeclareredVariables.h"
#include "SyntaxicAnalizator_MathAndlogicOperator/SyntaxicAnalizator_MathAndlogicOperator.h"
using namespace std;

    class SynAnalizator
    {
        SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
        ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
        ClientCode_Declaration *client_code_declaration;
        ClientCode_Init *client_code_init;
        SyntaxicAnalizator_MathAndlogicOperator *_syntaxicAnalizator_MathAndlogicOperator = new SyntaxicAnalizator_MathAndlogicOperator();
        DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
    public:
        
        SynAnalizator();
        bool MainCheck();
        bool DataTypeCheck();
        bool Assignment();
        bool ForCheck();
        bool OperatorCheck();
        bool WhileCheck();
        void Print();
    };