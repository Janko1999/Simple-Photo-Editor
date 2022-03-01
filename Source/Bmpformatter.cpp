#include "Bmpformatter.h"
#include"slika_u_bmp.h"

unsigned int row{ 0 };

void check_color_header(Colorheader& bmp_color_header) {
	Colorheader expected_color_header;
	if (expected_color_header.red != bmp_color_header.red ||
		expected_color_header.blue != bmp_color_header.blue ||
		expected_color_header.green != bmp_color_header.green ||
		expected_color_header.alpha != bmp_color_header.alpha) {
		throw std::runtime_error("Unexpected color mask format! The program expects the pixel data to be in the BGRA format");
	}
	if (expected_color_header.space_type != bmp_color_header.space_type) {
		throw std::runtime_error("Unexpected color space type! The program expects sRGB values");
	}
}



void Bmpformatter::write(slika_u_bmp* s,std::string fname, std::vector<unsigned char> data1) {
	
		
		bmpInfo.size = sizeof(Bmpinfo) + sizeof(Colorheader);
		bmpHeader.offset = sizeof(Bmpheader) + sizeof(Bmpinfo) + sizeof(Colorheader);
		bmpInfo.bit_count = 32;
		bmpInfo.compression = 3;
		
		bmpHeader.size = bmpHeader.offset + data1.size();
		bmpHeader.type = 0x4D42;
		data.resize(bmpInfo.height*bmpInfo.width*4);
		std::ofstream of{ fname, std::ios_base::binary };
	if (of) {
		int i = 0;
		
			of.write((const char*)&bmpHeader, sizeof(bmpHeader));
			of.write((const char*)&bmpInfo, sizeof(bmpInfo));
			of.write((const char*)&colorHeader, sizeof(colorHeader));
	        of.write((const char*)data1.data(), data1.size());
	
	}
	else {
		throw std::runtime_error("Unable to open the output image file.");
	}
}

std::vector<unsigned char> Bmpformatter::read(slika_u_bmp* s, std::string location) {
	std::ifstream file{ location, std::ios_base::binary };
	if (file) {
		file.read((char*)&bmpHeader, sizeof(Bmpheader));
		if (bmpHeader.type != 0x4D42) {
			std::cout << "Unrecognized file format";
		}
		file.read((char*)&bmpInfo, sizeof(Bmpinfo));

		if (bmpInfo.size >= (sizeof(Bmpheader) + sizeof(Colorheader))) {
			file.read((char*)&colorHeader, sizeof(Colorheader));
			//check_color_header(colorHeader);
		}
		else {
			std::cerr << "Warning! The file \"" << location << "\" does not seem to contain bit mask information\n";
			throw std::runtime_error("Error! Unrecognized file format.");
		}

		file.seekg(bmpHeader.offset, file.beg);
		bmpInfo.size = sizeof(Bmpinfo) + sizeof(Colorheader);
		bmpHeader.offset = sizeof(Bmpheader) + sizeof(Bmpinfo) + sizeof(Colorheader);
		bmpHeader.size = bmpHeader.offset;
		int x = (bmpInfo.width * bmpInfo.height * bmpInfo.bit_count) / 8;
		data.resize(bmpInfo.width * bmpInfo.height * bmpInfo.bit_count / 8);
		if (bmpInfo.width % 4 == 0) {
			file.read((char*)data.data(), data.size());
			bmpHeader.size += data.size();
		}
	}
	else throw std::runtime_error("Unable to open");
	int channels = bmpInfo.bit_count/8;
	int i = 0;
	
	
	s->width=(bmpInfo.width);
	s->height=(bmpInfo.height);

	return data;
}
