/*
* File:   ListaEnlazadaSimple.h
* Author: Manu
*
* Created on 11 de octubre de 2017, 17:02
*/
#pragma once
#include <stdexcept>
template <typename T>
class SimpleList {
	class Nodo {

	public:
		T dato;
		Nodo *sig;
		Nodo(const T &Dato, Nodo *Sig = 0) : dato(Dato), sig(Sig) {}
		~Nodo() {}
	};
	Nodo *cab, *cola;
	int tam = 0;
public:
	class Iterator {
		Nodo *nodo;
	public:
		Iterator(Nodo *Nodo) : nodo(Nodo) {}
		bool fin() { return nodo == 0; }
		void siguiente() { if(nodo->sig!=0) nodo = nodo->sig; }
		T &dato() { return nodo->dato; }
		~Iterator() {}
	};

	SimpleList() : cab(0), cola(0) {}
	~SimpleList();
	SimpleList(const SimpleList<T> &orig);
	SimpleList &operator=(const SimpleList<T> &orig);
	Iterator iterator() { return Iterator(cab); }
	void insertIni(const T &dato);
	void insertFin(const T &dato);
	void insert(Iterator &it, const T &dato);
	void borrarIni();
	void borrarFin();
	void borrar(Iterator &i);
	T &inicio();
	T &final();
	int get_tam();
};
template <typename T>
SimpleList<T>::SimpleList(const SimpleList<T>& orig) {//Funciona
	Nodo *p = orig.cab;
	cab = 0;
	cola = 0;
	while (p) {
		Nodo *nuevo;
		nuevo = new Nodo(p->dato, 0);
		if (cola) cola->sig = nuevo;

		if (!cab) cab = nuevo;

		cola = nuevo;
		p = p->sig;
	}
}
template <typename T>
SimpleList<T>::~SimpleList() {//funciona
	if (cab) {
		Nodo *siguiente = cab;
		while (siguiente) {
			cab = cab->sig;
			delete siguiente;
			siguiente = cab;
		}
		cola = 0;
	}
}
template <typename T>
SimpleList<T> &SimpleList<T>::operator =(const SimpleList<T>& orig) {//funciona
	if (orig.cab != cab) {
		if (cab) {
			Nodo *eliminar = cab;
			while (eliminar) {
				cab = cab->sig;
				delete eliminar;
				eliminar = cab;
			}
			cola = 0;
		}
		Nodo *p = orig.cab;
		cab = 0;
		cola = 0;
		while (p) {
			Nodo *nuevo = new Nodo(p->dato, 0);
			if (cola) cola->sig = nuevo;

			if (!cab) cab = nuevo;

			cola = nuevo;
			p = p->sig;
		}
	}
	return *this;
}
template <typename T>
void SimpleList<T>::insertIni(const T& dato) {//Funciona
	Nodo *nuevo;
	nuevo = new Nodo(dato, cab);
	if (!cola) cola = nuevo;
	cab = nuevo;
	tam++;
}
template <typename T>
void SimpleList<T>::insertFin(const T &dato) {//Funciona
	Nodo *nuevo;
	nuevo = new Nodo(dato, 0);
	if (cola) cola->sig = nuevo;

	if (!cab) cab = nuevo;

	cola = nuevo;
	tam++;
}
template <typename T>
void SimpleList<T>::insert(Iterator& it, const T& dato) {//No se si funciona pero creo que si... :(
	if (!it.fin()) {
		if (it.dato() == cab) {
			insertIni(dato);
			return;
		}
		else if (it.dato() == cola) {
			insertFin(dato);
			return;
		}
		else {
			Nodo *ant = 0;
			ant = cab;
			while (ant->sig != it.dato()) ant = ant->sig;

			Nodo *nuevo;
			nuevo = new Nodo(dato, it.dato());
			ant->sig = nuevo;
			tam++;
		}
	}
}
template <typename T>
void SimpleList<T>::borrarIni() {//No se usa
	if (cab) {
		Nodo *eliminar = cab;
		cab = cab->sig;
		delete eliminar;
		tam--;
		if (!cab) cola = 0;
	}
}
template <typename T>
void SimpleList<T>::borrarFin() {//No se usa
	Nodo *ant = 0;
	if (cab != cola) {
		ant = cab;
		while (ant->sig != cola) ant = ant->sig;

		delete cola;
		tam--;
		cola = ant;
		if (ant) ant->sig = 0;
		else cab = 0;
	}
}
template <typename T>
void SimpleList<T>::borrar(Iterator& i) {//No se usa
	Nodo *ant;
	if (!i.fin()) {
		if (i.dato() == cab) {
			borrarIni();
			return;
		}
		else if (i.dato() == cola) {
			borrarFin();
			return;
		}
		else {
			ant = cab;
			while (ant->sig != i.dato()) ant = ant->sig;

			ant->sig = i.siguiente();
			delete i.dato();
			tam--;
		}
	}
}
template <typename T>
T& SimpleList<T>::inicio() {//Funciona
	if (cab) return cab->dato;
	else throw std::out_of_range("Error");
}
template <typename T>
T& SimpleList<T>::final() {//Funciona
	if (cola)return cola->dato;
	else throw std::out_of_range("Error");
}
template <typename T>
int SimpleList<T>::get_tam() {
	return tam;
}