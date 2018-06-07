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

bool Palabra::operator>(const Palabra &orig) {
	return Termino > orig.Termino;
}

void Palabra::NuevoSucesor(std::string &cadena) {
	SimpleList<Sucesor>::Iterator MiIterador(MisSucesores.iterator());
	Sucesor Auxiliar;
	bool esta = false;
	while (!MiIterador.fin() && esta == false) {
		if (MiIterador.dato().get_Termino() == cadena) {
			MiIterador.dato().set_NumOcurrencias(MiIterador.dato().get_NumOcurrencias() + 1);
			esta = true;
		}
		MiIterador.siguiente();
	}
	if (esta == false) {
		MisSucesores.insertFin(Sucesor(1, cadena));
	}
}

SimpleList<std::string> Palabra::MostrarLista() {
	SimpleList<std::string> milista;
	SimpleList<Sucesor>::Iterator MiIterador(MisSucesores.iterator());
	std::string aux = "";
	while (!MiIterador.fin()) {
		aux = MiIterador.dato().get_Termino();
		milista.insertFin(aux);
		MiIterador.siguiente();
	}
	return milista;
}
