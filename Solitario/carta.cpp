#include "carta.h"
carta::carta() {}
carta::carta(int x) {
	this->visible = true;
	if( x <= 0 or x>52 ) throw -1;
	int numero = x % 13;
	if (numero == 0) numero = 13;
	bool f = true;
	int contador = 1;
	while (f) {
		if ((13 * contador) < x) {
			f = true;
			contador++;
		}
		else {
			f = false;
		}
	}
	this->numero = numero;
	switch (contador) {
	case 1:
	case 3:
		if (contador == 1) {
			this->palo = "co";
		}
		else {
			this->palo = "diam";
		}
		this->color = "rojo";
		break;
	case 2:
	case 4:
		if (contador == 2)
			this->palo = "tre";
		else
			this->palo = "pic";
		this->color = "negro";
		break;
	default:
		this->color = "SN";
	}
	if (this->getNumero() < 11 and 1 < this->getNumero()) {
		this->outxt = std::to_string(this->getNumero())+ " "  + this->getColor()+ " " + this->getPalo();
	}
	else {
		switch (this->getNumero()) {
		case 1:
			this->outxt = "As " + this->getColor()+ " " + this->getPalo();
			break;
		case 11:
			this->outxt = "Joker " + this->getColor()+ " " + this->getPalo();
			break;
		case 12:
			this->outxt = "Reina " + this->getColor()+" " + this->getPalo();
			break;
		case 13:
			this->outxt = "Rey " + this->getColor()+ " " + this->getPalo();
			break;
		}
	}
}
std::string carta::getPalo()
{
	return this->palo;
}
std::string carta::getColor()
{
	return this->color;
}
int carta::getNumero()
{
	return this->numero;
}
bool carta::isVisible()
{
	return this->visible;
}
void carta::setVisible(bool visible)
{
	this->visible = visible;
}
std::string carta::getOutxt()
{
	return this->outxt;
}
std::ostream& operator <<(std::ostream& out, const carta& card) {
	out << card.outxt;
	return out;
}

bool operator==(const carta& a, const carta& b)
{
	if (a.color.compare(b.color.c_str()) == 0 and a.numero == b.numero and a.palo.compare(b.palo.c_str())== 0) {
		return true;
	}
	else {
		return false;
	}
	
	
}

bool operator!=(const carta& a, const carta& b)
{
	if (a == b)
		return false;
	else 
		return true;
	
}
