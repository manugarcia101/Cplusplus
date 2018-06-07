/* 
 * File:   Palabra.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:03
 */

#ifndef PALABRA_H
#define	PALABRA_H

#include <string>
#include "Listas.h"
#include "Sucesor.h"
using namespace std;

class Palabra {
private:
    std::string termino;
    ListaEnlazada<Sucesor> siguientes;
    
public:
    //Palabra();
    Palabra(const Palabra& orig);
    Palabra(std::string _termino="");
    ~Palabra();
    Palabra& operator=(const Palabra &orig);
    
    std::string GetTermino() const;
    void SetTermino(std::string _termino);
    bool operator==(const Palabra &orig);    
    bool operator<(const Palabra &orig);
    
    ListaEnlazada<Sucesor> getSucesores() { return siguientes; }
    
    void nuevoSucesor( std::string &termino);
    ListaEnlazada<std::string> sucesores();
    
};


#endif	/* PALABRA_H */
