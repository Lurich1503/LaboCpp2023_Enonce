#include "Dimension.h"
#include "XYException.h"
#include <fstream>

const Dimension Dimension::VGA(640, 480);
const Dimension Dimension::HD(1280, 720);
const Dimension Dimension::FULL_HD(1920, 1080);

//----------------------------------------------
//---------CONSTRUCTEURS PAR DEFAUT
//----------------------------------------------
Dimension::Dimension(void)
{
	#ifdef DEBUG
	cout << ">>> Dimension : constructeur par defaut <<<" << endl;
	#endif

	setLargeur(400);
	setHauteur(300);
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
Dimension::Dimension(int l, int h)
{
	#ifdef DEBUG
	cout << ">>> Dimension : constructeur d'initialisation <<<" << endl;
	#endif

	setLargeur(l);
	setHauteur(h);
}



//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
Dimension::Dimension(const Dimension& d)
{
	#ifdef DEBUG
	cout << ">>> Dimension : constructeur de copie <<<" << endl;
	#endif

	setLargeur(d.getLargeur());
	setHauteur(d.getHauteur());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
Dimension::~Dimension()
{
	#ifdef DEBUG
	cout << ">>> Dimension : destructeur <<<" << endl;
	#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void Dimension::setLargeur(int l)
{
	if(l<=0) throw XYException(120,"Dimension : largeur plus petite que 1 impossible !");
	largeur = l;
}

void Dimension::setHauteur(int h)
{
	if(h<=0) throw XYException(121,"Dimension : hauteur plus petite que 1 impossible !");
	hauteur = h;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int Dimension::getLargeur() const
{
	return largeur;
}
		
int Dimension::getHauteur() const
{
	return hauteur;
}


//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
void Dimension::Affiche() const
{
	cout << "[Dimension : largeur=";
	cout << getLargeur();
	
	cout << ", hauteur=";
	cout << getHauteur();
	
	cout << "]" << endl;
}


//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
ostream& operator<<(ostream& s, const Dimension& d)
{
	s << d.largeur << "/" << d.hauteur;
	return s;
}

istream& operator>>(istream& s, Dimension& d)
{
	int largeur,hauteur;

	cout << "entrez une largeur (0 < largeur > 500): ";
	s>>largeur;
	cout << "entrez une hauteur (0 < hauteur > 500): ";
	s>>hauteur;

	if ((largeur < 1 || largeur > 500) && (hauteur < 1 || hauteur > 500)) 
	 {
        throw XYException(100,"Dimension : la largeur et la hauteurs sont plus petites que 1 ou plus grande que 500 (IMPOSSIBLE)!");
     }
     else
     {
     	if(largeur < 1 || largeur > 500)
     	{
     		throw XYException(120,"Dimension : largeur plus petite que 1 ou plus grande que 500 (IMPOSSIBLE)!");
     	}
     	else
     	{ 
     		if(hauteur < 1 || hauteur > 500)
     		{
     			throw XYException(121,"Dimension : hauteur plus petite que 1 ou plus grande que 500 (IMPOSSIBLE)!");
     		}
     	}
     }

	d.largeur = largeur;
	d.hauteur = hauteur;
	return s;
}

int Dimension::operator==(const Dimension& d)
{
	return compD(d)==0;
}

int Dimension::operator!=(const Dimension& d)
{
	return compD(d)==-1;
}

int Dimension::compD(const Dimension& d)
{
	 if(largeur != d.getLargeur() || hauteur != d.getHauteur())
	 {
	 	return -1;
	 }
	 return 0;
}


//----------------------------------------------
//------------------FLUX
//----------------------------------------------
void Dimension::Save(ofstream &fichier) const
{
	fichier.write((char*)&largeur,sizeof(int));
	fichier.write((char*)&hauteur,sizeof(int));
}

void Dimension::Load(ifstream & fichier)
{
	fichier.read((char*)&largeur,sizeof(int));
	fichier.read((char*)&hauteur,sizeof(int));
}