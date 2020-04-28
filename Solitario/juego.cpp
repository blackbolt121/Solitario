#include "juego.h"
#include "gotoxy.h"
#include <string>
juego::juego() {
	this->iniciar();

}
pilaAuxiliar** juego::getPalos()
{
	return palos;
}
pilaDeJuego** juego::getPilasDelJuego()
{
	return this->pilasDelJuego;
}
bool juego::sacarCartaDeCartasSobrantes()
{
	carta* s = this->jdor.obtenerEnMano();
	if (s == nullptr) {
		this->jdor.setIsInsertarEnSobrantes();
		carta aux = this->cartasSobrantes->pop();
		this->jdor.insertarMano(aux);
		return true;
	}
	else {
		this->jdor.insertarMano(*s);
		return false;
	}
}
bool juego::sacarCartaDePilaDelJuego(const int& i)
{
	carta* s = this->jdor.obtenerEnMano();
	if (s == nullptr) {
		carta card = this->pilasDelJuego[i]->pop();
		this->jdor.insertarMano(card);
		return true;
	}
	else {
		this->jdor.insertarMano(*s);
		return false;
	}
}
bool juego::insertarCartaEnPalos(const int &i)
{
	carta* s = this->jdor.obtenerEnMano();
	bool retorno = false;
	if (s != nullptr) {
		retorno = this->palos[i]->push(*s);
		if (retorno == false) {
			this->jdor.insertarMano(*s);
		}
	}
	return retorno;
}
bool juego::insertarCartaEnCartasSobrantes()
{
	if (this->jdor.isInsertarEnSobrantes() == true) { //Esta parte del código verifica que la carta que tiene en la mano el jugador proviene de la pila de carta sobrantes
		carta* s = this->jdor.obtenerEnMano();
		if (s != nullptr) { //Si el jugador no tiene carta en la mano entonces no puede insertar una carta en una pila
			this->cartasBarajear.insert(*s);
			if (this->cartasSobrantes->length() == 0) { //Verifica si la pila de cartas sobrantes esta vacia para barajear
				srand((int)time(NULL));
				while (!(this->cartasBarajear == 0)) { // Esta parte del codigo sirve para barajear las cartas y devolverla a la pila de cartas sobrantes
					int x = rand() % this->cartasBarajear.size();
					carta aux = this->cartasBarajear.getByIndex(x)->getDato();
					this->cartasSobrantes->push(aux);
					this->cartasBarajear.pop(x);
				}
			}
			return true; //Si se inserto con exito, devuelve verdadero
		}
		else {
			return false; //Si no se inserto con exito, devuelve falso al usuario.
		}
	}
	else {
		return false;
	}
}
bool juego::insertarCartaEnPilaDelJuego(const int &i)
{
	bool retorno = false;;
	carta* s = this->jdor.obtenerEnMano();
	if (s != nullptr) {
		if (this->pilasDelJuego[i]->push(*s) == true) {
			retorno = true;
		}
		else {
			this->jdor.insertarMano(*s);
		}
	}
	return retorno;
}
void juego::iniciar() {
	for (int i = 0; i < 4; i++) {
		this->palos[i] = new pilaAuxiliar();
	}
	for (int i = 0; i < 7; i++) {
		this->pilasDelJuego[i] = new pilaDeJuego();
	}
	this->cartasSobrantes = new maso();
	srand((int)time(nullptr));
	do {
		int x = rand() % 52 + 1;
		carta card(x);
		if (this->cartasSobrantes->inMaso(card) == false) {
			this->cartasSobrantes->push(card);
		}
	} while (!(*(this->cartasSobrantes) == 52));
	stack<carta> k[7];
	for (int i = 0; i < 7; i++) {
		for (int e = 0; e < i + 1; e++) {
			k[i].push(this->cartasSobrantes->pop());
		}
	}
	for (int i = 0; i < 7; i++) {
		pilaDeJuego t = k[i];
		*(this->pilasDelJuego[i]) = t;
	}
}
void juego::imprimirPilasDeJuego() {
	int columna = 0, renglon = 1; //Coordenadas de impresion en la consola
	frame<carta>* aux;
	List<carta> x[7]; //Se crean siete lista para convertir de pilas a listas, sin afectar las pilas del juego, solo se obtienen las cartas de la pila
	for (int i = 0; i < 7; i++) {
		aux = this->pilasDelJuego[i]->getPeek(); //Se optiene la cima de la pila y a partir de ahí se recorre la pila insertandolas en la lista
		List<carta> auxlist;
		while (aux != nullptr) { //Minentras el Nodo no sea nulo recorre la pila y va insertando en la lista
			carta *inserta = aux->getItem();
			if (inserta != nullptr) { //En caso de que el item este vacio por cualquier erro este no inserta en la pila
				auxlist.insert(*inserta);
			}
			
			aux = aux->getNext();
		}
		x[i] = auxlist; 
		x[i] = x[i].reverse();
		//Por alguna razon el tratar de insertar las cartas en las listas asignadas al inicio de la función no inserta las cartas
		//Entonces se crea una lista auxiliar y se inserta en la posición que le corresponde al numero de pila.
	}
	for (int i = 0; i < 7; i++) {
		gotoXY(columna, 0);
		cout << "   Pila " << i + 1; //Imprime el numero de pila para la comodidad del usuario
		if (0 < x[i].size()) { //Si el tamaño de la lista es mayor a cero la imprimie, de lo contrario no la imprime
			int max = 0;
			Nodo<carta>* aux2 = x[i].getHead();
			while (aux2 != nullptr) {
				carta carta1 = aux2->getDato();
				gotoXY(columna, renglon);
				cout << carta1;
				if (max < carta1.getOutxt().length()) { // Aqui se verifica la longitud de el texto escrito más largo, de esta manera se le asigna como
					max = carta1.getOutxt().length(); //El texto más largo para luego sumarlo a la coordenada columna
				}
				aux2 = aux2->getNext();
				renglon++;
			}
			columna += max + 2;
			renglon = 1;
		}
		else { //Imprime vacio, mueve la coordenada columna a 14 "pixeles" (si es que lo puedo nombrar de esa manera) y el renglon le asigna como 1
			gotoXY(columna, renglon);
			cout << "   Vacio";
			columna += 14;
			renglon = 1;
		}
	}
	gotoXY(0, 10);
}
void juego::imprimirPilasDePalos() //El codigo es muy similar al de imprimir pilas del juego. Checa los comentarios de esa funcion
{
	int columna = 0, renglon = 1;
	frame<carta>* aux;
	List<carta> x[4];
	for (int i = 0; i < 4; i++) {
		aux = this->palos[i]->getPeek();
		List<carta> auxlist;
		while (aux != nullptr) {
			carta* inserta = aux->getItem();
			if (inserta != nullptr) {
				auxlist.insert(*inserta);
			}

			aux = aux->getNext();
		}
		x[i] = auxlist;
		x[i] = x[i].reverse();
	}
	for (int i = 0; i < 4; i++) {
		gotoXY(columna, 0);
		cout << "   Palo " << i + 1;
		if (0 < x[i].size()) {
			int max = 0;
			Nodo<carta>* aux2 = x[i].getHead();
			while (aux2 != nullptr) {
				carta carta1 = aux2->getDato();
				gotoXY(columna, renglon);
				cout << carta1;
				if (max < carta1.getOutxt().length()) {
					max = carta1.getOutxt().length();
				}
				aux2 = aux2->getNext();
				renglon++;
			}
			columna += max + 2;
			renglon = 1;
		}
		else {
			gotoXY(columna, renglon);
			cout << "   Vacio";
			columna += 14;
			renglon = 1;
		}
	}
	gotoXY(0, 6);
}
void juego::imprimirCartasSobrantes() {
	int columna = 0, renglon = 1;
	frame<carta>* aux;
	List<carta> x;
	aux = this->cartasSobrantes->getPeek();
	while (aux != nullptr) {
		carta* inserta = aux->getItem();
		if (inserta != nullptr) {
			x.insert(*inserta);
		}
		aux = aux->getNext();
	}
	x = x.reverse();
	gotoXY(columna, 0);
	std::cout << "   Pila auxiliar " << std::endl;
	if (0 < x.size()) {
		int max = 0;
		Nodo<carta>* aux2 = x.getHead();
		while (aux2 != nullptr) {
			carta carta1 = aux2->getDato();
			gotoXY(columna, renglon);
			cout << carta1;
			if (max < carta1.getOutxt().length()) {
				max = carta1.getOutxt().length();
			}
			aux2 = aux2->getNext();
			renglon++;
		}
		columna += max + 2;
		renglon = 1;
	}
	else {
		gotoXY(columna, renglon);
		cout << "   Vacio";
		columna += 14;
		renglon = 1;
	}
	gotoXY(0, x.size()+2);
}
void juego::mezclarNuevamenteCartasSobrantes()
{
	srand((int)time(NULL));
	while (this->cartasSobrantes->length() != 0) {
		carta aux = this->cartasSobrantes->pop();
		this->cartasBarajear.insert(aux);
	}
	while (this->cartasBarajear.size() != 0) {
		int aux = rand() % this->cartasBarajear.size();
		carta aux2 = this->cartasBarajear.getByIndex(aux)->getDato();
		this->cartasBarajear.pop(aux);
		this->cartasSobrantes->push(aux2);
	}
}
jugador juego::Jugador()
{
	return this->jdor;
}
