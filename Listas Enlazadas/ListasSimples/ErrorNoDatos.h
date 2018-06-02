/* 
 * File:   ErrorNoDatos.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:11
 */

#ifndef ERRORNODATOS_H
#define	ERRORNODATOS_H

#include <exception>

using namespace std;

class ErrorNoDatos:public exception{
public:
    const char* what() const throw()
    {
        return "\nError: El array no contiene elementos";
    }
};

#endif	/* ERRORNODATOS_H */
