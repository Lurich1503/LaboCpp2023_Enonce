#ifndef SORTED_ARRAY_LIST_H
#define SORTED_ARRAY_LIST_H

#include <iostream>
using namespace std;
#include "ArrayList.h"

template<class T> class SortedArrayList : public ArrayList<T>
{
	private:
    Cellule<T> *pTete;

	public:
    	SortedArrayList();

    	void insereElement(const T &val); // surcharge de la fonction insereElement
    	T& getElement(int ind) const;
    	void viderListe();
};

#endif