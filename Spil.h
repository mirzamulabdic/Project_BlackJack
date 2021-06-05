#pragma once
#include <vector>
#include "Karta.h"
using std::vector;

class Spil
{
public:
	vector<Karta> karte;
	Spil() {
		Karta temp;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < 15; j++) {
				if (j == 11) {}
				else {
					temp.setVrijednost(j);
					switch (i) {
						case 0:
							temp.setBoja(tref);
							break;
						case 1:
							temp.setBoja(pik);
							break;
						case 2:
							temp.setBoja(srce);
							break;
						case 3:
							temp.setBoja(karo);
							break;
					}
					karte.emplace_back(temp);
				}
			}
		}
	}
	void izmjesaj();
	friend void operator!(Spil& s);
};

