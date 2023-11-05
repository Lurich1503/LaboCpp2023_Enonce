#include "Dimension.h"
#include "XYException.h"

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
	Dimension D;
	//Saisie de l et h;
	d.largeur = D.largeur;
	d.hauteur = D.hauteur;
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