#pragma once
// ≥ÈœÛ¿‡
#include<iostream>
using namespace std;
class Prototype
{
public:
	virtual void split() = 0;
	virtual Prototype* clone() = 0;
};