#pragma once
#include<string>
#include<fstream>
#include<vector>
class slika_u_bmp;
class Formater
{ 
public:
	virtual std::vector<unsigned char> read(slika_u_bmp* s, std::string location)=0;
	virtual void write(slika_u_bmp* s, std::string fname,std::vector<unsigned char>)=0;
	virtual int get_height()const = 0;
	virtual int get_width()const = 0;
	virtual void set_height(int x) = 0;
	virtual void set_width(int y) = 0;
};

