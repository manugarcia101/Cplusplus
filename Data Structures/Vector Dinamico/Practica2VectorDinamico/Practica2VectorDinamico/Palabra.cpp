#include "stdafx.h"
#include "Palabra.h"


Palabra::Palabra(std::string termino):Termino(termino)
{
}

Palabra::Palabra(const Palabra& orig):Termino(orig.Termino)
{
	Termino = orig.Termino;
}

Palabra::~Palabra()
{
}

void Palabra::set_Termino(std::string T) {
	Termino = T;
}

std::string Palabra::getTermino() {
	return this->Termino;
}

Palabra& Palabra::operator= (const Palabra& orig) {
	if (this != &orig) {
		this->Termino = orig.Termino;
	}
	return *this;
}

bool Palabra::operator< (const Palabra& orig) {
	return Termino < orig.Termino;
}