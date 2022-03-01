#include "Kompozitnaoperacija.h"
#include<algorithm>
void Kompozitnaoperacija::napraviMapu()
{
	mapa["Sabiranje"] = 1;
	mapa["Oduzimanje"] = 2;
	mapa["Deljenje"] = 3;
	mapa["InvertOduzimanje"] = 4;
	mapa["InvertDeljenje"] = 5;
	mapa["Mnozenje"] = 6;
	mapa["Log"] = 7;
	mapa["Abs"] = 8;
	mapa["Min"] = 9;
	mapa["Max"] = 10;
	mapa["Power"] = 11;
	mapa["Siva"] = 12;
	mapa["CrnoBela"] = 13;
	mapa["Invertujuca"] = 14;
	mapa["Medijana"] = 15;
	mapa["Kompozitna"] = 16;
}

void Kompozitnaoperacija::citajizFajla(std::string fname,sloj slika)
{
	std::ifstream file(fname);
	std::regex header("<KompozitnaFunkcija>");
	std::regex end("</KompozitnaFunkcija>");
	std::regex fun("<function>([^<]*)</function>.*");
	std::regex arg("<parametri>([^<]*)</parametri>.*");
	std::regex put("<putanja>([^<]*)</putanja>.*");
	std::smatch result;
	std::string text;
	int argumenti;
	std::string putanja;

	if (file) {
		getline(file, text);
		if (std::regex_match(text, result, header)) {
			while (getline(file, text)) {
				if (std::regex_match(text, result, end))break;
				if (std::regex_match(text, result, fun)) {
					std::string funkcija = result.str(1);
					getline(file,text);
					if (std::regex_match(text, result, put)) {
						putanja = result.str(1); getline(file, text);
					}
					if (std::regex_match(text, result, arg)) {
						 argumenti = atoi(result.str(1).c_str());
					}
						int r = mapa[funkcija];
						switch (mapa[funkcija])
						{
						case 1: operacije.push_back(new sabiranje(argumenti)); break;
						case 2: operacije.push_back(new oduzimanje(argumenti)); break;
						case 3: operacije.push_back(new deljenje(argumenti)); break;
						case 6: operacije.push_back(new mnozenje(argumenti)); break;
						case 7: operacije.push_back(new logaritam()); break;
						case 8: operacije.push_back(new absolute()); break;
						case 9: operacije.push_back(new Min(argumenti)); break;
						case 10: operacije.push_back(new Max(argumenti)); break;
						case 11: operacije.push_back(new power(argumenti)); break;
						case 12: operacije.push_back(new siva()); break;
						case 13: operacije.push_back(new crnobela()); break;
						case 14: operacije.push_back(new invert()); break;
						case 15: operacije.push_back(new Medijana()); break;
						case 16: operacije.push_back(new Kompozitnaoperacija(slika, putanja)); break;
						default:
							break;
						}
					}
				}
			
		}
		else {
			std::runtime_error("Not suitable file");
		}
	}
	else {
		std::runtime_error("File not found");
	}
}

sloj Kompozitnaoperacija::operacija(sloj s)
{
	
	for (Operation* o : operacije)
		s=o->operacija(s);
	for_each(s.slojevi.begin(), s.slojevi.end(), [&](slika_u_bmp *sl) {
		for_each(sl->pikseli.begin(), sl->pikseli.end(), [&](Piksel* p) {
			if (p->get_R() > 255)p->set_R(255);
			else if (p->get_R() < 0)p->set_R(0);
			if (p->get_G() > 255)p->set_G(255);
			else if (p->get_G() < 0)p->set_G(0);
			if (p->get_B() > 255)p->set_B(255);
			else if (p->get_B() < 0)p->set_B(0);
			if (p->get_A() > 255)p->set_A(255);
			else if (p->get_A() < 0)p->set_A(0);
		});
	});
	return s;
}
