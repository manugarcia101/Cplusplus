/* 
 * File:   Palabra.cpp
 * Author: Manu
 * 
 * Created on 23 de octubre de 2017, 21:04
 */

#include "Palabra.h"
//#include "listas.h"

   // Palabra::Palabra(): termino(""), siguientes() {}
    Palabra::Palabra(const Palabra& orig):termino(orig.termino), siguientes(orig.siguientes) {}
    Palabra::Palabra(std::string _termino):termino(_termino), siguientes() {}
    Palabra::~Palabra(){}

    Palabra& Palabra::operator=(const Palabra &orig){
       if (this!=&orig){           
           termino=orig.termino;
           siguientes=orig.siguientes;
       }
       return *this;
    }
    std::string Palabra::GetTermino() const {
        return termino;
    }

    void Palabra::SetTermino(std::string _termino) {
        this->termino = _termino;
    }
    
    bool Palabra::operator==(const Palabra &orig) {
        return  termino==orig.termino;// return (termino.compare(orig.termino)==0);
    }
    
    bool Palabra::operator<(const Palabra &orig) {
        return termino<orig.termino;
    }
    
    void Palabra::nuevoSucesor( std::string &termino){
        ListaEnlazada<Sucesor>::Iterador it(siguientes.iterador());
        while (!it.fin()){
            if (termino==it.dato().GetTermino()){
                it.dato().SetNumOcurrencias(it.dato().GetNumOcurrencias()+1);
                return;
            }
            it.siguiente();
        }
        Sucesor sc(termino,1);
        siguientes.insertarFinal(sc);        
    }
 
    
    ListaEnlazada<std::string> Palabra::sucesores(){
        ListaEnlazada<Sucesor>::Iterador it(siguientes.iterador());
        ListaEnlazada<std::string> lista;
        while (!it.fin()){
            lista.insertarFinal(to_string(it.dato().GetNumOcurrencias())+" - "+it.dato().GetTermino());
            it.siguiente();
        }
        return lista;
    }

