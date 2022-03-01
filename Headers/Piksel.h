#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

class Piksel
{
private:
	int R;
	int G;
	int B;
	float A;
	bool done = false;
	
public:
	float get_A()const { return A; }
	int get_B()const { return B; }
	int get_G()const { return G; }
	int get_R()const { return R; }
	void set_R(int x) { R = x; }
	void set_G(int x) { G = x; }
	void set_B(int x) { B = x; }
	void set_A(float x) { A = x; }
	static bool function;
	Piksel(int x = 0, int y = 0, int z = 0,float g=0) :B(x), G(y), R(z),A(g) {};
	Piksel& operator+(int x);
	Piksel& operator-(int x);
	Piksel& operator*(int x);
	Piksel& operator/(int x);
	Piksel& power(int x);
	Piksel& logarithm();
	Piksel& absolute();
	Piksel& min(int x);
	Piksel& max(int x);
	Piksel& siva();
	Piksel& crnobela();
	Piksel& invert();
	Piksel& medijana();

};
