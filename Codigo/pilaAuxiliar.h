#pragma once
#include <iostream>
#include "maso.h"
class pilaAuxiliar : public maso
{
public:
	bool push(carta s);
	pilaAuxiliar();
	carta pop();
};

