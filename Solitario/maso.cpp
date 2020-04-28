#include "maso.h"
maso::maso() {

}
bool maso::push(carta s)
{
	if (this->inMaso(s) == false) {
		this->m.push(s);
		return true;
	}
	else {
		return false;
	}
	
	
}
carta maso::pop()
{
	carta aux = *this->m.getPeek()->getItem();
	this->m.pop();
	return aux;
}
bool maso::inMaso(const carta& s)
{
	if (this->m.get(s) == nullptr)
		return false;
	else
		return true;

}
stack<carta> maso::getMaso()
{
	return this->m;
}
frame<carta>* maso::getPeek()
{
	return this->m.getPeek();
}
int maso::length() {
	return this->m.getSize();
}
void maso::imprimir()
{
	frame<carta>* aux = this->getPeek();
	while (true) {
		std::cout << *aux->getItem() << std::endl;
		if (aux->getNext() != nullptr)
			aux = aux->getNext();
		else
			break;
	}
}
bool operator==(maso &a, const int& b)
{
	if (a.m.getSize() == b)
		return true;
	else
		return false;
}
bool operator==(maso &a, maso &b)
{
	return false;
}
