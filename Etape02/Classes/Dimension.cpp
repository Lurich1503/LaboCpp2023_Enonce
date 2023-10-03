#include "Dimension.h"

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
Dimension::Dimension(const int l, const int h)
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
	if(l<=0)
	{
		l=400;
		return;
	}
	largeur = l;
}

void Dimension::setHauteur(int h)
{
	if(h<=0)
	{
		h=300;
		return;
	}
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
	if (largeur) cout << getLargeur();
	else cout << "???";
	cout << ", hauteur=";
	if (hauteur) cout << getHauteur();
	else cout << "???";
	cout << "]" << endl;
}