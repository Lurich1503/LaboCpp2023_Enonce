#include "ImageB.h"
#include <string.h>
#include "MyQT.h"
#include "XYException.h"
#include <fstream>

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
	if (x < 0 && y < 0) 
	  {
      	throw XYException(100,"Coordonnées x et y invalides !");
      } 
      else 
      	{
      		if (x < 0)
      		{
        		throw XYException(120,"Coordonnée x invalide !");
    		} 
    		else
    		{
    			if (y < 0)
    			{
        			throw XYException(121,"Coordonnée y invalide !");
    			} 
    			else 
    			{
    				if (x >= dimension.getLargeur() && y >= dimension.getHauteur()) 
    				{
        				throw XYException(100,"Coordonnées x et y hors limites !");
    				} 
    				else 
    				{
    					if (x >= dimension.getLargeur()) 
    					{
        					throw XYException(120,"Coordonnée x hors limites !");
    					} 
    					else 
    					{
    						if (y >= dimension.getHauteur()) 
    						{
        						throw XYException(121,"Coordonnée y hors limites !");
    						}
    					}
    				}
    			}
    		}
    	}

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


//----------------------------------------------
//------------------FLUX
//----------------------------------------------
void ImageB::Save(ofstream &fichier) const
{
	Image::Save(fichier);

	int taille_largeur = dimension.getLargeur();
	fichier.write((char*)&taille_largeur, sizeof(int));
	int taille_hauteur = dimension.getHauteur();
	fichier.write((char*)&taille_hauteur, sizeof(int));

	for(int x=0;x<dimension.getLargeur();x++)
	{
		for(int y=0;y<dimension.getHauteur();y++)
		{
			fichier.write((char*)&matrice[x][y],sizeof(bool));
		}
	}
}

void ImageB::Load(ifstream &fichier)
{
	Image::Load(fichier);

	int taille_largeur;
	fichier.read((char*)&taille_largeur, sizeof(int));
	int taille_hauteur;
	fichier.read((char*)&taille_hauteur, sizeof(int));

	matrice = new bool*[taille_largeur];
	for (int x=0 ; x < taille_largeur ; x++) 
		{
			matrice[x] = new bool[taille_hauteur];
		}
 
	for(int x=0; x < taille_largeur; x++)
	{
		for(int y=0; y < taille_hauteur; y++)
		{
			fichier.read((char*)&matrice[x][y],sizeof(bool));
		}
	}
}