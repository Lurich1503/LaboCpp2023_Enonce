#include "Image.h"
#include <string.h>
#include "MyQT.h"

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
Image::Image(void)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur par defaut <<<" << endl;
#endif
	setId(-1);
	nom = NULL;
	setNom("???");
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
Image::Image(int i,const char *n)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur d'initialisation <<<" << endl;
#endif
	setId(i);
	nom = NULL;
	setNom(n);
}

Image::Image(int i,const char *n, const Dimension& d)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur d'initialisation avec dimension <<<" << endl;
#endif
	setId(i);
	nom = NULL;
	setNom(n);
	setDimension(d);
}


//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
Image::Image(const Image& p)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur de copie <<<" << endl;
#endif
	setId(p.getId());
	nom = NULL;
	setNom(p.getNom());
	setDimension(p.getDimension());
}

Image::Image(const char *n)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur de copie d'importation de fichier" << endl;
#endif

	setId(-1);
	nom = NULL;
	setNom("Défaut");
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
Image::~Image()
{
#ifdef DEBUG
	cout << ">>> Image : destructeur <<<" << endl;
#endif

	if (nom)
		delete nom;
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void Image::setId(int i)
{
	id = i;
}

void Image::setNom(const char *n)
{
	if (nom) delete nom;
	if (n == NULL)
	{
		nom = NULL;
		return;
	}
	nom = new char[strlen(n) + 1];
	strcpy (nom, n);
}

void Image::setDimension(const Dimension& d)
{
	dimension.setLargeur(d.getLargeur());
	dimension.setHauteur(d.getHauteur());
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int Image::getId() const
{
	return id;
}

const char * Image::getNom() const
{
	return nom;
}

Dimension Image::getDimension() const
{
	return dimension;
}


//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
Image& Image::operator=(const Image& p)
{
#ifdef DEBUG
	cout << ">>> Image : operator=" << endl;
#endif

	setId(p.getId());
	setNom(p.getNom());
	dimension = p.getDimension();

	return (*this);
}