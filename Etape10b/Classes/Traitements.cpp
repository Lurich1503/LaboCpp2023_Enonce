#include "Traitements.h"
#include <string.h>
#include <cstdio>
#include "Exception.h"
#include "SortedArrayList.h"


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
	int i, j, moy, diff;

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
			moy = 0;
			for(i = x - diff; i <= x + diff; i++)
			{
				for(j = y - diff; j <= y + diff; j++)
				{
					if(i >= 0 && i < d.getLargeur() && j >= 0 && j < d.getHauteur()) // !! ici bien faire attention qu'on ne dépasse pas l'image
					{
						moy += imageIn.getPixel(i,j);
					}
				}
			}
			moy = moy / (taille*taille);
			ImageOut.setPixel(x,y,moy);
		}
	}

	return ImageOut;

}


ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille)
{
	char nom[100],nombre[4];
	int i, j, diff, mediane, indice;

	if (taille % 2 == 0) 
	 {
        throw Exception("La taille du filtre doit toujours etre un nombre impair !");
     }

    strcpy(nom, imageIn.getNom());
	strcat(nom,"-median");
	sprintf(nombre, "%d", taille);
	strcat(nom,nombre);
	Dimension d = imageIn.getDimension();

	ImageNG ImageOut(1,nom,d);

	SortedArrayList<int> sortedList; // Création d'une instance de SortedArrayList

	diff = (taille - 1) / 2;
	indice = (taille*taille)/2+1;
	for(int x = 0; x < d.getLargeur(); x++)
	{
		for(int y = 0; y < d.getHauteur(); y++)
		{
			sortedList.viderListe(); // vider la liste
			for(i = x - diff; i <= x + diff; i++)
			{
				for(j = y - diff; j <= y + diff; j++)
				{
					if(i >= 0 && i < d.getLargeur() && j >= 0 && j < d.getHauteur()) // !! ici bien faire attention qu'on ne dépasse pas l'image
					{
						sortedList.insereElement(imageIn.getPixel(i,j));
					}
					else
					{
						sortedList.insereElement(0);
					}
				}
			}
			mediane = sortedList.getElement(indice);
			ImageOut.setPixel(x,y,mediane);
		}
	}

	return ImageOut;
}


ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille)
{
	char nom[100],nombre[4];
	int i, j, diff, min;

	if (taille % 2 == 0) 
	 {
        throw Exception("La taille du filtre doit toujours etre un nombre impair !");
     }

    strcpy(nom, imageIn.getNom());
	strcat(nom,"-erode");
	sprintf(nombre, "%d", taille);
	strcat(nom,nombre);
	Dimension d = imageIn.getDimension();

	ImageNG ImageOut(1,nom,d);

	SortedArrayList<int> sortedList; // Création d'une instance de SortedArrayList

	diff = (taille - 1) / 2;
	for(int x = 0; x < d.getLargeur(); x++)
	{
		for(int y = 0; y < d.getHauteur(); y++)
		{
			sortedList.viderListe(); // vider la liste
			for(i = x - diff; i <= x + diff; i++)
			{
				for(j = y - diff; j <= y + diff; j++)
				{
					if(i >= 0 && i < d.getLargeur() && j >= 0 && j < d.getHauteur()) // !! ici bien faire attention qu'on ne dépasse pas l'image
					{
						sortedList.insereElement(imageIn.getPixel(i,j));
					}
					else
					{
						sortedList.insereElement(0);
					}
				}
			}
			min = sortedList.getElement(0);
			ImageOut.setPixel(x,y,min);
		}
	}

	return ImageOut;
}


ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille)
{
	char nom[100],nombre[4];
	int i, j, diff, max, dernier_val_liste;

	if (taille % 2 == 0) 
	 {
        throw Exception("La taille du filtre doit toujours etre un nombre impair !");
     }

    strcpy(nom, imageIn.getNom());
	strcat(nom,"-dilate");
	sprintf(nombre, "%d", taille);
	strcat(nom,nombre);
	Dimension d = imageIn.getDimension();

	ImageNG ImageOut(1,nom,d);

	SortedArrayList<int> sortedList; // Création d'une instance de SortedArrayList

	dernier_val_liste = taille * taille -1;
	printf("dernier_val_liste %d\n", dernier_val_liste);
	diff = (taille - 1) / 2;
	for(int x = 0; x < d.getLargeur(); x++)
	{
		for(int y = 0; y < d.getHauteur(); y++)
		{
			sortedList.viderListe(); // vider la liste
			for(i = x - diff; i <= x + diff; i++)
			{
				for(j = y - diff; j <= y + diff; j++)
				{
					if(i >= 0 && i < d.getLargeur() && j >= 0 && j < d.getHauteur()) // !! ici bien faire attention qu'on ne dépasse pas l'image
					{
						sortedList.insereElement(imageIn.getPixel(i,j));
					}
					else
					{
						sortedList.insereElement(0);
					}
				}
			}
			max = sortedList.getElement(dernier_val_liste);
			ImageOut.setPixel(x,y,max);
		}
	}

	return ImageOut;
}


ImageNG Traitements::Negatif(const ImageNG& imageIn)
{
	char nom[100];

    strcpy(nom, imageIn.getNom());
	strcat(nom,"-negatif");
	Dimension d = imageIn.getDimension();

	ImageNG ImageOut(1,nom,d);

	for(int x = 0; x < d.getLargeur(); x++)
	{
		for(int y = 0; y < d.getHauteur(); y++)
		{
			ImageOut.setPixel(x,y,255 - imageIn.getPixel(x,y));
		}
	}

	return ImageOut;
}