#pragma once
#include "Operation.h"
#include<map>
#include<fstream>
#include<regex>
class Kompozitnaoperacija :
	public Operation
{
	vector<Operation*>operacije;
	std::map<std::string, int> mapa;
	std::string name;
public:
	Kompozitnaoperacija(sloj slika,std::string fname) {
		napraviMapu();
		citajizFajla(fname, slika);
		this->operacija(slika);
		Piksel::function = true;
		name = fname;
	}
	std::string get_name() { return name; }
	void napraviMapu();
	void citajizFajla(std::string fname,sloj slika);
	sloj operacija(sloj s)override;
	void dodaj_operaciju(Operation* o) {
		operacije.push_back(o);
	}
};

