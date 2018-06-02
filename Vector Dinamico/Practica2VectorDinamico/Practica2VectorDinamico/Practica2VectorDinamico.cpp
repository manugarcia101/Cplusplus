// Practica2VectorDinamico.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Diccionario.h"
#include "Palabra.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

int main()
{
	try {
		Diccionario miDiccionario("Lemario.txt");
		int lugar = 0;
		std::string Termino;
		Palabra palabras;
		while (Termino != "exit") {
			std::cout << "Introduzca la palabra o frase a buscar (exit para salir) ";
			std::getline(std::cin >> std::ws, Termino);
			if (Termino != "exit") {
				std::istringstream isstream(Termino);
				while (!isstream.eof()) {
					std::string temporal;
					isstream >> temporal;
					palabras.set_Termino(temporal);
					miDiccionario.inserta(palabras);
					lugar = miDiccionario.buscaPalabra(palabras);
					if (lugar != -1)
						std::cout << "Insertando en la posicion: " << lugar << std::endl;
				}
			}
		}
	}
	catch (std::runtime_error &e) {
		std::cout << "Error de ejecucion" << e.what() << std::endl;
	}
	catch (std::bad_alloc &e) {
		std::cout << "Error asignacion de memoria" << e.what() << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << "Error de rango" << e.what() << std::endl;
	}
	/**
	try {
		Diccionario miDiccionario("Lemario.txt");
		int total = 0;
		std::string Termino = " ";
		std::stringstream ss;
		std::string palabras;
		while (!std::cin.eof()) {
			ss >> palabras;
				if (palabras != "exit") {
					std::cout << ++total << "" << palabras<<std::endl;
					palabras = " ";
				}
			}
		std::cout << "Total palabras: " << total << std::endl;
		}
	catch (std::runtime_error &e) {
		std::cout << "Error de ejecucion" << e.what() << std::endl;
	}
	catch (std::bad_alloc &e) {
		std::cout << "Error asignacion de memoria" << e.what() << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << "Error de rango" << e.what() << std::endl;
	}
	*/
	return 0;
}

