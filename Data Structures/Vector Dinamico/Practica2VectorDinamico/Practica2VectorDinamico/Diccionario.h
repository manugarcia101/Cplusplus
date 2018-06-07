#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Palabra.h"
#include "VectorDinamico.h"
#include <algorithm>

class Diccionario
{
private:
	std::string Nombre;
	long int posicion;
	VectorDinamico<Palabra> miVector;
public:
	Diccionario(std::string nombre="");
	Diccionario(Diccionario& orig);
	virtual ~Diccionario();

	long int buscaPalabra(Palabra& p);
	void inserta(Palabra &p);
	void cargaPalabras(std::string nombreFichero);
};

