#include "ImageRGB.h"
#include <string.h>
#include "MyQT.h"
#include "XYException.h"
#include <fstream>

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
ImageRGB::ImageRGB(void) : Image()
{
#ifdef DEBUG
	cout << ">>> ImageRGB : constructeur par defaut <<<" << endl;
#endif

	matrice = NULL;
	init_matrice();
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
ImageRGB::ImageRGB(int i,const string n) : Image(i,n)
{
#ifdef DEBUG
	cout << ">>> ImageRGB : constructeur d'initialisation <<<" << endl;
#endif
	
	matrice = NULL;
	init_matrice(); 
}

ImageRGB::ImageRGB(int i,const string n, const Dimension& d) : Image(i,n,d)
{
#ifdef DEBUG
	cout << ">>> ImageRGB : constructeur d'initialisation avec dimension <<<" << endl;
#endif
	
	matrice = NULL;
	init_matrice();
}


//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
ImageRGB::ImageRGB(const ImageRGB& p) : Image(p)
{
#ifdef DEBUG
	cout << ">>> ImageRGB : constructeur de copie <<<" << endl;
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

ImageRGB::ImageRGB(const string n) : Image(n)
{
#ifdef DEBUG
	cout << ">>> ImageRGB : constructeur de copie d'importation de fichier" << endl;
#endif

	matrice = NULL;
	init_matrice();
	importFromFile(n);


}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
ImageRGB::~ImageRGB()
{
#ifdef DEBUG
	cout << ">>> ImageRGB : destructeur <<<" << endl;
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
void ImageRGB::setBackground(const Couleur& valeur)
{
	for (int i=0; i<dimension.getLargeur(); i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			setPixel(i,j,valeur);
		}
	}
}

void ImageRGB::setPixel(int x, int y, const Couleur& valeur)
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
Couleur ImageRGB::getPixel(int x, int y) const
{
	return matrice[x][y];
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
void ImageRGB::Affiche() const
{
	cout << "[ImageRGB : nom=";
	if (!nom.empty()) cout << getNom();
	else cout << "???";
	cout << " id =" << getId() << "]" << endl;
	dimension.Affiche();
	cout << endl;
}

void ImageRGB::init_matrice()
{
	matrice = new Couleur*[dimension.getLargeur()];
	for (int x=0 ; x < dimension.getLargeur() ; x++) 
		{
			matrice[x] = new Couleur[dimension.getHauteur()];
		}
	setBackground(Couleur::NOIR);
	
}

void ImageRGB::Dessine()
{
	MyQT::ViewImage(*this);
}

void ImageRGB::importFromFile(const string fichier)
{
	MyQT::ImportFromFile(*this, fichier.c_str());
}

void ImageRGB::exportToFile(const string fichier, const string format)
{
	MyQT::ExportToFile(*this, fichier.c_str(), format.c_str());
}

//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
ImageRGB& ImageRGB::operator=(const ImageRGB& p) 
{
#ifdef DEBUG
	cout << ">>> ImageRGB : operator=" << endl;
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

ostream& operator<<(ostream& s, const ImageRGB& p)
{
	s << p.id << "/" << p.nom << "/" << p.dimension;
	return s;
}


//----------------------------------------------
//------------------FLUX
//----------------------------------------------
void ImageRGB::Save(ofstream & fichier) const
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
			fichier.write((char*)&matrice[x][y],sizeof(Couleur));
		}
	}
}

void ImageRGB::Load(ifstream & fichier)
{
	Image::Load(fichier);

	int taille_largeur;
	fichier.read((char*)&taille_largeur, sizeof(int));
	int taille_hauteur;
	fichier.read((char*)&taille_hauteur, sizeof(int));

	matrice = new Couleur*[taille_largeur];
	for (int x=0 ; x < taille_largeur ; x++) 
		{
			matrice[x] = new Couleur[taille_hauteur];
		}
 
	for(int x=0; x < taille_largeur; x++)
	{
		for(int y=0; y < taille_hauteur; y++)
		{
			fichier.read((char*)&matrice[x][y],sizeof(Couleur));
		}
	}

}