/* 
 * File:   Diccionario.cpp
 * Author: Manu
 * 
 * Created on 23 de octubre de 2017, 21:03
 */

#include "Diccionario.h"
#include <iostream>
#include <sstream>

Diccionario::Diccionario():palabras(){}
Diccionario::Diccionario(const std::string &nombre):palabras()
{
   cargarFichero(nombre);   //llamamos al m�dulo de carga del fichero en el vector  
}

void Diccionario::cargarFichero(const std::string &nombre){
  
    std::string linea;
    int total=0;
    // Asociamos el flujo con un fichero y lo abrimos
    fstream fe(nombre);  
    if (!fe.is_open()) //funciona con constructor en C++11 
        //throw std::runtime_error("Main.cpp: main: fallo fichero de entrada");
    // Mientras no se haya llegado al final del fichero
        while (getline(fe,linea)){                 
            if (linea!=""){ // Ignoramos lineas en blanco                
                //palabras.insertar(linea);  otra forma
               
                Palabra pal(linea);                                      
                guardaPalabra(pal);
                total++;              
            }
        }        
        fe.close();//Cerramos el flujo de entrada
        //palabras.ordenar();
        /*  for (long int i=0; i<80383; ++i)
            std::cout << palabras[i].GetTermino() <<std::endl; 
         */
    
}

Diccionario::Diccionario(const Diccionario& orig): palabras(orig.palabras)
{    
}

Diccionario::~Diccionario() 
{  
}

void Diccionario::guardaPalabra(const Palabra &pal){
    palabras.insertar(pal,UINT_MAX);
}

Palabra& Diccionario::busca(const std::string ter){
    Palabra pal(ter),pal2,&nula=pal2;
    unsigned long int pos=palabras.busquedaDic(pal);
    if (pos==-1)
        return nula;
    else
        return palabras[pos];
}

bool Diccionario::inserta(const std::string &termino){
   
    if (palabras.busquedaDic(termino)==-1){
       unsigned long int i;
        for (i=0; i<tama(); ++i)
            if (palabras[i].GetTermino()>termino)
                break;
        palabras.insertar(Palabra(termino), i); 
        return true;
    }else return false; 
}

void Diccionario::entrena(const std::string &frase){
        
    std::stringstream ss;
    std::string palabra,palabraSuc;
    int total = 0;
    ss << frase; //enviamos la cadena al stream
    ss >> palabra; //leemos la siguiente palabra
    if (palabra!="")
    while (!ss.eof()){        
        ss >> palabraSuc; //leemos la siguiente Sucesora       
        if (palabraSuc!=""){
            int pos=palabras.busquedaDic(palabra);
            if (pos==-1){                            
                inserta(palabra);
                pos=palabras.busquedaDic(palabra);
            }
            palabras[pos].nuevoSucesor(palabraSuc);           
            palabra=palabraSuc;            
            palabraSuc="";
        }else break;
    }
    
}


void Diccionario::usacorpus(const std::string &nombrefich){
   std::ifstream fe;
	std::string linea;
	fe.open(nombrefich);
	if (fe.good()) {
		while (!fe.eof()) {
			getline(fe, linea);
			if (linea != " ") {
				entrena(linea);
			}
		}
		fe.close();
	}
         
}

Diccionario& Diccionario::operator=(const Diccionario &orig){
    if (this!=&orig){
        palabras=orig.palabras;
    }
    return *this;
}

