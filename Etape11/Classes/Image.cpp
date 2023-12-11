#include "Image.h"
#include <string.h>
#include "MyQT.h"
#include <fstream>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
Image::Image(void)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur par defaut <<<" << endl;
#endif
	setId(-1);
	setNom("???");
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
Image::Image(int i,const string n)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur d'initialisation <<<" << endl;
#endif
	setId(i);
	setNom(n);
}

Image::Image(int i,const string n, const Dimension& d)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur d'initialisation avec dimension <<<" << endl;
#endif
	setId(i);
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
	setNom(p.getNom());
	setDimension(p.getDimension());
}

Image::Image(const string n)
{
#ifdef DEBUG
	cout << ">>> Image : constructeur de copie d'importation de fichier" << endl;
#endif

	setId(-1);
	setNom(n);
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
Image::~Image()
{
#ifdef DEBUG
	cout << ">>> Image : destructeur <<<" << endl;
#endif

}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void Image::setId(int i)
{
	id = i;
}

void Image::setNom(const string n)
{
	nom = n;
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

const string Image::getNom() const
{
	return nom;
}

Dimension Image::getDimension() const
{
	return dimension;
}


//----------------------------------------------
//------------------FLUX
//----------------------------------------------
void Image::Save(ofstream &fichier) const
{
	fichier.write((char*)&id, sizeof(int));
	int taille = nom.length();
	fichier.write((char*)&taille, sizeof(int));
	fichier.write(nom.c_str(),taille * sizeof(char));
	dimension.Save(fichier);
}

void Image::Load(ifstream & fichier)
{
	fichier.read((char*)&id,sizeof(int));
	int taille;
	fichier.read((char*)&taille, sizeof(int));
	nom = new char[taille + 1];
	fichier.read(&nom[0], taille * sizeof(char));
	nom[taille] = '\0';
	dimension.Load(fichier);
}
