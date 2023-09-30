#ifndef IMAGE_NG_H
#define IMAGE_NG_H

#include <iostream>
using namespace std;

class ImageNG
{
	private:
		int 	id;
		char	*nom;

	public:
		ImageNG(void);
		~ImageNG();

		void setId(int i);
		void setNom(const char *n);

		int getId() const;
		const char * getNom() const;
	
		void Affiche() const;
		ImageNG(int i,const char *n);
		ImageNG(const ImageNG& p);
};

#endif