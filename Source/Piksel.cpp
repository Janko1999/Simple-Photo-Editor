#include "Piksel.h"

bool Piksel::function = false;

Piksel& Piksel::operator+(int x)
{
	R = R + x > 255 && !function ? 255 : R + x;
	G = G + x > 255 && !function ? 255 : G + x;
	B = B + x > 255 && !function ? 255 : B + x;
	A = A + x > 255 && !function ? 255 : A + x;
	return *this;
}

Piksel& Piksel::operator-(int x)
{
R = R - x < 0 && !function ? 255 : R - x;
G = G - x < 0 && !function ? 255 : G - x;
B = B - x < 0 && !function ? 255 : B - x;
A = A - x < 0 && !function ? 255 : A - x;
	return *this;
}

Piksel& Piksel::operator*(int x)
{
	R = R * x > 255 && !function ? 255 : R * x;
	G = G * x > 255 && !function ? 255 : G * x;
	B = B * x > 255 && !function ? 255 : B * x;
	A = A * x > 255 && !function ? 255 : A * x;
	return *this;
}

Piksel& Piksel::operator/(int x)
{
	R /= x;
	G /= x;
	B /= x;
	A /= x;
	return *this;
}

Piksel& Piksel::power(int x)
{
	R = pow(R,x) > 255 && !function ? 255 : pow(R,x);
	G = pow(G,x) > 255 && !function ? 255 : pow(G,x);
	B = pow(B,x) > 255 && !function ? 255 : pow(B,x);
	A = pow(A, x) > 255 && !function ? 255 : pow(A, x);
	return *this;
}

Piksel& Piksel::logarithm()
{
	R = log(R);
	G = log(G);
	B = log(B);
	A = log(A);
	return *this;
}

Piksel& Piksel::min(int x)
{
	if (R > x) R = x;
	if (G > x) G = x;
	if (B > x) B = x;
	if (A > x) A = x;
	return *this;
}

Piksel& Piksel::max(int x)
{
	if (R < x) R = x;
	if (G < x) G = x;
	if (B < x) B = x;
	if (A < x) A = x;
	return *this;
}

Piksel& Piksel::siva()
{
	int x = (R + G + B + A) / 4;
	R = G = B = A = x;
	return *this;
}

Piksel& Piksel::crnobela()
{
	if ((R + G + B + A) / 4 > 127) 
		R = G = B = A = 255;
	else
		R = G = B = A = 0;
	return *this;
}

Piksel& Piksel::invert()
{
	R = 255 - R;
	G = 255 - G;
	B = 255 - B;
	A = 255 - A;
	return *this;
}

Piksel& Piksel::absolute()
{
	R = abs(R);
	G = abs(G);
	B = abs(B);
	A = abs(A);
	return *this;
}
