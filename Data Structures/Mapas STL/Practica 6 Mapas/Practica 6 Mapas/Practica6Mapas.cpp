// Practica6Mapas.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "TextoPredictivo.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

int main()
{	
	std::string Corpusfrag1 = "son los salarios mas bajos de las mujeres indicio de discriminacion el control de la energia y la estrategia de las multinacionales perspectivas de utilizacion de la energia eolica en la agricultura transforma el clima exterior en un ambiente controlable y confortable cadenas linfaticas superficiales alrededor de las venas yugulares externa y anterior punto de introduccion de una aguja dentro de los ventriculos punto de introduccion de una aguja en la cavidad pericardica esta a nivel de el borde inferior de la primera vertebra lumbar movimientos de la escapula y de la articulacion de el hombro vision anterior y medial de la cadera muslo y rodilla vision anterior y medial de la cadera muslo y rodilla investigacion en salud publica incluida la investigacion sobre servicios de salud efectos de las hormonas sobre la contraccion de el musculo liso propagacion continua de los impulsos fibrilaforios en el ventriculo en fibrilacion manipulacion de el corazon como complemento de la fibrilacion caracteristicas de las auriculas para bombear la sangre durante la fibrilacion excrecion renal total y excrecion por nefrona en la insuficiencia renal efecto de la supresion renal en los componentes de el liquido extracelular retencion de agua y desarrollo de edema en la insuficiencia renal papel de los iones calcio en las vias intrinseca y extrinseca trastorno de la capacidad de los tejidos de utilizar el oxigeno resolucion de la asamblea general de las naciones unidas acuerdo sobre asuntos juridicos acuerdo sobre asuntos economicos";
	std::string Corpusfrag2 = "durante su desarrollo los capilares de el glomerulo comprimen el extremo ciego de el tubulo proximal la activacion de estas fibras mejora la absorcion de sodio en estos segmentos tubulares el concepto de aclaramiento renal se basa en el principio de el equilibrio de masa en condiciones normales la fraccion de filtracion oscila entre 015 y 020 como media la ifg puede alterarse cambiando el xxx o cualquiera de las fuerzas de starling a medida que aumenta el flujo plasmatico por la arteriola aferente aumenta la ifg el hipotalamo y el sistema nervioso simpatico participan en los componentes neurales de la respuesta sin embargo la secrecion de muchas hormonas se caracteriza por variaciones diurnas y aumentos episodicos en esos casos pueden ser necesarias varias muestras de plasma para hacer un calculo valido la combustion de las proteinas requiere en primer lugar la hidrolisis de sus aminoacidos componentes el glucogeno se puede formar a partir de los tres principales azucares de la dieta esto subraya la vital importancia de la produccion hepatica continua de glucosa durante el ayuno por otro lado el colesterol hdl ejerce un efecto protector frente a las enfermedades cardiovasculares estas adaptaciones tambien se reflejan en el cambio de las concentraciones plasmaticas de los sustratos";
	//--------------------------------------------------------------------------------------------------------------------------------
	std::string nombre = "Pepe", id = "39183123";
	//--------------------------------------------------------------------------------------------------------------------------------

	std::cout << std::endl;
	std::cout << "INICIO DEL PROGRAMA " << std::endl;
	std::cout << std::endl;
	std::cout << "Cargando las palabras en el diccionario, espere por favor " << std::endl;

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	Diccionario miDiccionario("listado.txt");
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> total = t2 - t1;
	std::cout << std::endl;
	std::cout << "Tiempo total: " << total.count() << std::endl;

	std::cout << std::endl;

	TextoPredictivo t(&miDiccionario);

	//--------------------------------------------------------------------------------------------------------------------------------
	t.nuevoUsuario(id,nombre);
	nombre = "Guille";
	id = "94983204";
	t.nuevoUsuario(id, nombre);
	
	Usuario *usu1 = new Usuario();
	Usuario *usu2 = new Usuario();

	try {
		usu1 = t.obtenerUsuario(id);
	}
	catch (std::out_of_range &e) {
		std::cout << e.what();
	}
	id = "39183123";
	try {
		usu2 = t.obtenerUsuario(id);
	}
	catch (std::out_of_range &e) {
		std::cout << e.what();
	}
	usu1->escribeFrase(Corpusfrag1);
	usu2->escribeFrase(Corpusfrag2);
	std::string terminoABuscar = "de";
	std::list<Sucesor> listaUsu = usu1->sugerencia(terminoABuscar);
	std::list<Sucesor>::iterator it = listaUsu.begin();
	std::cout << "Sucesores Usuario 1 para el termino: " << terminoABuscar << std::endl;
	while (it != listaUsu.end()) {
		std::cout << "Termino: " << it->get_Termino() <<" Numero de ocurrencias:" << it->get_NumOcurrencias()<< std::endl;
		it++;
	}
	//std::cout << "Salgo " << std::endl;
	listaUsu.clear();
	listaUsu = usu2->sugerencia(terminoABuscar);
	it = listaUsu.begin();
	std::cout << "Sucesores Usuario 2 para el termino:  " << terminoABuscar << std::endl;
	while (it != listaUsu.end()) {
		std::cout << "Termino: " << it->get_Termino() << " Numero de ocurrencias:" << it->get_NumOcurrencias() << std::endl;
		it++;
	}
	listaUsu.clear();


	//--------------------------------------------------------------------------------------------------------------------------------


	/*
	bool continuar = true;
	bool lista = false;
	char num;
	std::string mistring = "";
	std::string mistring2 = "";
	std::string auxs = "";



	do {

		try {

			std::cout << "¿Que quieres hacer?" << std::endl << "* Entrenar con una frase(1)" << std::endl << "* Entrenar usando corpus(2)" << std::endl;
			std::cin >> num;
			std::cout << "Seleccionada la funcion " << num << std::endl;

			if (num == '1') {
				std::cout << "Introduzca la frase: ";
				std::getline(std::cin >> std::ws, mistring);
				std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
				t.entrena(mistring);
				std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> total = t2 - t1;
				std::cout << std::endl;
				std::cout << "Duracion de carga de las palabras: " << total.count() << " segundos" << std::endl;

			}

			if (num == '2') {
				std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
				miDiccionario.Corpus("corpus.txt");
				std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> total2 = t4 - t3;
				std::cout << "Duracion de carga de Corpus:" << total2.count() << " segundos" << std::endl;

			}
			std::string volver = "";
			do {

				std::cout << std::endl;
				std::cout << "Introduzca una palabra para obtener sus sucesores: ";
				std::cin >> mistring2;
				std::cout << std::endl;

				std::list<Sucesor> MiSuc;
				MiSuc = t.sugerencia(mistring2);
				std::list<Sucesor>::iterator i = MiSuc.begin();
				int cont = 1;

				while (i != MiSuc.end()) {
					std::cout << "Sucesor " << cont << " de " << mistring2 << ": " << i->get_Termino() << std::endl;
					std::advance(i, 1);
					++cont;
				}
				std::cout << "¿Desea buscar sucesores de otra palabra?(Si/No): ";
				std::cin >> volver;
				std::cout << std::endl;
			} while (volver == "Si");
			std::cout << "¿Continuar?(Si/No):  ";
			std::cin >> auxs;
			if (auxs == "No") continuar = false;
		}
		catch (std::logic_error &e) {
			std::cout << e.what();

		}

	} while (continuar == true);

	std::cout << std::endl;
	std::cout << "FIN DEL PROGRAMA " << std::endl;
	std::cout << std::endl;
	*/
	return 0;
}