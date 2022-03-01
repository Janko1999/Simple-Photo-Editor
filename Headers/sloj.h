#pragma once
#include<vector>
#include<regex>
#include<iostream>
#include"slika_u_bmp.h"
using namespace std;
class Operation;
class My_formatter;
class sloj
{   public:
	sekcija* s = nullptr;

public:
	sekcija* get_s()const { return s; }
	void set_s(sekcija* x) { s = x; }
	Operation* op;
	vector<slika_u_bmp*> slojevi;
	vector<unsigned char> data;
	vector<Piksel*> pikseli;
	friend My_formatter;
	void ucitaj_program(string x);
	void ispisi_program(string x);
	sloj sivaa();
	sloj crnobelaa();
	sloj invertion();
	sloj powers(int x);
	sloj log();
	sloj abs();
	sloj Minimum(int x);
	sloj Maximum(int x);
	sloj plus(int x);
	sloj minus(int x);
	sloj deljenjee(int x);
	sloj mnozenjee(int x);
	sloj medijana();
	sloj(const sloj& sl);
	void dodaj_sloj(slika_u_bmp* s) {

		if (slojevi.size() > 0) {
			if (s->get_height() < slojevi[0]->get_height() || s->get_width() < slojevi[0]->get_width()) {
				std::vector<Piksel*> data1 = s->pikseli;
				s->pikseli.resize(slojevi[0]->get_height() * slojevi[0]->get_width());
				for (int i = 0; i < slojevi[0]->get_height(); i++)
					for (int j = 0; j < slojevi[0]->get_width(); j++)
						if (j >= s->get_width() || i >= s->get_height()) {
							s->pikseli[(i * slojevi[0]->get_width() + j)] = new Piksel(0, 0, 0, 0);
						}
						else {
							s->pikseli[i * slojevi[0]->get_width() + j] = data1[i * s->get_width() + j];
						}
				s->data.resize(slojevi[0]->get_height() * slojevi[0]->get_width() * 4);
				s->set_width(slojevi[0]->get_width());
				s->set_height(slojevi[0]->get_height());
				s->update();
				
			}

			else if (slojevi[0]->get_width() < s->get_width() || slojevi[0]->get_height() < s->get_height()) {
				for (slika_u_bmp* sl : slojevi) {
					std::vector<Piksel*> data1 = sl->pikseli;
					sl->pikseli.resize(s->get_height() * s->get_width());
					for (int i = 0; i < s->get_height(); i++)
						for (int j = 0; j < s->get_width(); j++)
							if (j >= sl->get_width() || i >= sl->get_height()) {
								sl->pikseli[(i * s->get_width() + j)] = new Piksel(0, 0, 0, 0);
							}
							else {
								sl->pikseli[i * s->get_width() + j] = data1[i * sl->get_width() + j];
							}
					sl->data.resize(s->get_height() * s->get_width() * 4);
					sl->set_width(s->get_width());
					sl->set_height(s->get_height());
					sl->update();
					
				}
			}
			
		}
		slojevi.push_back(s);
		repaint();
	}
	void postavi_sekciju(sekcija* s) {
		this->s = s;
	}
	void citajFunkciju(std::string fname);
	void repaint();
	void eksport(std::string s);
	sloj(){}
	
};


