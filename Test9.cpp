#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include <QApplication>

#include "ImageNG.h"
#include "ImageB.h"
#include "Traitements.h"

using namespace std;

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
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 9 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du Seuillage d'une ImageNG" << endl;
  cout << " 2. Test du filtre moyenneur sur une ImageNG" << endl;
  cout << " 3. Test du filtre median sur une ImageNG" << endl;
  cout << " 4. Test de l'erosion sur une ImageNG" << endl;
  cout << " 5. Test de la dilatation sur une ImageNG" << endl;
  cout << " 6. Essai de detection de contours sur une ImageNG" << endl;
  cout << " 7. Test du negatif sur une ImageNG" << endl;
  cout << " 8. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
void Essai1()
{
  cout << "***** 1. Test du Seuillage d'une ImageNG *****************************************************" << endl;

  ImageNG image("../images/joconde.bmp");
  image.setNom("joconde");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int seuil;
  cout << "Seuil = ";
  cin >> seuil;
  cin.ignore();

  ImageB imageSeuillee;
  imageSeuillee = Traitements::Seuillage(image,seuil);

  cout << "Voici l'image seuillee : " << imageSeuillee << endl; imageSeuillee.Dessine();
}

//*******************************************************************************************************
void Essai2()
{
  cout << "***** 2. Test du filtre moyenneur sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  image.setNom("lena");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG imageFiltree;
  imageFiltree = Traitements::FiltreMoyenneur(image,3);

  cout << "Voici l'image filtree : " << imageFiltree << endl; imageFiltree.Dessine();

  ImageNG image2("../images/mandrill.bmp");
  image2.setNom("mandrill");
  cout << "Voici l'image de départ : " << image << endl; image2.Dessine();

  ImageNG imageFiltree2;
  imageFiltree2 = Traitements::FiltreMoyenneur(image2,11);

  cout << "Voici l'image filtree : " << imageFiltree2 << endl; imageFiltree2.Dessine();
}

//*******************************************************************************************************
void Essai3()
{
  cout << "***** 3. Test du filtre median sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/house.bmp");
  image.setNom("house");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::FiltreMedian(image,taille);

  cout << "Voici l'image filtree : " << imageFiltree << endl; imageFiltree.Dessine();
}

//*******************************************************************************************************
void Essai4()
{
  cout << "***** 4. Test de l'erosion sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  image.setNom("lena");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::Erosion(image,taille);

  cout << "Voici l'image erodee : " << imageFiltree << endl; imageFiltree.Dessine();
}

//*******************************************************************************************************
void Essai5()
{
  cout << "***** 5. Test de la dilatation sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  image.setNom("lena");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::Dilatation(image,taille);

  cout << "Voici l'image dilatee : " << imageFiltree << endl; imageFiltree.Dessine();
}

//*******************************************************************************************************
void Essai6()
{
  cout << "***** 6. Essai de detection de contours sur une ImageNG ************************************" << endl;

  ImageNG image("../images/joconde.bmp");
  image.setNom("joconde");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG imageResultat;
  imageResultat = Traitements::Dilatation(image,3) - Traitements::Erosion(image,3);
  imageResultat.setNom("joconde-contours");

  cout << "Voici l'image contours : " << imageResultat << endl; imageResultat.Dessine();
}

//*******************************************************************************************************
void Essai7()
{
  cout << "***** 7. Test du negatif sur une ImageNG ************************************" << endl;

  ImageNG image("../images/bulles.bmp");
  image.setNom("bulles");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG negatif;
  negatif = Traitements::Negatif(image);

  cout << "Voici l'image negatif : " << negatif << endl; negatif.Dessine();
}

