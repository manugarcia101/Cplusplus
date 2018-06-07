#include "stdafx.h"
#include "VectorEstatico.h"
/**
@file Practica1VectorEstaticoEEDD
@brief Clase contenedora
@authors David Diaz Jimenez y Manuel Garcia Lopez
@date 22/09/2017
*/
VectorEstatico::VectorEstatico()
{
	V = new Palabra[tam];
	if (!V)
	{
		std::bad_alloc exception;
		throw exception;
	}
}

VectorEstatico::VectorEstatico(const VectorEstatico& orig) 
{
}

VectorEstatico::~VectorEstatico()
{
	if (V) delete[] V;
}
/**
*@brief Comprueba que i no sea mayor que el tama�o del vector.
*@param i indica la posicion dentro del vector a comprobar.
*@return devuelve el primer elemento en caso de que i sea mayor que el tama�o, en otro caso devuelve el elemento en la posicion i del vector.
*/
Palabra& VectorEstatico::operator[](int i) {
	if (i >= tam) {
		throw out_of_range("El valor del vector esta fuera de rango");
		return V[0];
	}
	return V[i];
}
/**
*@brief Inserta en la posicion indicada la palabra.
*@param p palabra a asignar, (pos) posicion dentro del vector.
*@return La funcion no devuelve nada.
*/
void VectorEstatico::asigna(const Palabra &p, unsigned long int pos) {
	V[pos] = p;
}
/**
*@brief Devuelve el tama�o del diccionario
*@param No recive ningun parametro
*@return El tama�o
*/
int VectorEstatico::devuelveTamanio() {
	return tam;
}
