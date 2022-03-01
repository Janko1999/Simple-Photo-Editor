#pragma once
#include "Formater.h"
#include<regex>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>

typedef struct pamHeader {
	std::string type;
	int width;
	int height;
	int depth;
	int maxval;
	std::string tupltype;
	std::string endhdr;
}Pamformater;
class Pam_formater :
	public Formater
{
	Pamformater Pamheader;
	std::vector<unsigned char> data;
public:
	std::vector<unsigned char> read(slika_u_bmp* s,std::string location)override;
	void write(slika_u_bmp* s,std::string file, std::vector<unsigned char>)override;
	int get_height()const { return Pamheader.height; }
	int get_width()const { return Pamheader.width; }
	void set_height(int x) { Pamheader.height = x; }
	void set_width(int x) { Pamheader.width = x; }
};

