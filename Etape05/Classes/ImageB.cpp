#include "ImageB.h"
#include <string.h>
#include "MyQT.h"

Couleur ImageB::couleurTrue(Couleur::BLANC);
Couleur ImageB::couleurFalse(Couleur::NOIR);

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
ImageB::ImageB(void) : Image()
{
#ifdef DEBUG
	cout << ">>> ImageB : constructeur par defaut <<<" << endl;
#endif

	matrice = NULL;
	init_matrice();
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
ImageB::ImageB(int i,const char *n) : Image(i,n)
{
#ifdef DEBUG
	cout << ">>> ImageB : constructeur d'initialisation <<<" << endl;
#endif
	
	matrice = NULL;
	init_matrice(); 
}

ImageB::ImageB(int i,const char *n, const Dimension& d) : Image(i,n,d)
{
#ifdef DEBUG
	cout << ">>> ImageB : constructeur d'initialisation avec dimension <<<" << endl;
#endif
	
	matrice = NULL;
	init_matrice();
}


//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
ImageB::ImageB(const ImageB& p) : Image(p)
{
#ifdef DEBUG
	cout << ">>> ImageB : constructeur de copie <<<" << endl;
#endif
	
	matrice = NULL;
	init_matrice();
	for(int i=0; i<dimension.getLargeur(); i++)
	{
		for(int j=0; j<dimension.getHauteur(); j++)
		{
			setPixel(i, j, p.getPixel(i, j));
		}
	}
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
ImageB::~ImageB()
{
#ifdef DEBUG
	cout << ">>> ImageB : destructeur <<<" << endl;
#endif

	if(matrice)
	{
		for(int x=0; x<dimension.getLargeur(); x++)
			{
				delete[] matrice[x];
			}
		delete[] matrice;
	}
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void ImageB::setBackground(bool valeur)
{
	for (int i=0; i<dimension.getLargeur(); i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			setPixel(i,j,valeur);
		}
	}
}

void ImageB::setPixel(int x, int y, bool valeur)
{
	matrice[x][y]=valeur;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
bool ImageB::getPixel(int x, int y) const
{
	return matrice[x][y];
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
void ImageB::Affiche() const
{
	cout << "[ImageB : nom=";
	if (nom) cout << getNom();
	else cout << "???";
	cout << " id =" << getId() << "]" << endl;
	dimension.Affiche();
	cout << endl;
}

void ImageB::init_matrice()
{
	matrice = new bool*[dimension.getLargeur()];
	for (int x=0 ; x < dimension.getLargeur() ; x++) 
		{
			matrice[x] = new bool[dimension.getHauteur()];
		}
	setBackground(true);
}

void ImageB::Dessine()
{
	MyQT::ViewImage(*this);
}

void ImageB::exportToFile(const char* fichier, const char* format)
{
	MyQT::ExportToFile(*this, fichier, format);
}

//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
ImageB& ImageB::operator=(const ImageB& p) 
{
#ifdef DEBUG
	cout << ">>> ImageB : operator=" << endl;
#endif

	setId(p.getId());
	setNom(p.getNom());
	dimension = p.getDimension();

	if(matrice)
	{
		for(int x=0; x<dimension.getLargeur(); x++)
			{
				delete[] matrice[x];
			}
		delete[] matrice;
	}

	init_matrice();
	for (int x=0; x<dimension.getLargeur(); x++)
	{
		for(int y=0; y<dimension.getHauteur(); y++)
		{
			setPixel(x, y, p.getPixel(x,y));
		}
	}

	return (*this);
}

ostream& operator<<(ostream& s, const ImageB& p)
{
	s << p.id << "/" << p.nom << "/" << p.dimension;
	return s;
}
