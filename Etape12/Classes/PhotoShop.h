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

		~PhotoShop();

	public:

		static Image* operande1;           // variables membres statiques publiques
		static Image* operande2;
		static Image* resultat;

		static PhotoShop& getInstance();   // donne acces au singleton

		void reset();
		void ajouteImage(Image* pImage);

		void afficheImages() const;
		void dessineImages() const;

		Image* getImageParIndice(int indice);
		Image* getImageParId(int id);

		ArrayList<Image*> getArraylist()const;

		void supprimeImageParIndice(int ind);
		void supprimeImageParId(int id);

};

#endif