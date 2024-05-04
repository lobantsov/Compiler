#pragma once
#include <string>

class SingletoneCurrentposition
{
protected:
    SingletoneCurrentposition(){}
    static SingletoneCurrentposition* singleton_;

    std::string value_;

public:
    SingletoneCurrentposition(SingletoneCurrentposition &other) = delete;
    void operator=(const SingletoneCurrentposition &) = delete;
    static SingletoneCurrentposition *GetInstance();
    static int currentPosition;
    static int currentPosition_backup;
};
