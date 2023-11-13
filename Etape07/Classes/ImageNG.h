#ifndef IMAGE_NG_H
#define IMAGE_NG_H

#include "Dimension.h"
#include "Image.h"
#include <iostream>
using namespace std;

class ImageNG : public Image
{
	friend ostream& operator<<(ostream&, const ImageNG&);
	friend ImageNG operator+(int, ImageNG&);

	private:
		int** matrice;  
		void init_matrice();
		void redimMatrice(Dimension);
		int compImg(const ImageNG&);

	public:
		ImageNG(void);
		ImageNG(int i,const char *n);
		ImageNG(int i,const char *n,const Dimension& d);
		ImageNG(const ImageNG& p);
		ImageNG(const char *n);
		

		~ImageNG();
 
 		void setDimension(const Dimension& d);
		void setPixel(int x, int y, int val);
		void setBackground(int val);

		int getPixel(int x,int y) const;
		int getLuminance() const;
		int getMinimum() const;
		int getMaximum() const;
		float getContraste() const;
	
		void Affiche() const;
		void Dessine();
		void importFromFile(const char* fichier);
		void exportToFile(const char* fichier, const char* format);

		ImageNG& operator=(const ImageNG&);
		ImageNG operator+(int);
		ImageNG operator-(int);
		ImageNG operator-(ImageNG&);
		ImageNG operator++();
		ImageNG operator++(int);
		ImageNG operator--();
		ImageNG operator--(int);
		int operator<(const ImageNG&);
		int operator>(const ImageNG&);
		int operator==(const ImageNG&);

};

#endif