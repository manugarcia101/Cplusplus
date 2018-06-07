#pragma once
#include "VectorEstatico.h"
#include "Palabra.h"
class Diccionario
{
public:
	Diccionario(string Nombre="");
	Diccionario(const Diccionario& orig);
	virtual ~Diccionario();

	int busca(Palabra &p);
	void inserta(const Palabra &p);
	void cargaPalabras(string nombreFichero);

private:
	VectorEstatico palabras;
	unsigned long int posicion;
	string nombre;
};

