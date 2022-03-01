

#include"Operation.h"
#include"Kompozitnaoperacija.h"
#include"Bmpformatter.h"
#include"Pam_formater.h"
#include"My_formatter.h"



void sloj::ucitaj_program(string file)
{
	
	My_formatter* form = new My_formatter(this);
	form->read(nullptr, file);
}

void sloj::ispisi_program(string location)
{
	
	My_formatter* form = new My_formatter(this);
	form->write(nullptr, location, this->data);
	eksport(location + "\\Konacna.bmp");
}

sloj sloj::sivaa()
{
 op = new siva();
 return op->operacija(*this);
}
sloj sloj::crnobelaa()
{
	op = new crnobela();
	return op->operacija(*this);
}
sloj sloj::invertion()
{
	op = new invert();
	return op->operacija(*this);
	
}
sloj sloj::powers(int x)
{
	op = new power(x);
	return op->operacija(*this);
}
sloj sloj::Minimum(int x)
{
	op = new Min(x);
	return op->operacija(*this);
}
sloj sloj::Maximum(int x)
{
	op = new Max(x);
	return op->operacija(*this);
}
sloj sloj::log()
{
	op = new logaritam();
	return op->operacija(*this);
}
sloj sloj::abs()
{
	op = new absolute();
	return op->operacija(*this);
}
sloj sloj::plus(int x)
{
	op = new sabiranje(x);
	return op->operacija(*this);
}
sloj sloj::minus(int x)
{
	op = new oduzimanje(x);
	return op->operacija(*this);
}
sloj sloj::deljenjee(int x)
{
	op = new deljenje(x);
	return op->operacija(*this);
}
sloj sloj::mnozenjee(int x)
{
	op = new mnozenje(x);
	return op->operacija(*this);
}

sloj sloj::medijana()
{
	op = new Medijana();
	return op->operacija(*this);
}

sloj::sloj(const sloj& sl)
{
	this->data = sl.data;
	this->op = sl.op;
	this->pikseli = sl.pikseli;
	this->s = sl.s;
	this->slojevi = sl.slojevi;
}

void sloj::citajFunkciju(std::string fname)
{
	op = new Kompozitnaoperacija(*this, fname);
}

void sloj::repaint()
{
	if (slojevi.size() == 1) {
		pikseli = slojevi[slojevi.size() - 1]->pikseli;
	}
	else {
		pikseli.resize(slojevi[slojevi.size() - 1]->pikseli.size());
	}
	if (slojevi.size() > 1) {
		int p = slojevi.size();
		while (slojevi[p - 1]->get_visible() == false)p--;
		for (int i = 0; i < slojevi[p - 1]->get_height(); i++) 
			for (int j = 0; j < slojevi[p - 1]->get_width(); j++) {
				int x = (i * slojevi[p - 1]->get_width() + j);
				pikseli[x] = new Piksel(slojevi[p - 1]->pikseli[x]->get_B(), slojevi[p - 1]->pikseli[x]->get_G(), slojevi[p - 1]->pikseli[x]->get_R(), slojevi[p - 1]->pikseli[x]->get_A());
			}
			float newtransp = slojevi[p - 1]->get_transp();
			int x = p - 2;
			int p1 = x;
			while (p1 >= 0) {
				if (slojevi[p1]->get_visible() == true)
					for (int i = 0; i < slojevi[p1]->get_height(); i++) {
						for (int j = 0; j < slojevi[p1]->get_width(); j++) {
							int x = (i * slojevi[p1]->get_width() + j);
							float A = newtransp + (1 - newtransp) * slojevi[p1]->get_transp();
							int B = pikseli[x]->get_B() * (newtransp / A) + slojevi[p1]->pikseli[x]->get_B() * (1 - newtransp) * (slojevi[p1]->get_transp() / A);
							int G = pikseli[x]->get_G() * (newtransp / A) + slojevi[p1]->pikseli[x]->get_G() * (1 - newtransp) * (slojevi[p1]->get_transp() / A);
							int R = pikseli[x]->get_R() * (newtransp / A) + slojevi[p1]->pikseli[x]->get_R() * (1 - newtransp) * (slojevi[p1]->get_transp() / A);
							pikseli[x]->set_A(slojevi[p1]->pikseli[x]->get_A());
							pikseli[x]->set_B(B);
							pikseli[x]->set_G(G);
							pikseli[x]->set_R(R);

						}
					}
				newtransp = (newtransp + slojevi[p1]->get_transp() - newtransp * slojevi[p1]->get_transp());
				p1--;
			}
		
	}
			data.resize(slojevi[0]->get_width() * slojevi[0]->get_height() * 4);
			for (uint32_t x = 0; x < slojevi[0]->get_height(); ++x) {
				for (uint32_t y = 0; y < slojevi[0]->get_width(); ++y) {
					data[4 * (x * slojevi[0]->get_width() + y) + 0] = (pikseli[(x * slojevi[0]->get_width() + y)])->get_B();
					data[4 * (x * slojevi[0]->get_width() + y) + 1] = (pikseli[(x * slojevi[0]->get_width() + y)])->get_G();
					data[4 * (x * slojevi[0]->get_width() + y) + 2] = (pikseli[(x * slojevi[0]->get_width() + y)])->get_R();
					data[4 * (x * slojevi[0]->get_width() + y) + 3] = (pikseli[(x * slojevi[0]->get_width() + y)])->get_A();

				}
			}
		
	}



void sloj::eksport(std::string s)
{
	Formater* form;
	std::regex rx("[^.]*.(.*)");
	smatch rezultat;
	if (regex_match(s, rezultat, rx)) {
		if (rezultat.str(1) == "pam") {
			form = new Pam_formater();
			form->set_height(slojevi[0]->get_height());
			form->set_width(slojevi[0]->get_width());
			form->write(slojevi[0],s,data);
		}
		else {
			form = new Bmpformatter();
			form->set_height(slojevi[0]->get_height());
			form->set_width(slojevi[0]->get_width());
			form->write(slojevi[0], s, data);
		}
	}
}
