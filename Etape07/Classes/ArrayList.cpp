#include "ArrayList.h"
#include <string.h>
#include "ArrayListException.h"

/******* Class ArrayList*******/

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
template <class T> 
ArrayList<T>::ArrayList(void)
{
#ifdef DEBUG
	cout << ">>> ArrayList : constructeur par defaut <<<" << endl;
#endif

	pTete = NULL;
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> &autreListe)
{
#ifdef DEBUG
	cout << ">>> ArrayList : constructeur de copie <<<" << endl;
#endif

	pTete = NULL;
	Cellule<T> *pCur = autreListe.pTete;
	Cellule<T> *pFin = NULL;

	while(pCur != NULL)
	{
		Cellule<T> *nouvelleCellule = new Cellule<T>{pCur->valeur, NULL};

		if(pTete == NULL)
		{
			pTete = nouvelleCellule;
		}
		else
		{
			pFin->suivant = nouvelleCellule;
		}

		pFin = nouvelleCellule;
		pCur = pCur->suivant; 
	}
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
template <class T>
ArrayList<T>::~ArrayList()
{
#ifdef DEBUG
	cout << ">>> ArrayList : destructeur <<<" << endl;
#endif

	Cellule<T> *pCur, *pPrec;
	pCur = pTete;
	while(pCur != NULL)
	{
		pPrec = pCur;
		pCur = pCur->suivant;
		delete pPrec;
	}

}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
template <class T>
int ArrayList<T>::getNombreElements() const
{
	int nbElem = 0;
	Cellule<T> *pCur = pTete;

	while(pCur != NULL)
	{
		nbElem ++;
		pCur = pCur->suivant;
	}

	return nbElem;
}

template <class T>
T& ArrayList<T>::getElement(int ind) const
{
	if(ind<0 || ind >= getNombreElements() || pTete == NULL)
	{
		throw ARRAYLISTException(ind, "indice invalide ou liste inexistante!");
	}

	Cellule<T> *pCur = pTete;
    for (int i = 0; i < ind; i++) 
    {
        pCur = pCur->suivant;
    }

    return pCur->valeur;
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
template <class T>
bool ArrayList<T>::estVide()
{
	if(pTete == NULL)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

template <class T>
void ArrayList<T>::Affiche() const
{
	Cellule<T> *pCur = pTete;

	cout << "(";
	while(pCur != NULL)
	{
		cout << pCur->valeur << " ";
		pCur = pCur->suivant;
	}
	cout << ")";
}

template <class T>
void ArrayList<T>::insereElement(const T & val) //inserer en fin de liste 
{
	Cellule<T> *nouvelleCellule = new Cellule<T>;

	nouvelleCellule->valeur = val;
	nouvelleCellule->suivant = NULL;

	if(pTete == NULL)
	{
		pTete = nouvelleCellule;
	}
	else
	{
		Cellule<T> *pCur = pTete;
		while(pCur->suivant != NULL)
		{
			pCur = pCur->suivant;
		}
		pCur->suivant = nouvelleCellule;
	}
}

template <class T>
T ArrayList<T>::retireElement(int ind)
{
	if(ind<0 || ind >= getNombreElements() || pTete == NULL)
	{
		throw ARRAYLISTException(ind, "indice invalide ou liste inexistante!");
	}

	Cellule<T> *pCur = pTete;
    Cellule<T> *pPrec = NULL;

    for (int i = 0; i < ind; i++) 
    {
        pPrec = pCur;
        pCur = pCur->suivant;
    }

    if (pPrec != NULL) 
    {
        pPrec->suivant = pCur->suivant;
    } 
    else 
    {
        pTete = pCur->suivant;
    }

    T valeurRetiree = pCur->valeur;
    delete pCur;

    return valeurRetiree;
}


//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &autreListe)
{
	Cellule<T> *pCur = autreListe.pTete;

	while(pCur != NULL)
	{
		insereElement(pCur->valeur);
		pCur = pCur->suivant;
	}
	return *(this);
}

/******* Class Iterateur *******/


template<class T>
Iterateur<T>::Iterateur (ArrayList<T> &l):p(l), pCurliste(l.pTete)
{

}

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
template class ArrayList<int>;
template class Iterateur<int>;
#include "Couleur.h"
template class ArrayList<Couleur>;
template class Iterateur<Couleur>;
