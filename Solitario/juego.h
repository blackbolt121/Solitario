#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "List.h"
#include "pilaDeJuego.h"
#include "pilaAuxiliar.h"
#include "jugador.h"
class juego
{
public:
	juego();
	pilaAuxiliar** getPalos();
	pilaDeJuego** getPilasDelJuego();
	bool sacarCartaDeCartasSobrantes();
	bool sacarCartaDePilaDelJuego(const int& i);
	bool insertarCartaEnPalos(const int &i);
	bool insertarCartaEnCartasSobrantes();
	bool insertarCartaEnPilaDelJuego(const int &i);
	void imprimirPilasDeJuego();
	void imprimirPilasDePalos();
	void imprimirCartasSobrantes();
	void mezclarNuevamenteCartasSobrantes();
	jugador Jugador();
	bool hasGanado();
private:
	jugador jdor;
	pilaAuxiliar *palos[4];
	pilaDeJuego* pilasDelJuego[7];
	maso* cartasSobrantes;
	List<carta> cartasBarajear;
	void iniciar();
};

