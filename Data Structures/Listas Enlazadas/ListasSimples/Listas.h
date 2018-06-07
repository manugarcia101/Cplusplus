/* 
 * File:   Listas.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:10
 */

#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

using namespace std;
#include <iostream>

//ANTICIPAMOS EL USO DE LA LISTA EN EL ITERADOR
//template<class T>
//class ListaEnlazada;


// ************* CLASE NODO  **************
template<class T>
class Nodo {
 
public:
    T dato;
    Nodo *sig;
    Nodo(const T &aDato, Nodo *aSig = 0):   dato(aDato), sig(aSig) {}
    ~Nodo() {}
};


/* ************* CLASE ITERADOR   **************
template<class T>
class Iterador {
    Nodo<T> *nodo;
  //  friend class ListaEnlazada<T>;
public:
    Iterador(Nodo<T> *aNodo) : nodo(aNodo) {}
    bool fin() { return nodo == 0; }
    void siguiente() {
        nodo = nodo->sig;
    }
    T &dato() { return nodo->dato; }
    ~Iterador() {}
};*/


// ************* CLASE LISTA ENLAZADA  **************
template<class T>
class ListaEnlazada {
    Nodo<T> *cabecera, *cola;

public:
    //  ************* CLASE ITERADOR   **************
        template<class U>
        class Iterador {
            Nodo<U> *nodo;
            friend class ListaEnlazada<T>;
        public:          
            Iterador(Nodo<U> *aNodo) : nodo(aNodo) {}
            bool fin() { return nodo == 0; }
            void siguiente() {
                nodo = nodo->sig;
            }
            U &dato() {  return nodo->dato; }
            Nodo<U> *vernodo(){ return nodo; }
            ~Iterador() {}
            };

    ListaEnlazada() : cabecera(0), cola(0) {}
    ~ListaEnlazada();
    ListaEnlazada(const ListaEnlazada<T> &l);
    ListaEnlazada &operator=(const ListaEnlazada<T> &l);
    Iterador<T> iterador() const { return Iterador<T> (cabecera); }
    void insertarInicio(const T &dato);
    void insertarFinal(const T &dato);
    void insertar( Iterador<T> &p,const T &dato);
    void borrarInicio();
    void borrarFinal();
    void borrar(Iterador<T> &i);
   
    T &inicio(){ if (cabecera) return cabecera->dato;};
    T &fin(){ if (cola) return cola->dato;};

    // T leer(Iterador<T> &i);
    // void destruyeLista();
    // T leer(int n);
    // void imprimir() const;
};


//CONSTRUCTOR DE COPIA
template<class T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T> &l){
    Iterador<T> i= l.iterador();
    cabecera=0;
    cola=0;
    while (!i.fin()){
        insertarFinal(i.dato());
        i.siguiente();
    }
}

// DESTRUCTOR
template<class T>
ListaEnlazada<T>::~ListaEnlazada(){
    if (cabecera) {
        Iterador<T> i= iterador();
        while ( !i.fin() ){
              i.siguiente();
              borrarInicio();  //borro puntero a nodo
        }
    }
}

//OPERADOR DE ASIGNACION
template<class T>
ListaEnlazada<T> &ListaEnlazada<T>::operator=(const ListaEnlazada<T> &l){
   
    if (l.cabecera!=cabecera){
        Iterador<T> j= l.iterador();
      //  destruyeLista();
        if (cabecera) {
            Iterador<T> i= iterador();
            while ( !i.fin() ){
                  i.siguiente();
                  borrarInicio();  //borro puntero a nodo
            }
        }
        cabecera=0;
        cola=0;
        while (!j.fin()){
            insertarFinal(j.dato());
            j.siguiente();
        }
    }
    return (*this);

}
    
template<class T>
void ListaEnlazada<T>::insertarInicio(const T &dato){
Nodo<T> *nuevo;
nuevo = new Nodo<T>(dato, cabecera);
//tama++;
// Caso especial: si la lista estaba vac�a poner la cola apuntando al nodo
if (cola == 0)
    cola = nuevo;

cabecera = nuevo;
};

template<class T>
void ListaEnlazada<T>::insertarFinal(const T &dato){
Nodo<T> *nuevo;
nuevo = new Nodo<T>(dato, 0);
//tama++;
if (cola != 0)
    cola->sig = nuevo;
// Caso especial: si la lista estaba vac�a, poner la cabecera apuntando al nodo
if (cabecera == 0)
    cabecera = nuevo;
cola = nuevo;
}

template<class T>
void ListaEnlazada<T>::insertar( Iterador<T> &p,const T &dato){
    
        if (p.vernodo()==cabecera || cabecera==cola){
            insertarInicio(dato);
            return;
        }
            //if (cabecera != cola) {
           // tama++;
            Nodo<T> *anterior = 0;
          
            anterior = cabecera;
            while (anterior->sig != p->nodo)//.vernodo())
                anterior = anterior->sig;
           
            Nodo<T> *nuevo;
            nuevo = new Nodo<T>(dato, p.vernodo());
            anterior->sig = nuevo;
           
}

template<class T>
void ListaEnlazada<T>::borrarInicio(){

    if  (cabecera!=0){
        Nodo<T> *borrado = cabecera;
        cabecera= cabecera->sig;
        delete borrado;
        // Caso especial al
        // borrar el �ltimo nodo
        if (cabecera == 0)
            cola = 0;
    }
}

template<class T>
void ListaEnlazada<T>::borrarFinal(){
    Nodo<T> *anterior = 0;      
    if ( cabecera != cola && cabecera) {  //miro si hay uno al menos
        anterior = cabecera;
        while (anterior->sig != cola)
            anterior = anterior->sig;

        delete cola;   // sino OJO cuando est� vac�a intenta un delete absurdo!!
        cola = anterior;
        if (anterior != 0)
            anterior->sig = 0;
        else
            cabecera= 0;
    }else
        borrarInicio();
}

template<class T>
void ListaEnlazada<T>::borrar(Iterador<T> &p){
    Nodo<T> *anterior;
    if (!p.fin()) {
        if (p.vernodo()==cabecera){ 
            borrarInicio();
            return;
        }
        if (p.vernodo()==cola){
            borrarFinal();
            return;
        }
        anterior = cabecera;
        while (anterior->sig != p.vernodo())
            anterior = anterior->sig;
        anterior->sig = p.vernodo()->sig;
        delete p.vernodo();
    }
}


/*DEVUELVE EL CONTENIDO DE UN ITERADOR
template<class T>
T ListaEnlazada<T>::leer(Iterador<T> &p) {
    return p.dato();
}*/

/*CALCULA EL N� DE ELEMENTOS
template<class T>
unsigned ListaEnlazada<T>::tam() const {   
    return tama;
}*/


/*DESTRUYE LA LISTA
template<class T>
void ListaEnlazada<T>::destruyeLista(){
 if (cabecera) {
    Iterador<T> i= iterador();
    while ( !i.fin() ){
          i.siguiente();
          borrarInicio();  //borro puntero a nodo
    }
 }
}
*/
/*BUSCA POSICIONAL
template<class T>
T ListaEnlazada<T>::leer(int n) {
Nodo<T> *nodo = cabecera;
while (n-- > 0 && nodo != 0) {
    nodo = nodo->sig;
}
if (nodo != 0)
    return nodo->dato;
return 0;
}*/

/*template<class T>
void ListaEnlazada<T>::imprimir() const {
Iterador<T> i= this->iterador();
    while (!i.fin()) {   //acceso a atributo privado... al ser friend, debe hacerse con fin
        cout << i.dato() << endl;
        i.siguiente();
    }
}*/

#endif // LISTAS_H_INCLUDED
