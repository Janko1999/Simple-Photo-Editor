#include<iostream>
long sgn(long x) {
	long znak = 0;
	if (x > 0)znak = 1;
	if (x < 0)znak = -1;
	return znak;
}
int main(int argc, char** argv) {
	long a[10] = { -2,-1,5,2,-6,-5,0,2,-13,0 };
	long s[10] = { 1,0,1,0,3,2,1,0,1,0 };
	long i;
	for (i = 0; i < 9; i++) {
		switch (a[i + 1] - a[i]) {
		case 1: s[i] = 3; break;
		case 0:s[i] = -3; break;
		default: s[i] = 0;
		}
	}
	for (i = 0; i < 10; i++)printf("%li", s[i]);
}