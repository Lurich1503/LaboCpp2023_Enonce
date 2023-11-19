#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>
using namespace std;

class Couleur
{
	friend ostream& operator<<(ostream&, const Couleur&);

	private: 
		int rouge;
		int vert;
		int bleu;

	public:

		static const Couleur ROUGE;
		static const Couleur VERT;
		static const Couleur BLEU;
		static const Couleur BLANC;
		static const Couleur NOIR;

		Couleur(void);			 //defaut
		Couleur(int, int, int);  //initialisation
		Couleur(const Couleur&); //copie

		~Couleur();

		void setRouge(int);
		void setVert(int);
		void setBleu(int);

		int getRouge() const;
		int getVert() const;
		int getBleu() const;

		void Affiche() const;

		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);


};

#endif