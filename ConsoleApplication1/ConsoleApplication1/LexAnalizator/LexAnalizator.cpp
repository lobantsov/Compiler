#include "LexAnalizator.h"

vector<Lex> LexAnalizator::readCode()
{
    ifstream fileForParth("C:\\Users\\loban\\OneDrive\\Desktop\\13.txt");
    if (!fileForParth.is_open())
    {
        cerr << "????????? ??????? ????" << endl;
    }
    else {
        string line;
        string currentWord;
        Lex lex;
        int index = 0;
        
        while (getline(fileForParth, line))
        {
            index++;

            for (int i = 0; i < line.length(); i++) {
                auto found = find(SingleLexConfig.begin(), SingleLexConfig.end(), string(1, line[i]));

                if (found != SingleLexConfig.end())
                {
                    if (!currentWord.empty())
                    {
                        processLexeme(currentWord, index, line);
                        currentWord.clear();
                    }

                    lex.value = *found;
                    lex.lexID = distance(SingleLexConfig.begin(), found);
                    lex.lexLine = index;
                    FinalLexConfig.push_back(lex);
                }
                else
                {
                    currentWord += line[i];
                }
            }

            if (!currentWord.empty()) 
            {
                processLexeme(currentWord, index, line);
                currentWord.clear();
            }
        }

        fileForParth.close();
        /*int tmpLenth = FinalLexConfig.size();
        for (int i = 0; i < tmpLenth; i++)
        {
            if (VariablesTable.size() > i)
            {
                VariablesTable[i].lexID = FinalLexConfig.size() + 1;
                FinalLexConfig.push_back(VariablesTable[i]);
            }
            if (ConstantsTable.size() > i)
            {
                ConstantsTable[i].lexID = FinalLexConfig.size() + 1;
                FinalLexConfig.push_back(ConstantsTable[i]);
            }
        }*/
       //Print();
        return FinalLexConfig;
    }
    return {};
}

void LexAnalizator::Print()
{
    for (int i = 0; i < FinalLexConfig.size(); i++)
    {
        cout << "ID: " << FinalLexConfig[i].lexID << endl;
        cout << "LineN: " << FinalLexConfig[i].lexLine << endl;
        cout << "ValueL: " << FinalLexConfig[i].value << endl;
        cout << "----------------------------------------------" << endl;
    }
}

void LexAnalizator::processLexeme(const string& word, int line, const string& orLine)
{
    Lex lex;
    // ???????? ?? ?????
    if (isVariable(word, orLine))
    {
        if (!ThisContains(&VariablesTable, word))
        {
            VariableIdexator++;
            lex.value = word;
            lex.lexID = VariableIdexator;
            lex.lexLine = line;
            VariablesTable.push_back(lex);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
        else
        {
            auto lex = GetLex(&VariablesTable, word);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
    }
    // ???????? ?? ?????????
    else if (isConstant(word, orLine))
    {
        if (!ThisContains(&ConstantsTable, word))
        {
            //ConstIdexator+=2;
            lex.value = word;
            VariableIdexator++;
            lex.lexID = VariableIdexator;
            lex.lexLine = line;
            ConstantsTable.push_back(lex);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
        else
        {
            auto lex = GetLex(&ConstantsTable, word);
            lex.lexID += SingleLexConfig.size() + MultiplyLexConfig.size();
            FinalLexConfig.push_back(lex);
        }
    }
    else 
    {
        auto it = find(MultiplyLexConfig.begin(), MultiplyLexConfig.end(), word);
        lex.value = word;
        lex.lexID = distance(MultiplyLexConfig.begin(), it)+ SingleLexConfig.size();
        lex.lexLine = line;
        FinalLexConfig.push_back(lex);
    }

}

bool LexAnalizator::isVariable(const string& word, const string& orLine)
{
    if (find(SingleLexConfig.begin(), SingleLexConfig.end(), word) != SingleLexConfig.end())
    {
        return false;
    }

    if (find(MultiplyLexConfig.begin(), MultiplyLexConfig.end(), word) != MultiplyLexConfig.end())
    {
        return false;
    }
    if (isQuotedString(word, orLine))
    {
        return false;
    }
    if (word.empty()) {
        return false;
    }
    if (!isalpha(word[0]) && word[0] != '_') {
        return false; 
    }
    for (char ch : word.substr(1)) {
        if (!isalnum(ch) && ch != '_') {
            return false; 
        }
    }
    return true;  
}

bool LexAnalizator::isConstant(const string& word, const string& orLine)
{
    if (word.empty()) {
        return false;
    }
    if (isQuotedString(word, orLine))
    {
        return true;
    }
    bool hasDot = false;
    for (char ch : word) {
        if (isdigit(ch)) {
            continue; 
        }
        else if (ch == '.' && !hasDot) {
            hasDot = true;
        }
        else {
            return false; 
        }
    }

    return true;
}

bool LexAnalizator::isQuotedString(const string& word, const string& orLine)
{
    if (word.empty()) 
    {
        return false;
    }

    size_t position = orLine.find(word);
    if (position > 0) 
    {
        if (orLine[position - 1] == '"' && orLine[position + word.length()] == '"') return true;
    }
    return false;
}



bool LexAnalizator::ThisContains(vector<Lex> *tmp,const string& word)
{
    for (int i = 0; i < tmp->size(); i++)
    {
        if ((*tmp)[i].value == word)
        {
            return true;
        }
    }
    return false;
}

Lex LexAnalizator::GetLex(vector<Lex> *tmp ,const string&word)
{
    Lex newLex;
    for (int i = 0; i < tmp->size(); i++)
    {
        if ((*tmp)[i].value == word)
        {
            newLex.value = (*tmp)[i].value;
            newLex.lexID = (*tmp)[i].lexID;
            newLex.lexLine = (*tmp)[i].lexLine;
            return newLex;
        }
    }
}