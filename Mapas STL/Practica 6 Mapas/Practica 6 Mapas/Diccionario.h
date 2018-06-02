#pragma once
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "Palabra.h"
#include <map>

class Diccionario
{
private:
	std::string nombreFichero;
public:
	Diccionario();
	Diccionario(std::string nomfich);
	Diccionario(const Diccionario &orig);
	~Diccionario();

	//Avl<Palabra> miArbol;
	std::map<std::string, Palabra> miMapa;

	Diccionario& operator=(Diccionario &orig);
	void cargaPalabras(std::string nomFichero);
	bool inserta(std::string Termino);
	bool buscaDicotomica(std::string Termino);
	void entrena(std::string cadena);
	void entrenaNuevo(std::string termino1, std::string termino2);
	void Corpus(std::string cadena);
	std::list<Sucesor> mostrarEnPantalla(std::string cadena);
	std::list<Sucesor> mostrarPrioritarios(std::string cadena);
};

