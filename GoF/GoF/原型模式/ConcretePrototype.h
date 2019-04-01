#pragma once
#include "Prototype.h"
class Prototype_A : public Prototype
{
	virtual Prototype* clone()
	{
		return new Prototype_A(*this);
	}
	virtual void split()
	{
		cout <<"Prototype_A" << endl;
	}
};


class Prototype_B : public Prototype
{
	virtual Prototype* clone()
	{
		return new Prototype_B(*this);
	}
	virtual void split()
	{
		cout << "Prototype_B" << endl;
	}
};