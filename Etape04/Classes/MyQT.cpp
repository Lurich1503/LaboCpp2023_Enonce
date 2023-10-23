#include "MyQT.h"

#include <QImage>
#include <QPixmap>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSize>

//***************************************************************************************
//***** Images NG ***********************************************************************
//***************************************************************************************
void MyQT::ViewImage(const ImageNG & image)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
  	for(int y=0 ; y<hauteur ; y++)
  	{
      int valeur = image.getPixel(x,y);
      im1.setPixel(x,y,qRgb(valeur,valeur,valeur));
  	}
  QPixmap im2 = QPixmap::fromImage(im1);

  // Affichage du QPixmax dans une boite de dialogue
  QLabel *label = new QLabel();
  label->setPixmap(im2);
  label->setAlignment(Qt::AlignCenter);

  QDialog dialog;
  dialog.setStyleSheet("background-color: lightgreen;");
  dialog.setFixedSize(largeur+30,hauteur+30);
  dialog.setWindowTitle(QString::fromStdString(image.getNom()));
  QVBoxLayout* layout = new QVBoxLayout(&dialog);
  layout->addWidget(label);
  dialog.exec();        
}

void MyQT::ImportFromFile(ImageNG & image,const char* fichier)
{
  QPixmap pixmap(fichier);
  if (pixmap.isNull()) return;  // exception ??

  // Recuperation des dimensions de l'image
  QSize size = pixmap.size();
  int largeur = size.width();
  int hauteur = size.height();
  image.setDimension(Dimension(largeur,hauteur));

  // Parsing du QPixmap via un QImage
  QImage im = pixmap.toImage();
  for (int x=0 ; x<largeur ; x++)
  	for (int y=0 ; y<hauteur ; y++)
  	{
      QRgb pixel = im.pixel(x, y);
      int rouge = qRed(pixel);
      int vert = qGreen(pixel);
      int bleu = qBlue(pixel);
      image.setPixel(x,y,(rouge+vert+bleu)/3);
    }
}

void MyQT::ExportToFile(const ImageNG & image, const char* fichier,const char* format)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
  	for(int y=0 ; y<hauteur ; y++)
  	{
      int valeur = image.getPixel(x,y);
      im1.setPixel(x,y,qRgb(valeur,valeur,valeur));
  	}
  QPixmap pixmap = QPixmap::fromImage(im1);

  // Ecriture sur disque
  pixmap.save(fichier,format);
}

//***************************************************************************************
//***** Images RGB **********************************************************************
//***************************************************************************************
/*
void MyQT::ViewImage(const ImageRGB & image)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
    for(int y=0 ; y<hauteur ; y++)
    {
      Couleur valeur = image.getPixel(x,y);
      im1.setPixel(x,y,qRgb(valeur.getRouge(),valeur.getVert(),valeur.getBleu()));
    }
  QPixmap im2 = QPixmap::fromImage(im1);

  // Affichage du QPixmax dans une boite de dialogue
  QLabel *label = new QLabel();
  label->setPixmap(im2);
  label->setAlignment(Qt::AlignCenter);

  QDialog dialog;
  dialog.setStyleSheet("background-color: lightgreen;");
  dialog.setFixedSize(largeur+30,hauteur+30);
  dialog.setWindowTitle(QString::fromStdString(image.getNom()));
  QVBoxLayout* layout = new QVBoxLayout(&dialog);
  layout->addWidget(label);
  dialog.exec();        
}

void MyQT::ImportFromFile(ImageRGB & image,const char* fichier)
{
  QPixmap pixmap(fichier);
  if (pixmap.isNull()) return;  // exception ??

  // Recuperation des dimensions de l'image
  QSize size = pixmap.size();
  int largeur = size.width();
  int hauteur = size.height();
  image.setDimension(Dimension(largeur,hauteur));

  // Parsing du QPixmap via un QImage
  QImage im = pixmap.toImage();
  for (int x=0 ; x<largeur ; x++)
    for (int y=0 ; y<hauteur ; y++)
    {
      QRgb pixel = im.pixel(x, y);
      int rouge = qRed(pixel);
      int vert = qGreen(pixel);
      int bleu = qBlue(pixel);
      image.setPixel(x,y,Couleur(rouge,vert,bleu));
    }
}

void MyQT::ExportToFile(const ImageRGB & image, const char* fichier,const char* format)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
    for(int y=0 ; y<hauteur ; y++)
    {
      Couleur valeur = image.getPixel(x,y);
      im1.setPixel(x,y,qRgb(valeur.getRouge(),valeur.getVert(),valeur.getBleu()));
    }
  QPixmap pixmap = QPixmap::fromImage(im1);

  // Ecriture sur disque
  pixmap.save(fichier,format);
}
*/
//***************************************************************************************
//***** Images B ************************************************************************
//***************************************************************************************
/*
void MyQT::ViewImage(const ImageB & image)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
    for(int y=0 ; y<hauteur ; y++)
    {
      bool valeur = image.getPixel(x,y);
      if (valeur) im1.setPixel(x,y,qRgb(ImageB::couleurTrue.getRouge(),ImageB::couleurTrue.getVert(),ImageB::couleurTrue.getBleu()));
      else im1.setPixel(x,y,qRgb(ImageB::couleurFalse.getRouge(),ImageB::couleurFalse.getVert(),ImageB::couleurFalse.getBleu()));
    }
  QPixmap im2 = QPixmap::fromImage(im1);

  // Affichage du QPixmax dans une boite de dialogue
  QLabel *label = new QLabel();
  label->setPixmap(im2);
  label->setAlignment(Qt::AlignCenter);

  QDialog dialog;
  dialog.setStyleSheet("background-color: lightgreen;");
  dialog.setFixedSize(largeur+30,hauteur+30);
  dialog.setWindowTitle(QString::fromStdString(image.getNom()));
  QVBoxLayout* layout = new QVBoxLayout(&dialog);
  layout->addWidget(label);
  dialog.exec();        
}

void MyQT::ExportToFile(const ImageB & image, const char* fichier,const char* format)
{
  int largeur = image.getDimension().getLargeur();
  int hauteur = image.getDimension().getHauteur();

  // Creation du QPixmap
  QImage im1(largeur,hauteur,QImage::Format_RGB32);
  for(int x=0 ; x<largeur ; x++)
    for(int y=0 ; y<hauteur ; y++)
    {
      bool valeur = image.getPixel(x,y);
      if (valeur) im1.setPixel(x,y,qRgb(ImageB::couleurTrue.getRouge(),ImageB::couleurTrue.getVert(),ImageB::couleurTrue.getBleu()));
      else im1.setPixel(x,y,qRgb(ImageB::couleurFalse.getRouge(),ImageB::couleurFalse.getVert(),ImageB::couleurFalse.getBleu()));
    }
  QPixmap pixmap = QPixmap::fromImage(im1);

  // Ecriture sur disque
  pixmap.save(fichier,format);
}
*/