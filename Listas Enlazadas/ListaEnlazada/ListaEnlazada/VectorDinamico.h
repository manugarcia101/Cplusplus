#pragma once
#include <stdexcept>
#include <cmath>
#include <climits>
template<typename T>
class VectorDinamico
{
private:
	void aumentar();
	void disminuir();
	unsigned long int tamFisico;
	unsigned long int tamLogico;
	T *vector;
public:
	VectorDinamico<T>();
	VectorDinamico<T>(unsigned long int TamLogico);
	VectorDinamico<T>(const VectorDinamico &orig);
	VectorDinamico<T>(const VectorDinamico &orig, unsigned long int inicio, unsigned long int num);
	virtual ~VectorDinamico();

	unsigned long int get_Tamaniologico() { return this->tamLogico; }
	void insertarnormal(const T& dato, unsigned long int pos = UINT_MAX);
	T borrar(unsigned long int pos = UINT_MAX);
	VectorDinamico& operator= (const VectorDinamico& vect);
	T operator[](unsigned long int pos);
};
template<typename T>
void VectorDinamico<T>::aumentar() {//Dobla el tamaño fisico si es necesario (funciona correctamente)
	tamFisico = tamFisico * 2;
	
	T *nuevoVector = new T[tamFisico];
	for (unsigned long int i = 0; i < tamLogico; ++i) {
		nuevoVector[i] = vector[i];
	}
	delete[]vector;
	vector = nuevoVector;
	
}
template<typename T>
void VectorDinamico<T>::disminuir() {//Disminuye el tamaño fisico si es necesario (no se usa actualmente)
	tamFisico /= 2;
	
	T *nuevoVector = new T[tamFisico];
	for (unsigned long int i = 0; i < tamLogico; ++i) {
		nuevoVector[i] = vector[i];
	}
	delete[]vector;
	vector = nuevoVector;
	
}
template<typename T>
VectorDinamico<T>::VectorDinamico() {
	tamLogico = 2;
	tamFisico = 4;
	
	vector = new T[tamFisico];
	
}
template<typename T>
VectorDinamico<T>::VectorDinamico(unsigned long int TamLogico) :tamLogico(TamLogico) {//Constructor en base a un tamaño logico dado, (funciona correctamente)
	unsigned long int Tam = (log2(tamLogico)) + 1;
	tamFisico = pow(2, Tam);

	vector = new T[tamFisico];
	
}
template<typename T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico& orig) :tamLogico(orig.tamLogico) {//Constructor copia (funciona correctamente)
	
	vector = new T[tamFisico = orig.tamFisico];
	
	for (unsigned long int i = 0; i < tamFisico; ++i) vector[i] = orig.vector[i];
}
template<typename T>
VectorDinamico<T>::VectorDinamico(const VectorDinamico& orig, unsigned long int inicio, unsigned long int num) {//Constructor copia parcial (no usado por el momento)
	if (inicio >= orig.tamLogico || num + inicio, unsigned long int num) throw std::out_of_range("El intervalo se sale de rango");
	int TamAux = num;
	unsigned long int Tam = (log2(tamLogico)) + 1;
	tamFisico = pow(2, Tam);
	
	vector = new T[tamFisico = orig.tamFisico];
	
	for (int i = inicio; i < num + inicio; ++i) vector[i - inicio] = orig.vector[i];
}
template<typename T>
VectorDinamico<T>::~VectorDinamico()
{
	if (vector) delete[] vector;
}
template<typename T>
void VectorDinamico<T>::insertarnormal(const T& dato, unsigned long int pos) { //Inserta datos desde diccionario (funciona correctamente) 
	if (pos == UINT_MAX) {
		if (tamLogico == tamFisico) {
			aumentar();
		}
		vector[tamLogico] = dato;
	}
	else {
		if (pos > tamLogico) {
			throw std::out_of_range("Error de rango");
		}
		if (tamLogico == tamFisico) {
			aumentar();
		}
		for (unsigned long int i = tamLogico-1; i > pos; --i) {
			vector[i+1] = vector[i];
		}
		vector[pos] = dato;
	}
	tamLogico++;
}
template<typename T>
T VectorDinamico<T>::borrar(unsigned long int pos) { //Borra datos del vector (no se usa actualmente)
	T DatoAuxiliar;
	if (tamLogico == 0) {
		throw std::out_of_range("No hay datos");
	}
	if (pos == UINT_MAX) {
		if (tamFisico / 3 > tamLogico)
			disminuir();
		DatoAuxiliar = vector[tamLogico - 1];
	}
	else {
		if (pos >= tamLogico) throw std::out_of_range("Error de rango");
		if (tamFisico / 3 > tamLogico) disminuir();
		for (unsigned long int i = pos; i < tamLogico; ++i) {
			vector[i] = vector[i + 1];
		}
	}
	tamLogico--;
	return vector[pos];
}
template<typename T>
T VectorDinamico<T>::operator[](unsigned long int pos) { //(Funciona)
	if (pos >= tamFisico) {
		throw std::out_of_range("Fallo en el operator []");
	}
	return vector[pos];
}
template<typename T>
VectorDinamico<T>& VectorDinamico<T>::operator= (const VectorDinamico& orig) { //(Funciona)
	if (this != &orig) {
		delete[] vector;
		tamLogico = orig.tamLogico;
		
		vector = new T[tamFisico = orig.tamFisico];
		
		for (unsigned long int i = 0; i < tamFisico; ++i) {
			vector[i] = orig.vector[i];
		}
	}
	return *this;
}

