#pragma once
#include "Formater.h"
class sloj;
class My_formatter :
	public Formater
{
	
public:
	sloj* slika;
	My_formatter(sloj* s):slika(s){}
	std::vector<unsigned char> read(slika_u_bmp* s, std::string location)override;
	void write(slika_u_bmp* s, std::string location, std::vector<unsigned char>data)override;
	int get_height()const { return 5; }
	int get_width()const { return 5; }
	void set_height(int x){}
	void set_width(int x){}
};

