#include "My_formatter.h"
#include"sloj.h"
#include<fstream>
#include"Bmpformatter.h"
#include"Pam_formater.h"
#include"Kompozitnaoperacija.h"
std::vector<unsigned char> My_formatter::read(slika_u_bmp* s, std::string location)
{
	string loc = location + "\\Mojprogramcic.txt";
	ifstream fajl(loc);
	std::regex pocetak("<MojProgram>");
	std::regex kraj("</MojProgram>");
	std::regex selekcijapoc("<Selekcija>");
	std::regex selekcijakraj("</Selekcija>");
	std::regex nizslojpocetak("<Nizslojeva>");
	std::regex nizslojkraj("</Nizslojeva>");
	std::regex slojpoc("<Sloj>");
	std::regex slojkraj("</Sloj>");
	std::regex put("<putanja>([^<]*)</putanja>.*");
	std::regex transp("<transp>([^<]*)</transp>.*");
	std::regex active("<active>([^<]*)</active>.*");
	std::regex vidljivost("<vidljivost>([^<]*)</vidljivost>.*");
	std::regex sirina("<sirina>([^<]*)</sirina>.*");
	std::regex visina("<visina>([^<]*)</visina>.*");
	std::regex ime("<ime>([^<]*)</ime>.*");
	std::regex kvadrat("<kvadrat><poz>([^,]*),([^<]*)</poz><dimenz>([^,]*),([^<]*)</dimenz></kvadrat>.*");
	std::regex kompozitna("<Kompozitna>([^<]*)</Kompozitna>");
	
	if (fajl) {
		std::smatch rezultat;
		std::string tekst;
		getline(fajl, tekst);
		if (regex_match(tekst, rezultat, pocetak)) {
			getline(fajl, tekst);
			if (regex_match(tekst, rezultat, nizslojpocetak)) {
				while (getline(fajl, tekst)) {
					if (regex_match(tekst, rezultat, nizslojkraj)) break;
					if (regex_match(tekst, rezultat, slojpoc)) {
						getline(fajl, tekst);
						if (regex_match(tekst, rezultat, put)) {
							std::string fname = rezultat.str(1);
							getline(fajl, tekst);
							regex_match(tekst, rezultat, transp);
							int transp = atoi(rezultat.str(1).c_str());
							getline(fajl, tekst);
							regex_match(tekst, rezultat, active);
							std::string active = rezultat.str(1);
							getline(fajl, tekst);
							regex_match(tekst, rezultat, vidljivost);
							std::string visible = rezultat.str(1);
							slika_u_bmp* l = new slika_u_bmp(fname, transp);
							visible == "1" ? l->set_visible(true) : l->set_visible(false);
							active == "1" ? l->set_active(true) : l->set_active(false);
							slika->dodaj_sloj(l);
						}
						else {
							regex_match(tekst, rezultat, sirina);
							int sirina = atoi(rezultat.str(1).c_str());
							getline(fajl, tekst);
							regex_match(tekst, rezultat, visina);
							int visina = atoi(rezultat.str(1).c_str());
							getline(fajl, tekst);
							regex_match(tekst, rezultat, transp);
							int transp = atoi(rezultat.str(1).c_str());
							slika_u_bmp* s = new slika_u_bmp(visina, sirina, transp);
							getline(fajl, tekst);
							regex_match(tekst, rezultat, active);
							std::string active = rezultat.str(1);
							getline(fajl, tekst);
							regex_match(tekst, rezultat, vidljivost);
							std::string visible = rezultat.str(1);
							visible == "1" ? s->set_visible(true) : s->set_visible(false);
							active == "1" ? s->set_active(true) : s->set_active(false);
							slika->dodaj_sloj(s);
						}
					}

				}
				getline(fajl, tekst);
			}
			if (regex_match(tekst, rezultat, selekcijapoc)) {
				getline(fajl, tekst);
				regex_match(tekst, rezultat, ime);
				std::string ime = rezultat.str(1);
				sekcija* s = new sekcija(ime);
				slika->postavi_sekciju(s);
				while (getline(fajl, tekst)) {
					if (regex_match(tekst, rezultat, selekcijakraj))break;
					regex_match(tekst, rezultat, kvadrat);
					int x = atoi(rezultat.str(1).c_str());
					int y = atoi(rezultat.str(2).c_str());
					int height = atoi(rezultat.str(3).c_str());
					int width = atoi(rezultat.str(4).c_str());
					Kvadrat* k = new Kvadrat(height, width, x, y);
					s->dodajKvadrat(*k);
				}
				getline(fajl, tekst);
			}
			if (regex_match(tekst, rezultat, kompozitna)) {
				std::string put = rezultat.str(1);
				slika->citajFunkciju(put);
				getline(fajl, tekst);
			}
		}

	}
	slika->repaint();
	return slika->data;
}

void My_formatter::write(slika_u_bmp* s, std::string location, std::vector<unsigned char> data)
{
	ofstream fajl(location+"\\Mojprogramcic.txt");
	if (fajl) {
		fajl << "<MojProgram>"<<endl;
		int p = 0;
		if (slika->slojevi.size() > 0) {
			fajl << "<Nizslojeva>" << endl;
			while (p < slika->slojevi.size()) {
				fajl << "<Sloj>" << endl;
				if (slika->slojevi[p]->get_loaded() == true) {
					std::string newlocation;
					if (slika->slojevi[p]->get_bmp() == true) {
						 newlocation= location+"\\sloj_" + to_string(p) + ".bmp";
						fajl << "<putanja>" << newlocation << "</putanja>"<<endl;
					}
					else {
						 newlocation = location+"\\sloj_" + to_string(p) + ".pam";
						fajl << "<putanja>" << newlocation << "</putanja>" << endl;
}
					slika->slojevi[p]->eksport(newlocation);
					fajl << "<transp>" << slika->slojevi[p]->get_transp()*100 << "</transp>" << endl;
					fajl << "<active>" << slika->slojevi[p]->get_active() << "</active>" << endl;
					fajl << "<vidljivost>" << slika->slojevi[p]->get_visible() << "</vidljivost>" << endl;
				}else{
					fajl << "<sirina>" << slika->slojevi[p]->get_width() << "</sirina>" << endl;
					fajl << "<visina>" << slika->slojevi[p]->get_height() << "</visina>" << endl;
					fajl << "<transp>" << slika->slojevi[p]->get_transp()*100 << "</transp>" << endl;
					fajl << "<active>" << slika->slojevi[p]->get_active() << "</active>" << endl;
					fajl << "<vidljivost>" << slika->slojevi[p]->get_visible() << "</vidljivost>" << endl;
				}
				fajl << "</Sloj>" << endl;
				p++;
			}
			fajl << "</Nizslojeva>" << endl;
		}
		if (slika->s != nullptr) {
			fajl << "<Selekcija>" << endl;
			fajl << "<ime>" << slika->s->get_name() << "</ime>" << endl;
			for (Kvadrat k : slika->s->kvadrati) {
				fajl << "<kvadrat><poz>" << k.poz.first << "," << k.poz.second << "</poz><dimenz>" << k.height << "," << k.width << "</dimenz></kvadrat>" << endl;
			}
			fajl << "</Selekcija>" << endl;
		}
		if (dynamic_cast<Kompozitnaoperacija*>(slika->op) != nullptr) {
			Kompozitnaoperacija* composite = (Kompozitnaoperacija*)slika->op;
			fajl << "<Kompozitna>" << composite->get_name()  << "</Kompozitna>" << std::endl;
		}
		fajl << "</Mojprogram>" << endl;
	}
	else throw runtime_error("Fajl nije otvoren");
}
