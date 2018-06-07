#include "stdafx.h"
#include "Usuario.h"


Usuario::Usuario(std::string Id, std::string Nombre, TextoPredictivo *Tp) :id(Id), nombre(Nombre), tp(Tp), miDiccionario()
{
}

Usuario::Usuario(const Usuario &orig) : id(orig.id), nombre(orig.nombre), miDiccionario(orig.miDiccionario), tp(orig.tp) {

}


Usuario::~Usuario()
{
}

Usuario& Usuario::operator=(Usuario& orig) {
	if (this != &orig) {
		id = orig.id;
		nombre = orig.nombre;
		tp = orig.tp;
		miDiccionario = orig.miDiccionario;
	}
	return *this;
}

void Usuario::set_Nombre(std::string nombre) {
	this->nombre = nombre;
}

std::string Usuario::get_Nombre() {
	return nombre;
}

void Usuario::set_Id(std::string id) {
	this->id = id;
}

std::string Usuario::get_Id() {
	return id;
}

void Usuario::set_Tp(TextoPredictivo *Tp) {
	this->tp = Tp;
}

Usuario& Usuario::get_Tp() {
	return *this;
}

bool Usuario::operator<(Usuario& orig) {
	return id < orig.id;
}

std::list<Sucesor> Usuario::sugerencia(std::string &termino) {
	static std::list<Sucesor> miDiccBase, miDicc;
	bool publico = tp->busca(termino);
	bool privado = miDiccionario.buscaDicotomica(termino);
	if (publico == false && privado == false) {
		miDiccionario.inserta(termino);
		return miDicc;
	}
	else if (publico == true && privado == true) {
		std::list<Sucesor> milista = miDiccionario.mostrarPrioritarios(termino);
		std::list<Sucesor>::iterator miIterador = milista.begin();
		static std::list<Sucesor> milistaux;
		std::list<Sucesor>::iterator aux = milistaux.begin();
		int cont = 0;

		while (cont<5 && miIterador != milista.end())
		{
			milistaux.insert(aux, *miIterador);
			cont++;
			std::advance(miIterador, 1);

		}

		milista.clear();
		milista = tp->sugerencia(termino);
		miIterador = milista.begin();
		cont = 0;
		std::list<Sucesor>::iterator aux2;
		bool esta = false;

		while (cont<5 && miIterador != milista.end())
		{

			aux2 = milistaux.begin();
			while (aux2 != milistaux.end()) {
				if (aux2->get_Termino() == termino) {
					esta = true;
					break;
				}
				std::advance(aux2, 1);
			}
			if (esta == false) {
				milistaux.insert(aux, *miIterador);
				cont++;
			}
			else {
				int ocurrencias = aux2->get_NumOcurrencias() + 1;
				aux2->set_NumOcurrencias(ocurrencias);
			}
			std::advance(miIterador, 1);
		}
		milistaux.sort();
		return milistaux;
	}
	else if (publico == true || privado == true) {
		if (publico == true) {
			miDiccBase = tp->sugerencia(termino);
			return miDiccBase;
		}
		else if (privado == true) {
			miDicc = miDiccionario.mostrarPrioritarios(termino);
			return miDicc;
		}
	}

	return miDicc;
}

void Usuario::escribeFrase(const std::string &Frase) {

	std::string PalabraUno;
	std::string PalabraDos;
	std::stringstream Stream;
	Stream << Frase;
	Stream >> PalabraUno;
	Palabra miPalabra = "";
	bool estaEnMiDiccBase = false;
	while (!Stream.eof()) {
		Stream >> PalabraDos;
		estaEnMiDiccBase = tp->entrenaNuevo(PalabraUno, PalabraDos);
		if (estaEnMiDiccBase == false) {
			miDiccionario.inserta(PalabraUno);
			miDiccionario.inserta(PalabraDos);
			miDiccionario.entrenaNuevo(PalabraUno, PalabraDos);
		}
		PalabraUno = PalabraDos;
		PalabraDos = "";
	}
}