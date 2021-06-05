#include <iostream>
#include <vector>
#include "IgracCovjek.h"
#include "IgracAI.h"
#include "Spil.h"
using std::cout;
using std::cin;
int main() {
	int brojIgraca;
	cout << "Unesite broj igraca: ";
	cin >> brojIgraca;
	cin.ignore();
	std::vector<IgracCovjek> igraci;
	IgracCovjek temp;
	for (int i = 0; i < brojIgraca; i++) {
		cin >> temp;
		igraci.emplace_back(temp);
	}
	std::vector<int> ulozi;
	int x;
	for (int i = 0; i < brojIgraca; i++) {
		do {
			cout << igraci[i].naziv << " unesite ulog: ";
			cin >> x;
			cin.ignore();
			if (igraci[i].budzet >= x) {
				ulozi.emplace_back(x);
			}
			else {
				cout << "Nije moguce toliko uloziti!\n";
			}

		} while (igraci[i].budzet < x);
	}
	IgracAI racunar;
	Spil s;
	!s;
	for (int j = 0; j < 2; j++) {
		racunar.ruka.emplace_back(*s.karte.begin());
		s.karte.erase(s.karte.begin());
		for (int i = 0; i < brojIgraca; i++) {
			igraci[i].ruka.emplace_back(*s.karte.begin());
			s.karte.erase(s.karte.begin());
		}
	}
	int runda = 1;
	cout << "Runda: " << runda << "\n";
	cout << racunar.naziv << ": " << racunar.ruka[0].vrijednost << " *\n";
	cout << "-----------------------------\n";
	for (int i = 0; i < brojIgraca; i++) {
		cout << igraci[i].naziv << ": ";
		for (int j = 0; j < igraci[i].ruka.size(); j++) {
			cout << igraci[i].ruka[j].vrijednost << " ";
		}
		cout << "\n";
	}
	cout << "-----------------------------\n";
	for (int i = 0; i < brojIgraca; i++) {
		bool busted = true;
		string izbor;
		do {
			cout << igraci[i].naziv << ": H ili S\n";
			do {
				cout << "Izbor: ";
				getline(cin, izbor);
			} while (izbor != "S" && izbor != "H");
			if (izbor == "H") {
				igraci[i].ruka.emplace_back(*s.karte.begin());
				s.karte.erase(s.karte.begin());
				for (int j = 0; j < igraci[i].ruka.size(); j++) {
					cout << igraci[i].ruka[j].vrijednost << " ";
				}
				if (igraci[i].sumaKarti() > 21) {
					cout << " BUSTED";
					busted = false;
				}
				cout << "\n";
			}
		} while (izbor != "S" && busted);
		cout << igraci[i].naziv << " je zavrsio igru!\n";
	}
	cout << racunar.naziv << ": " << racunar.ruka[0].vrijednost << " "
		<< racunar.ruka[1].vrijednost << "\n";
	while (racunar.sumaKarti() < 17){
		racunar.ruka.emplace_back(*s.karte.begin());
		s.karte.erase(s.karte.begin());
		cout << racunar.naziv << ": ";
		for (int j = 0; j < racunar.ruka.size(); j++) {
			cout << racunar.ruka[j].vrijednost << " ";
		}
		cout << "\n";
	} 
	return 0;
}