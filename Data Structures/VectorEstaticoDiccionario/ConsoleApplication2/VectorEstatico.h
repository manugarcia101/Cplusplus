#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Palabra.h"
using namespace std;
class VectorEstatico
{
public:
	VectorEstatico();
	VectorEstatico(const VectorEstatico& orig);
	virtual ~VectorEstatico();

	Palabra& operator[](int i);
	void asigna(const Palabra &p,unsigned long int pos);
	int devuelveTamanio();

private:
	static const int tam = 80383;
	Palabra *V;
};

