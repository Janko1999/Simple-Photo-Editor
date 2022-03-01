#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"sekcija.h"
#include"Piksel.h"
#include"Formater.h"
#include<vector>

class Bmpformatter;
class Pam_formater;
class slika_u_bmp {
	Formater* form;
	bool loaded = false;
	bool bmp;
	int width;
	int height;
	bool visible = true;
	bool active = true;
	float transp;
	
	
public:
	bool get_loaded()const { return loaded; }
	bool get_bmp()const { return bmp; }
	void set_active(bool x) { active = x; }
	void set_visible(bool x) { visible = x; }
	std::vector<unsigned char> data;
	std::vector<Piksel*> pikseli;
	void set_height(int x) { height = x; }
	void set_width(int x) { width = x; }
	int get_height()const { return height; }
	int get_width()const { return width; }
	bool get_active()const { return active; }
	float get_transp()const { return transp; }
	bool get_visible()const { return visible; }
	friend  Bmpformatter;
	friend  Pam_formater;
	slika_u_bmp(int x, int y, int transp) {
		this->height = x;
		this->width = y;
		this->transp = transp;
	}
	slika_u_bmp(std::string x, float y, bool active = true);
	void update();

	void fill_section(sekcija s, int R, int G, int B,float A) {
		unsigned int channels = 4;
		for(Kvadrat k:s.kvadrati){
			for(int x=k.poz.first;x<k.poz.first+k.height;++x)
				for (int y = k.poz.second; y < k.poz.second + k.width; ++y) {
					int index = channels * (x * width + y);
					pikseli[index / 4]->set_A(A);
					pikseli[index / 4]->set_R(R);
					pikseli[index / 4]->set_G(G);
					pikseli[index / 4]->set_B(B);
					
				}
}
		update();
	}

	void eksport(std::string x);
};

