#include <stdlib.h>
#include <iostream>
using namespace std;

#include "ImageNG.h"
#include "Dimension.h"

int  Menu();
void Essai1();
void Essai2();

int main(int argc,char* argv[])
{
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
  cout << "--- JEU DE TESTS 2 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Dimension" << endl;
  cout << " 2. Tests de la classe ImageNG (avec agregation par valeur avec Dimension)" << endl;
  cout << " 3. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

//*******************************************************************************************************
//*** Tests de la Dimension *****************************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << endl << "(1) ***** Test constructeurs par defaut + Affiche ******************************************" << endl;
  {
    Dimension d1,d2(600,400),d3(d2);
    d1.Affiche();
    d2.Affiche();
    d3.Affiche();
  }

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Dimension dim;
    dim.setLargeur(360);
    dim.setHauteur(240);
    cout << "Largeur = " << dim.getLargeur() << endl;
    cout << "Hauteur = " << dim.getHauteur() << endl;
  }

  cout << endl << "(3) ***** Tests de base des objets statiques ***********************************************" << endl;
  Dimension::VGA.Affiche(); // VGA est un objet de la classe Dimension, il possede donc la methode Affiche()
  Dimension::FULL_HD.Affiche();
  cout << endl;

  //Couleur::VGA.setLargeur(100); // --> ne compile pas car l'objet VGA est un objet constant (voir enonce) !!!

  cout << endl << "(4) ***** Copie des objets statiques *******************************************************" << endl;
  Dimension d(Dimension::HD);
  d.Affiche();
  d.setLargeur(600);   // compile car d n'est pas un objet constant
  d.Affiche();
  cout << endl;
}

//*************************************************************************************************
//*** Tests de la classe ImageNG + agregation par valeur avec Dimension *************************** 
//*************************************************************************************************
void Essai2()
{
  cout << endl << "(1) ***** Test du constructeur par defaut de ImageNG ************************************" << endl;
  { 
    ImageNG i;
    i.Affiche();
  }

  cout << endl << "(2) ***** Test du constructeur d'initialisation complet *********************************" << endl;
  { 
    Dimension d(800,600);
    ImageNG i1(2,"boat",d);
    i1.Affiche();

    ImageNG i2(7,"car",Dimension(1024,780));
    i2.Affiche();
    
    ImageNG i3(6,"house",Dimension::FULL_HD);
    i3.Affiche();
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation partiel *********************************" << endl;
  { 
    ImageNG i1(13,"house");
    i1.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie + setters/getters ******************************" << endl;
  { 
    ImageNG i(3,"flowers",Dimension::VGA);
    cout << "Voici i : " << endl;
    i.Affiche();
    cout << "Sa dimension est : ";
    i.getDimension().Affiche();
    {
      ImageNG i2(i);
      cout << endl << "Voici la copie i2 : " << endl;
      i2.Affiche();
      cout << "On modifie la dimension de i2 :" << endl;
      i2.setDimension(Dimension(800,600));
      i2.Affiche();
      cout << "La copie i2 est détruite..." << endl;
    }
    cout << endl << "Re-voici i : " << endl;
    i.Affiche();
    cout << "Et sa dimension est : ";
    i.getDimension().Affiche();
  }
}

