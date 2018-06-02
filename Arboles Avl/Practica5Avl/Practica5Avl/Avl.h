#pragma once
#include <vector>
#include <stdexcept>
template <typename T>
class Nodo {
public:
	Nodo<T> *izq, *dcha;
	T dato;
	char balanceo;

	Nodo(T &elemento) :izq(0), dcha(0), balanceo(0), dato(elemento) {}
	Nodo(const Nodo<T> &orig) :izq(0), dcha(0), bal(orig->bal), dato(orig->dato){}
	Nodo<T> &operator=(const Nodo<T> &orig);
	virtual ~Nodo() {}
};
template <typename T>
Nodo<T>& Nodo<T>::operator=(const Nodo<T> &orig) {
	this->izq = orig.izq;
	this->dcha = orig.dcha;
	this->balanceo = orig.balanceo;
	this->dato = orig.dato;
}
template <typename U>
class Avl {
	Nodo<U> *raiz;
private:
	void constructorCopiaPrivado(Nodo<U>* &raiz, Nodo<U> *orig);
	void destructorPrivado(Nodo<U>* &x);

	int insertaPrivado(Nodo<U>* &c, U &dato);
	Nodo<U>* buscaPrivado(U& dato, Nodo<U> *p);
	void inordenPrivado(Nodo<U> *p, int nivel);
	unsigned int numElementosPrivado(Nodo<U> *p);
	void alturaPrivada(Nodo<U> *p, int nivel, int &altura);
	void rotacionDcha(Nodo<U>* &p);
	void rotacionIzq(Nodo<U>* &p);

public:
	Avl();
	Avl(const Avl<U>& orig);
	virtual ~Avl();

	bool inserta(U &dato);
	U& buscaEspecial(U& dato, U* &result);
	bool busca(U& dato);
	Avl<U>& operator= (const Avl<U>& orig);
	void recorreInorden();
	unsigned int numElementos();
	int altura();
};
template <typename U>
void Avl<U>::constructorCopiaPrivado(Nodo<U>* &raiz, Nodo<U> *orig) {
	if (orig != 0) {
		raiz = new Nodo<U>(orig->dato);
		constructorCopiaPrivado(raiz->izq, orig->izq);
		constructorCopiaPrivado(raiz->dcha, orig->dcha);
	}
	else {
		raiz = 0;
	}
}
template <typename U>
void Avl<U>::destructorPrivado(Nodo<U>* &x) {
	if (x) {
		destructorPrivado(x->izq);
		destructorPrivado(x->dcha);
		delete x;
		x = 0;
	}
}
template <typename U>
int Avl<U>::insertaPrivado(Nodo<U>* &c, U &dato) {
	Nodo<U> *p = c;
	int deltaH = 0;
	if (p == 0) {
		p = new Nodo<U>(dato);
		c = p;
		deltaH = 1;
	}
	else if (dato > p->dato) {
		if (insertaPrivado(p->dcha, dato)) {
			p->balanceo--;
			if (p->balanceo == -1) deltaH = 1;
			else if (p->balanceo == -2) {
				if (p->dcha->balanceo == 1) rotacionDcha(p->dcha);
				rotacionIzq(c);
			}
		}
	}
	else if (dato < p->dato) {
		if (insertaPrivado(p->izq, dato)) {
			p->balanceo++;
			if (p->balanceo == 1) deltaH = 1;
			else if (p->balanceo == 2) {
				if (p->izq->balanceo == -1) rotacionIzq(p->izq);
				rotacionDcha(c);
			}
		}
	}
	return deltaH;
}
template <typename U>
Nodo<U> *Avl<U>::buscaPrivado(U& dato, Nodo<U> *p) {
	if (p == 0)
		return 0;
	else if (dato < p->dato)
		return buscaPrivado(dato, p->izq);
	else if (dato > p->dato)
		return buscaPrivado(dato, p->dcha);
	else return p;
}
template <typename U>
void Avl<U>::rotacionDcha(Nodo<U>* &p) {
	Nodo<U> *q = p, *l;
	p = l = q->izq;
	q->izq = l->dcha;
	l->dcha = q;
	q->balanceo--;
	if (l->balanceo > 0) q->balanceo -= l->balanceo;
	l->balanceo--;
	if (q->balanceo < 0) l->balanceo -= -q->balanceo;
}
template <typename U>
void Avl<U>::rotacionIzq(Nodo<U>* &p) {
	Nodo<U> *q = p, *r;
	p = r = q->dcha;
	q->dcha = r->izq;
	r->izq = q;
	q->balanceo++;
	if (r->balanceo < 0) q->balanceo += -r->balanceo;
	r->balanceo++;
	if (q->balanceo > 0) r->balanceo += q->balanceo;
}
template <typename U>
void Avl<U>::inordenPrivado(Nodo<U> *p, int nivel) {
	if (p) {
		inordenPrivado(p->izq, nivel + 1); 
		p->dato.MuestraPalabra(std::cout);
		std::cout << "Procesando nodo en el nivel: " << nivel << std::endl;
		inordenPrivado(p->dcha, nivel + 1);
	}
}
template <typename U>
unsigned int Avl<U>::numElementosPrivado(Nodo<U> *p) {
	if (p != 0) {
		return numElementosPrivado(p->izq) + numElementosPrivado(p->dcha) + 1;
	}
	else {
		return 0;
	}
}
template <typename U>
void Avl<U>::alturaPrivada(Nodo<U> *p, int nivel, int &altura) {
	if (p) {
		alturaPrivada(p->izq, nivel + 1, altura);
		if (p->izq == 0 && p->dcha == 0)
			if (nivel > altura) altura = nivel;
		alturaPrivada(p->dcha, nivel + 1, altura);
	}
}
template <typename U>
Avl<U>::Avl() {
	raiz = 0;
}
template <typename U>
Avl<U>::Avl(const Avl<U>& orig) :raiz(0) {
	constructorCopiaPrivado(this->raiz, orig.raiz);
}
template <typename U>
Avl<U>::~Avl() {
	destructorPrivado(raiz);
}
template <typename U>
U& Avl<U>::buscaEspecial(U& dato, U* &result) {
	Nodo<U> *p = buscaPrivado(dato, raiz);
	if (p != 0) {
		result = &(p->dato);
		return (p->dato);
	}
	throw std::logic_error("NO ENCONTRADO");
}
template <typename U>
bool Avl<U>::busca(U& dato) {
	Nodo<U> *p = buscaPrivado(dato, raiz);
	if (p != 0) {
		return true;
	}
	return false;
}
template <typename U>
bool Avl<U>::inserta(U &dato) {
	return insertaPrivado(raiz, dato);
}
template <typename U>
Avl<U>& Avl<U>::operator= (const Avl<U>& orig) {
	if (this != &orig) {
		destructorPrivado(raiz);
		constructorCopiaPrivado(raiz, orig.raiz);
	}
	return *this;
}
template <typename U>
void Avl<U>::recorreInorden() {
	inordenPrivado(raiz, 1);
}
template <typename U>
unsigned int Avl<U>::numElementos() {
	return numElementosPrivado(raiz);
}
template <typename U>
int Avl<U>::altura() {
	int auxiliar = 0;
	alturaPrivada(raiz, 0, auxiliar);
	return auxiliar;
}