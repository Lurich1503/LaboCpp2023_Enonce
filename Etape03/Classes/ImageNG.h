#ifndef IMAGE_NG_H
#define IMAGE_NG_H

#include "Dimension.h"
#include <iostream>
using namespace std;

class ImageNG
{
	private:
		int 	id;
		char	*nom;
		Dimension dimension;
		int** matrice;  
		void init_matrice();

	public:
		ImageNG(void);
		ImageNG(int i,const char *n);
		ImageNG(int i,const char *n,const Dimension& d);
		ImageNG(const ImageNG& p);
		

		~ImageNG();

		void setId(int i);
		void setNom(const char *n);
		void setDimension(const Dimension& d);
		void setPixel(int x, int y, int val);
		void setBackground(int val);

		int getId() const;
		const char * getNom() const;
		Dimension getDimension() const;
		int getPixel(const int x,const int y) const;
	
		void Affiche() const;
		void Dessine();
		void importFromFile(const char* fichier);
		void exportToFile(const char* fichier, const char* format);

		

};

#endif