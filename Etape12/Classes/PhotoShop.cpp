#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"

int PhotoShop::numCourant = 1;
PhotoShop PhotoShop::instance;
Image* PhotoShop::operande1 = NULL;
Image* PhotoShop::operande2 = NULL;
Image* PhotoShop::resultat = NULL;

//----------------------------------------------
//---------------CONSTRUCTEURS
//----------------------------------------------
PhotoShop::PhotoShop(void)
{
#ifdef DEBUG
	cout << ">>> PhotoShop : constructeur par defaut <<<" << endl;
#endif
}


//----------------------------------------------
//----------------DESTRUCTEUR
//----------------------------------------------
PhotoShop::~PhotoShop() 
{
#ifdef DEBUG
	cout << ">>> PhotoShop : destructeur <<<" << endl;
#endif

	reset();
}

//----------------------------------------------
//------------METHODE D'INSTANCE
//----------------------------------------------
void PhotoShop::ajouteImage(Image* pImage)
{
	pImage->setId(numCourant);  // j'attribue un id a l'image
	numCourant++;				// incrémentation numCourant
	images.insereElement(pImage);   // ajout de l'image au conteneur
}


void PhotoShop::afficheImages() const
{
	Iterateur<Image*> it(images);

	for (it.reset() ; !it.end() ; it++)
	{
		(&it)->Affiche();
	}
}


void PhotoShop::dessineImages() const
{
	Iterateur<Image*> it(images);

	for (it.reset() ; !it.end() ; it++)
	{
		(&it)->Dessine();
	}
}


Image* PhotoShop::getImageParIndice(int indice)
{
	Iterateur<Image*> it(images); 
	int i = 0;
	it.reset();

	while(i<indice && !it.end())
	{
		i++;
		it++;
	}
	return (&it);
}


Image* PhotoShop::getImageParId(int id)
{
	Iterateur<Image*> it(images); 
	it.reset();

	while(!it.end() && (&it)->getId() != id)
	{
		it++;
	}
	return (&it);
}


void PhotoShop::supprimeImageParIndice(int ind)
{
	Image* img = images.retireElement(ind);

	delete img;
}

void PhotoShop::supprimeImageParId(int id)
{
	Iterateur<Image*> it(images);
	int i=0;
	it.reset();

	while(!it.end() && (&it)->getId() != id)
	{
		it++;
		i++;
	}
	
	Image* img = images.retireElement(i);

	delete img;

}


void PhotoShop::reset()
{
	while(!images.estVide())
	{
		Image* img = images.retireElement(0);
		delete img;
	}
}


PhotoShop& PhotoShop::getInstance()
{
	return instance;
}

ArrayList<Image*> PhotoShop::getArraylist()const
{
	return images;
}