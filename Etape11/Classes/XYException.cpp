#include "XYException.h"
#include <string.h>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
XYException::XYException(void) : Exception()
{
#ifdef DEBUG
	cout << ">>> XYException : constructeur par defaut <<<" << endl;
#endif	
	setCoordonnee(63);
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
XYException::XYException(char c, const char* m) : Exception(m)
{
#ifdef DEBUG
	cout << ">>> XYException : constructeur d'initialisation <<<" << endl;
#endif
	setCoordonnee(c);
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
XYException::XYException(const XYException& e) : Exception(e)
{
#ifdef DEBUG
	cout << ">>> XYException : constructeur de copie <<<" << endl;
#endif
	setCoordonnee(e.getCoordonnee());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
XYException::~XYException()
{
#ifdef DEBUG
	cout << ">>> XYException : destructeur <<<" << endl;
#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void XYException::setCoordonnee(char c)
{
	coordonnee = c;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
char XYException::getCoordonnee() const 
{
	return coordonnee;
}