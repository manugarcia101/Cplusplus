#include "stdafx.h"
#include "Palabra.h"


Palabra::Palabra(std::string termino):Termino(termino), MisSucesores()
{
}

Palabra::Palabra(const Palabra &orig):Termino(orig.Termino), MisSucesores(orig.MisSucesores)
{
	
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

bool Palabra::operator==(const Palabra &orig) const {
	return (Termino.compare(orig.Termino));
}

bool Palabra::operator<(const Palabra &orig) const {
	return Termino < orig.Termino;
}

bool Palabra::operator>(const Palabra &orig) const {
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

std::list<Sucesor> Palabra::MostrarLista() {
	std::list<Sucesor> milista;
	std::list<Sucesor>::iterator MiIterador(MisSucesores.begin());
	Sucesor aux;
	while (MiIterador != MisSucesores.end()) {
		aux = *MiIterador;
		milista.push_back(aux);
		MiIterador++;
	}
	return milista;
}

std::list<Sucesor> Palabra::mostrarPrioritarios() {
	std::priority_queue<Sucesor> MiCola;
	std::list<Sucesor> Milista;
	std::list<Sucesor>::iterator it = MisSucesores.begin();
	int cont = 0;
	while (it != MisSucesores.end()) {
		MiCola.push(*it);
		it++;
	}
	while (!MiCola.empty() && cont < 10 ){
		Milista.push_back(MiCola.top());
		MiCola.pop();
		cont++;
	}
	return Milista;
}
void Palabra::MuestraPalabra(std::ostream &salidaEnPantalla) {
	salidaEnPantalla << Termino << "\n";
}