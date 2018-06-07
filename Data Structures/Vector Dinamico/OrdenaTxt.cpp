// OrdenaTxt.cpp: define el punto de entrada de la aplicación de consola.
//
#include <iostream>
#include <fstream>
#include <string>
#include "stdafx.h"
using namespace std;

int main()
{
	std::string vector[80383];
	int j = 0;
	std::ifstream fe;
	std::string linea;
	fe.open("listado-sin-acentos.txt");
	if (fe.good()) {

		while (!fe.eof()) {
			getline(fe, linea);
			if (linea != " ") {
				vector[j] = linea;
				++j;
			}
		}
		fe.close();
	}
	for (int k = 0; k < 80383; k++) {
		std::cout << vector[k] << std::endl;
	}
	std::string aux = "";
	for (int a = 0; a < 80383; ++a) {
		for (int b = 0; b < 80383 - a; ++b) {
			if (vector[b] > vector[b + 1]) {
				aux = vector[b];
				vector[b] = vector[b + 1];
				vector[b + 1] = aux;
			}
		}
	}
	for (int k = 0; k < 80383; k++) {
		std::cout << vector[k] << std::endl;
	}
	std::ofstream ofs("Lemario.txt", std::ofstream::out);
	std::string line;
	for (int k = 0; k < 80383; k++) {
		line = vector[k];
		ofs << line;
	}
	ofs.close();
    return 0;
}

