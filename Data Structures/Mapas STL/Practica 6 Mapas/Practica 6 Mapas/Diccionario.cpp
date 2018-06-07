#include "stdafx.h"
#include "Diccionario.h"

Diccionario::Diccionario():miMapa(){

}
Diccionario::Diccionario(std::string nomfich) :nombreFichero(nomfich), miMapa()
{
	cargaPalabras(nomfich);
}
Diccionario::Diccionario(const Diccionario &orig) : miMapa(orig.miMapa)
{
}
Diccionario::~Diccionario()
{
}
Diccionario& Diccionario::operator=(Diccionario &orig) {
	if (this != &orig) {
		miMapa = orig.miMapa;
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

bool Diccionario::buscaDicotomica(std::string Termino) {
	bool cp = false;
	auto i = miMapa.find(Termino);
	if (i != miMapa.end()) cp = true;
	return cp;
}

bool Diccionario::inserta(std::string Termino) {
	Palabra p;
	p.set_Termino(Termino);
	std::pair<std::map<std::string, Palabra>::iterator, bool> miPair = miMapa.insert(std::pair<std::string, Palabra> (Termino, p));
	bool esta = miPair.second;
	if (esta == true) return true;
	else return false;
}

void Diccionario::entrena(std::string cadena) {
	std::string PalabraUno;
	std::string PalabraDos;
	std::stringstream Stream;
	Stream << cadena;
	Stream >> PalabraUno;
	Palabra miPalabra = "";
	while (!Stream.eof()) {
		Stream >> PalabraDos;
		if (PalabraUno != "") {
			inserta(PalabraUno);
		}
		if (PalabraDos != "") {
			Palabra &p = miMapa.at(PalabraUno);
			p.NuevoSucesor(PalabraDos);
			PalabraUno = PalabraDos;
			PalabraDos = "";
		}
	}
}

void Diccionario::entrenaNuevo(std::string termino1, std::string termino2) {
	Palabra &p = miMapa.at(termino1);
	p.NuevoSucesor(termino2);
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
					if (contador == 1000) break;
				}
			}
		}
		fe.close();
	}
	else {
		throw std::runtime_error("Error apertura fichero inicial");
	}
}

std::list<Sucesor> Diccionario::mostrarEnPantalla(std::string cadena) {
	Palabra &p = miMapa.at(cadena);
	if (p.get_Termino() != "")
		return p.MostrarLista();
	else {
		std::pair<std::map<std::string, Palabra>::iterator, bool> miPair = miMapa.insert(std::pair<std::string, Palabra>(cadena, p));
		Palabra &pal = miMapa.at(cadena);
		return pal.MostrarLista();
	}
}

std::list<Sucesor> Diccionario::mostrarPrioritarios(std::string cadena) {
	Palabra &p = miMapa.at(cadena);
	if (p.get_Termino() != "")
		return p.mostrarPrioritarios();
	else {
		std::pair<std::map<std::string, Palabra>::iterator, bool> miPair = miMapa.insert(std::pair<std::string, Palabra>(cadena, p));
		Palabra &pal = miMapa.at(cadena);
		return pal.mostrarPrioritarios();
	}
}