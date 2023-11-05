#include "Couleur.h"
#include "RGBException.h"
const Couleur Couleur::ROUGE(255,0,0);
const Couleur Couleur::VERT(0,255,0);
const Couleur Couleur::BLEU(0,0,255);
const Couleur Couleur::BLANC(255,255,255);
const Couleur Couleur::NOIR(0,0,0);


//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
Couleur::Couleur(void)
{
#ifdef DEBUG
	cout << ">>> Couleur : constructeur par defaut <<<" << endl;
#endif
	setRouge(0);
	setVert(0);
	setBleu(0);
}

//----------------------------------------------
//-----CONSTRUCTEURS D'INITIALISATION
//----------------------------------------------
Couleur::Couleur(int r, int v, int b)
{
#ifdef DEBUG
	cout << ">>> Couleur : constructeur d'initialisation <<<" << endl;
#endif	
	setRouge(r);
	setVert(v);
	setBleu(b);
}

//----------------------------------------------
//----------CONSTRUCTEURS DE COPIE
//----------------------------------------------
Couleur::Couleur(const Couleur& c)
{
#ifdef DEBUG
	cout << ">>> Couleur: constructeur de copie <<<" << endl;
#endif	
	setRouge(c.getRouge());
	setVert(c.getVert());
	setBleu(c.getBleu());
}

//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
Couleur::~Couleur()
{
#ifdef DEBUG
	cout << ">>> Couleur : destructeur <<<" << endl;
#endif
}

//----------------------------------------------
//------------------SETTERS
//----------------------------------------------
void Couleur::setRouge(int r)
{
	if(r < 0 || r > 255) throw RGBException(r,"Composante rouge invalide !");
	rouge = r;
}

void Couleur::setVert(int v)
{
	if(v < 0 || v > 255) throw RGBException(v,"Composante verte invalide !");
	vert = v;
}

void Couleur::setBleu(int b)
{
	if(b < 0 || b > 255) throw RGBException(b,"Composante bleue invalide !");
	bleu = b;
}

//----------------------------------------------
//------------------GETTERS
//----------------------------------------------
int Couleur::getRouge() const
{
	return rouge;
}

int Couleur::getVert() const
{
	return vert;
}

int Couleur::getBleu() const
{
	return bleu;
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
void Couleur::Affiche() const
{
	cout << "[Couleur : ";
	cout << " rouge = " << getRouge() << ", ";
	cout << " vert = " << getVert() << ", ";
	cout << " bleu = " << getBleu() << "]" << endl;
	cout << endl;
}


//----------------------------------------------
//----------SURCHARGE DES OPERATEURS
//----------------------------------------------
ostream& operator<<(ostream& s, const Couleur& c)
{
	s << c.rouge << "/" << c.vert << "/" << c.bleu;
	return s;
}