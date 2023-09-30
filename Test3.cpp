#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include <QApplication>
#include "ImageNG.h"
#include "Dimension.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

//*******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 3 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageNG" << endl;
  cout << " 2. Tests de importFromFile, getPixel et exportToFile de ImageNG" << endl;
  cout << " 3. Tests de setDimension de ImageNG" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}


//*************************************************************************************************
//*** Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageNG *************** 
//*************************************************************************************************
void Essai1()
{
  cout << endl << "***** (1) Tests de setBackground, setPixel, Dessine et constructeur de copie de ImageNG ********" << endl;
  
  ImageNG image1(1,"test",Dimension(300,300));
  image1.setBackground(100);
  for (int x=0 ; x<300 ; x=x+4) image1.setPixel(x,x,255);
  cout << "Voici image1..." << endl;
  image1.Affiche();
  image1.Dessine();

  {
    ImageNG image2 (image1);
    cout << "On modifie la copie image2 de image1..." << endl;
    for (int x=0 ; x<300 ; x=x+4) image2.setPixel(x,299-x,255);
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
//*** Test de importFromFile, getPixel et exportToFile de ImageNG ********************************* 
//*************************************************************************************************
void Essai2()
{
  cout << endl << "***** (2) Tests de importFromFile, getPixel et exportToFile de ImageNG *************************" << endl;
  
  ImageNG image;
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
  for (int x=0 ; x<255 ; x++) image.setPixel(x,(x*x/255),255); // Dessin d'une parabole blanche :)
  image.Dessine();
  image.exportToFile("joconde2.png","PNG");
}

//*************************************************************************************************
//*** Tests de setDimension de ImageNG ************************************************************** 
//*************************************************************************************************
void Essai3()
{
  cout << endl << "***** (3) Tests de setDimension de ImageNG **********************************************" << endl;
  
  ImageNG image;
  cout << "Importation d'une image à partir du fichier mandrill.bmp......" << endl;
  image.importFromFile("../images/mandrill.bmp");
  image.Affiche();
  image.Dessine();

  cout << "On agrandit la taille de l'image......" << endl;
  image.setDimension(Dimension::VGA); // Attention à la taille de la matrice de l'image !!
  image.Affiche();
  image.Dessine();

  cout << "On reduit la taille de l'image......" << endl;
  image.setDimension(Dimension(100,100));
  image.Affiche();
  image.Dessine();
}
