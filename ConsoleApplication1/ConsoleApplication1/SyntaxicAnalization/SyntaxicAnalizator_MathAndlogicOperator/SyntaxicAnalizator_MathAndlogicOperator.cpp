#include "SyntaxicAnalizator_MathAndlogicOperator.h"


bool SyntaxicAnalizator_MathAndlogicOperator::MathOperatorCheck()
{
    //var
    //+-*/
    // if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    // {
    //     tmpConst = singletone_currentposition->currentPosition;
    //     singletone_currentposition->currentPosition++;
    // }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==9||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==10||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==11||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==12)
    {
        //var of const
        singletone_currentposition->currentPosition++;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1||
           LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            //create_erorrs->CreateSyntaxError();
            return false;
        }
        //;
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
        {
            return true;
        }
        else
        {
            //create_erorrs->CreateSyntaxError();
            return false;
        }
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
}

bool SyntaxicAnalizator_MathAndlogicOperator::SelfMathAdiction()
{
    //var
    //+=,-=,*=,/=
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateDeclarationError();
            return false;
        }
    }
   
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==43||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==44||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==45||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==46)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1&&
        declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
}

bool SyntaxicAnalizator_MathAndlogicOperator::ConditionCheck(bool isloop)
{
    //<,>,<=,>=,==
    //add check for declareted var
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1&&
         declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))||
         LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==7||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==8||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==47||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==48||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==49)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
    if((LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1&&
         declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))||
         LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+2)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //create_erorrs->CreateSyntaxError();
        return false;
    }
    if(isloop)
    {
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==4)
        {
            return true;
        }
    }
    else
    {
        
        if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
        {
            return true;
        }
        else
        {
            //create_erorrs->CreateSyntaxError();
            return false;
        }
    }
}

bool SyntaxicAnalizator_MathAndlogicOperator::IncrementAndDicremental()
{
    //++,--,**
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==LexAnalizator::SingleLexConfig.size()+LexAnalizator::MultiplyLexConfig.size()+1)
    {
        if(declarered_variables_->ContainingLex(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition]))
        {
            singletone_currentposition->currentPosition++;
        }
        else
        {
            create_erorrs->CreateDeclarationError();
            return false;
        }
    }
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==42||LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==43||
        LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==44)
    {
        singletone_currentposition->currentPosition++;
    }
    else
    {
        //singletone_currentposition->currentPosition--;
        return false;
    }
    
    if(LexAnalizator::FinalLexConfig[singletone_currentposition->currentPosition].lexID==0)
    {
        return true;
    }
    else
    {
        //create_erorrs->CreateSyntaxError();
        return false;
    }
}
