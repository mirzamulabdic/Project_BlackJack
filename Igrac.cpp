#include "Igrac.h"
#include <iostream>

void Igrac::setNaziv()
{
	std::cout << "Unesite naziv igraca: ";
	getline(std::cin, this->naziv);
}

int Igrac::sumaKarti()
{
	int suma = 0;
	int br = 0;
	for (int i = 0; i < this->ruka.size(); i++) {
		if (this->ruka[i].vrijednost == 1 && br == 0) {
			suma += 11;
			br++;
		}
		else if (this->ruka[i].vrijednost > 11 && this->ruka[i].vrijednost < 15) {
			suma += 10;
		}
		else {
			suma += this->ruka[i].vrijednost;
		}
	}
	if (suma > 21 && br == 1) {
		suma -= 10;
	}
	return suma;
}
