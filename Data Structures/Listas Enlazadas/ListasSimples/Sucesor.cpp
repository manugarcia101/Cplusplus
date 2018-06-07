/* 
 * File:   Sucesor.cpp
 * Author: Manu
 * 
 * Created on 23 de octubre de 2017, 21:04
 */

#include "Sucesor.h"

Sucesor::Sucesor(const std::string &_termino, unsigned int oc): termino(_termino), numOcurrencias(oc) {
}

Sucesor::Sucesor(const Sucesor& orig): 
        termino(orig.termino), 
        numOcurrencias(orig.numOcurrencias) {
}

Sucesor::~Sucesor() {
}

void Sucesor::SetNumOcurrencias(unsigned int numOcurrencias) {
    this->numOcurrencias = numOcurrencias;
}

unsigned int Sucesor::GetNumOcurrencias() const {
    return numOcurrencias;
}

void Sucesor::SetTermino(std::string termino) {
    this->termino = termino;
}

std::string Sucesor::GetTermino() const {
    return termino;
}

