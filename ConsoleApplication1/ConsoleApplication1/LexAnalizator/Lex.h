#pragma once
#include <string>
using namespace std;
    class Lex
    {
    public:
        string value;
        int lexID=-1;
        int lexLine=-1;
        int dataTypeID=-1;
        int array=-1;//-1 - is not array     0 - is array without new       1 - is array was init
        string data;
        bool operator==(const Lex& other) const {
            return value == other.value && lexID == other.lexID && dataTypeID == other.dataTypeID;
        }
    };