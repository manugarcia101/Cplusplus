// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Diccionario.h"
#include "Palabra.h"
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
/**
@file Practica1VectorEstaticoEEDD
@brief Realiza busquedas de palabras en un diccionario usando un vector como contenedor
@authors David Diaz Jimenez y Manuel Garcia Lopez
@date 22/09/2017
*/
int main(int argc, char *argv[])
{
	if (argc == 1) {
		
		try {
			std::string nombre;
			std::cout << "Escriba el nombre del fichero donde se encuentran las palabras del diccionario" << std::endl;
			std::cin >> nombre;
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			Diccionario d(nombre);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> total = t2 - t1;
			std::cout <<"Duracion de carga de el programa: "<< total.count() << " segundos" << std::endl;
		
			bool fin = false;
			std::string miString;
			Palabra miPalabra;
			char z;
			do {
				std::cout << "¿Que palabra quieres buscar" << std::endl;
				std::cin >> miString;
				miPalabra.set_Termino(miString);
				d.busca(miPalabra);
				std::cout << "¿Quieres continuar buscando? (s/n)" << std::endl;
				std::cin >> z;
				if (z == 'n') fin = true;
			} while (!fin);
		}
		catch (bad_alloc) {
			std::cout << " No hay memoria disponible " << std::endl;
		}
		catch (runtime_error) {
			std::cout << " Se esta haciendo una copia indebida " << std::endl;
		}
		catch (out_of_range) {
			std::cout << " Acceso a posicion erronea " << std::endl;
		}
	}

    return 0;
}

