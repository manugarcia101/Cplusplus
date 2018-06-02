/* 
 * File:   ErrorRango.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:12
 */

#ifndef ERRORRANGO_H
#define	ERRORRANGO_H

#include <exception>

using namespace std;

class ErrorRango:public exception{
public:
    const char* what() const throw()
    {
        return "\nError: Posicion del array fuera de rango";
    }
};

#endif	/* ERRORRANGO_H */

