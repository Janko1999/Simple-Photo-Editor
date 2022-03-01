#pragma once
#include<vector>
#include<string>
#include"Kvadrat.h"
using namespace std;
class sekcija
{
	bool active;

	string ime;
public:
	vector<Kvadrat> kvadrati;
	sekcija(string ime) {
		this->ime = ime;
	}
	sekcija& dodajKvadrat(const Kvadrat& K) {
		kvadrati.push_back(K);
		return *this;
	}
	std::string get_name()const { return ime; }
};

