#include "stdafx.h"
#include "Diccionario.h"


Diccionario::Diccionario(std::string nomfich) :nombreFichero(nomfich), miArbol()
{
	cargaPalabras(nomfich);
}
Diccionario::Diccionario(const Diccionario &orig) :miArbol(orig.miArbol)
{
}
Diccionario::~Diccionario()
{
}
Diccionario& Diccionario::operator=(Diccionario &orig) {
	if (this != &orig) {
		miArbol = orig.miArbol;
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
	Palabra mip;
	mip.set_Termino(Termino);
	bool cp = false;
	miArbol.busca(mip);
	return cp;
}	

bool Diccionario::inserta(std::string Termino) {
	Palabra p;
	p.set_Termino(Termino);
	miArbol.inserta(p);
	bool esta = buscaDicotomica(Termino);
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
			miPalabra.set_Termino(PalabraUno);
			Palabra *miTerminoPalabra;
			miArbol.buscaEspecial(miPalabra, miTerminoPalabra);
			miTerminoPalabra->NuevoSucesor(PalabraDos);
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
	Palabra miPalabra;
	miPalabra.set_Termino(cadena);
	Palabra *miTerminoPalabra;
	miArbol.buscaEspecial(miPalabra, miTerminoPalabra);
	if(miTerminoPalabra != 0)
	return miTerminoPalabra->MostrarLista();
	else {
		miArbol.inserta(miPalabra);
		Palabra *miTerminoPalabra1;
		miArbol.buscaEspecial(miPalabra, miTerminoPalabra1);
		return miTerminoPalabra1->MostrarLista();
	}
}

std::list<Sucesor> Diccionario::mostrarPrioritarios(std::string cadena) {
	Palabra miPalabra;
	miPalabra.set_Termino(cadena);
	Palabra *miTerminoPalabra;
	miArbol.buscaEspecial(miPalabra, miTerminoPalabra);
	if (miTerminoPalabra != 0)
		return miTerminoPalabra->mostrarPrioritarios();
	else {
		miArbol.inserta(miPalabra);
		Palabra *miTerminoPalabra1;
		miArbol.buscaEspecial(miPalabra, miTerminoPalabra1);
		return miTerminoPalabra1->mostrarPrioritarios();
	}
}