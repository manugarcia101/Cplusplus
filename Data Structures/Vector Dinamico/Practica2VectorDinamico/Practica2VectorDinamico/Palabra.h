#pragma once
#include <string>
#include <stdexcept>
class Palabra
{
private:
	std::string Termino;
public:
	Palabra(std::string termino="");
	Palabra(const Palabra& orig);
	virtual ~Palabra();

	void set_Termino(std::string T);
	std::string getTermino();
	Palabra& operator= (const Palabra& orig);
	bool operator< (const Palabra& orig);
};

