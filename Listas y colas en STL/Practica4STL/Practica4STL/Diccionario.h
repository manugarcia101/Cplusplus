#pragma once
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "Palabra.h"

class Diccionario
{
private:
	std::string nombreFichero;
	std::vector<Palabra> miVector;
	bool insertar;
	int posicionVector;
public:
	Diccionario(std::string nomfich);
	Diccionario(const Diccionario &orig);
	~Diccionario();

	Diccionario& operator=(Diccionario &orig);
	void cargaPalabras(std::string nomFichero);
	bool inserta(std::string Termino);
	Palabra& buscaDicotomica(std::string Termino);
	void entrena(std::string cadena);
	void Corpus(std::string cadena);
	std::list<std::string> mostrarEnPantalla(std::string cadena);
	std::list<std::string> mostrarPrioritarios(std::string cadena);
};

