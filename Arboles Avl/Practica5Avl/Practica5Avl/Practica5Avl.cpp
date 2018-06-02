// Practica5Avl.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "TextoPredictivo.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <chrono>
#include <string>
#include <stdexcept>

int main()
{
	std::cout << std::endl;
	std::cout << "INICIO DEL PROGRAMA " << std::endl;
	std::cout << std::endl;
	std::cout << "Cargando las palabras en el diccionario, espere por favor " << std::endl;
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	Diccionario miDiccionario("listado.txt");
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> total = t2 - t1;
	std::cout << "Duracion de carga de las palabras: " << total.count() << " segundos" << std::endl;
	std::cout << std::endl;

	TextoPredictivo t(&miDiccionario);

	bool continuar = true;
	bool lista = false;
	char num;
	std::string mistring= "";
	std::string mistring2 = "";
	std::string auxs = "";

		
	do {
		
		try {

			std::cout << "¿Que quieres hacer?" << std::endl << "*Entrenar con frase(1)" << std::endl << "*Entrenar con corpus(2)" << std::endl;
			std::cin >> num;
			std::cout << std::endl;

			if (num == '1') {
				std::cout << "Introduzca la frase:  ";
				std::getline(std::cin >> std::ws, mistring);
				t.entrena(mistring);
			}

			if (num == '2') {
				std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
				miDiccionario.Corpus("corpus.txt");
				std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> total2 = t4 - t3;
				std::cout << "Duracion de carga de Corpus " << total2.count() << " segundos" << std::endl;

			}
			
			std::cout << std::endl;
			std::cout << "Introduzca una palabra para obtener sus sucesores:" << std::endl;
			std::cin >> mistring2;
			std::cout << std::endl;

			std::list<Sucesor> MiSuc;
			MiSuc = t.sugerencia(mistring2);
			std::list<Sucesor>::iterator i = MiSuc.begin();
			int cont = 1;

			while (i != MiSuc.end()) {
				std::cout <<"Sucesor "<< cont <<" de " << mistring2 << ": " << i->get_Termino() << std::endl;
				std::advance(i, 1);
				++cont;
			}
			std::cout << std::endl;
			std::cout << "¿Continuar?(Si/No): " << std::endl;
			std::cin >> auxs;
			if (auxs == "No") continuar = false;
		}
		catch (std::logic_error &e) {
			std::cout << e.what();

		}

	} while (continuar == true);

	std::cout << std::endl;
	std::cout << "FIN DEL PROGRAMA " << std::endl;
	std::cout << std::endl;

    return 0;
}