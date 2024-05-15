#pragma once
#include <vector>

#include "../../LexAnalizator/Lex.h"
using namespace std;
class DeclareredVariables
{
protected:
    DeclareredVariables(){}
    static DeclareredVariables *declarered_variables_;
public:
    DeclareredVariables(DeclareredVariables &other) = delete;
    static DeclareredVariables *GetInstance();
    bool ContainingLex(const Lex& lex);
    Lex ContainingLexGetLex(const Lex& lex);
    vector<Lex> CreatedLexemus;
};
