﻿#pragma once
#include "iostream"
#include "vector"
#include <windows.h>
#include "../Singletone/SingletoneCurrentposition.h"
#include "../SpawnErrors/ClassForCreateErorrs.h"
#include "Chain_of_Responsibility_Assignment/MainClientAssigment/MainClientAssigment.h"
#include "SingletoneDeclaretedVariables/DeclareredVariables.h"
#include "Chain_of_Responsibility_Declaration/ClientCode_Declaration.h"
#include "Chain_of_Responsibility_IF_ELSE_IFELSE/Client_If_Declaratoin.h"
#include "SyntaxicAnalizator_MathAndlogicOperator/SyntaxicAnalizator_MathAndlogicOperator.h"

using namespace std;

    class SynAnalizator
    {
    protected:
        ~SynAnalizator() = default;

    private:
        SingletoneCurrentposition *singletone_currentposition = SingletoneCurrentposition::GetInstance();
        ClassForCreateErorrs *create_erorrs = ClassForCreateErorrs::GetInstance();
        ClientCode_Declaration *client_code_declaration;
        Client_If_Declaratoin *client_if_declaratoin_;
        DeclareredVariables *declarered_variables_ = DeclareredVariables::GetInstance();
        MainClientAssigment *client_assigment_;
        stack<bool> callStack;
    public:
        
        SynAnalizator();
        bool MainCheck();
        bool DataTypeCheck();
        bool Assignment(bool endSigntStatus);
        bool Write();
        bool Read();
        bool ForCheck();
        bool OperatorCheck(bool innerCheckStatus);
        bool WhileCheck();
        //bool Do_whileCheck();
        void Print();
        bool innerStatus = false;
    };