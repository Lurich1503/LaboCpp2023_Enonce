#ifndef IMAGE_B_H
#define IMAGE_B_H

#include "Dimension.h"
#include "Image.h"
#include "Couleur.h"
#include <iostream>
using namespace std;

class ImageB : public Image
{
	friend ostream& operator<<(ostream&, const ImageB&);

	private: 
		bool **matrice;
		void init_matrice();

	public: 
		static Couleur couleurTrue;
		static Couleur couleurFalse;

		ImageB(void);
		ImageB(int i,const char *n);
		ImageB(int i,const char *n,const Dimension& d);
		ImageB(const ImageB& p);

		~ImageB();

		void Affiche() const;
		void Dessine();

		void setBackground(bool valeur);
		void setPixel(int x, int y, bool valeur);

		bool getPixel(int x, int y)const;

		void exportToFile(const char* fichier, const char* format);

		ImageB& operator=(const ImageB&);

		void Save(ofstream & fichier) const;
		void Load(ifstream & fichier);
};
#endif