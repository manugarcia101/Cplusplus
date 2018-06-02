#pragma once
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "Palabra.h"
#include "Avl.h"

class Diccionario
{
private:
	std::string nombreFichero;
public:
	Diccionario(std::string nomfich);
	Diccionario(const Diccionario &orig);
	~Diccionario();

	Avl<Palabra> miArbol;

	Diccionario& operator=(Diccionario &orig);
	void cargaPalabras(std::string nomFichero);
	bool inserta(std::string Termino);
	bool buscaDicotomica(std::string Termino);
	void entrena(std::string cadena);
	void Corpus(std::string cadena);
	std::list<Sucesor> mostrarEnPantalla(std::string cadena);
	std::list<Sucesor> mostrarPrioritarios(std::string cadena);
};