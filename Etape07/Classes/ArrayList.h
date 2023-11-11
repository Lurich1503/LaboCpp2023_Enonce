#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
using namespace std;


template<class T> struct Cellule //structure de Cellule
{
	T valeur;
	Cellule<T> *suivant;
};

template<class T> class Iterateur; //classe declaree mais pas encore definie

template<class T> class ArrayList
{
	private:
		Cellule<T> *pTete;

	public: 
		ArrayList(void);
		ArrayList(const ArrayList<T> &); //constructeur de copie
		~ArrayList();

		bool estVide();

		int getNombreElements() const;

		void Affiche() const;

		void insereElement(const T & val);

		T& getElement(int ind) const;

		T retireElement(int ind);

		ArrayList<T>& operator=(const ArrayList<T>&);

		friend class Iterateur<T>;

};

template<class T>
class Iterateur
{
	private:
		ArrayList<T> &p;
		Cellule<T> *pCurliste;
	public: 
		Iterateur (ArrayList<T> &l);
		void reset();
		bool end();
		void operator++();
		void operator++(int);
		operator T() const;
		T& operator&(void);

};

#endif