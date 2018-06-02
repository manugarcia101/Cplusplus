/* 
 * File:   main.cpp
 * Author: Manu
 *
 * Created on 20 de octubre de 2017, 10:52
 */

//#include <cstdlib>
//#include "ListasSimples.h"
//#include <iostream>
/*
 * 
 */
/**
int main (){
    
    SimpleList<int> MyList;
    int a = 1;
    MyList.insertIni(a);
    MyList.insertIni(a);
    MyList.insertFin(a);
    MyList.final();
    MyList.inicio();
    SimpleList<int> NewList(MyList);
    MyList.borrarIni();
    MyList.borrarFin();
    SimpleList<int>::Iterator MyIterator(NewList.iterator());
    while(!MyIterator.fin()){
        std::cout<<"Dato: "<<MyIterator.dato()<<std::endl;
        MyIterator.siguiente();
    }
    return 0;
}
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include "Diccionario.h"
#include "Listas.h"
using namespace std;
 
Vdinamico<string> mostrarSucesores(Palabra &pal){
    int i=0;
    Vdinamico<string> posiciones;
    ListaEnlazada<std::string> lsuc(pal.sucesores());
    ListaEnlazada<std::string>::Iterador it(lsuc.iterador());
    cout << "Listado Sucesoras de " << pal.GetTermino() << ": " << endl;
    while (!it.fin()){
        posiciones.insertar(it.dato());        
        it.siguiente();
    }
    posiciones.ordenar();
    for (unsigned i=0; i<posiciones.tama(); i++){
        cout << i+1 << " -> " << posiciones[i] << endl;
    }
    return posiciones;   
}


int main(){
     std::string frase,texto;
     unsigned long int total=0;              
     
     try{     
         Vdinamico<string> vpos;
         int x=0,p;
         if (x==0){
          //******** OPCION 1
            Diccionario diccionario;       
            std::cout << " Total de palabras en el archivo: " << diccionario.tama() << std::endl;
            frase = "veloz veloz estamos murcielago veloz hindu veloz cardillo veloz y veloz";
            texto="hindu";
            diccionario.entrena(frase);
            do{
                Palabra pal=diccionario.busca(texto);
                if (pal.GetTermino()=="")
                    std::cout << "Palabra no existe en el diccionario" << std::endl;
                else
                    vpos=mostrarSucesores(pal);
                std::cout << "Elije un numero de palabra o 0-fin: ";
                std::cin >> p;
                if (p!=0)
                    texto=vpos[p-1];
            }while(p!=0);
         }else
              if (x==1){  
                //******** OPCION 2
                   Diccionario dic2("listado-sin-acentos_v2.txt");  
                   std::cout << " Total de palabras en el archivo: " << dic2.tama() << std::endl;
                   frase = "veloz veloz estamos murcielago hindu veloz cardillo y veloz";                   
                   dic2.entrena(frase);
                   texto="veloz";
                   Palabra pal2=dic2.busca(texto);
                   mostrarSucesores(pal2);
                   //dic2.mostrarSuc(texto);
             }else{ 
            
                //******** OPCION 3
               Diccionario dic3("listado-sin-acentos_v2.txt");  
               std::cout << " Total de palabras en el archivo: " << dic3.tama() << std::endl;               
               dic3.usacorpus("corpus_spanish.txt");                           
               texto="y";
               Palabra pal2=dic3.busca(texto);
               mostrarSucesores(pal2);
             }
         
        
     //Tratamiento de errores 
     }catch (std::runtime_error &e){ //std::ifstream::failure &e){
            std::cerr << "Excepcion en fichero: " << e.what() << std::endl;
     }catch (std::bad_alloc &e){
            std::cerr << "No hay memoria suficiente para el objeto dinamico" << std::endl;     
     }catch (ErrorRango &e){
            std::cerr << e.what() << std::endl;
    }
       
    return 0;
    
}
