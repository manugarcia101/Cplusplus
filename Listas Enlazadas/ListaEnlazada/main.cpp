/* 
 * File:   main.cpp
 * Author: Manu
 *
 * Created on 11 de octubre de 2017, 17:01
 */

#include <cstdlib>
#include "ListaEnlazadaSimple.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ListaEnlazada<int> MiLista;
    int a = 1;
    int b = 2;
    int c = 4;
    Nodo<int> MyNode(a);
    Iterador<int> MyIterator = MiLista.iterador();
    MiLista.insertarInicio(a);
    MiLista.insertarInicio(b);
    MiLista.insertar(MyIterator, c);
    MiLista.inicio();
    //MiLista.insertarFinal(b);
    MiLista.final();
    ListaEnlazada<int> NuevaLista(MiLista);
    //MiLista.borrarInicio();
    //MiLista.borrarFinal();
    
    
    
    
    
    
    return 0;
}

