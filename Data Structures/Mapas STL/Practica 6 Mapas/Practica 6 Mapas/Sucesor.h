#pragma once
#include <string>
class Sucesor
{
private:
	int NumOcurrencias;
	std::string Termino;
public:
	Sucesor();
	Sucesor(int numOcurrencias, std::string termino);
	Sucesor(const Sucesor &orig);
	~Sucesor();

	void set_NumOcurrencias(int n);
	int get_NumOcurrencias();
	void set_Termino(std::string Termino);
	std::string get_Termino();
	Sucesor& operator=(const Sucesor &orig);
	bool operator<(const Sucesor &orig) const;
	bool operator>(const Sucesor &orig);
	bool operator==(const Sucesor &orig);
};
