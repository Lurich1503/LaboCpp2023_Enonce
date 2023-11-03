#ifndef IMAGE_H
#define IMAGE_H

#include "Dimension.h"
#include <iostream>
using namespace std;

class Image
{
	protected:
		int 	id;
		char	*nom;
		Dimension dimension;
	public:
		Image(void);
		Image(int i,const char *n);
		Image(int i,const char *n,const Dimension& d);
		Image(const Image& p);
		Image(const char *n);
		
		virtual ~Image();

		void setId(int i);
		void setNom(const char *n);
		virtual void setDimension(const Dimension& d);

		int getId() const;
		const char * getNom() const;
		Dimension getDimension() const;

		virtual void Affiche() const = 0;
		virtual void Dessine() = 0;
		virtual void exportToFile(const char* fichier, const char* format) = 0;
};

#endif