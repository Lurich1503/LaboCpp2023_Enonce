#ifndef ITERATEUR_H
#define ITERATEUR_H

#include "ArrayList.h"


template<class T>
class Iterateur
{
	private:
		ArrayList<T> &p;
		Cellule<T> *pCurliste;
	public: 
		Iterateur (ArrayList<T> &l) : p(l), pCurliste(l.pTete) {};
		void reset();
		bool end();
		void operator++();
		void operator++(int);
		operator T() const;
		T& operator&(void);

};

#endif
