#pragma once
#include <iostream>
#include "stack.h"
#include "carta.h"
#include "frame.h"
class maso
{
public:
	maso();
	virtual bool push(carta s);
	virtual carta pop();
	bool inMaso(const carta& s);
	void imprimir();
	friend bool operator == (maso &a, const int& b);
	friend bool operator == (maso &a, maso &b);
	friend bool operator != (maso& a, const int& b) 
	{
		if (a == b)
			return true;
		else
			return false;
	}
	stack<carta> getMaso();
	frame<carta>* getPeek();
	int length();
protected:
	stack<carta> m;
};

