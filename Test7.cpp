#include <stdlib.h>
#include <iostream>

#include "ArrayList.h"
#include "Iterateur.h"
#include "Couleur.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();

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
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
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
  cout << " 1. Test de base du template ArrayList avec des entiers" << endl;
  cout << " 2. Test du constructeur de copie ArrayList avec des entiers" << endl;
  cout << " 3. Test de l'operateur = de ArrayList avec des entiers" << endl;
  cout << " 4. Test du template ArrayList avec des objets de la classe Couleur" << endl;
  cout << " ---------------------------------------------------------------------" << endl;
  cout << " 5. Test de l'iterateur avec une ArrayList d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une ArrayList de couleurs" << endl;
  cout << " 7. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

/*******************************************************************************************************/
void Essai1()
{
  cout << "----- 1. Test de base du template ArrayList avec des entiers --------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;

  ArrayList<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  liste.insereElement(3);
  liste.insereElement(-2);
  liste.insereElement(5);
  liste.insereElement(-1);
  liste.insereElement(0);
  liste.insereElement(17);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0 17)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << "----- 1.2 On recupere une elements de la Liste dans le supprimer ----------------------------" << endl;
  cout << "On recupere l'element d'indice 3 (-1)  : " << liste.getElement(3) << endl;
  liste.Affiche();

  cout << "----- 1.3 On recupere une elements de la Liste et on le modifie a 100 -----------------------" << endl;
  cout << "On modifie l'element d'indice 4 (0)  : " << endl; 
  liste.getElement(4) = 100;
  liste.Affiche();

  cout << "----- 1.4 On retire des elements de la Liste ------------------------------------------------" << endl;
  cout << "On retire l'element d'indice 4 (100) : " << liste.retireElement(4) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 0 (3)   : " << liste.retireElement(0) << endl;
  liste.Affiche();
  cout << "On retire l'element d'indice 3 (17)  : " << liste.retireElement(3) << endl;
  liste.Affiche();

  cout << endl;
}

/*******************************************************************************************************/
void Essai2()
{
  cout << "----- 2. Test du constructeur de copie ArrayList avec des entiers ---------------------------" << endl;
  cout << "----- 2.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;
  ArrayList<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  liste.insereElement(3);
  liste.insereElement(-2);
  liste.insereElement(5);
  liste.insereElement(-1);
  liste.insereElement(0);
  liste.insereElement(17);
  liste.Affiche();                                       // --> (3 -2 5 -1 0 17)

  cout << "----- 2.2 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    ArrayList<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insereElement(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

/*******************************************************************************************************/
void Essai3()
{
  cout << "----- 3. Test de l'operateur = de ArrayList avec des entiers ---------------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste --------------------------------------------------" << endl;
  ArrayList<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et 17..." << endl;
  liste.insereElement(3);
  liste.insereElement(-2);
  liste.insereElement(5);
  liste.insereElement(-1);
  liste.insereElement(0);
  liste.insereElement(17);
  liste.Affiche();                                       // --> (3 -2 5 -1 0 17)

  cout << "----- 3.2 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    ArrayList<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 50 dans la nouvelle liste :" << endl; 
    liste3.insereElement(50);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

/*********************************************************************************************/
void Essai4()
{
  cout << "----- 4. Test du template ArrayList avec des objets de la classe Couleur --------------" << endl;
  cout << "Creation  d'une ArrayList..." << endl;
  ArrayList<Couleur> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere Couleur(128,23,89)..." << endl;
  liste.insereElement(Couleur(128,23,89));
  liste.Affiche();

  cout << "On insere Couleur(100,100,100)..." << endl;
  Couleur c(100,100,100);
  liste.insereElement(c);
  liste.Affiche();

  cout << "On insere Couleur::ROUGE..." << endl;
  liste.insereElement(Couleur::ROUGE);
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << endl;
}

/*******************************************************************************************************/
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une ArrayList d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  ArrayList<int> liste;

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insereElement(3);
  liste.insereElement(-2);
  liste.insereElement(5);
  liste.insereElement(-1);
  liste.insereElement(0);

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<int> it(liste);
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On modifie l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  it.reset();
  it++;
  &it = 100;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime l'element d'indice 3 et on re-affiche grace a l'iterateur..." << endl;
  liste.retireElement(3);
  it.reset();
  while (!it.end())
  {
    cout << " " << (int)it << endl;
    it++;
  }
}

/*******************************************************************************************************/
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une ArrayList de couleurs ---------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  ArrayList<Couleur> liste;
  
  cout << "On insere quelques couleurs..." << endl;
  liste.insereElement(Couleur::BLEU);
  liste.insereElement(Couleur::BLANC);
  liste.insereElement(Couleur(128,0,36));
  liste.insereElement(Couleur(0,128,255));

  cout << "On affiche grace a un iterateur..." << endl;
  Iterateur<Couleur> it(liste);
  for (it.reset() ; !it.end() ; it++)
  {
    Couleur c = (Couleur) it;
    cout << " " << c << endl;
  }
  cout << endl;

  cout << "On supprime l'element d'indice 1 et on re-affiche grace a l'iterateur..." << endl;
  liste.retireElement(1);
  it.reset();
  while (!it.end())
  {
    cout << " " << (Couleur)it << endl;
    it++;
  }
}

/*******************************************************************************************************/
