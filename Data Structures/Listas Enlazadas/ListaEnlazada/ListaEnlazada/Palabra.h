#pragma once
#include <string>
#include <list>
#include "Recurso.h"
#include "ListaEnlazada.h"

class Palabra
{
private:
	std::string Termino;
	SimpleList<Sucesor> MisSucesores;
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
	SimpleList<std::string> MostrarLista();
};

