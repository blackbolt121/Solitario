#include "jugador.h"

void jugador::setNombre(std::string nombre)
{
	this->nombre = nombre;
}

void jugador::insertarPalos(pilaAuxiliar aux)
{
	this->rpalos.push(aux);
}

void jugador::insertarMano(carta mano)
{
	if (this->mano == nullptr) {
		this->mano = new carta();
		*this->mano = mano;
	}
}

carta* jugador::obtenerEnMano()
{
	carta* aux = this->mano;
	this->mano = nullptr;
	return aux;
}

bool jugador::isInsertarEnSobrantes()
{
	return this->InsertarEnSobrantes;
}

void jugador::setIsInsertarEnSobrantes()
{
	if (this->InsertarEnSobrantes == false) {
		this->InsertarEnSobrantes = true;
	}
	else {
		this->InsertarEnSobrantes = false;
	}
}
