#pragma once
#include "Igrac.h"
class IgracCovjek :
    public Igrac
{
public:
    int budzet;
    friend std::istream& operator>>(std::istream& stream, IgracCovjek& i);
};

