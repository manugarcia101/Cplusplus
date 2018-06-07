#include "stdafx.h"
#include "Palabra.h"


Palabra::Palabra(std::string termino) :Termino(termino), MisSucesores()
{
}

Palabra::Palabra(const Palabra &orig)
{
	Termino = orig.Termino;
	MisSucesores = orig.MisSucesores;
}

Palabra::~Palabra()
{
}

void Palabra::set_Termino(std::string termino) {
	this->Termino = termino;
}

std::string Palabra::get_Termino() {
	return Termino;
}

Palabra& Palabra::operator=(const Palabra &orig) {
	if (this != &orig) {
		this->Termino = orig.Termino;
		MisSucesores = orig.MisSucesores;
	}
	return *this;
}

bool Palabra::operator==(const Palabra &orig) {
	return (Termino.compare(orig.Termino));
}

bool Palabra::operator<(const Palabra &orig) {
	return Termino < orig.Termino;
}

bool operator <(Sucesor &a, Sucesor &b) {
	return a.get_NumOcurrencias() < b.get_NumOcurrencias();
}

bool Palabra::operator>(const Palabra &orig) {
	return Termino > orig.Termino;
}

void Palabra::NuevoSucesor(std::string &cadena) {
	std::list<Sucesor>::iterator MiIterador = MisSucesores.begin();
	Sucesor Auxiliar;
	bool esta = false;
	while (MiIterador != MisSucesores.end() && esta == false) {
		if (MiIterador->get_Termino() == cadena) {
			MiIterador->set_NumOcurrencias(MiIterador->get_NumOcurrencias() + 1);		
			esta = true;
		}
		++MiIterador;
	}
	if (esta == false) {
		MisSucesores.push_back(Sucesor(1, cadena));
		MisSucesores.sort();
	}
}

std::list<std::string> Palabra::MostrarLista() {
	std::list<std::string> milista;
	std::list<Sucesor>::iterator MiIterador(MisSucesores.begin());
	std::string aux = "";
	while (MiIterador != MisSucesores.end()) {
		aux = MiIterador->get_Termino();
		milista.push_back(aux);
		MiIterador++;
	}
	return milista;
}

std::list<std::string> Palabra::mostrarPrioritarios() {
	std::priority_queue<std::string> MiCola;
	std::list<std::string> MiListaLimitada;
	std::list<Sucesor>::iterator MiIterador(MisSucesores.begin());
	int contador = 0;
	while (MiIterador != MisSucesores.end()) {
		MiCola.push(MiIterador->get_Termino());
		MiIterador++;
	}
	while (!MiCola.empty() && contador < 10) {
		MiListaLimitada.push_back(MiCola.top());
		MiCola.pop();
		contador++;
	}

	return MiListaLimitada;
}
