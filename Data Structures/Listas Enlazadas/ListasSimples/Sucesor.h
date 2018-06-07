/* 
 * File:   Sucesor.h
 * Author: Manu
 *
 * Created on 23 de octubre de 2017, 21:04
 */

#ifndef SUCESOR_H
#define SUCESOR_H

#include <string>
using namespace std;
class Sucesor {
public:
    Sucesor(const std::string &_termino="--", unsigned int oc=0);
    Sucesor(const Sucesor& orig);
    ~Sucesor();
    void SetNumOcurrencias(unsigned int numOcurrencias);
    unsigned int GetNumOcurrencias() const;
    void SetTermino(std::string termino);
    std::string GetTermino() const;
    
    bool operator<(const Sucesor &orig){
        return termino<orig.termino;
    }
    
private:
    std::string termino;
    unsigned int numOcurrencias;

};

#endif /* SUCESOR_H */

