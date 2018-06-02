#include "stdafx.h"
#include "Diccionario.h"


Diccionario::Diccionario(std::string nombre):miVector(),posicion(0),Nombre(nombre)
{
	cargaPalabras(nombre);
}

Diccionario::Diccionario(Diccionario& orig)
{
	for (unsigned long int i = 0; i < miVector.get_Tamaniologico(); ++i) {
		miVector[i] = orig.miVector[i];
	}
}

Diccionario::~Diccionario()
{
}

long int Diccionario::buscaPalabra(Palabra& p) {
	bool encontrado = false;
	unsigned long int inicio = 0;
	unsigned long int final = miVector.get_Tamaniologico()-1;
	unsigned long int mitad = (inicio + final) / 2;
	std::string Termino = p.getTermino();
	std::string miPalabra = miVector[mitad].getTermino();
	while ((inicio <= final) && (!encontrado)) {
		if (Termino.compare(miPalabra) > 0) inicio = mitad + 1;
		else if (Termino.compare(miPalabra) < 0) final = mitad - 1;
		else encontrado = true;
		mitad = (inicio + final) / 2;
		miPalabra = miVector[mitad].getTermino();
	}
	if (encontrado) {
		std::cout << "Posicion: " << mitad << std::endl;
		return -1;
	}
	else {
		if (Termino.compare(miPalabra) > 0) {
			return (mitad);	
		}
		else {
			return (mitad + 1);
		}
	}
	return 0;
}
void Diccionario::inserta(Palabra& p) {
	if (miVector.get_Tamaniologico() > 0) {
		posicion = buscaPalabra(p);
	}
	if(posicion != -1) miVector.insertarnormal(p,posicion);
	else std::cout << "Ya insertada" << std::endl;
}

void Diccionario::cargaPalabras(std::string NombreFichero) {
	std::ifstream fe;
	std::string linea;
	fe.open(NombreFichero);
	if (fe.good()) {
		while (!fe.eof()) {
			Palabra palab;
			getline(fe, linea);
			if (linea != " ") {
				palab.set_Termino(linea);
				inserta(palab);
				palab.set_Termino(" ");
			}
		}
		fe.close();
	}
	else
	{
		throw std::runtime_error("El constructor de copia de diccionario se esta llamando");
	}
}