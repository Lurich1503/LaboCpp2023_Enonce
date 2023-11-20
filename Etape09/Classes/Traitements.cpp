#include "Traitements.h"
#include <string.h>
#include <cstdio>


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