#include "SortedArrayList.h"

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
template<class T>
SortedArrayList<T>::SortedArrayList() // constructeur par defaut de arraylist
{
#ifdef DEBUG
	cout << ">>> SortedArrayList : constructeur par defaut <<<" << endl;
#endif

	pTete = NULL;
}  


//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
template<class T>
void SortedArrayList<T>::insereElement(const T &val)
{
    // Créer une nouvelle cellule avec la valeur fournie
    Cellule<T> *nouvelleCellule = new Cellule<T>;

    nouvelleCellule->valeur = val;
	nouvelleCellule->suivant = NULL;

    // Si la liste est vide ou si la valeur est inférieure à la première valeur
    if (pTete == NULL || val < pTete->valeur)
    {
        nouvelleCellule->suivant = pTete;
        pTete = nouvelleCellule;
    }
    else
    {
        Cellule<T> *pCur = pTete;
        Cellule<T> *pPrec = NULL;

        // Trouver le bon emplacement pour insérer la nouvelle cellule
        while (pCur != NULL && pCur->valeur < val)
        {
            pPrec = pCur;
            pCur = pCur->suivant;
        }

        // Insérer la nouvelle cellule à la bonne position
        nouvelleCellule->suivant = pCur;

        if(pPrec == NULL)
        {
        	pTete = nouvelleCellule;
        }
        else
        {
        	pPrec->suivant = nouvelleCellule;
        }
    }
}

template <class T>
T& SortedArrayList<T>::getElement(int ind) const
{
	Cellule<T> *pCur = pTete;
    for (int i = 0; i < ind; i++) 
    {
        pCur = pCur->suivant;
    }

    return pCur->valeur;
}


template<class T>
void SortedArrayList<T>::viderListe()
{
    Cellule<T> *pCur = pTete;
    Cellule<T> *pSuivant = NULL;

    while (pCur != NULL)
    {
        pSuivant = pCur->suivant;
        delete pCur;
        pCur = pSuivant;
    }

    // Réinitialisez la tête de la liste à NULL
    pTete = NULL;
}


//----------------------------------------------
//----------INSTANCIATION DES TEMPLATES
//----------------------------------------------
template class SortedArrayList<int>;
