#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"
#include "ArrayListException.h"

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
	if(i == indice && !it.end())
	{
		return (&it);
	}
	else
	{
		throw ARRAYLISTException(indice, "indice invalide ou liste inexistante!");
	}
}


Image* PhotoShop::getImageParId(int id)
{
	Iterateur<Image*> it(images); 
	it.reset();

	while(!it.end() && (&it)->getId() != id)
	{
		it++;
	}
	if(!it.end() && (&it)->getId() == id)
	{
		return (&it);
	}
	else
	{
		throw ARRAYLISTException(id, "id invalide ou liste inexistante!");
	}
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
	
	if(!it.end() && (&it)->getId() == id)
	{
		Image* img = images.retireElement(i);

		delete img;
	}
	else
	{
		throw ARRAYLISTException(id, "id invalide ou liste inexistante!");
	}

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