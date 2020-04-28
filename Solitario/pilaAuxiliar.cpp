#include "pilaAuxiliar.h"
pilaAuxiliar::pilaAuxiliar() : maso()
{}
bool pilaAuxiliar::push(carta s)
{
	if (this->length() == 0) {
		if (1 == s.getNumero()) {
			return maso::push(s);
		}
		else {
			return false;
		}
	}
	else {
		if ((this->getPeek()->getItem()->getNumero() + 1) == s.getNumero()) {
			if (this->getPeek()->getItem()->getPalo().compare(s.getPalo()) == 0) {
				return maso::push(s);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return false;
}
carta pilaAuxiliar::pop() {
	throw - 1;
	return carta(0);
}
