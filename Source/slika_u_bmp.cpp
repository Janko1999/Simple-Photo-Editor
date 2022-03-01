#include "slika_u_bmp.h"
#include"Pam_formater.h"
#include"Bmpformatter.h"



slika_u_bmp::slika_u_bmp(std::string x, float y, bool active) :transp(y / 100.)

	{
	
		std::regex rx("[^.]*.(.*)");
		smatch rezultat;
		if (regex_match(x, rezultat, rx)) {
			loaded = true;
			if (rezultat.str(1) == "pam") {
				bmp = false;
				form = new Pam_formater();
				data=form->read(this, x);
			}
			else {
				bmp = true;
				form = new Bmpformatter();
				data=form->read(this, x);
				height = form->get_height();
				width = form->get_width();
				for (uint32_t x = 0; x < height; ++x) {
					for (uint32_t y = 0; y < width; ++y) {

						pikseli.push_back(new Piksel(data[4 * (x *width + y) + 0],
							data[4 * (x * width + y) + 1],
							data[4 * (x * width + y) + 2],
							data[4 * (x * width + y) + 3]));

					}

				}
			}
		}
		
		this->active = active;
	}

void slika_u_bmp::update()
{
	for (uint32_t x = 0; x < height; ++x) {
		for (uint32_t y = 0; y < width; ++y) {
			data[4 * (x * width + y) + 0] = (pikseli[(x * width + y)])->get_B();
			data[4 * (x * width + y) + 1] = (pikseli[(x * width + y)])->get_G();
			data[4 * (x * width + y) + 2] = (pikseli[(x * width + y)])->get_R();
			data[4 * (x * width + y) + 3] = (pikseli[(x * width + y)])->get_A();

		}
	}
}


void slika_u_bmp::eksport(std::string x)
{
		Formater* form;
		std::regex rx("[^.]*.(.*)");
		smatch rezultat;
		if (regex_match(x, rezultat, rx)) {
			if (rezultat.str(1) == "pam") {
				form = new Pam_formater();
				form->set_height(height);
				form->set_width(width);
				form->write(this, x,data);
			}
			else {
				form = new Bmpformatter();
				form->set_height(height);
				form->set_width(width);
				form->write(this, x,data);
			}
		}
	
}
