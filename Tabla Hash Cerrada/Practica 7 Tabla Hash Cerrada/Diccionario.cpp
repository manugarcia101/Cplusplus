#include "stdafx.h"
#include "Diccionario.h"
#include <algorithm>


Diccionario::Diccionario():miTabla() {

}
Diccionario::Diccionario(std::string nomfich) : nombreFichero(nomfich), miTabla()
{
	cargaPalabras(nomfich);
}
Diccionario::Diccionario(const Diccionario &orig) : miTabla(orig.miTabla)
{
}
Diccionario::~Diccionario()
{
}
Diccionario& Diccionario::operator=(Diccionario &orig) {
	if (this != &orig) {
		miTabla = orig.miTabla;
	}
	return *this;
}
void Diccionario::cargaPalabras(std::string nombreFichero) {
	std::string linea;
	std::fstream fe;
	bool insertado = false;
	fe.open(nombreFichero);
	if (fe.is_open()) {
		if (fe.good()) {
			while (!fe.eof()) {
				fe >> linea;
				if (linea != "") {
					insertado = inserta(linea);
					linea = "";
				}
			}
		}
		fe.close();
	}
	else {
		throw std::runtime_error("Error apertura fichero inicial");
	}
}

bool Diccionario::buscaDicotomica(std::string Termino) {
	Palabra p, *pAux;
	p.set_Termino(Termino);
	unsigned long clave = miTabla.djb2((unsigned char*)Termino.c_str());
	pAux = miTabla.buscar(clave, p);
	if (pAux != NULL) {
		if (p == *pAux) return true;
		else return false;
	}
	else {
		return false;
	}
}

bool Diccionario::inserta(std::string Termino) {
	Palabra p;
	p.set_Termino(Termino);
	unsigned long clave = miTabla.djb2((unsigned char*)Termino.c_str());
	bool insertado = miTabla.insertar(clave, p);
	return insertado;
}

void Diccionario::entrena(std::string cadena) {
	std::string PalabraUno;
	std::string PalabraDos;
	std::stringstream Stream;
	Stream << cadena;
	Stream >> PalabraUno;
	Palabra miPalabra("");
	while (!Stream.eof()) {
		Stream >> PalabraDos;
		if (PalabraUno != "") {
			inserta(PalabraUno);
		}
		if (PalabraDos != "") {
			unsigned long clave = miTabla.djb2((unsigned char*)PalabraUno.c_str());
			Palabra PAux;
			PAux.set_Termino(PalabraUno);
			Palabra *p = miTabla.buscar(clave,PAux);
			if (p != NULL) { //Si p==NULL, significa que no se ha podido (ni se podrá) insertar, debido a un numero de intentos de inserción muy limitado
							 // por lo que no trataríamos de insertarlo de nuevo y pasaríamos a la siguiente palabra
				p->NuevoSucesor(PalabraDos);
			}
			PalabraUno = PalabraDos;
			PalabraDos = "";
		}
	}
}

void Diccionario::entrenaNuevo(std::string termino1, std::string termino2) {
	Palabra *miPalabra, palabraSucesora;
	palabraSucesora.set_Termino(termino1);
	unsigned long clave = miTabla.djb2((unsigned char*)termino1.c_str());
	miPalabra = miTabla.buscar(clave, palabraSucesora);
	if (miPalabra != NULL) {//Si p==NULL, significa que no se ha podido insertar, debido a un numero de intentos de inserción muy limitado
							//para asegurarnos de que no se ha podido insertar por ese tipo de causas, en este caso, trataremos de insertar de nuevo
		miPalabra->NuevoSucesor(termino2);
	}
	else {
		Palabra p;
		p.set_Termino(termino2);
		miTabla.insertar(clave, p);
		miPalabra = miTabla.buscar(clave, palabraSucesora);
		if (miPalabra != NULL) {//Si p==NULL de nuevo, es que es imposible insertar dicha palabra, debido a los parámetros de tabla actuales (Nº intentos y tamaño de tabla), 
								//por lo que continuamos con la ejecución
			miPalabra->NuevoSucesor(termino2);
		}
	}
}

void Diccionario::Corpus(std::string cadena) {
	std::string linea;
	std::fstream fe;
	fe.open(cadena);
	int contador = 0;
	if (fe.is_open()) {
		if (fe.good()) {
			while (!fe.eof()) {
				getline(fe, linea, '\n');
				if (linea != "") {
					entrena(linea);
					linea = "";
					contador++;
					if (contador == 5000) break;
				}
			}
		}
		fe.close();
	}
	else {
		throw std::runtime_error("Error apertura fichero inicial");
	}
}

std::list<Sucesor> Diccionario::mostrarPrioritarios(std::string cadena) {
	Palabra p;
	p.set_Termino(cadena);
	unsigned long clave = miTabla.djb2((unsigned char*)cadena.c_str());
	Palabra *pAux = miTabla.buscar(clave, p);
	if (pAux->get_Termino() != "")
		return pAux->mostrarPrioritarios();
	else {
		inserta(cadena);
		unsigned long clave = miTabla.djb2((unsigned char*)cadena.c_str());
		Palabra *pAux = miTabla.buscar(clave, p);
		return pAux->mostrarPrioritarios();
	}
}

void Diccionario::MuestraDatos(float &carga, int &MaxColisiones, int &numElementos, float &promedioColisiones) { //Muestra las estadísticas de la tabla
	carga = miTabla.factorCarga();
	MaxColisiones = miTabla.get_MaxColisiones();
	numElementos = miTabla.get_numElementos();
	promedioColisiones = miTabla.promedioColisiones();
}
/*
void Diccionario::Borrar(std::string Termino) { //Para probar el borrado en la tabla basta con descomentar esta función
Palabra p;
p.set_Termino(Termino);
unsigned long clave = miTabla.djb2((unsigned char*)Termino.c_str());
bool insertado = miTabla.borrar(clave, p);
if (insertado == true)std::cout << "Borrado" << std::endl;
}
*/