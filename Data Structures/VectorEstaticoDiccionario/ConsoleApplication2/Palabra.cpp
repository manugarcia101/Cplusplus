#include "stdafx.h"
#include "Palabra.h"
/**
@file Practica1VectorEstaticoEEDD
@brief Clase contenedora
@authors David Diaz Jimenez y Manuel Garcia Lopez
@date 22/09/2017
*/
Palabra::Palabra(string termino):Termino(termino)
{
}

Palabra::Palabra(const Palabra& orig):Termino(orig.Termino)
{
	throw std::runtime_error("¡¡Se esta copiando en Palabra!!");
}

Palabra::~Palabra()
{
}
/**
*@brief Setter de termino.
*@param string T.
*@return no devuelve nada;
*/
void Palabra::set_Termino(string T) {
	Termino = T;
}
/**
*@brief Getter de termino.
*@param No requiere parametros.
*@return devuelve el valor del string termino;
*/
string Palabra::get_Termino() {
	return this->Termino;
}
/**
*@brief Sobrecarga el operador de asignacion.
*@param Direccion de memoria de la palabra a copiar.
*@return devuelve la direccion de memorua de la palabra a copiar;
*/
Palabra& Palabra::operator= (const Palabra& orig) {
	if (this != &orig) {
		this->Termino = orig.Termino;
	}
	return *this;
}
