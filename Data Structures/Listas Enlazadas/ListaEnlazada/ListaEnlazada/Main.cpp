// Prueba.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Diccionario.h"
#include <iostream>
#include <string>
#include <list>
#include "ListaEnlazada.h"

void mostrarLista(Diccionario &diccionario, std::string &cadena) {
	SimpleList<std::string> miLista;
	miLista = diccionario.mostrarEnPantalla(cadena);
	if (miLista.get_tam() != 0) {
		SimpleList<std::string>::Iterator MiIterador(miLista.iterator());
		std::string sucesor = "";
		int contador = 0;
		while (!MiIterador.fin()) {
			sucesor = MiIterador.dato();
			std::cout << "Sucesor: " << contador << " Termino: " << sucesor << /*" Ocurrencias: " << MiSucesor.get_NumOcurrencias() <<*/ std::endl;
			MiIterador.siguiente();
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
	char num;
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

		mostrarLista(diccionario, miString2);

		std::cout << "¿Seguimos?(Si/No): " << std::endl;
		std::cin >> Aux;
		if (Aux == "No") seguir = false;
	} while (seguir == true);

	return 0;
}

