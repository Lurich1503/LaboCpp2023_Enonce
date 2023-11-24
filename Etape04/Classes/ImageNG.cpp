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
	matrice = NULL;
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
	matrice = NULL;
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
	matrice = NULL;
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
	matrice = NULL;
	setDimension(p.getDimension());
	init_matrice();
	for(int i=0; i<dimension.getLargeur(); i++)
	{
		for(int j=0; j<dimension.getHauteur(); j++)
		{
			setPixel(i, j, p.getPixel(i, j));
		}
	}
}

ImageNG::ImageNG(const char *n)
{
#ifdef DEBUG
	cout << ">>> ImageNG : constructeur de copie d'importation de fichier" << endl;
#endif

	setId(-1);
	nom = NULL;
	setNom(n);
	matrice = NULL;
	init_matrice();
	importFromFile(n);


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
	Dimension oldDimension(dimension);

	dimension.setLargeur(d.getLargeur());
	dimension.setHauteur(d.getHauteur());

	if(matrice != NULL)
	{
		redimMatrice(oldDimension);
	}
}

void ImageNG::setPixel(int x, int y, int val)
{
	if(val<0||val>255)
 	{
 		return;
 	}
	matrice[x][y]=val;
}

void ImageNG::setBackground(int val)
{
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
	matrice = new int*[dimension.getLargeur()];
	for (int x=0 ; x < dimension.getLargeur() ; x++) 
		{
			matrice[x] = new int[dimension.getHauteur()];
		}
	setBackground(0);
	
}

void ImageNG::redimMatrice(Dimension oldDimension)
{
	int** newMatrice = new int*[dimension.getLargeur()]; // créer une nouvelle matrice avec nouvelles dimensions

	for (int x=0 ; x < dimension.getLargeur() ; x++) 
		{
			newMatrice[x] = new int[dimension.getHauteur()];
		}	

	for(int x=0; x < dimension.getLargeur(); x++) // on met chaque pixel de la nouvelle matrice à 0
	{
		for(int y=0; y < dimension.getHauteur(); y++)
		{
			newMatrice[x][y]=0;
		}
	}

	for(int x=0; x < min(dimension.getLargeur(),oldDimension.getLargeur()); x++) // on met chaque pixel de l'ancienne matrice dans la nouvelle matrice
	{
		for(int y=0; y < min(dimension.getHauteur(),oldDimension.getHauteur()); y++)
		{
			newMatrice[x][y]=getPixel(x,y);
		}
	}	

	for(int x=0; x<oldDimension.getLargeur(); x++) // on supprime l'ancienne matrice;
			{
				delete[] matrice[x];
			}
		delete[] matrice;

	matrice = newMatrice; // on met la nouvelle matrice dans l'ancienne matrice 

}

void ImageNG::Dessine()
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

int ImageNG::getLuminance() const
{
	int moy=0,cpt=0;
	for(int x=0; x < dimension.getLargeur(); x++)
	{
		for(int y=0; y < dimension.getHauteur(); y++)
		{
			moy += matrice[x][y];
			cpt++;
		}
	}
	return moy/cpt;
}

int ImageNG::getMinimum() const
{
	int min;
	min = matrice[0][0];
	for(int x=0; x < dimension.getLargeur(); x++)
	{
		for(int y=0; y < dimension.getHauteur(); y++)
		{
			if(matrice[x][y] < min)
			{
				min = matrice[x][y];
			}
		}
	}
	return min;
}

int ImageNG::getMaximum() const
{
	int max;
	max = matrice[0][0];
	for(int x=0; x < dimension.getLargeur(); x++)
	{
		for(int y=0; y < dimension.getHauteur(); y++)
		{
			if(matrice[x][y] > max)
			{
				max = matrice[x][y];
			}
		}
	}
	return max;
}

float ImageNG::getContraste() const
{
	int min,max;

	min=getMinimum();
	max=getMaximum();

	float contraste;

	contraste = (float)(max - min)/(max + min);
	return contraste;
}

//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------

ImageNG& ImageNG::operator=(const ImageNG& p)
{
#ifdef DEBUG
	cout << ">>> ImageNG : operator=" << endl;
#endif

	setId(p.getId());
	setNom(p.getNom());

	if(matrice)
	{
		for(int x=0; x<dimension.getLargeur(); x++)
			{
				delete[] matrice[x];
			}
		delete[] matrice;
	}

	dimension = p.getDimension();
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

ostream& operator<<(ostream& s, const ImageNG& p)
{
	s << p.id << "/" << p.nom << "/" << p.dimension << "/" << p.getLuminance() << "/" << p.getContraste();
	return s;
}

ImageNG ImageNG::operator+(int nb)
{
	ImageNG img(*this);
	
	for (int x=0; x<img.dimension.getLargeur(); x++)
	{
		for(int y=0; y<img.dimension.getHauteur(); y++)
		{
			if((img.getPixel(x,y)+nb) <= 255)
			{
				img.setPixel(x,y,img.getPixel(x,y)+nb);
			}
			else
			{
				img.setPixel(x,y,255);
			}
		}
	}

	return img;
}

ImageNG ImageNG::operator-(int nb)
{
	ImageNG img(*this);

	for (int x=0; x<img.dimension.getLargeur(); x++)
	{
		for(int y=0; y<img.dimension.getHauteur(); y++)
		{
			if((img.getPixel(x,y)-nb) >= 0)
			{
				img.setPixel(x,y,img.getPixel(x,y)-nb);
			}
			else
			{
				img.setPixel(x,y,0);
			}
		}
	}

	return img;
}

ImageNG operator+(int nb, ImageNG& p)
{
	return p+nb;
}

ImageNG ImageNG::operator++()
{
	(*this) = (*this)+20;
	return (*this);
}

ImageNG ImageNG::operator++(int)
{
	ImageNG img(*this);
	(*this) = (*this) + 20;
	return img;
}

ImageNG ImageNG::operator--()
{
	(*this) = (*this)-20;
	return (*this);
}

ImageNG ImageNG::operator--(int)
{
	ImageNG img(*this);
	(*this) = (*this) - 20;
	return img;
}

ImageNG ImageNG::operator-(const ImageNG& im2)
{
	ImageNG img(*this);
	for(int x=0; x<img.dimension.getLargeur(); x++)
	{
		for(int y=0; y<img.dimension.getHauteur(); y++)
		{
			if(img.getPixel(x,y)-im2.getPixel(x,y) >=0)
			{
				img.setPixel(x,y,img.getPixel(x,y)-im2.getPixel(x,y));
			}
			else
			{
				img.setPixel(x,y,0);
			}
		}
	}	
	return img;
}

int ImageNG::operator<(const ImageNG& p)
{
	return compImg(p)==-1;
}

int ImageNG::operator>(const ImageNG& p)
{
	return compImg(p)==1;
}

int ImageNG::operator==(const ImageNG& p)
{
	return compImg(p)==0;
}

int ImageNG::compImg(const ImageNG& p)
{
	int cmpt,egal=0,petit=0,grand=0;

	cmpt=dimension.getLargeur()*dimension.getHauteur();

	for(int x=0; x<p.dimension.getLargeur(); x++)
	{
		for(int y=0; y<p.dimension.getHauteur(); y++)
		{
			if(matrice[x][y] == p.getPixel(x,y))
			{
				egal++;
			}
			else
				if(matrice[x][y] < p.getPixel(x,y))
				{
					petit++;
				}
				else
					if(matrice[x][y] > p.getPixel(x,y))
					{
						grand++;
					}
		}
	}

	if(cmpt == egal)
	{
		return 0;
	}
	if(cmpt == petit)
	{
		return -1;
	}
	if(cmpt == grand)
	{
		return 1;
	}
	return 2;
}

	