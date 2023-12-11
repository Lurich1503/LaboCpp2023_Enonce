#include "RGBException.h"
#include <string.h>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
RGBException::RGBException(void) : Exception()
{
#ifdef DEBUG
	cout << ">>> RGBException : constructeur par defaut <<<" << endl;
#endif	
	setValeur(-1);
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
RGBException::RGBException(int v, const string m) : Exception(m)
{
#ifdef DEBUG
	cout << ">>> RGBException : constructeur d'initialisation <<<" << endl;
#endif
	setValeur(v);
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
RGBException::RGBException(const RGBException& e) : Exception(e)
{
#ifdef DEBUG
	cout << ">>> RGBException : constructeur de copie <<<" << endl;
#endif
	setValeur(e.getValeur());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
RGBException::~RGBException()
{
#ifdef DEBUG
	cout << ">>> RGBException : destructeur <<<" << endl;
#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void RGBException::setValeur(int v)
{
	valeur = v;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int RGBException::getValeur() const 
{
	return valeur;
}
