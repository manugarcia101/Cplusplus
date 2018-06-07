// Practica7TablaHashCerrada.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "TextoPredictivo.h"
#include <ctime>
#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include "TablaHashCerrada.h"
#include <vector>
#include <math.h>

int main()
{
	
	std::string Corpusfrag1 = "de cuerdo y loco todos tenemos un poco  we are all a little crazy in one way or another a caballo regalado no se le miran los dientes never look a gift horse in the mouth dime con quien andas y te dire quien eres you can judge a man by the company he keeps donde hay patron no manda marinero  what the boss says goes el amor todo lo puede  love will find a way todos ven lo que aparentas pero pocos ven lo que realmente eres eeveryone sees what you appear but few see what you really are";
	std::string Corpusfrag2 = "el termino es linguisticamente impreciso agrupa sin un criterio comun al empleo de prestamos linguisticos normal en el desarrollo de la lengua con el code switching frecuente entre hablantes bilingues o en las jergas profesionales con criterios de pureza estilistica que carecen en rigor de fundamento cientifico el termino spanglish no esta incluido en el diccionario de la real academia española";
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
	std::cout << "Tiempo total de carga de las palabras: " << total.count()<< std::endl;

	std::cout << std::endl;
	std::cout << "DATOS DE LA TABLA" << std::endl;
	std::cout << std::endl;

	float carga = 0, promedioColisiones = 0;
	int MaxColisiones = 0, numElementos = 0;
	miDiccionario.MuestraDatos(carga, MaxColisiones, numElementos, promedioColisiones);
	std::cout << "Factor de carga: "<<carga << std::endl;
	std::cout << "Maximo numero de colisiones: "<<MaxColisiones << std::endl;
	std::cout << "Numero de elementos en la tabla: " << numElementos << std::endl;
	std::cout << "Promedio de colisiones: " << promedioColisiones << std::endl;
	/*
	std::string uno = "hola";
	miDiccionario.Borrar(uno);
	miDiccionario.MuestraDatos(carga, MaxColisiones, numElementos, promedioColisiones);
	std::cout << "Factor de carga: " << carga << std::endl;
	std::cout << "Maximo numero de colisiones: " << MaxColisiones << std::endl;
	std::cout << "Numero de elementos en la tabla: " << numElementos << std::endl;
	std::cout << "Promedio de colisiones: " << promedioColisiones << std::endl;
	*/
	std::cout << std::endl;
	std::cout << "Cargando el corpus, espere por favor " << std::endl;
	std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
	miDiccionario.Corpus("corpus.txt");
	std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> total1 = t4 - t3;
	std::cout << std::endl;
	std::cout << "Tiempo total de carga del corpus: " << total1.count() << std::endl;

	std::cout << std::endl;

	TextoPredictivo t(&miDiccionario);

	//--------------------------------------------------------------------------------------------------------------------------------
	
	nombre = "Guille";
	id = "94983204";
	t.nuevoUsuario(id, nombre);

	Usuario *usu1 = t.obtenerUsuario(id);


	//--------------------------------------------------------------------------------------------------------------------------------

	bool continuar = true;
	bool lista = false;
	char num;
	std::string mistring = "";
	std::string mistring2 = "";
	std::string auxs = "";
	std::string id_usu = "";
	std::string nombre_usu = "";
	
	do {

		try {

			std::cout << "¿Que quieres hacer?" << std::endl << "* Ver sucesores de una palabra de usu1(1)" << std::endl << "* Entrenar a usu2 con una frase(2)" << std::endl;
			std::cin >> num;
			std::cout << "Seleccionada la funcion " << num << std::endl;

			if (num == '1') {
				bool nuevabusqueda = true;
				do {
					
					usu1->escribeFrase(Corpusfrag1);
					std::cout << "Palabra de la que quiere ver los sucesores:";
					std::string terminoABuscar = "";
					std::cin >> terminoABuscar;
					std::list<Sucesor> listaUsu = usu1->sugerencia(terminoABuscar);
					std::list<Sucesor>::iterator it = listaUsu.begin();
					std::cout << "Sucesores Usuario 1 para el termino: " << terminoABuscar << std::endl;
					while (it != listaUsu.end()) {
						std::cout << "Termino: " << it->get_Termino() << " Numero de ocurrencias:" << it->get_NumOcurrencias() << std::endl;
						it++;
					}
					std::string rep = "";
					std::cout << "Volver a buscar?(Si/No): ";
					std::cin >> rep;
					if (rep == "No") nuevabusqueda = false;
					listaUsu.clear();
				} while (nuevabusqueda);

			}
			std::string fraseusu = "";
			if (num == '2') {
				nombre = "Juan", id = "68569560";
				t.nuevoUsuario(id, nombre);

				Usuario *usu2 = t.obtenerUsuario(id);

				bool puede = false;
				std::cout << "Introzuca la frase para entrenarlo: ";
				std::getline(std::cin >> std::ws, fraseusu);
				usu2->escribeFrase(fraseusu);
				bool nuevabusqueda = true;
				do {

					usu1->escribeFrase(Corpusfrag1);

					std::cout << "Palabra de la que quiere ver los sucesores:";
					std::string terminoABuscar = "";
					std::cin >> terminoABuscar;
					std::list<Sucesor> listaUsu1 = usu2->sugerencia(terminoABuscar);
					std::list<Sucesor>::iterator it2 = listaUsu1.begin();
					std::cout << "Sucesores Usuario 2 para el termino: " << terminoABuscar << std::endl;
					while (it2 != listaUsu1.end()) {
						std::cout << "Termino:   " << it2->get_Termino() << "     Numero de ocurrencias:" << it2->get_NumOcurrencias() << std::endl;
						it2++;
					}
					std::string rep = "";
					std::cout << "Volver a buscar?(Si/No): ";
					std::cin >> rep;
					if (rep == "No") nuevabusqueda = false;
					listaUsu1.clear();
				} while (nuevabusqueda);


			}
			std::string volver = "";
			
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
	
	return 0;
}

