#include "IgracCovjek.h"
#include <iostream>

std::istream& operator>>(std::istream& stream, IgracCovjek& i)
{
    i.setNaziv();
    std::cout << "Unesite budzet: ";
    std::cin >> i.budzet;
    std::cin.ignore();
    return stream;
}
