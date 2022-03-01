#pragma once
#include<vector>
#include "Formater.h"
#pragma pack(push,1)
using namespace std;
typedef struct bmpheader {
	uint16_t type;
	uint32_t size;
	uint16_t reserved0;
	uint16_t reserved1;
	uint32_t offset;
}Bmpheader;
typedef struct bmpinfo {
	uint32_t size{ 0 };
	int32_t width{ 0 };
	int32_t height{ 0 };
	uint16_t planes{ 1 };
	uint16_t bit_count{ 0 };
	uint32_t compression{ 0 };
	uint32_t image_size{ 0 };
	int32_t x_pixels_per_meter{ 0 };
	int32_t y_pixels_per_meter{ 0 };
	uint32_t colors{ 0 };
	uint32_t used_colors{ 0 };
} Bmpinfo;
typedef struct colorheader {
	uint32_t red{ 0x00ff0000 };
	uint32_t  green{ 0x0000ff00 };
	uint32_t blue{ 0x000000ff };
	uint32_t alpha{ 0xff000000 };
	uint32_t space_type{ 0x73524742 };
	uint32_t unused[16]{ 0 };
}Colorheader;
class Bmpformatter :
	public Formater
{public:
	int get_height()const { return bmpInfo.height; }
	int get_width()const { return bmpInfo.width; }
	void set_height(int x) { bmpInfo.height = x; }
	void set_width(int x) { bmpInfo.width = x; }
	Bmpheader bmpHeader;
	Bmpinfo bmpInfo;
	Colorheader colorHeader;
	vector<unsigned char> data;
	std::vector<unsigned char> read(slika_u_bmp* s,std::string location)override;
	void write(slika_u_bmp* s,std::string file, std::vector<unsigned char>)override;

};

