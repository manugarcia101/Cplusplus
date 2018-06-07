#pragma once
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include "Sucesor.h"

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
	bool operator==(const Palabra &orig)const;
	bool operator<(const Palabra &orig)const;
	bool operator>(const Palabra &orig)const;
	void NuevoSucesor(std::string &cadena);
	std::list<Sucesor> MostrarLista();
	std::list<Sucesor> mostrarPrioritarios();
	void MuestraPalabra(std::ostream &salidaEnPantalla);
};

