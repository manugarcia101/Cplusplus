/* 
 * File:   Diccionario.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:03
 */

#ifndef DICCIONARIO_H
#define	DICCIONARIO_H
#include <fstream>
#include "Vector.h"
#include "Palabra.h"
using namespace std;

class Diccionario {
public:
    Diccionario();
    Diccionario( const std::string &nombre);
    Diccionario(const Diccionario& orig);
    virtual ~Diccionario();
    
    long int tama(){
        return palabras.tama();
    }
    
    void cargarFichero(const std::string &nombre);
    void guardaPalabra(const Palabra &pal);
    Palabra& busca(const std::string ter);
    bool inserta(const std::string &termino);   
    
    void entrena(const std::string &frase);
    void mostrarSuc(std::string texto);
    void usacorpus(const std::string &nombre);
    
    Diccionario& operator=(const Diccionario &orig);
    
private:
    Vdinamico<Palabra> palabras;
};


#endif	/* DICCIONARIO_H */


