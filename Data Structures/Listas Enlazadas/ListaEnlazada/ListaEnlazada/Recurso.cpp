#include "stdafx.h"
#include "Recurso.h"

Sucesor::Sucesor()
{
	NumOcurrencias = 0;
	Termino = "";
}


Sucesor::Sucesor(int ocurrencias, std::string termino)
{
	NumOcurrencias = ocurrencias;
	Termino = termino;
}

Sucesor::Sucesor(const Sucesor &orig)
{
	NumOcurrencias = orig.NumOcurrencias;
	Termino = orig.Termino;
}

Sucesor::~Sucesor()
{
}

void Sucesor::set_NumOcurrencias(int n) {
	this->NumOcurrencias = n;
}

int Sucesor::get_NumOcurrencias() {
	return NumOcurrencias;
}

void Sucesor::set_Termino(std::string Termino) {
	this->Termino = Termino;
}

std::string Sucesor::get_Termino() {
	return Termino;
}

Sucesor& Sucesor::operator=(const Sucesor &orig) {
	if (this != &orig) {
		NumOcurrencias = orig.NumOcurrencias;
		Termino = orig.Termino;
	}
	return *this;
}

bool Sucesor::operator<(const Sucesor &orig) {
	return NumOcurrencias < orig.NumOcurrencias;
}

bool Sucesor::operator>(const Sucesor &orig) {
	return NumOcurrencias > orig.NumOcurrencias;
}

bool Sucesor::operator==(const Sucesor &orig) {
	if (NumOcurrencias == orig.NumOcurrencias && Termino == orig.Termino) {
		return true;
	}
	return false;
}
