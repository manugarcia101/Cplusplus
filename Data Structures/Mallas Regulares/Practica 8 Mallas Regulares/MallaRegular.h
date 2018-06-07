#pragma once
#include <vector>

template <typename T>
class MallaRegular {
public:
	
	MallaRegular();
	//MallaRegular();//Hacer este por parámetros
	MallaRegular(const MallaRegular &orig);
	~MallaRegular();
	
	void operator=(const MallaRegular &orig);
	
	vector<T> buscarRango(float rxmin, float rymin, float rxmax, float rymax);
	unsigned numElementos();
	unsigned maxElementosEnCelda();
	float promedioElementosPorCelda();

private:

	

};