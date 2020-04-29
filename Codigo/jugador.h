#pragma once
#include "pilaAuxiliar.h"
class jugador
{
public:
	jugador() {
		this->nombre = "Jugador 1";
		this->mano = nullptr;
		this->InsertarEnSobrantes = false;
	}
	void setNombre(std::string nombre);
	void insertarPalos(pilaAuxiliar aux);
	void insertarMano(carta mano);
	carta* obtenerEnMano();
	bool isInsertarEnSobrantes();
	void setIsInsertarEnSobrantes();
private:
	carta *mano;
	std::string nombre;
	stack<pilaAuxiliar> rpalos;
	bool InsertarEnSobrantes;
};

