#include "ImageNG.h"
#include <string.h>
#include "MyQT.h"

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
ImageNG::ImageNG(void)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur par defaut <<<" << endl;
#endif
	setId(-1);
	nom = NULL;
	setNom("???");
	init_matrice();
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
ImageNG::ImageNG(int i,const char *n)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur d'initialisation <<<" << endl;
#endif
	setId(i);
	nom = NULL;
	setNom(n);
	init_matrice();
}

ImageNG::ImageNG(int i,const char *n, const Dimension& d)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur d'initialisation avec dimension <<<" << endl;
#endif
	setId(i);
	nom = NULL;
	setNom(n);
	setDimension(d);
	init_matrice();
}


//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
ImageNG::ImageNG(const ImageNG& p)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur de copie <<<" << endl;
#endif
	setId(p.getId());
	nom = NULL;
	setNom(p.getNom());
	setDimension(p.getDimension());
	init_matrice();
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
ImageNG::~ImageNG()
{
#ifdef DEBUG
	cout << ">>> ImageNG : destructeur <<<" << endl;
#endif

	if (nom)
		delete nom;

	for(int x=0; x<dimension.getLargeur(); x++)
		{
			delete[] matrice[x];
		}
	delete[] matrice;
}


//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void ImageNG::setId(int i)
{
	id = i;
}

void ImageNG::setNom(const char *n)
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

void ImageNG::setDimension(const Dimension& d)
{
	dimension.setLargeur(d.getLargeur());
	dimension.setHauteur(d.getHauteur());
}

void ImageNG::setPixel(int x, int y, int val)
{
	if(val<=0||val>255)
 	{
 		return;
 	}
	matrice[x][y]=val;
}

void ImageNG::setBackground(int val)
{
	if(val<=0||val>255)
 	{
 		return;
 	}
	for (int i=0; i<dimension.getLargeur(); i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			setPixel(i,j,val);
		}
	}
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int ImageNG::getId() const
{
	return id;
}

const char * ImageNG::getNom() const
{
	return nom;
}

Dimension ImageNG::getDimension() const
{
	return dimension;
}

int ImageNG::getPixel(int x, int y) const
{
	return matrice[x][y];
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------

void ImageNG::Affiche() const
{
	cout << "[ImageNG : nom=";
	if (nom) cout << getNom();
	else cout << "???";
	cout << " id =" << getId() << "]" << endl;
	dimension.Affiche();
	cout << endl;
}

void ImageNG::init_matrice()
{
	if(dimension.getLargeur()<=500 && dimension.getHauteur()<=500)
	{
		matrice = new int*[dimension.getLargeur()];
		for (int x=0 ; x < dimension.getLargeur() ; x++) 
			{
				matrice[x] = new int[dimension.getHauteur()];
			}
	}
}

void ImageNG::dessine()
{
	MyQT::ViewImage(*this);
}

void ImageNG::importFromFile(const char* fichier)
{
	MyQT::ImportFromFile(*this, fichier);
}

void ImageNG::exportToFile(const char* fichier, const char* format)
{
	MyQT::ExportToFile(*this, fichier, format);
}