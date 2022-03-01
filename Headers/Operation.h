#pragma once
#include"sloj.h"

class Operation
{
public:
	Operation() { Piksel::function = false; }
	virtual sloj operacija(sloj s) = 0;
};

class sabiranje :
	public Operation
{
	int z;
public:
	sabiranje(int y) :z(y) {}
	sloj operacija(sloj s)override;
};

class oduzimanje :
	public Operation
{
	int z;
public:
	oduzimanje(int y) :z(y) {}
	sloj operacija(sloj s);
};

class mnozenje :
	public Operation
{
	int z;
public:
	mnozenje(int y) :z(y) {}
	sloj operacija(sloj s) override;
};

class deljenje :
	public Operation
{
	int z;
public:
	deljenje(int y) :z(y) {}
	sloj operacija(sloj s)override;
};

class logaritam :
	public Operation
{
public:
	sloj operacija(sloj s)override;
};

class Max :
	public Operation
{
	int z;
public:
	Max(int x) :z(x) {}
	sloj operacija(sloj s)override;
};

class Min :
	public Operation
{
	int z;
public:
	Min(int x) :z(x) {}
	sloj operacija(sloj s) override;
};

class power :
	public Operation
{
	int z;
public:
	power(int x) :z(x) {}
	sloj operacija(sloj s)override;
};

class absolute :
	public Operation
{
public:
	sloj operacija(sloj s) override;
};

class crnobela :
	public Operation
{
public:
	sloj operacija(sloj s);
};

class siva :
	public Operation
{
public:
	sloj operacija(sloj s)override;

};
class invert :
	public Operation {
	sloj operacija(sloj s)override;
};
class Medijana :
	public Operation {
	sloj operacija(sloj s)override;
};