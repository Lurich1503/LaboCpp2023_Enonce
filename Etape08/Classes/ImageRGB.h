#ifndef IMAGE_RGB_H
#define IMAGE_RGB_H

#include "Dimension.h"
#include "Image.h"
#include "Couleur.h"
#include <iostream>
using namespace std;

class ImageRGB : public Image
{
	friend ostream& operator<<(ostream&, const ImageRGB&);

	private: 
		Couleur **matrice;
		void init_matrice();

	public:
		ImageRGB(void);
		ImageRGB(int i,const char *n);
		ImageRGB(int i,const char *n,const Dimension& d);
		ImageRGB(const ImageRGB& p);
		ImageRGB(const char *n);

		~ImageRGB();

		void Affiche() const;
		void Dessine();
		void importFromFile(const char* fichier);
		void exportToFile(const char* fichier, const char* format);

		void setBackground(const Couleur& valeur);
		void setPixel(int x, int y, const Couleur& valeur);

		Couleur getPixel(int x, int y)const;

		ImageRGB& operator=(const ImageRGB&);

		void Save(ofstream &fichier) const;
		void Load(ifstream &fichier);

};

#endif