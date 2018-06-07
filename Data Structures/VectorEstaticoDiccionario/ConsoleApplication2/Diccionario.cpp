#include "stdafx.h"
#include "Diccionario.h"
/**
@file Practica1VectorEstaticoEEDD
@authors David Diaz Jimenez y Manuel Garcia Lopez
@date 22/09/2017
*/
Diccionario::Diccionario(string Nombre):palabras(),posicion(0),nombre(Nombre)
{
	cargaPalabras(Nombre);
}

Diccionario::Diccionario(const Diccionario& orig) 
{
	//throw std::runtime_error("El constructor de copia de diccionario se esta llamando");
}

Diccionario::~Diccionario()
{
}
/**
*@brief Realiza una busqueda binaria dicotomica en el vector de Palabras.
*@param p El objeto palabra que contiene el string a buscar.
*@details Nuestra funcion de busqueda se establece mediante la comparacion de el string que contiene la palabra a buscar y el string 
* que contiene la palabra a comparar a cada ciclo del bucle, para esta comparacion nos ayudamos de la funcion compare() de string, 
* ademas usamos tres variables para ir acotando el espacio de busqueda en el vector, y un booleano que nos indicara si se ha encontrado 
* o no la palabra.
*@return Devuerlve la posicion dentro del vector en caso de encontrar la palabra, en caso de no encontrala devuelve -1.

*/
int Diccionario::busca(Palabra &p) {
	bool encontrado = false;
	int inicio = 0;
	int final = palabras.devuelveTamanio()-1;
	int mitad = (inicio + final) / 2;
	std::string Termino = p.get_Termino();
	std::string pal = palabras[mitad].get_Termino();
	while((inicio <= final) && (!encontrado)){
	if(Termino.compare(pal) > 0) inicio = mitad + 1;
	else if(Termino.compare(pal) < 0) final = mitad - 1;
	else encontrado = true;
	mitad = (inicio + final) / 2;
	pal = palabras[mitad].get_Termino();
	}
	if (encontrado) {
		std::cout << "Elemento encontrado en la posicion " << mitad << std::endl;
		return mitad;
	}
	else {
		std::cout << "El elemento no esta en la lista" << std::endl;
		return -1;
	}
}
/**
*@brief Esta funcion debe enviar cada una de las palabras leidas en la funcion cargaPalabras, a la funcion asigna, 
*de la clase vector estatico.
*@param p objeto palabra que contiene el string a insertar.
*@return No devuelve nada.
*/
void Diccionario::inserta(const Palabra &p) {
	palabras.asigna(p,posicion);
	++posicion;
}
/**
*@brief Lee el fichero en el que se encuentran las palabras a insertar en el diccionario.
*@param NombreFichero Nombre del fichero donde se ubican las palabras.
*@details Creamos un flujo de entrada (fe), asociamos el flujo con un fichero (NombreFichero) y lo abrimos, 
* si se abre correctamente, toma cada línea del fichero hasta cada retorno de carro, y llama a inserta con ella
* como una palabra; sino se abre correctamente, lanza un mensaje de error 
*@return No devuelve nada.
*/
void Diccionario::cargaPalabras(string NombreFichero) {
	ifstream fe; 
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
