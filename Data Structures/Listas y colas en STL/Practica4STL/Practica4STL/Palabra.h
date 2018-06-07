#pragma once
#include <string>
#include <list>
#include "Sucesor.h"
#include <queue>
#include <iostream>

class Palabra
{
private:
	std::string Termino;
	std::list<Sucesor> MisSucesores;
public:
	Palabra(std::string termino = "");
	Palabra(const Palabra &orig);
	~Palabra();

	void set_Termino(std::string Termino);
	std::string get_Termino();
	Palabra& operator=(const Palabra &orig);
	bool operator==(const Palabra &orig);
	bool operator<(const Palabra &orig);
	bool operator>(const Palabra &orig);
	void NuevoSucesor(std::string &cadena);
	std::list<std::string> MostrarLista();
	std::list<std::string> mostrarPrioritarios();
};

