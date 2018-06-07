#include "stdafx.h"
#include "Diccionario.h"


Diccionario::Diccionario(std::string nomfich) :nombreFichero(nomfich), miVector()
{
	cargaPalabras(nomfich);
}
Diccionario::Diccionario(const Diccionario &orig):miVector(orig.miVector)
{

}
Diccionario::~Diccionario()
{
}
Diccionario& Diccionario::operator=(Diccionario &orig) {
	if (this != &orig) {
		miVector = orig.miVector;
	}
	return *this;
}
void Diccionario::cargaPalabras(std::string nombreFichero) {
	std::string linea;
	std::fstream fe;
	fe.open(nombreFichero);
	if (fe.is_open()) {
		if (fe.good()) {
			while (!fe.eof()) {
				fe >> linea;
				if (linea != "") {
					inserta(linea);
					linea = "";
				}
			}
		}
		fe.close();
	}
	else {
		throw std::runtime_error("Error apertura fichero inicial");
	}
}

Palabra& Diccionario::buscaDicotomica(std::string Termino) {
	insertar = true;
	bool insertado = false;
	int final = miVector.get_Tamaniologico();
	int inicio = 0;
	while (insertado == false && inicio < final) {
		posicionVector = (final + inicio) / 2;
		if (Termino == miVector[posicionVector].get_Termino()) {
			insertado = true;
			insertar = false;
		}
		else {
			if (Termino > miVector[posicionVector].get_Termino()) {
				inicio = posicionVector + 1;
			}
			else {
				final = posicionVector - 1;
			}
		}
	}
	static Palabra palabra;
	palabra.set_Termino(Termino);
	return palabra;
}
bool Diccionario::inserta(std::string Termino) {
	buscaDicotomica(Termino);
	if (insertar == true) {
		Palabra palabra;
		palabra.set_Termino(Termino);
		miVector.insertarnormal(palabra, posicionVector);
		return true;
	}
	return false;
}

void Diccionario::entrena(std::string cadena) {
	std::string PalabraUno;
	std::string PalabraDos;
	std::stringstream Stream;
	Stream << cadena;
	Stream >> PalabraUno;
	int posAux;
	while (!Stream.eof()) {
		Stream >> PalabraDos;
		if (PalabraUno != "") {
			inserta(PalabraUno);
			posAux = posicionVector;
		}
		if (PalabraDos != "") {
			miVector[posAux].NuevoSucesor(PalabraDos);
			PalabraUno = PalabraDos;
			PalabraDos = "";

		}
	}
}

void Diccionario::Corpus(std::string cadena) {
	std::string linea;
	std::fstream fe;
	fe.open(cadena);
	int contador = 0;
	if (fe.is_open()) {
		if (fe.good()) {
			while (!fe.eof()) {
				getline(fe, linea, '\n');
				if (linea != "") {
					entrena(linea);
					linea = "";
					contador++;
					if (contador == 100) break; //Se puede comentar, es solo para coger un fragmento y que no tarde tanto en ejecutar
				}
			}
		}
		fe.close();
	}
	else {
		throw std::runtime_error("Error apertura fichero inicial");
	}
}

SimpleList<std::string> Diccionario::mostrarEnPantalla(std::string cadena) {
	buscaDicotomica(cadena);
	return miVector[posicionVector].MostrarLista();
}

