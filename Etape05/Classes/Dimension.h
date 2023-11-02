#ifndef DIMENSION_H
#define DIMENSION_H

#include <iostream>
using namespace std;

class Dimension
{
	friend ostream& operator<<(ostream&, const Dimension&);
	friend istream& operator>>(istream&, Dimension&);


	private: 
		int  largeur;
		int  hauteur;
		int compD(const Dimension&);

	public:

		static const Dimension VGA;
		static const Dimension HD;
		static const Dimension FULL_HD;

		Dimension(void);
		Dimension(int, int);
		Dimension(const Dimension&);
		~Dimension();

		void setLargeur(int);
		void setHauteur(int);

		int getLargeur() const;
		int getHauteur() const;

		void Affiche() const;

		int operator==(const Dimension&);
		int operator!=(const Dimension&);
};

#endif