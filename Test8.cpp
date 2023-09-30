#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>

#include <QApplication>

#include "Dimension.h"
#include "ImageNG.h"
#include "ImageB.h"
#include "ImageRGB.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des methodes Save et Load de la classe Dimension" << endl;
  cout << " 2. Test des mathodes Save et Load de la classe ImageNG" << endl;
  cout << " 3. Test des mathodes Save et Load de la classe ImageB" << endl;
  cout << " 4. Test des methodes Save et Load de la classe Couleur" << endl;
  cout << " 5. Test des methodes Save et Load de la classe ImageRGB" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*********************************************************************************************
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test des methodes Save et Load de la classe Dimension ------" << endl;
  
  Dimension d1(640,480);
  cout << "d1 = " << d1 << endl;
  cout << endl;

  cout << "----- Sauvegarde de la dimension dans le fichier D.dat -----" << endl;
  ofstream fichier1("D.dat",ios::out);
  d1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'objet dimension situe dans le fichier D.dat -----" << endl;
  ifstream fichier2("D.dat",ios::in);
  Dimension d2;
  d2.Load(fichier2);
  fichier2.close();
  cout << "d2 = " << d2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai2()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 2. Test des methodes Save et Load de la classe ImageNG ------" << endl;
  
  ImageNG i1("../images/joconde.bmp");
  cout << "i1 = " << i1 << endl; i1.Dessine();
  cout << endl;

  cout << "----- Sauvegarde de l'image dans le fichier NG.dat -----" << endl;
  ofstream fichier1("NG.dat",ios::out);
  i1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'image situee dans le fichier NG.dat -----" << endl;
  ifstream fichier2("NG.dat",ios::in);
  ImageNG i2;
  i2.Load(fichier2);
  fichier2.close();
  cout << "i2 = " << i2 << endl; i2.Dessine();
  cout << endl;
}

//*********************************************************************************************
void Essai3()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 3. Test des methodes Save et Load de la classe ImageB ------" << endl;
  
  ImageB i1(1,"testBinaire",Dimension(255,255));
  i1.setBackground(false);
  for (int x=0 ; x<255 ; x=x+1) i1.setPixel(x,x,true);
  cout << "i1 = " << i1 << endl; i1.Dessine();
  cout << endl;

  cout << "----- Sauvegarde de l'image dans le fichier B.dat -----" << endl;
  ofstream fichier1("B.dat",ios::out);
  i1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'image situee dans le fichier B.dat -----" << endl;
  ifstream fichier2("B.dat",ios::in);
  ImageB i2;
  i2.Load(fichier2);
  fichier2.close();
  cout << "i2 = " << i2 << endl; i2.Dessine();
  cout << endl;
}

//*********************************************************************************************
void Essai4()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 4. Test des methodes Save et Load de la classe Couleur ------" << endl;
  
  Couleur c1(112,141,35);
  cout << "c1 = " << c1 << endl;
  cout << endl;

  cout << "----- Sauvegarde de la couleur dans le fichier C.dat -----" << endl;
  ofstream fichier1("C.dat",ios::out);
  c1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de la couleur situee dans le fichier C.dat -----" << endl;
  ifstream fichier2("C.dat",ios::in);
  Couleur c2;
  c2.Load(fichier2);
  fichier2.close();
  cout << "c2 = " << c2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai5()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 5. Test des methodes Save et Load de la classe ImageRGB ------" << endl;
  
  ImageRGB i1("../images/joconde.bmp");
  cout << "i1 = " << i1 << endl; i1.Dessine();
  cout << endl;

  cout << "----- Sauvegarde de l'image dans le fichier RGB.dat -----" << endl;
  ofstream fichier1("RGB.dat",ios::out);
  i1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de l'image situee dans le fichier RGB.dat -----" << endl;
  ifstream fichier2("RGB.dat",ios::in);
  ImageRGB* i2 = new ImageRGB();
  i2->Load(fichier2);
  fichier2.close();
  cout << "i2 = " << *i2 << endl; i2->Dessine();
  delete i2;
  cout << endl;
}

