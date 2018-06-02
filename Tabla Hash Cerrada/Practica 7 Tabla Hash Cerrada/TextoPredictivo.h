#pragma once
#include <map>
#include <list>
#include <string>
#include "Diccionario.h"
#include "Usuario.h"

class Usuario;

class TextoPredictivo
{
private:
	std::map<std::string, Usuario> misUsuarios;
	Diccionario *miDiccBase;
public:
	TextoPredictivo(Diccionario *dicIdioma);
	TextoPredictivo(const TextoPredictivo &orig);
	~TextoPredictivo();

	std::list<Sucesor> sugerencia(std::string &cadena);
	void entrena(std::string frase);
	bool entrenaNuevo(std::string termino1, std::string termino2);
	bool nuevoUsuario(const std::string &id, const std::string &nombre);
	Usuario* obtenerUsuario(const std::string &id);
	bool busca(std::string &termino);
};


