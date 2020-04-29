#include "pilaDeJuego.h"
#include "carta.h"
pilaDeJuego::pilaDeJuego() : maso(){

}
pilaDeJuego::pilaDeJuego(stack<carta> masodelapila) : maso() {
	this->m = masodelapila;

}
bool pilaDeJuego::push(carta s) 
{
	if (this->getPeek() != nullptr) 
	{
		if (this->getPeek()->getItem()->getPalo().compare("co") == 0 or this->getPeek()->getItem()->getPalo().compare("diam") == 0) 
			//Este condicional revisa si pertenece a un palo que sea rojo, de lo contrario es negro
		{
			if (s.getPalo().compare("pic") == 0 or s.getPalo().compare("tre") == 0) 
			 //Este condicional revisa que el palo de la carta que se desea insertar sea de un color opuesto al rojo
			{
				if (((this->getPeek()->getItem()->getNumero() - 1) == s.getNumero()))
				//Este condicional revisa si la carta es menor a la carta que se encuentra en la parte inicial de la pila.
				{
					this->getPeek()->getItem()->setVisible();
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
		else 
		{
			if (s.getPalo().compare("co") == 0 or s.getPalo().compare("diam") == 0)
				//Este condicional revisa que el palo de la carta que se desea insertar sea de un color opuesto al negro 
			{
				if ((this->getPeek()->getItem()->getNumero() - 1) == s.getNumero())
				//Este condicional revisa si la carta es menor a la carta que se encuentra en la parte inicial de la pila.
				{
					this->getPeek()->getItem()->setVisible();
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
	}
	else {
		if (s.getNumero() == 13) {
			return maso::push(s);
		}
		else {
			return false;
		}
	}
	return false;
	
}

carta pilaDeJuego::pop() {
	return maso::pop();
}
