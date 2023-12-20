#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "ArrayList.h"


template<class T>
class Iterateur
{
	private:
		const ArrayList<T> &p;
		Cellule<T> *pCurliste;
	public: 
		Iterateur (const ArrayList<T> &l) : p(l), pCurliste(l.pTete) {};
		void reset();
		bool end();
		void operator++();
		void operator++(int);
		operator T() const;
		T& operator&(void) const;

};

#endif
