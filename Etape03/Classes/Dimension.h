#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>
using namespace std;

class Dimension
{
	private: 
		int  largeur;
		int  hauteur;

	public:

		static const Dimension VGA;
		static const Dimension HD;
		static const Dimension FULL_HD;

		Dimension(void);
		Dimension(const int, const int);
		Dimension(const Dimension&);
		~Dimension();

		void setLargeur(int);
		void setHauteur(int);

		int getLargeur() const;
		int getHauteur() const;

		void Affiche() const;
};

#endif