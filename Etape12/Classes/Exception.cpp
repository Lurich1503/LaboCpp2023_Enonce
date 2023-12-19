#include "Exception.h"
#include <string.h>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
Exception::Exception(void)
{
#ifdef DEBUG
	cout << ">>> Exception : constructeur par defaut <<<" << endl;
#endif
	setErreur("???");
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
Exception::Exception(const string m)
{
#ifdef DEBUG
	cout << ">>> Exception : constructeur d'initialisation <<<" << endl;
#endif
	setErreur(m);
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
Exception::Exception(const Exception& e)
{
#ifdef DEBUG
	cout << ">>> Exception : constructeur de copie <<<" << endl;
#endif
	setErreur(e.getMessageErreur());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
Exception::~Exception()
{
#ifdef DEBUG
	cout << ">>> Exception : destructeur <<<" << endl;
#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void Exception::setErreur(const string m)
{
	message = m;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
const string Exception::getMessageErreur() const
{
	return message;
}