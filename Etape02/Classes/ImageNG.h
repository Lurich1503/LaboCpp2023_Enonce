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

	public:
		ImageNG(void);
		~ImageNG();

		void setId(int i);
		void setNom(const char *n);
		void setDimension(const Dimension& d);

		int getId() const;
		const char * getNom() const;
		Dimension getDimension() const;
	
		void Affiche() const;
		ImageNG(int i,const char *n);
		ImageNG(const ImageNG& p);
		ImageNG(int i,const char *n,const Dimension& d);

};

#endif