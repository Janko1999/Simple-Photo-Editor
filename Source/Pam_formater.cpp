#include "Pam_formater.h"
#include"slika_u_bmp.h"

using namespace std;
std::vector<unsigned char> Pam_formater::read(slika_u_bmp* s,std::string location)
{
	std::ifstream file{ location, std::ios_base::binary };
	if (file) {
		string x;
		string y="";
		getline(file, x);
		
		y += x+" ";
		getline(file, x);
		y += x+" ";
		getline(file, x);
		y += x+" ";
		getline(file, x);
		y += x+" ";
		getline(file, x);
		y += x+" ";
		getline(file, x);
		y += x+" ";
		getline(file, x);
		y += x+" ";
		regex rx("([^ ]*) [^ ]* ([^ ]*) [^ ]* ([^ ]*) [^ ]* (.) [^ ]* ([^ ]*) [^ ]* ([^ ]*) ([^ ]*) .*");
		smatch result;
		if (regex_match(y, result, rx)) {
			Pamheader.type = result.str(1);
			Pamheader.width = atoi(result.str(2).c_str());
			Pamheader.height = atoi(result.str(3).c_str());
			Pamheader.depth = atoi(result.str(4).c_str());
			Pamheader.maxval = atoi(result.str(5).c_str());
			Pamheader.tupltype = result.str(6);
			Pamheader.endhdr = result.str(7);
		}
		data.resize(Pamheader.width * Pamheader.height * Pamheader.depth);
		file.read((char*)data.data(), data.size());
		s->height=(Pamheader.height);
		s->width=(Pamheader.width);
		
		int i = 0;
		for (uint32_t x = 0; x < s->height; ++x) {
			for (uint32_t y = 0; y < s->width; ++y) {
				s->pikseli.push_back(new Piksel(data[4 * (x * s->width + y) + 0],
					data[4 * (x * s->width + y) + 1],
					data[4 * (x * s->width + y) + 2],
					data[4 * (x * s->width + y) + 3]));
				

			}
		}

	}
	else throw std::runtime_error("Unable to open the file!");
	return data;
}

void Pam_formater::write(slika_u_bmp* s, std::string file, std::vector<unsigned char> data)
{
	Pamheader.height = s->height;
	Pamheader.width = s->width;
	Pamheader.depth = 4;
	Pamheader.maxval = 255;
	Pamheader.type = "P7";
	Pamheader.tupltype="RGB Alpha";
	data.clear();
	data.resize(Pamheader.height * Pamheader.width * Pamheader.depth);
	for (uint32_t x = 0; x < s->height; ++x) {
		for (uint32_t y = 0; y < s->width; ++y) {
			data[4 * (x * s->width + y) + 0] = (s->pikseli[(x * s->width + y)])->get_B();
			data[4 * (x * s->width + y) + 1] = (s->pikseli[(x * s->width + y)])->get_G();
			data[4 * (x * s->width + y) + 2] = (s->pikseli[(x * s->width + y)])->get_R();
			data[4 * (x * s->width + y) + 3] = (s->pikseli[(x * s->width + y)])->get_A();
		}
	}
	std::ofstream f(file, std::ios_base::binary);
	if (f) {
		f << Pamheader.type << std::endl;
		f << "WIDTH " << Pamheader.width << std::endl;
		f << "HEIGHT " <<Pamheader.height << std::endl;
		f << "DEPTH " << Pamheader.depth << std::endl;
		f << "MAXVAL " <<Pamheader.maxval << std::endl;
		f << "TUPLTYPE " << Pamheader.tupltype << std::endl;
		f << Pamheader.endhdr << std::endl;
		f.write((char*)data.data(), data.size());
	}
	else {
		throw std::runtime_error("Error!");
	}
}

