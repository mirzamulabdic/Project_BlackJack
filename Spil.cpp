#include "Spil.h"
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using std::random_shuffle;

void Spil::izmjesaj()
{
	srand(time(NULL));
	rand();
	int t;
	random_shuffle(this->karte.begin(), this->karte.end());
	for (int i = 0; i < 10; i++) {
		t = rand() % 52;
		if (t < 26) {
			random_shuffle(this->karte.begin() + t, this->karte.end());
		}
		else {
			random_shuffle(this->karte.begin(), this->karte.begin() + t);
		}
	}
}

void operator!(Spil& s)
{
	srand(time(NULL));
	rand();
	int t;
	random_shuffle(s.karte.begin(), s.karte.end());
	for (int i = 0; i < 10; i++) {
		t = rand() % 52;
		if (t < 26) {
			random_shuffle(s.karte.begin() + t, s.karte.end());
		}
		else {
			random_shuffle(s.karte.begin(), s.karte.begin() + t);
		}
	}
}
