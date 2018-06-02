#pragma once
#include <list>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "Palabra.h"
#include "TablaHashCerrada.h"

class Diccionario
{
private:
	std::string nombreFichero;
	TablaHashCerrada<Palabra> miTabla;
public:
	Diccionario();
	Diccionario(std::string nomfich);
	Diccionario(const Diccionario &orig);
	~Diccionario();

	Diccionario& operator=(Diccionario &orig);
	void cargaPalabras(std::string nomFichero);
	bool inserta(std::string Termino);
	bool buscaDicotomica(std::string Termino);
	void entrena(std::string cadena);
	void entrenaNuevo(std::string termino1, std::string termino2);
	void Corpus(std::string cadena);
	std::list<Sucesor> mostrarPrioritarios(std::string cadena);
	void MuestraDatos(float &carga, int &MaxColisiones, int &numElementos, float &promedioColisiones);
	//void Borrar(std::string Termino);
};

