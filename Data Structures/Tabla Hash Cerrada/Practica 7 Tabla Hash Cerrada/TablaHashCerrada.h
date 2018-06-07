#pragma once
#include <vector>
#include <climits>
#include <cmath>
#include <iostream>
#define intentos 50 
#define tam 132367

template <typename T>
class Entrada {
public:
	T dato;
	bool uno; //combinacion 1 (true, true) "libre", combinacion 2 (true, false) "disponible", combinacion 3 (false, false) "ocupada"
	bool dos;

	Entrada();
	Entrada(T Dato);
	Entrada(const T &Dato): dato(Dato), uno(true), dos(true){}
	Entrada(const Entrada &orig);
	~Entrada();

	Entrada<T>& operator=(const Entrada &orig);	
};

template<typename T>
Entrada<T>::Entrada():uno(true), dos(true) {

}
template<typename T>
Entrada<T>::Entrada(T Dato):dato(Dato), uno(true), dos(true){

}
template<typename T>
Entrada<T>::Entrada(const Entrada &orig) :dato(orig.dato), uno(orig.uno),dos(orig.dos){

}
template <typename T>
Entrada<T>::~Entrada() {

}
template <typename T>
Entrada<T>& Entrada<T>::operator=(const Entrada &orig) {
	if (this != &orig) {
		dato = orig.dato;
		uno = orig.uno;
		dos = orig.dos;
	}
	return *this;
}



template <typename T>
class TablaHashCerrada{
public:

	TablaHashCerrada(unsigned int Tamfisico = tam);
	TablaHashCerrada(const TablaHashCerrada<T> &orig);
	~TablaHashCerrada();

	T* buscar(unsigned long int clave, const T& resultado);
	bool insertar(unsigned long int clave, const T& dato);
	bool borrar(unsigned long int clave, const T& resultado);

	TablaHashCerrada<T>&  operator=(const TablaHashCerrada &orig);
	//bool operator==(const TablaHashCerrada &orig);
	unsigned int get_numElementos();
	unsigned int get_MaxColisiones();
	float promedioColisiones();
	float factorCarga();
	static inline unsigned long djb2(unsigned char *str);
	unsigned int calcularPrimoRelativo();


private:

	unsigned int primoRelativo;
	float media;
	unsigned int numElementos;
	unsigned long int MaxColisiones;
	unsigned long int totalColisiones; 
	unsigned int tamFisico;
	std::vector<Entrada<T> > misDatos;

	inline unsigned long DispersionCuadratica(unsigned long posicionInicial, int intento);
	inline unsigned long DispersionDoble(unsigned long posicionInicial, int intento);

};

template <typename T>
TablaHashCerrada<T>::TablaHashCerrada(unsigned int Tamfisico):primoRelativo(calcularPrimoRelativo()), media(0), numElementos(0), MaxColisiones(0),
totalColisiones(0), tamFisico(tam), misDatos(tam) {}

template <typename T>
TablaHashCerrada<T>::TablaHashCerrada(const TablaHashCerrada &orig) {
	primoRelativo = orig.primoRelativo;
	media = orig.media;
	numElementos = orig.numElementos;
	MaxColisiones = orig.MaxColisiones;
	totalColisiones = orig.totalColisiones;
	tamFisico = orig.tamFisico;
	misDatos = orig.misDatos;
}

template <typename T>
TablaHashCerrada<T>::~TablaHashCerrada() {

}

template <typename T>
TablaHashCerrada<T>& TablaHashCerrada<T>::operator=(const TablaHashCerrada &orig) {
	if (this != &orig) {
		primoRelativo = orig.primoRelativo;
		media = orig.media;
		numElementos = orig.numElementos;
		MaxColisiones = orig.MaxColisiones;
		totalColisiones = orig.totalColisiones;
		tamFisico = orig.tamFisico;
		misDatos = orig.misDatos;
	}
	return *this;
}

//template <typename T>
//bool TablaHashCerrada<T>::operator==(const TablaHashCerrada &orig) {
//	misDatos == orig.misDatos ? return true : return false;
//}

template <typename T>
unsigned long TablaHashCerrada<T>::DispersionCuadratica(unsigned long posicionInicial, int intento) {
	unsigned long posicion = (posicionInicial + (intento*intento)) % tam;
	return posicion;
}
template <typename T>
unsigned long TablaHashCerrada<T>::DispersionDoble(unsigned long posicionInicial, int intento) {
	unsigned long posicion = ((posicionInicial % tam) + (intento*(primoRelativo-(posicionInicial % primoRelativo))))%tam;
	return posicion;
}

template <typename T>
T* TablaHashCerrada<T>::buscar(unsigned long int clave, const T& resultado) {
	int intento = 0;
	bool insertado = false;
	unsigned long posicion = 0;
	while (!insertado && intento < intentos) {
		//posicion = this->DispersionCuadratica(clave,intento);
		posicion = DispersionDoble(clave, intento);
		if (misDatos.at(posicion).dato == resultado) {
			return &(misDatos.at(posicion).dato);
		}
		else {
			intento++;
		}
	}
	return 0;
}

template <typename T>
bool TablaHashCerrada<T>::insertar(unsigned long int clave, const T& dato) {
	unsigned long int intento = 0;
	bool insertado = false;
	unsigned long posicion = 0;
	T *p = buscar(clave, dato); //Comprobamos que no esté ya insertada para evitar repetidas
	if (p != NULL) { return false; }
	else {
		while (!insertado && intento < intentos) {
			//posicion = DispersionCuadratica(clave, intento);
			posicion = DispersionDoble(clave, intento);
			if (misDatos.at(posicion).uno == true) {
				misDatos.at(posicion).dato = dato;
				misDatos.at(posicion).uno = false;
				misDatos.at(posicion).dos = false;
				insertado = true;
				numElementos++;
			}
			else {
				intento++;
			}
		}
		if (!insertado) {
			return false;
		}
		if (intento > MaxColisiones) MaxColisiones = intento;
		totalColisiones += intento;
		return true;
	}
	
}

template <typename T>
bool TablaHashCerrada<T>::borrar(unsigned long int clave, const T& resultado) {
	int intento = 0;
	bool borrado = false;
	int posicion = 0;
	while (!borrado && intento < intentos) {
		//posicion = DispersionCuadratica(clave, intento);
		posicion = DispersionDoble(clave, intento);
		if (misDatos.at(posicion).dato == resultado) {
			misDatos.at(posicion).uno = true;
			borrado = true;
			numElementos--;
		}
		else {
			intento++;
		}
	}
	if (borrado == true) return true;
	else return false;
}

template <typename T>
unsigned int TablaHashCerrada<T>::get_numElementos() { //Devuelve el tamaño de la tabla
	return numElementos;
}

template <typename T>
unsigned int TablaHashCerrada<T>::get_MaxColisiones() { //Devuelve el número máximo de colisiones
	return MaxColisiones;
}

template <typename T>
float TablaHashCerrada<T>::promedioColisiones() { //Devuelve el promedio de colisiones 
	float total = totalColisiones;
	float num = numElementos;
	media = (total / num);
	return media;
}

template <typename T>
float TablaHashCerrada<T>::factorCarga() { //Devuelve el factor de carga 
	float num = numElementos;
	float Tam = tam;
	float carga = (num / Tam);
	return carga;
}

template <typename T>
unsigned long TablaHashCerrada<T>::djb2(unsigned char *str) { //Función hash 
	unsigned long hash = 5381;
	int c;
	while (c = *str++) hash = ((hash << 5) + hash) + c;
	return hash;
}

template <typename T>
unsigned int TablaHashCerrada<T>::calcularPrimoRelativo() { //Devuelve el primer primo por debajo del tamaño de la tabla 
	int lineaAux = 0;
	if (tam > 999984) {
		std::vector<int> mivector;
		mivector.push_back(2);
		mivector.push_back(3);
		int numero = tam - 1;
		int limite = sqrt(numero);
		for (int i = 5; i < numero; i = i + 2) {
			bool insertar = true;
			for (unsigned int j = 0; j < mivector.size(); j++) {
				if (mivector[j] < limite) {
					if (i%mivector.at(j) == 0) {
						insertar = false;
						break;
					}
				}
				else {
					break;
				}
			}
			if (insertar) {
				mivector.push_back(i);
			}
		}
		return mivector.at(mivector.size() - 1);
	}
	else {
		std::string linea;
		std::string linea2;
		std::fstream fe;
		fe.open("primos.txt");
		if (fe.is_open()) {
			if (fe.good()) {
				fe >> linea;
				while (!fe.eof()) {
					fe >> linea2;
					lineaAux = std::stoi(linea2);
					if (lineaAux >= tam) {
						lineaAux = std::stoi(linea);
						break;
					}
					linea = linea2;

				}
			}
			fe.close();
		}
		else {
			throw std::runtime_error("Error apertura fichero inicial");
		}
	}
	return lineaAux;
}

