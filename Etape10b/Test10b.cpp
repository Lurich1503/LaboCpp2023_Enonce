#include <iostream>
using namespace std;
#include <unistd.h>
#include <QApplication>

#include "PhotoShop.h"
#include "ImageNG.h"
#include "ImageB.h"
#include "ImageRGB.h"
#include "Traitements.h"

int main(int argc,char* argv[])
{
  // Initialisation de QT
  QApplication app(argc,argv);
  close(2);

  // Creation du Garage
  // implicite !!! (variable statique)

  // Ajout d'images
  cout << endl << "//***** Ajout d'images à la biblothèque ******************************" << endl;
  cout << "Ajout image NG \"../images/joconde.bmp\"..." << endl;
  PhotoShop::getInstance().ajouteImage(new ImageNG("../images/joconde.bmp"));

  cout << "Ajout image NG \"../images/lena.bmp\"..." << endl;
  ImageNG *p = new ImageNG();
  p->importFromFile("../images/lena.bmp");
  p->setNom("lena");
  PhotoShop::getInstance().ajouteImage(p);

  cout << "Ajout image B lena seuillée à 128..." << endl;
  PhotoShop::getInstance().ajouteImage(new ImageB(Traitements::Seuillage(*p,128)));

  cout << "Ajout image NG dessin à moi..." << endl;
  p = new ImageNG();
  p->setNom("monDessin");
  p->setDimension(Dimension(400,200));
  p->setBackground(100);
  for(int i=0 ; i<200 ; i++)
    p->setPixel(i,i,250);
  PhotoShop::getInstance().ajouteImage(p);

  cout << "Ajout image RGB \"../images/mandrill.bmp\"..." << endl;
  PhotoShop::getInstance().ajouteImage(new ImageRGB("../images/mandrill.bmp"));

  cout << endl << "//***** Images de la biblothèque *************************************" << endl;
  PhotoShop::getInstance().afficheImages();
  PhotoShop::getInstance().dessineImages();

  cout << endl << "//***** Ajout de 2 images par copie **********************************" << endl;
  cout << "Copie image id=3..." << endl;
  Image* pImage = PhotoShop::getInstance().getImageParId(3);
  ImageB *pB = (ImageB*)pImage;                 // downcasting dangereux !!!
  PhotoShop::getInstance().ajouteImage(new ImageB(*pB));
  cout << "Copie image indice=1..." << endl;
  pImage = PhotoShop::getInstance().getImageParIndice(1);
  ImageNG *pNG = (ImageNG*)pImage;              // downcasting dangereux !!!
  PhotoShop::getInstance().ajouteImage(new ImageNG(*pNG));

  cout << endl << "//***** Images de la biblothèque *************************************" << endl;
  PhotoShop::getInstance().afficheImages();

  cout << endl << "//***** Apres suppression par indice (1) *****************************" << endl;
  PhotoShop::getInstance().supprimeImageParIndice(1);
  PhotoShop::getInstance().afficheImages();

  cout << endl << "//***** Apres suppression par id (4) *********************************" << endl;
  PhotoShop::getInstance().supprimeImageParId(4);
  PhotoShop::getInstance().afficheImages();  
  
  return 0;
}

