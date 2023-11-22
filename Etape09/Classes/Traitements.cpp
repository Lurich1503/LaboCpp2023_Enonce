#include "Traitements.h"
#include <string.h>
#include <cstdio>
#include "Exception.h"


//----------------------------------------------
//------------METHODES STATIQUES
//----------------------------------------------
ImageB Traitements::Seuillage(const ImageNG& imageIn, int seuil)
{
	char nom[100],nombre[4];

	strcpy(nom, imageIn.getNom());
	strcat(nom,"-Seuil");
	sprintf(nombre, "%d", seuil);
	strcat(nom,nombre);
	Dimension d = imageIn.getDimension();

	ImageB ImageOut(1,nom,d);

	for(int x=0; x < d.getLargeur(); x++)
	{
		for(int y=0; y < d.getHauteur(); y++)
		{
			if(imageIn.getPixel(x, y) > seuil)
			{
				ImageOut.setPixel(x,y,true);
			}
			else
			{
				ImageOut.setPixel(x,y,false);
			}
		}
	}

	return ImageOut;
}


ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille)
{
	char nom[100],nombre[4];
	int i, j, cpt, moy, diff;

	if (taille % 2 == 0) 
	 {
        throw Exception("La taille du filtre doit toujours etre un nombre impair !");
     }

	strcpy(nom, imageIn.getNom());
	strcat(nom,"-moyenne");
	sprintf(nombre, "%d", taille);
	strcat(nom,nombre);
	Dimension d = imageIn.getDimension();

	ImageNG ImageOut(1,nom,d);

	diff = (taille - 1) / 2;
	for(int x = 0; x < d.getLargeur(); x++)
	{
		for(int y = 0; y < d.getHauteur(); y++)
		{
			cpt = 0;
			moy = 0;
			for(i = x - diff; i <= x + diff; i++)
			{
				for(j = y - diff; j <= y + diff; j++)
				{
					if(i >= 0 && i < d.getLargeur() && j >= 0 && j < d.getHauteur()) // !! ici bien faire attention qu'on ne dépasse pas l'image
					{
						cpt++;
						moy += imageIn.getPixel(i,j);
					}
				}
			}
			moy = moy / cpt;
			ImageOut.setPixel(x,y,moy);
		}
	}

	return ImageOut;

}