#ifndef PHOTO_SHOP_H
#define PHOTO_SHOP_H

#include "Image.h"
#include "ArrayList.h"

#include <iostream>
using namespace std;

class PhotoShop
{
	private:
		ArrayList<Image*> images; 
		static int numCourant;
		PhotoShop(void);
		
		static PhotoShop instance;
		PhotoShop(const PhotoShop &);
		PhotoShop& operator=(const PhotoShop&);

	public:
		~PhotoShop();

		void reset();
		void ajouteImage(Image* pImage);

		void afficheImages() const;
		void dessineImages() const;

		Image* getImageParIndice(int indice);
		Image* getImageParId(int id);

		ArrayList<Image*> getArraylist()const;

		void supprimeImageParIndice(int ind);
		void supprimeImageParId(int id);

		static PhotoShop& getInstance();
};

#endif