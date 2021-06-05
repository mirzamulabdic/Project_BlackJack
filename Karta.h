#pragma once
enum Boja{tref,pik,srce,karo};

class Karta
{
public:
	int vrijednost;
	Boja boja;
	void setVrijednost(int x) {
		this->vrijednost = x;
	}
	void setBoja(Boja b) {
		this->boja = b;
	}
	int getVrijednost() {
		return this->vrijednost;
	}
	Boja getBoja() {
		return this->boja;
	}
};

