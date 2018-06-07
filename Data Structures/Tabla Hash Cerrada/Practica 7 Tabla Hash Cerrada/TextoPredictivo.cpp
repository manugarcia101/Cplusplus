#include "stdafx.h"
#include "TextoPredictivo.h"


TextoPredictivo::TextoPredictivo(Diccionario *dicIdioma) : miDiccBase(dicIdioma), misUsuarios()
{
}

TextoPredictivo::TextoPredictivo(const TextoPredictivo &orig) : miDiccBase(orig.miDiccBase), misUsuarios(orig.misUsuarios)
{
}

TextoPredictivo::~TextoPredictivo()
{
}

std::list<Sucesor> TextoPredictivo::sugerencia(std::string &cadena) {
	static std::list<Sucesor> misSugerencias;
	misSugerencias = miDiccBase->mostrarPrioritarios(cadena);
	return misSugerencias;
}

void TextoPredictivo::entrena(std::string frase) {
	miDiccBase->entrena(frase);
}

bool TextoPredictivo::entrenaNuevo(std::string termino1, std::string termino2) {
	bool estatermino1 = miDiccBase->buscaDicotomica(termino1), estatermino2 = miDiccBase->buscaDicotomica(termino2);
	if (estatermino1 && estatermino2) {
		miDiccBase->entrenaNuevo(termino1, termino2);
		return true;
	}
	else return false;
}

bool TextoPredictivo::nuevoUsuario(const std::string &id, const std::string &nombre) {

	std::pair<std::map<std::string, Usuario>::iterator, bool> miPair = misUsuarios.insert(std::pair<std::string, Usuario>(id, Usuario(id, nombre, this)));

	return true;

}

Usuario* TextoPredictivo::obtenerUsuario(const std::string &id) {

	std::map<std::string, Usuario>::iterator miIt = misUsuarios.find(id);
	if (miIt == misUsuarios.end()) {

		throw std::out_of_range("error");
	}
	return &(miIt->second);
}

bool TextoPredictivo::busca(std::string &termino) {
	bool esta = miDiccBase->buscaDicotomica(termino);
	return esta;
}
