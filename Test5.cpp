#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>
#include <unistd.h>
#include <QApplication>

#include "Couleur.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "ImageNG.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();

int main(int argc,char* argv[])
{
  // Initialisation de QT
  QApplication app(argc,argv);
  close(2);

  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Couleur" << endl;
  cout << "    ----- Image Couleur ----------------------------------------------------" << endl;
  cout << " 2. Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageRGB" << endl;
  cout << " 3. Tests de importFromFile, getPixel et exportToFile de ImageRGB" << endl;
  cout << "    ----- Image Binaire ----------------------------------------------------" << endl;
  cout << " 4. Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageB" << endl;
  cout << " 5. Tests de getPixel et exportToFile de ImageB" << endl;
  cout << "    ------------------------------------------------------------------------" << endl;
  cout << " 6. Tests de la virtualite" << endl;
  cout << " 7. Tests du downcasting et dynamic-cast" << endl;
  cout << "    ------------------------------------------------------------------------" << endl;
  cout << " 8. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Couleur ************************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << endl << "(1.1) ***** Test constructeur des constructuers + Affiche **********************************" << endl;
  {
    Couleur c1,c2(128,255,10),c3(c2);
    c1.Affiche();
    c2.Affiche();
    c3.Affiche();
  }

  cout << endl << "(1.2) ***** Test des setters et getters ****************************************************" << endl;
  {
    Couleur couleur;
    couleur.setRouge(180);
    couleur.setVert(60);
    couleur.setBleu(210);
    couleur.Affiche();
    cout << "Rouge = " << couleur.getRouge() << endl;
    cout << "Vert = " << couleur.getVert() << endl;
    cout << "Bleu = " << couleur.getBleu() << endl;
  }

  cout << endl << "(1.3) ***** Tests de base des objets statiques + operateur << ******************************" << endl;
  cout << "Bleu = " << Couleur::BLEU << endl;
  cout << "Vert = " << Couleur::VERT << endl;
  cout << "Blanc = " << Couleur::BLANC << endl;
}

//*************************************************************************************************
//*** Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageRGB ************** 
//*************************************************************************************************
void Essai2()
{
  cout << endl << "(2) Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageRGB ********" << endl;
  
  ImageRGB image1(1,"testCouleur",Dimension(300,300));
  image1.setBackground(Couleur(0,0,128));
  for (int x=0 ; x<300 ; x=x+4) image1.setPixel(x,x,Couleur::VERT);
  cout << "Voici image1..." << endl;
  image1.Affiche();
  image1.Dessine();

  {
    ImageRGB image2 (image1);
    cout << "On modifie la copie image2 de image1..." << endl;
    for (int x=0 ; x<300 ; x=x+4) image2.setPixel(x,299-x,Couleur::ROUGE);
    image2.setNom("testModif");
    cout << "Voici image2..." << endl;
    image2.Affiche();
    image2.Dessine();
    cout << "Destruction de image2..." << endl;
  }

  cout << "Re-voici image1..." << endl;
  image1.Affiche();
  image1.Dessine();
}

//*************************************************************************************************
//*** Test de importFromFile, getPixel et exportToFile de ImageRGB ******************************** 
//*************************************************************************************************
void Essai3()
{
  cout << endl << "(3) Tests de importFromFile, getPixel et exportToFile de ImageRGB ************************" << endl;
  
  ImageRGB image;
  cout << "Importation d'une image à partir du fichier joconde.bmp......" << endl;
  image.importFromFile("../images/joconde.bmp");
  image.setNom("La Joconde");
  image.setId(1);
  image.Affiche();
  cout << "Largeur = " << image.getDimension().getLargeur() << endl;
  cout << "Hauteur = " << image.getDimension().getHauteur() << endl;
  cout << "Valeur du pixel (125,56) = " << image.getPixel(125,56) << endl;
  image.Dessine();

  cout << "Exportation de l'image modifiee vers le fichier joconde2.png......" << endl;
  for (int x=0 ; x<255 ; x++) image.setPixel(x,(x*x/255),Couleur::ROUGE); // Dessin d'une parabole rouge :)
  image.Dessine();
  image.exportToFile("joconde2.png","PNG");
}

//*************************************************************************************************
//*** Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageB **************** 
//*************************************************************************************************
void Essai4()
{
  cout << endl << "(4) Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageB **********" << endl;
  
  ImageB image1(1,"testBinaire",Dimension(300,300));
  image1.setBackground(false);
  for (int x=0 ; x<300 ; x=x+4) image1.setPixel(x,x,true);
  cout << "Voici image1..." << endl;
  image1.Affiche();
  image1.Dessine();

  {
    ImageB image2 (image1);
    cout << "On modifie la copie image2 de image1..." << endl;
    for (int x=0 ; x<300 ; x=x+4) image2.setPixel(x,299-x,true);
    image2.setNom("testModif");
    cout << "Voici image2..." << endl;
    image2.Affiche();
    image2.Dessine();
    cout << "Destruction de image2..." << endl;
  }

  cout << "Re-voici image1..." << endl;
  image1.Affiche();
  image1.Dessine();
}

//*************************************************************************************************
//*** Test de getPixel et exportToFile de ImageB ************************************************** 
//*************************************************************************************************
void Essai5()
{
  cout << endl << "(5) Tests de getPixel et exportToFile de ImageB ********************************" << endl;
  
  ImageB image;
  cout << "Creation d'une image binaire --> dessin d'une disque......" << endl;
  image.setNom("Mon Beau Dessin");
  image.setDimension(Dimension(300,300));
  image.setId(1);
  for (int x=0 ; x<300 ; x++)
    for (int y=0 ; y<300 ; y++)
      if ((x-100)*(x-100)+(y-100)*(y-100) < 2500) image.setPixel(x,y,true);
  cout << "Largeur = " << image.getDimension().getLargeur() << endl;
  cout << "Hauteur = " << image.getDimension().getHauteur() << endl;
  cout << "Valeur du pixel (125,56) = " << image.getPixel(125,56) << endl;
  image.Affiche();
  image.Dessine();

  ImageB::couleurTrue = Couleur::ROUGE;
  ImageB::couleurFalse = Couleur(0,255,255);
  cout << "Exportation de l'image binaire vers le fichier disque.png......" << endl;
  image.Dessine();
  image.exportToFile("disque.png","PNG");
}

//***********************************************************************************************
//*** Tests de la virtualite ********************************************************************
//***********************************************************************************************
void Essai6()
{
  srand((unsigned)time(NULL));

  cout << "(6.1) Allocation dynamique d'images ****************************************************" << endl;
  Image* image[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "image[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : image[i] = new ImageB(); 
               ((ImageB*)(image[i]))->setBackground(true);
               cout << "ImageB" << endl;
               break;

      case 1 : image[i] = new ImageNG();
               ((ImageNG*)(image[i]))->setBackground(128);
               cout << "ImageNG" << endl;
               break;

      case 2 : image[i] = new ImageRGB();
               ((ImageRGB*)(image[i]))->setBackground(Couleur::BLEU);
               cout << "ImageRGB" << endl;
               break;
    }
  }
  cout << endl;

  cout << "(6.2) Test de la methode VIRTUELLE Dessine() ******************************************" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "image[" << i << "] : " << endl; 
    image[i]->Dessine();
  }
  cout << endl;

  
  cout << "(6.3) Liberation memoire **************************************************************" << endl;
  for (int i=0 ; i<10 ; i++) delete image[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

//***********************************************************************************************
//*** Tests du downcasting et dynamic-cast ******************************************************
//***********************************************************************************************
void Essai7()
{
  srand((unsigned)time(NULL));

  cout << "(7.1) Allocation dynamique d'images ***************************************************" << endl;
  Image* image[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "image[" << i << "] : ";
    int n = rand()%3;
    switch(n)
    {
      case 0 : image[i] = new ImageB(); 
               cout << "ImageB" << endl;
               break;

      case 1 : image[i] = new ImageNG();
               cout << "ImageNG" << endl;
               break;

      case 2 : image[i] = new ImageRGB();
               cout << "ImageRGB" << endl;
               break;
    }
  }
  cout << endl;

  cout << "(7.2) Test du downcasting et dynamic-cast **********************************************" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "image[" << i << "] ";
    ImageB* pB = dynamic_cast<ImageB*>(image[i]);
    if (pB != NULL)
    {
      cout << "est une ImageB";
      pB->setBackground(true);
    }
    ImageNG* pNG = dynamic_cast<ImageNG*>(image[i]);
    if (pNG != NULL) 
    {
      cout << "est une ImageNG";
      pNG->setBackground(128);
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(image[i]);
    if (pRGB != NULL) 
    {
      cout << "est une ImageRGB";
      pRGB->setBackground(Couleur::BLEU);
    }
    cout << endl;
    image[i]->Dessine();
  }
  cout << endl;

  cout << "(7.3) Liberation memoire ****************************************************************" << endl;
  for (int i=0 ; i<10 ; i++) delete image[i];
}


