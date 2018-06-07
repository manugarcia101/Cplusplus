#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Palabra
{
private:
	std::string Termino;
public:
	Palabra(string termino="");
	Palabra(const Palabra& orig);
	virtual ~Palabra();

	void set_Termino(string T);

	string get_Termino();

	Palabra& operator= (const Palabra& orig);

	bool operator<(const Palabra& orig) {
		return Termino < orig.Termino; //Funcion inline
	}
};

