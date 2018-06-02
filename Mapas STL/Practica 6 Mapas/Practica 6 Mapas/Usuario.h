#pragma once
#include "TextoPredictivo.h"
#include "Diccionario.h"
#include <string>
#include <list>
#include <fstream>
#include <sstream>

class TextoPredictivo;

class Usuario
{
public:
	Usuario(std::string Id = "", std::string Nombre="--", TextoPredictivo *Tp = 0);
	Usuario(const Usuario &orig);
	~Usuario();
	Usuario& operator=(Usuario& orig);
	bool operator<(Usuario& orig);
	void set_Nombre(std::string nombre);
	std::string get_Nombre();
	void set_Id(std::string id);
	std::string get_Id();
	void set_Tp(TextoPredictivo *Tp);
	Usuario& get_Tp();

	std::list<Sucesor> sugerencia(std::string &termino);
	void escribeFrase(const std::string &Frase);

private:
	std::string id;
	std::string nombre;
	TextoPredictivo *tp;
	Diccionario miDiccionario;
};

