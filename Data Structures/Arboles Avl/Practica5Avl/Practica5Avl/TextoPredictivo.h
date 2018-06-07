#pragma once
#include <list>
#include <string>
#include "Diccionario.h"

class TextoPredictivo
{
private:
	Diccionario *miDiccionario;
public:
	TextoPredictivo(Diccionario *dicIdioma);
	TextoPredictivo(const TextoPredictivo &orig);
	~TextoPredictivo();

	std::list<Sucesor>& sugerencia(std::string cadena);
	void entrena(std::string frase);
};