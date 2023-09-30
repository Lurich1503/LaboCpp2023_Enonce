#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Classes/ImageNG.h"

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cpp contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

int main()
{

  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************************" << endl;
  {
    ImageNG image;
    image.Affiche();
  } // La presence des accolades assure que le destructeur de ImageNG sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    ImageNG image;
    image.Affiche();
    image.setId(3);
    image.setNom("joconde");
    image.Affiche();
    cout << "Nom = " << image.getNom() << endl;
    cout << "Id  = " << image.getId() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation ********************************************" << endl;
  {
    ImageNG image(6,"boat");
    image.Affiche();
  }


  cout << endl << "(4) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    ImageNG image1(2,"joconde");
    cout << "image1 (AVANT) :" << endl;
    image1.Affiche();
    {   
      ImageNG image2(image1);
      cout << "image2 :" << endl;
      image2.Affiche();
      cout << "--> on modifie la copie" << endl;
      image2.setNom("superman");
      image2.Affiche();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que image2 sera detruit avant la suite
    cout << "image1 (APRES) :" << endl;
    image1.Affiche();
  }


  cout << endl << "(5) ***** Test d'allocation dynamique ******************************************************" << endl;
  { // Vous n'avez rien à faire... juste comprendre et savoir expliquer!!!
    ImageNG *i = new ImageNG();
    i->Affiche();
    delete i;
    i = new ImageNG(12,"fleur");
    i->setNom("rose");
    i->Affiche();
    delete i;
  }


  return 0;
}


