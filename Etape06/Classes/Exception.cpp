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
Exception::Exception(const char* m)
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
void Exception::setErreur(const char* m)
{
	strcpy(message, m);
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
const char* Exception::getMessageErreur() const
{
	return message;
}