#include "PhotoShop.h"
#include "Image.h"
#include "Iterateur.h"
#include "Exception.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"

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
	numCourant = 1;
	ImageB::couleurTrue = Couleur::BLANC;
	ImageB::couleurFalse = Couleur::NOIR;
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

void PhotoShop::Save() const
{
	numCourant = 1; // !!! il faut que le numcourant soit egal a 1 pour ne pas que l'indice augmente a chaque fois qu'on sauvegarde car de base s'il y a deja 3 elements dans la bibliotehque, le fait d'ajouter une image ne mettra pas l'indice a 4 mais a 1
	ofstream fichierSauvegarde("sauvegarde.dat", ios::out | ios::binary);

	if(!fichierSauvegarde.is_open())
	{
		cout << " Le fichier sauvegarde n'existe pas! Il va être creer" << endl;
	}

	fichierSauvegarde.write((char*)&numCourant,sizeof(int));

	fichierSauvegarde.write((char*)&ImageB::couleurTrue, sizeof(Couleur));
    fichierSauvegarde.write((char*)&ImageB::couleurFalse, sizeof(Couleur));

    int nombreImages = images.ArrayList::getNombreElements();
    fichierSauvegarde.write((char*)&nombreImages, sizeof(int));

    Iterateur<Image*> it(images);
    for (it.reset() ; !it.end() ; it++)
    {
    	ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
    	if(pNG != NULL) 
    	{
            int typeImage = 1;
            fichierSauvegarde.write((char*)&typeImage, sizeof(int));
            pNG->ImageNG::Save(fichierSauvegarde);
        } 
        else 
        {
        	ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
        	if (pRGB != NULL) 
        	{
            	int typeImage = 2;
            	fichierSauvegarde.write((char*)&typeImage, sizeof(int));
            	pRGB->ImageRGB::Save(fichierSauvegarde);
        	} 
        	else 
        	{
        		ImageB* pB = dynamic_cast<ImageB*>(&it);
        		if (pB != NULL) 
        		{
		            int typeImage = 3;
		            fichierSauvegarde.write((char*)&typeImage, sizeof(int));
		            pB->ImageB::Save(fichierSauvegarde);
        		}

    		}
    	}
    }



}
		
void PhotoShop::Load()
{
	ifstream fichierSauvegarde("sauvegarde.dat",ios::in | ios::binary);
    if (!fichierSauvegarde.is_open()) 
    {
        throw Exception(" Le fichier sauvegarde n'existe pas ! La bibliotheque sera vierge !");
    }
    else
    {

	    fichierSauvegarde.read((char*)&numCourant, sizeof(int));

	    fichierSauvegarde.read((char*)&ImageB::couleurTrue, sizeof(Couleur));
	    fichierSauvegarde.read((char*)&ImageB::couleurFalse, sizeof(Couleur));

	    int nombreImages;
	    fichierSauvegarde.read((char*)&nombreImages, sizeof(int));
	    for (int i = 0; i < nombreImages; i++) 
	    {
	        int typeImage;
	        fichierSauvegarde.read((char*)&typeImage, sizeof(int));
	        cout<< typeImage<<endl;
	        if (typeImage == 1) 
	        {
	            ImageNG* nouvelleImage = new ImageNG();
	            nouvelleImage->Load(fichierSauvegarde);
	            ajouteImage(nouvelleImage);
	        }
	        else
	        {
	        	if(typeImage == 2)
	            {
	                ImageRGB* nouvelleImage = new ImageRGB();
	                nouvelleImage->Load(fichierSauvegarde);
	                ajouteImage(nouvelleImage);
	            }
	            else
	            {
	            	if(typeImage == 3)
	            	{
		            	ImageB* nouvelleImage = new ImageB();
		                nouvelleImage->Load(fichierSauvegarde);
		                ajouteImage(nouvelleImage);
		            }
	            }
	        }
	    }
	}
}