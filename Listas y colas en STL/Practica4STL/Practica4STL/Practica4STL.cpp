// Prueba.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Diccionario.h"
#include <iostream>
#include <string>
#include <list>

void mostrarLista(Diccionario &diccionario, std::string &cadena, bool listas) {
	std::list<std::string> miLista;
	if (listas == true) {
		miLista = diccionario.mostrarEnPantalla(cadena);
	}
	else { miLista = diccionario.mostrarPrioritarios(cadena); }
	if (miLista.size() != 0) {
		std::list<std::string>::iterator MiIterador(miLista.begin());
		Sucesor MiSucesor;
		std::string sucesor = "";
		int contador = 0;
		while (MiIterador != miLista.end()) {
			sucesor = *MiIterador;
			std::cout << "Sucesor: "<< contador <<" Termino: " << sucesor << /*" Ocurrencias: " << MiSucesor.get_NumOcurrencias() <<*/ std::endl;
			MiIterador++;
			contador++;
		}
	}
	else {
		std::cout << "Lista vacia " << std::endl;
	}
}

int main()
{

	Diccionario diccionario("listado.txt");
	bool seguir = true;
	bool lista = true;
	char num, numAux;
	std::string miString2 = "";
	std::string Aux = "";
	do {
		std::cout << "¿Que quieres hacer? (Entrenar con frase (1), entrenar con frase por defecto (2), entrenar con corpus(3): )" << std::endl;
		std::cin >> num;
		if (num == '1') {
			std::cout << "Introduce tu frase: " << std::endl;
			std::string miString;
			std::cin >> miString;
		}
		if (num == '2') {
			std::string miString = "veloz hola veloz y hola y veloz mi gato veloz come ";
			diccionario.entrena(miString);
		}
		if (num == '3') diccionario.Corpus("corpus.txt");

		std::cout << "Introduce palabra para obtener sus sucesores: " << std::endl;
		std::cin >> miString2;
		std::cout << "¿Quieres ver toda la lista (1) o solo los elementos prioritarios? (2): " << std::endl;
		std::cin >> numAux;
		if (numAux == '1')
			mostrarLista(diccionario, miString2, true);
		else
			mostrarLista(diccionario, miString2, false);

		std::cout << "¿Seguimos?(Si/No): " << std::endl;
		std::cin >> Aux;
		if (Aux == "No") seguir = false;
	} while (seguir == true);

	return 0;
}

