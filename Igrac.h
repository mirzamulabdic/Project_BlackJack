#pragma once
#include <string>
#include <vector>
#include "Karta.h"
using std::string;
using std::vector;

class Igrac
{
public:
	string naziv;
	vector<Karta> ruka;
	Igrac() {
		this->naziv = "Dealer";
	}
	void setNaziv();
	int sumaKarti();
};

