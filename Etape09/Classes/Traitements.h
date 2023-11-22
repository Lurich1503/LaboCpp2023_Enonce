#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H

#include "ImageNG.h"
#include "ImageB.h"
#include <iostream>
using namespace std;

class Traitements
{
	public:
		static ImageB Seuillage(const ImageNG& imageIn, int seuil);
		static ImageNG FiltreMoyenneur(const ImageNG& imageIn, int taille);

};

#endif