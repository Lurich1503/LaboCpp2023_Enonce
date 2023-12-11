#include "ArrayListException.h"
#include <string.h>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
ARRAYLISTException::ARRAYLISTException(void) : Exception()
{
#ifdef DEBUG
	cout << ">>> ARRAYLISTException : constructeur par defaut <<<" << endl;
#endif	
	setValeur(-1);
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
ARRAYLISTException::ARRAYLISTException(int v, const string m) : Exception(m)
{
#ifdef DEBUG
	cout << ">>> ARRAYLISTException : constructeur d'initialisation <<<" << endl;
#endif
	setValeur(v);
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
ARRAYLISTException::ARRAYLISTException(const ARRAYLISTException& e) : Exception(e)
{
#ifdef DEBUG
	cout << ">>> ARRAYLISTException : constructeur de copie <<<" << endl;
#endif
	setValeur(e.getValeur());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
ARRAYLISTException::~ARRAYLISTException()
{
#ifdef DEBUG
	cout << ">>> ARRAYLISTException : destructeur <<<" << endl;
#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void ARRAYLISTException::setValeur(int v)
{
	valeur = v;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int ARRAYLISTException::getValeur() const 
{
	return valeur;
}