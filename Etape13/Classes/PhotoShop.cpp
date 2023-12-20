#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"
#include "Exception.h"
#include "ImageNG.h"
#include "ImageRGB.h"

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

int PhotoShop::importeImages(string nomFichier)
{
	ifstream fichier(nomFichier,ios::in);

	if(!fichier.is_open())
	{
		throw Exception(" Erreur d'ouverture du fichier ...!");
	}

	string ligne;
	int nombre = 0; 

	while(getline(fichier, ligne))
	{
		nombre++;

		stringstream ss(ligne);
		string type, nomChemin, nom;
		getline(ss, type, ';');
		getline(ss, nomChemin, ';');
		getline(ss, nom, ';');

		if(type == "NG")
		{
			ImageNG* nouvelle_image = new ImageNG(nom);
			nouvelle_image->ImageNG::importFromFile(nomChemin);
			ajouteImage(nouvelle_image);
		}
		else
		{
			if(type == "RGB")
			{
				ImageRGB* nouvelle_image = new ImageRGB(nom);
				nouvelle_image->ImageRGB::importFromFile(nomChemin);
				ajouteImage(nouvelle_image);
			}
		}
	}

	fichier.close();
	return nombre;
}