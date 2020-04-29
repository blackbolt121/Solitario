#pragma once
#include <iostream>
#include "maso.h"
class pilaDeJuego : public maso
{
public:
	pilaDeJuego();
	pilaDeJuego(stack<carta> s);
	bool push(carta s);
	carta pop();
	pilaDeJuego operator=(const stack<carta> s) { return pilaDeJuego(s); }
	pilaDeJuego operator=(maso s) { return pilaDeJuego(s.getMaso()); }

};

