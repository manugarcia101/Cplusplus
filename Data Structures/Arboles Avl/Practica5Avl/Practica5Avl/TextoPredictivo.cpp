#include "stdafx.h"
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo(Diccionario *dicIdioma):miDiccionario(dicIdioma)
{
}

TextoPredictivo::TextoPredictivo(const TextoPredictivo &orig) :miDiccionario(orig.miDiccionario)
{
}

TextoPredictivo::~TextoPredictivo()
{
}

std::list<Sucesor>& TextoPredictivo::sugerencia(std::string cadena) {
	static std::list<Sucesor> misSugerencias;
	misSugerencias = miDiccionario->mostrarPrioritarios(cadena);
	return misSugerencias;
}
void TextoPredictivo::entrena(std::string frase) {
	miDiccionario->entrena(frase);
}