/* 
 * File:   Vector.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:03
 */

#ifndef VDINAMICO_H_INCLUDED
#define VDINAMICO_H_INCLUDED
#include <algorithm>
#include <cmath>
#include <climits>
#include "ErrorRango.h"
#include "ErrorNoDatos.h"
using namespace std;

template<class T>
class Vdinamico {
private:
    void aumenta(); 
    void disminuye(); 
    void tamabase2(unsigned long int &t);
    
    unsigned long int tamal,tamaf;
    T *v;
public:
    Vdinamico();
    Vdinamico(unsigned long int tama);    //,const T &dato
    Vdinamico(const Vdinamico<T> &orig);
    Vdinamico(const Vdinamico<T>& origen, unsigned long int inicio, unsigned long int num);
    ~Vdinamico();
    
    Vdinamico<T> &operator=(const Vdinamico<T> &arr);
    T &operator[](unsigned long int pos);
    //void insertar (unsigned pos,const T &dato);
    void insertar (const T &dato, unsigned long int pos=UINT_MAX);
    T borrar (unsigned long int pos=UINT_MAX);       
    unsigned long int tama();
       
    unsigned long int busquedaDic(const T &dato);
    void ordenar();
      
};

 template<class T>
 Vdinamico<T>::Vdinamico(){
        tamal=0;
        v = new T[tamaf = 1];
 };
    
 template<class T>
 Vdinamico<T>::Vdinamico(unsigned long int tama){   //,const T &dato
         tamal=tama;
         tamabase2(tama); //calculo el tamaño fisico adecuado a potencia de 2
         v = new T[tamaf = tama];
         //for (unsigned i = 0; i <tamal; i++) {
           // v[i] = dato;
         //}
    };
    
template<class T>
Vdinamico<T>::Vdinamico(const Vdinamico<T> &orig):tamal(orig.tamal){
    v = new T[tamaf = orig.tamaf];
    for (unsigned long int i=0; i<tamal; i++) 
        v[i] = orig.v[i];
};
    
template<class T>
Vdinamico<T>::Vdinamico(const Vdinamico<T>& origen, unsigned long int inicio, unsigned long int num){
    if (inicio>=origen.tamal || num+inicio>origen.tamal)
        throw ErrorRango();
    int nuevotama=num;
    tamabase2(nuevotama);
    v = new T[tamaf =nuevotama];
    tamal=num;
    for (unsigned long int c = inicio; c <inicio+num; c++) {
        v[c-inicio] = origen.v[c];
    }      
}
        
template<class T>
Vdinamico<T> &Vdinamico<T>::operator=(const Vdinamico<T> &arr){
    if (this!=&arr){
        delete[] v;
        tamal = arr.tamal;
        v = new T[tamaf=arr.tamaf];
        for (unsigned long int c = 0; c < tamal; c++) {
            v[c] = arr.v[c];
        }
    }
    return *this;
};

template<class T>
T &Vdinamico<T>::operator[](unsigned long int pos){
     if (pos>=tamal)
        throw ErrorRango();
     return v[pos];
};

template<class T>
void Vdinamico<T>::insertar (const T &dato, unsigned long int pos){

    if (pos==UINT_MAX){
        if(tamal==tamaf) {
            aumenta();   
        }
        v[tamal]=dato;
    }else{
        if (pos>tamal)
          throw ErrorRango();
        if(tamal==tamaf) {
            aumenta();   
        }
        if (tamal>0)
            for(long int i=tamal-1, c=0; i>=pos && c<tamal;c++, --i){ 
                v[i+1]=v[i]; 
                
            }
        //v[pos+1]=v[pos];  en caso de poner unsigned en el for
        v[pos]=dato;
    }
    tamal++;
};

template<class T>
T Vdinamico<T>::borrar (unsigned long int pos){
      T aux;
      if (tamal==0)
          throw ErrorNoDatos();
      if (pos==UINT_MAX){
        if(tamal*3<tamaf) {
             disminuye();
        }; 
        aux=v[tamal-1];
      }else{
        if (pos>=tamal)
             throw ErrorRango();
        if(tamal*3<tamaf) {
             disminuye();
        };
        aux=v[pos];
        for(unsigned i=pos;i<tamal-1;i++){
           v[i]=v[i+1];
        }
      }
     tamal--;
     return aux;
};


template<class T>
unsigned long int Vdinamico<T>::tama(){ return tamal; };

template<class T>
Vdinamico<T>::~Vdinamico(){ 
if (v)
    delete []v; };

//privados
template<class T>
void Vdinamico<T>::aumenta(){
    T *vaux;
    vaux= new T[tamaf=tamaf*2];
    for(unsigned i=0;i<tamal;i++)
        vaux[i]=v[i];
    delete []v;
    v=vaux;
}; 
template<class T>
void Vdinamico<T>::disminuye(){
    tamaf=tamaf/2;
    T *vaux = new T[tamaf];
    for(unsigned i=0;i<tamal;i++){
        vaux[i]=v[i];
    };
    delete []v;
    v=vaux;
}; 

template<class T>
void Vdinamico<T>::tamabase2(unsigned long int &t){
    while (log2(t) != round(log2(t))){
        t++;
    }  
}

template<class T>
void Vdinamico<T>::ordenar(){    
    sort(v,v+tamal);
}

template<class T>
unsigned long int Vdinamico<T>::busquedaDic(const T &dato) {
    int inf = 0;
    int sup = tamal - 1;
    int curIn;
    while (inf <= sup) {
        curIn = (inf + sup) / 2;
      
        if (v[curIn] == dato)
            return curIn;
        else    
            if (v[curIn] < dato) 
                inf = curIn + 1;
            else 
                sup = curIn - 1;     
    }
    return -1;
   }
#endif // VESTATICO_H_INCLUDED

