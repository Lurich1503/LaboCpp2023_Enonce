#include "Iterateur.h"

template<class T>
void Iterateur<T>::reset()
{
	pCurliste = p.pTete;
}

template<class T>
bool Iterateur<T>::end()
{
	return pCurliste == 0;
}

template<class T>
void Iterateur<T>::operator++()
{
	if(pCurliste)
	{
		pCurliste = pCurliste->suivant;
	}
}

template<class T>
void Iterateur<T>::operator++(int)
{
	return operator++();
}

template<class T>
Iterateur<T>::operator T() const
{
	return pCurliste->valeur;
}

template<class T>
T& Iterateur<T>::operator& (void)
{
	return pCurliste->valeur;
}


//----------------------------------------------
//----------INSTANCIATION DES TEMPLATES
//----------------------------------------------
template class Iterateur<int>;
#include "Couleur.h"
template class Iterateur<Couleur>;