#include "run.h"
#include <string>
#include <algorithm>
using namespace std;
void run(int numero, juego *&a) {

	if (a != nullptr) {
		do {
			switch (numero) {
			case 0:
				std::cout << "Bienvenido Jugador 1" << std::endl;;
				run(menu(), a);
				break;
			case 1:
				system("cls");
				a->imprimirPilasDeJuego();
				run(menu(), a);
				break;
			case 2:
				system("cls");
				a->imprimirPilasDePalos();
				run(menu(), a);
				break;
			case 3:
				system("cls");
				a->imprimirCartasSobrantes();
				run(menu(), a);
				system("Pause");
				exit(1);
				break;
			case 4:
				std::cout << "Se hizo un movimiento" << std::endl;
				operaciones(99, a);
				system("Pause");
				run(menu(), a);
				exit(1);
				break;
			case 5:
				if (a->Jugador().obtenerEnMano() != nullptr) std::cout << *a->Jugador().obtenerEnMano() << std::endl;
				else std::cout << "Mano vacia" << std::endl;
				system("Pause");
				system("cls");
				run(menu(), a);
			case 6:
				a->mezclarNuevamenteCartasSobrantes();
				system("cls");
				run(menu(), a);
			case 20:
				system("cls");
				std::cout << "Adios..." << std::endl;
				exit(1);
			case 99:
				system("cls");
				run(menu(), a);
			default:
				std::cout << "Opcion invalida..." << std::endl;
				cin.get();
				system("cls");
				run(menu(), a);
			}

		} while (true);
	}
	else
	{	
		system("cls");
		if (numero == 100) {
			std::cout << "Digito una opción invalida... Por favor, responda la pregunta..." << std::endl;
		}
		std::string rpt;
		std::cout << "Desea crear un juego nuevo.. (Si / No): " << std::endl;
		getline(cin, rpt, '\n');
		system("cls");
		toLowerCase(rpt);
		if (rpt.compare("si")==0) {
			juego* b = new juego();
			run(0, b);
		}
		else {
			run(100, a);
		}

	}
}

void operaciones(int x, juego*& a)
{
	int aux;
	std::string rpt;
	switch (x) {
	case 1:
		volver:
		system("cls");
		a->imprimirPilasDeJuego();
		std::cout << "Digite el numero de pila de la cual desea remover una carta (1-7) o 9 para cancelar: ";
		cin >> aux;
		aux--;
		if (0<=aux and aux<7) {
			if (a->Jugador().obtenerEnMano() == nullptr) {
				a->sacarCartaDePilaDelJuego(aux);
				std::cout << "Operación exitosa....\n Carta en mano: " << *a->Jugador().obtenerEnMano() << std::endl;
				system("Pause");
				system("cls");
			}
			else {
				std::cout << "No puede realizar esta accion, tiene una carta en la mano, insertenla en una pila" << std::endl;
				cin.get();
				fflush(stdin);
			}
		}
		else {
			if (aux == 8) {
				operaciones(99, a);
			}
			else {
				std::cout << "Operacion invalida..." << std::endl;
				system("Pause");
				goto volver;
			}
		}
		aux = 0;
		operaciones(97, a);
		break;
	case 2: // Sacar carta de la pila de cartas sobrantes...
		if (a->Jugador().obtenerEnMano() == nullptr) 
		{
			if (a->sacarCartaDeCartasSobrantes()) 
				std::cout << "Operacion realizada con exito" << std::endl;
			else 
				std::cout << "Ocurrio un error" << std::endl;
			system("Pause");
			operaciones(97, a);
		}
		else
		{
			std::cout << "Lo siento eso no es posible, tienes una carta en la mano...." << std::endl;
			operaciones(97, a);
		}
		break;
	case 3:
		volver2:
		system("cls");
		a->imprimirPilasDeJuego();
		std::cout << "La carta que usted tiene en la mano es: "<< *a->Jugador().obtenerEnMano() << std::endl;
		std::cout << "Digite el numero de pila de la cual desea remover una carta (1-7) o 9 para cancelar: ";
		cin >> aux;
		aux--;
		if (0 <= aux and aux < 7) {
			if (a->Jugador().obtenerEnMano() != nullptr) {
				if (a->insertarCartaEnPilaDelJuego(aux) == true) {
					std::cout << "La carta ha sido colocada con exito"<< std::endl;
				}
				else {
					std::cout << "La carta no ha sido colocada en la pila indicada" << std::endl;
					goto volver2;
				}
			}
			else {
				std::cout << "Usted no puede realizar esta operación" << std::endl;
			}
			system("Pause");
		}
		else {
			if (aux == 9) {
				operaciones(99, a);
			}
			else {
				std::cout << "Operacion invalida..." << std::endl;
				system("Pause");
				goto volver2;
			}
		}
		aux = 0;
		operaciones(97, a);
		break;
	case 4: //Insertar en cartas sobrantes
		if (a->Jugador().obtenerEnMano() != nullptr) {
			if (a->Jugador().isInsertarEnSobrantes() == true) {
				if (a->insertarCartaEnCartasSobrantes()) {
					std::cout << "La carta fue devuelta..." << std::endl;
				}
				else {
					std::cout << "La carta no fue devuelta...";
				}
				a->Jugador().setIsInsertarEnSobrantes();
			}
			else {
				std::cout << "Usted no puede colocar esta carta en esta pila" << std::endl;
			}
		}
		else {
			std::cout << "No puede hacer esta operacion puesto que no tiene una carta en la mano..." << std::endl;
		}
		system("Pause");
		operaciones(97, a);
		break;
	case 5: //Insertar en palos recolectados por el jugador
		regresar:
		system("cls");
		a->imprimirPilasDePalos();
		if (a->Jugador().obtenerEnMano() != nullptr) {
			std::cout << "Digite el numero de palo en el que desea colocar la carta (1-4) o 8 para salir: "; cin >> aux;
			aux--;
			if (0 <= aux and aux <= 3) {
				if (a->Jugador().obtenerEnMano() != nullptr) 
				{
					if (a->insertarCartaEnPalos(aux)) {
						std::cout << "La carta fue colocada en el palo" << std::endl;
					}
					else {
						std::cout << "La carta no puede ser colacada en el palo" << std::endl;
					}
				}
				else
				{
					std::cout << "Usted no puede hacer esta operacion porque no tiene una carta en la mano..." << std::endl;
				}
			}
			else {
				if (aux == 7) {
					operaciones(97, a);
				}
				else
				{
					std::cout << "Palo no valido" << std::endl;
					goto regresar;
				}
			}
		}
		else {
			std::cout << "Usted no puede hacer esta operacion puesto que no tiene una carta en la mano...." << std::endl;
		}
		system("Pause");
		operaciones(97, a);
		break;
	case 6:
		std::system("cls");
		run(99, a);
	case 97:
		std::system("cls");
		std::cin.ignore();
		std::cout << "Desea realizar una nueva operacion (Si/No): " << std::endl;
		std::fflush(stdin);
		std::getline(std::cin, rpt, '\n');
		std::fflush(stdin);
		toLowerCase(rpt);
		if (rpt.compare("si") == 0) {
			operaciones(99, a);
		}
		else if(rpt.compare("no") == 0){
			operaciones(6, a);
		}
		else {
			system("cls");
			std::cout << "Opcion invalida...." << std::endl;
			system("Pause");
			operaciones(97, a);
		}
		

	case 98:
		system("cls");
		std::cout << "Operacion invalida..." << std::endl;
		system("Pause");
	case 99:
		system("cls");
		a->imprimirPilasDeJuego();
		if (a->Jugador().obtenerEnMano() != nullptr) {
			std::cout << "Carta en la mano del jugador: " << *a->Jugador().obtenerEnMano() << std::endl;
		}
		else {
			std::cout << "Mano vacia..." << std::endl;
		}
		int aux;
		std::cout << "Operaciones: " << std::endl;
		std::cout << "1.- Sacar carta de pilas del juego " << std::endl;
		std::cout << "2.- Sacar carta de la pila de cartas sobrantes del juego" << std::endl;
		std::cout << "3.- Insertar en las pilas del juego" << std::endl;
		std::cout << "4.- Insertar en la pila de cartas sobrantes: " << std::endl;
		std::cout << "5.- Insertar en la pila de palos de carta" << std::endl;
		std::cout << "6.- Volver al menu" << std::endl;;
		std::cout << "---->";
		cin >> aux;
		operaciones(aux, a);
		break;

	default:
		operaciones(98, a);
		break;
	}
}
int menu() {
	int op;
	std::cout << "Digite las siguientes opciones: " << std::endl;
	std::cout << "1.- Impimir las pilas del juego " << std::endl;
	std::cout << "2.- Imprimir la pila de palos recolectados" << std::endl;;
	std::cout << "3.- Imprimir la pila de cartas sobrantes" << std::endl;
	std::cout << "4.- Hacer un movimiento" << std::endl;
	std::cout << "5.- Ver carta en mano" << std::endl;
	std::cout << "6.- Mezclar nuevamente pila de cartas sobrantes" << std::endl;
	std::cout << "20.- Salir" << std::endl;
	std::cout << "------>";
	std::cin >> op;
	return op;
}
void toLowerCase(std::string& cadena) {
	std::for_each(cadena.begin(), cadena.end(), [](char &s) { s = ::tolower(s); } );
}
