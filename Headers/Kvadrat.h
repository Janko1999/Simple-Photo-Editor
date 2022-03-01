#pragma once
#include<iostream>
using namespace std;
class Kvadrat
{
public:

	int height;
	int width;
	pair<int, int> poz;
	Kvadrat(int h, int w, int x, int y) {
		height = h;
		width = w;
		poz.first = x;
		poz.second = y;
	}
};

