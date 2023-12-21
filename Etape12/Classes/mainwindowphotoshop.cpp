#include "mainwindowphotoshop.h"
#include "ui_mainwindowphotoshop.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QScreen>
#include <QRect>
#include <QPixmap>
#include <QColorDialog>


#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "PhotoShop.h"
#include "Iterateur.h"
#include "Traitements.h"
#include "XYException.h"
#include "ArrayList.h"
#include "ArrayListException.h"
#include "RGBException.h"
#include "Exception.h"
#include "Couleur.h"


MainWindowPhotoShop::MainWindowPhotoShop(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindowPhotoShop)
{
    ui->setupUi(this);
    setTitre("Mini-PhotoShop  en C++");

    // Centrage de la fenetre
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
    setFixedSize(1021,845);

    // Configuration de la table des images
    ui->tableWidgetImages->setColumnCount(4);
    ui->tableWidgetImages->setRowCount(0);
    QStringList labelsTableOptions;
    labelsTableOptions << "Id" << "Type" << "Dimension" << "Nom";
    ui->tableWidgetImages->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetImages->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetImages->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetImages->horizontalHeader()->setVisible(true);
    ui->tableWidgetImages->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetImages->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetImages->verticalHeader()->setVisible(false);
    ui->tableWidgetImages->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Intialisation des scrollArea
    
    setImageNG("selection");
    setImageNG("operande1");
    setImageNG("operande2");
    setImageNG("resultat");
  

    // ComboBox des traitements disponibles
    ajouteTraitementDisponible("Eclaircir (+ val)");
    ajouteTraitementDisponible("Eclaircir (++)");
    ajouteTraitementDisponible("Assombrir (- val)");
    ajouteTraitementDisponible("Assombrir (--)");
    ajouteTraitementDisponible("Différence");
    ajouteTraitementDisponible("Comparaison (==)");
    ajouteTraitementDisponible("Comparaison (<)");
    ajouteTraitementDisponible("Comparaison (>)");
    ajouteTraitementDisponible("Seuillage");
    ajouteTraitementDisponible("Filtre moyenneur");
    ajouteTraitementDisponible("Filtre médian");
    ajouteTraitementDisponible("Erosion");
    ajouteTraitementDisponible("Dilatation");
    ajouteTraitementDisponible("Négatif");

    // Etape 14 (TO DO)
    // Restauration bibliothèque via fichier de sauvegarde
}

MainWindowPhotoShop::~MainWindowPhotoShop()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Méthodes de la fenêtre (ne pas modifier) ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setTitre(string titre)
{
  this->setWindowTitle(titre.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setNomImage(string nom)
{
  ui->lineEditNom->setText(QString::fromStdString(nom));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getNomImage() const
{
  return ui->lineEditNom->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setParametresImageNG(int max,int min,int luminance,float contraste)
{
  if (max == -1)
  {
    ui->lineEditMax->setText("");
    ui->lineEditMin->setText("");
    ui->lineEditLuminance->setText("");
    ui->lineEditContraste->setText("");
    return;
  }
  char tmp[20];
  sprintf(tmp,"%d",max);
  ui->lineEditMax->setText(tmp);
  sprintf(tmp,"%d",min);
  ui->lineEditMin->setText(tmp);
  sprintf(tmp,"%d",luminance);
  ui->lineEditLuminance->setText(tmp);
  sprintf(tmp,"%f",contraste);
  ui->lineEditContraste->setText(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageNG(string destination,const ImageNG* imageng)
{
    QPixmap * pixmap = NULL;
    if (imageng != NULL)
    {
      // Creation du QPixmap
      int largeur = imageng->getDimension().getLargeur();
      int hauteur = imageng->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          int valeur = imageng->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur,valeur,valeur));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageRGB(string destination,const ImageRGB* imagergb)
{
    QPixmap * pixmap = NULL;
    if (imagergb != NULL)
    {
      // Creation du QPixmap
      int largeur = imagergb->getDimension().getLargeur();
      int hauteur = imagergb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          Couleur valeur = imagergb->getPixel(x,y);
          im1.setPixel(x,y,qRgb(valeur.getRouge(),valeur.getVert(),valeur.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindowPhotoShop::setImageB(string destination,const ImageB* imageb)
{
    QPixmap * pixmap = NULL;
    if (imageb != NULL)
    {
      // Creation du QPixmap
      int largeur = imageb->getDimension().getLargeur();
      int hauteur = imageb->getDimension().getHauteur();
      QImage im1(largeur,hauteur,QImage::Format_RGB32);
      for(int x=0 ; x<largeur ; x++)
        for(int y=0 ; y<hauteur ; y++)
        {
          bool valeur = imageb->getPixel(x,y);
          if (valeur) im1.setPixel(x,y,qRgb(ImageB::couleurTrue.getRouge(),ImageB::couleurTrue.getVert(),ImageB::couleurTrue.getBleu()));
          else im1.setPixel(x,y,qRgb(ImageB::couleurFalse.getRouge(),ImageB::couleurFalse.getVert(),ImageB::couleurFalse.getBleu()));
        }
     pixmap = new QPixmap(QPixmap::fromImage(im1));
    }

    // Mise en place du QPixmap
    QLabel* label = new QLabel();
    label->setAlignment(Qt::AlignCenter);
    if (pixmap) label->setPixmap(*pixmap);
    else label->setText("vide");
    if (destination == "selection") ui->scrollAreaSelection->setWidget(label);
    if (destination == "operande1") ui->scrollAreaOperande1->setWidget(label);
    if (destination == "operande2") ui->scrollAreaOperande2->setWidget(label);
    if (destination == "resultat") ui->scrollAreaResultat->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::setResultatBoolean(int val)
{
  if (val == 1) // vrai
  {
    ui->checkBoxResultat->setChecked(true);
    ui->checkBoxResultat->setText("VRAI");
    ui->checkBoxResultat->setStyleSheet("background-color: lightgreen;border: 1px solid black;");
    return;
  }
  if (val == 0) // faux
  {
    ui->checkBoxResultat->setChecked(false);
    ui->checkBoxResultat->setText("FAUX");
    ui->checkBoxResultat->setStyleSheet("background-color: red;border: 1px solid black;");
    return;
  }
  // ni vrai, ni faux
  ui->checkBoxResultat->setChecked(false);
  ui->checkBoxResultat->setText("Résultat");
  ui->checkBoxResultat->setStyleSheet("background-color: lightyellow;border: 1px solid black;");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Images (ne pas modifier) ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTupleTableImages(int id,string type,string dimension,string nom)
{
    char Id[20];
    sprintf(Id,"%d",id);

    char Type[20];
    strcpy(Type,type.c_str());

    char Dimension[20];
    strcpy(Dimension,dimension.c_str());

    char Nom[80];
    strcpy(Nom,nom.c_str());

    // Ajout possible
    int nbLignes = ui->tableWidgetImages->rowCount();
    nbLignes++;
    ui->tableWidgetImages->setRowCount(nbLignes);
    ui->tableWidgetImages->setRowHeight(nbLignes-1,20);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Id);
    ui->tableWidgetImages->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Type);
    ui->tableWidgetImages->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(Dimension);
    ui->tableWidgetImages->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(Nom);
    ui->tableWidgetImages->setItem(nbLignes-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTableImages()
{
    ui->tableWidgetImages->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::getIndiceImageSelectionnee()
{
    QModelIndexList liste = ui->tableWidgetImages->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des traitements disponibles (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::ajouteTraitementDisponible(string operation)
{
    ui->comboBoxTraitements->addItem(operation.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::videTraitementsDisponibles()
{
    ui->comboBoxTraitements->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::getTraitementSelectionne() const
{
    return ui->comboBoxTraitements->currentText().toStdString();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue (ne pas modifier) ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int MainWindowPhotoShop::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float MainWindowPhotoShop::dialogueDemandeFloat(const char* titre,const char* question)
{
    return QInputDialog::getDouble(this,titre,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierOuvrir(const char* question)
{
  QString fileName = QFileDialog::getOpenFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string MainWindowPhotoShop::dialogueDemandeFichierEnregistrer(const char* question)
{
  QString fileName = QFileDialog::getSaveFileName(this,question, "", "Tous les fichiers (*.*)");
  return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::dialogueDemandeCouleur(const char* message,int* pRouge,int* pVert,int* pBleu)
{
  QColor color = QColorDialog::getColor(Qt::red,this,message);
  *pRouge = color.red();
  *pVert = color.green();
  *pBleu = color.blue();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Clic sur la croix de la fenêtre ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::closeEvent(QCloseEvent *event)
{
  if (event == NULL) {} // pour éviter le warning à la compilation
  // Etape 14 (TO DO)

  QApplication::exit();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionQuitter_triggered()
{
  // Etape 14 (TO DO)

  QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageNB_triggered()
{
  // Etape 11 (TO DO)
  string NomFichier, type;


  NomFichier = dialogueDemandeFichierOuvrir("chargez une ImageNG :");
  if(extension_valide(NomFichier)== -1)
  {
      dialogueErreur("erreur de nom de fichier", "le nom de fichier de l'image doit se terminer par .jpg ou .bmp ou .png !");
  }
  else
  {
    ImageNG* instance;

    instance = new ImageNG(NomFichier);
    instance->importFromFile(NomFichier);

    PhotoShop::getInstance().ajouteImage(instance);

    videTableImages();

    ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
    Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

    for(it.reset(); !it.end(); it++)
    {
      ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
      if(pNG != NULL)
      {
        type = "NG";
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
        if(pRGB != NULL)
        {
          type = "RGB";
        }
        else
        {
          type = "B";
        }
      }
      ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
    }
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCharger_ImageRGB_triggered()
{
  // Etape 11 (TO DO)
  string NomFichier, type;


  NomFichier = dialogueDemandeFichierOuvrir("chargez une ImageRGB :");

  if(extension_valide(NomFichier)== -1)
  {
      dialogueErreur("erreur de nom de fichier", "le nom de fichier de l'image doit se terminer par .jpg ou .bmp ou .png !");
  }
  else
  {

    ImageRGB* instance;

    instance = new ImageRGB(NomFichier);
    instance->importFromFile(NomFichier);

    PhotoShop::getInstance().ajouteImage(instance);

    videTableImages();

    ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
    Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

    for(it.reset(); !it.end(); it++)
    {
      ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
      if(pNG != NULL)
      {
        type = "NG";
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
        if(pRGB != NULL)
        {
          type = "RGB";
        }
        else
        {
          type = "B";
        }
      }
      ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
    }
  }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageNB_triggered()
{
  // Etape 11 (TO DO)
  int indice;
  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
     Image* instance = PhotoShop::getInstance().getImageParIndice(indice);

     ImageNG* pNG = dynamic_cast<ImageNG*>(instance);

     if(pNG == NULL)
     {
        dialogueErreur("erreur de type", "type ne correspond pas a une imageNG !");
     }
     else
     {
       string Nom, Format;
       Nom = dialogueDemandeFichierEnregistrer("Veuillez entrez le nom du fichier de l'image a enregistrer :");

       if(extension_valide(Nom)== -1)
       {
          dialogueErreur("erreur de nom de fichier", "le nom de fichier doit se terminer par .jpg ou .bmp ou .png !");
       }
       else
       {
          Format = dialogueDemandeTexte("Format", "Veuillez entrer le format du fichier :");
          if(Format != "JPG" && Format != "BMP" && Format != "PNG")
          {
              dialogueErreur("erreur de format", "le format doit etre soit JPG, BMP ou PNJ !");
          }
          else
          {
              pNG->exportToFile(Nom,Format);
          }
       }
     }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageRGB_triggered()
{
  // Etape 11 (TO DO)
  int indice;
  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
     Image* instance = PhotoShop::getInstance().getImageParIndice(indice);

     ImageRGB* pRGB = dynamic_cast<ImageRGB*>(instance);

     if(pRGB == NULL)
     {
        dialogueErreur("erreur de type", "type ne correspond pas a une imageRGB !");
     }
     else
     {
       string Nom, Format;
       Nom = dialogueDemandeFichierEnregistrer("Veuillez entrez le nom du fichier de l'image a enregistrer :");

       if(extension_valide(Nom)== -1)
       {
          dialogueErreur("erreur de nom de fichier", "le nom de fichier doit se terminer par .jpg ou .bmp ou .png !");
       }
       else
       {
          Format = dialogueDemandeTexte("Format", "Veuillez entrer le format du fichier :");
          if(Format != "JPG" && Format != "BMP" && Format != "PNG")
          {
              dialogueErreur("erreur de format", "le format doit etre soit JPG, BMP ou PNJ !");
          }
          else
          {
              pRGB->exportToFile(Nom,Format);
          }
       }
     }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionEnregistrer_ImageB_triggered()
{
  // Etape 11 (TO DO)
  int indice;
  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
     Image* instance = PhotoShop::getInstance().getImageParIndice(indice);

     ImageB* pB = dynamic_cast<ImageB*>(instance);

     if(pB == NULL)
     {
        dialogueErreur("erreur de type", "type ne correspond pas a une imageB !");
     }
     else
     {
       string Nom, Format;
       Nom = dialogueDemandeFichierEnregistrer("Veuillez entrez le nom du fichier de l'image a enregistrer :");

       if(extension_valide(Nom)== -1)
       {
          dialogueErreur("erreur de nom de fichier", "le nom de fichier doit se terminer par .jpg ou .bmp ou .png !");
       }
       else
       {
          Format = dialogueDemandeTexte("Format", "Veuillez entrer le format du fichier :");
          if(Format != "JPG" && Format != "BMP" && Format != "PNG")
          {
              dialogueErreur("erreur de format", "le format doit etre soit JPG, BMP ou PNJ !");
          }
          else
          {
              pB->exportToFile(Nom,Format);
          }
       }
     }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_selectionn_e_triggered()
{
  // Etape 11 (TO DO)
  int indice;
  string type;
  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
    PhotoShop::getInstance().supprimeImageParIndice(indice);
    videTableImages();
    ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
    Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

    for(it.reset(); !it.end(); it++)
    {
      ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
      if(pNG != NULL)
      {
        type = "NG";
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
        if(pRGB != NULL)
        {
          type = "RGB";
        }
        else
        {
          type = "B";
        }
      }
      ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
    }
    setImageNG("selection",NULL);
    setParametresImageNG(-1, -1, -1, 0);
    setNomImage("");
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImage_par_id_triggered()
{
  // Etape 11 (TO DO)
  int id;
  string type;
  id = dialogueDemandeInt("Supprimer image par id", "veuillez entrer un id :");
  try
  {
    PhotoShop::getInstance().supprimeImageParId(id);
  }
  catch(const ARRAYLISTException& m)
  {
    cout << "Exception ARRAYLISTException catchee..." << endl;
    cout << "message = " << m.getMessageErreur() << endl;
    cout << "valeur de l'indice = " << m.getValeur() << endl;
    dialogueErreur("erreur indice selectionnee","aucune image pour cet id dans la liste !");
  }
    videTableImages();
    ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
    Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

    for(it.reset(); !it.end(); it++)
    {
      ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
      if(pNG != NULL)
      {
        type = "NG";
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
        if(pRGB != NULL)
        {
          type = "RGB";
        }
        else
        {
          type = "B";
        }
      }
      ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
    }
    setImageNG("selection",NULL);
    setParametresImageNG(-1, -1, -1, 0);
    setNomImage("");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_TRUE_pour_ImageB_triggered()
{
  // Etape 12 (TO DO)
    int rouge, vert, bleu;
    dialogueDemandeCouleur("Veuillez choisir la couleur TRUE pour les imagesB :",&rouge,&vert,&bleu);
    Couleur nouvelleCouleur(rouge, vert, bleu);
    ImageB::couleurTrue = nouvelleCouleur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_FALSE_pour_imageB_triggered()
{
  // Etape 12 (TO DO)
    int rouge, vert, bleu;
    dialogueDemandeCouleur("Veuillez choisir la couleur FALSE pour les imagesB :",&rouge,&vert,&bleu);
    Couleur nouvelleCouleur(rouge, vert, bleu);
    ImageB::couleurFalse = nouvelleCouleur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionImporterCSV_triggered()
{
  // Etape 13 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionReset_triggered()
{
  // Etape 14 (TO DO)

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions selection sur la table des images ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_tableWidgetImages_itemSelectionChanged()
{
  // Etape 11 (TO DO)
  int indice;
  indice = getIndiceImageSelectionnee();
   if(indice != -1) // si on supprime l'image que l'on sélectionne ne pas demander l'image 
  {
    Image* instance = PhotoShop::getInstance().getImageParIndice(indice);
    setNomImage(instance->getNom());

    ImageNG* pNG = dynamic_cast<ImageNG*>(instance);
    if(pNG != NULL)
     {
        setParametresImageNG(pNG->getMaximum(), pNG->getMinimum(), pNG->getLuminance(), pNG->getContraste());
        setImageNG("selection",pNG);
     }
     else
     {
        setParametresImageNG(-1, -1, -1, 0);

        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(instance);
        if(pRGB != NULL)
        {
          setImageRGB("selection",pRGB);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(instance);
          if(pB != NULL)
          {
            setImageB("selection",pB);
          }
        }
     }
  }


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonModifierNom_clicked()
{
  // Etape 11 (TO DO)
  string nom, type;
  int indice;

  nom = getNomImage();

  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
      Image* instance = PhotoShop::getInstance().getImageParIndice(indice);

      instance->setNom(nom);

      videTableImages();
      ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
      Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

      for(it.reset(); !it.end(); it++)
      {
        ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
        if(pNG != NULL)
        {
          type = "NG";
        }
        else
        {
          ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
          if(pRGB != NULL)
          {
            type = "RGB";
          }
          else
          {
            type = "B";
          }
        }
        ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
      }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande1_clicked()
{
    // Etape 12 (TO DO)
  int indice;

  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
      Image* instance = PhotoShop::getInstance().getImageParIndice(indice);
      PhotoShop::operande1 = instance;

      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
      if(pNG != NULL)
      {
        setImageNG("operande1", pNG);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(PhotoShop::operande1);
        if(pRGB != NULL)
        {
          setImageRGB("operande1", pRGB);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::operande1);
          if(pB != NULL)
          {
            setImageB("operande1",pB);
          }
        }
      }
  }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimeOperande1_clicked()
{
    // Etape 12 (TO DO)
      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
      if(pNG != NULL)
      {
        setImageNG("operande1", NULL);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(PhotoShop::operande1);
        if(pRGB != NULL)
        {
          setImageRGB("operande1", NULL);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::operande1);
          if(pB != NULL)
          {
            setImageB("operande1",NULL);
          }
        }
      }
    PhotoShop::operande1 = NULL;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonOperande2_clicked()
{
    // Etape 12 (TO DO)
   int indice;

  indice = getIndiceImageSelectionnee();
  if(indice == -1)
  {
    dialogueErreur("erreur image selectionnee","aucune image selectionnee !");
  }
  else
  {
      Image* instance = PhotoShop::getInstance().getImageParIndice(indice);
      PhotoShop::operande2 = instance;

      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande2);
      if(pNG != NULL)
      {
        setImageNG("operande2", pNG);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(PhotoShop::operande2);
        if(pRGB != NULL)
        {
          setImageRGB("operande2", pRGB);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::operande2);
          if(pB != NULL)
          {
            setImageB("operande2",pB);
          }
        }
      }
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerOperande2_clicked()
{
    // Etape 12 (TO DO)
      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande2);
      if(pNG != NULL)
      {
        setImageNG("operande2", NULL);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(PhotoShop::operande2);
        if(pRGB != NULL)
        {
          setImageRGB("operande2", NULL);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::operande2);
          if(pB != NULL)
          {
            setImageB("operande2",NULL);
          }
        }
      }
    PhotoShop::operande2 = NULL;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonResultat_clicked()
{
    // Etape 12 (TO DO)
  string type;
  if(PhotoShop::resultat != NULL)
  {
      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::resultat);
      if(pNG != NULL)
      {
          ImageNG* instance;

          instance = new ImageNG((*pNG));

          PhotoShop::getInstance().ajouteImage(instance);

          videTableImages();

          ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
          Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

          for(it.reset(); !it.end(); it++)
          {
            ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
            if(pNG != NULL)
            {
              type = "NG";
            }
            else
            {
              ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
              if(pRGB != NULL)
              {
                type = "RGB";
              }
              else
              {
                type = "B";
              }
            }
            ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
          }
          setImageNG("resultat", NULL);
      }
      else
      {
        ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::resultat);
        if(pB != NULL)
        {
            ImageB* instance;

            instance = new ImageB((*pB));

            PhotoShop::getInstance().ajouteImage(instance);

            videTableImages();

            ArrayList<Image*> image = PhotoShop::getInstance().getArraylist(); // récupère la liste qui existe
            Iterateur<Image*> it(image);                                       // attache l'iterateur a cette liste

            for(it.reset(); !it.end(); it++)
            {
              ImageNG* pNG = dynamic_cast<ImageNG*>(&it);
              if(pNG != NULL)
              {
                type = "NG";
              }
              else
              {
                ImageRGB* pRGB = dynamic_cast<ImageRGB*>(&it);
                if(pRGB != NULL)
                {
                  type = "RGB";
                }
                else
                {
                  type = "B";
                }
              }
              ajouteTupleTableImages((&it)->getId(), type, to_string((&it)->getDimension().getLargeur()) + "x" + to_string((&it)->getDimension().getHauteur()), (&it)->getNom());
            }
            setImageB("resultat", NULL);
        }
      }
      PhotoShop::resultat = NULL;
  }
  else
  {
    dialogueErreur("image resultat","aucune image a charger !");
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerResultat_clicked()
{
    // Etape 12 (TO DO)
  if(PhotoShop::resultat != NULL)
  {
      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::resultat);
      if(pNG != NULL)
      {
          delete pNG;
          PhotoShop::resultat = NULL;
          setImageNG("resultat", NULL);
      }
      else
      {
        ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::resultat);
        if(pB != NULL)
        {
            delete pB;
            PhotoShop::resultat = NULL;
            setImageB("resultat", NULL);
        }
      }
  }
  else
  {
    dialogueErreur("image resultat","aucune image a charger !");
  }


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonTraitement_clicked()
{
  // Etape 12 (TO DO)
  string traitement;
  traitement = getTraitementSelectionne();
  if(PhotoShop::resultat != NULL)  // effacer image et vider resultat avant traitement
  {
    ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::resultat);
      if(pNG != NULL)
      {
          delete pNG;
          setImageNG("resultat", NULL);
      }
      else
      {
        ImageB* pB = dynamic_cast<ImageB*>(PhotoShop::resultat);
        if(pB != NULL)
        {
            delete pB;
            setImageB("resultat", NULL);
        }
      }
  }
  PhotoShop::resultat = NULL; // remettre toujours resultat a NULL avant traitement
  setResultatBoolean(-1);     // reseter le booléen

  if(PhotoShop::operande1 == NULL)
  {
    dialogueErreur("operande1", "veuillez selectionner une image dans l'operande1 !");
  }
  else
  {
    if((traitement == "Différence" || traitement == "Comparaison (==)" || traitement == "Comparaison (<)" || traitement == "Comparaison (>)") && PhotoShop::operande2 == NULL)
    {
      dialogueErreur("operande2", "veuillez selectionner une image dans l'operande2 si vous voulez faire ce traitement !");
    }
    else
    {
      if((traitement != "Différence" && traitement != "Comparaison (==)" && traitement != "Comparaison (<)" && traitement != "Comparaison (>)") && PhotoShop::operande2 != NULL)
      {
        dialogueErreur("operande2", "veuillez enlever l'image dans l'operande2 si vous voulez faire ce traitement !");
      }
      else
      {
        if(traitement == "Eclaircir (+ val)")
        {
            ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
            if(pNG == NULL)
            {
                dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
            }
            else
            {
                int valeur = dialogueDemandeInt("Eclaircir (+val)","Entrez une valeur :");
                try
                {
                  ImageNG* img_resultat = new ImageNG();
                  (*img_resultat) = (*pNG); // je mets image de pNG dans img_resultat pour ne pas modifier l'image dans la liste d'images car pNG pointe vers la liste!!!
                  (*img_resultat) = (*img_resultat) + valeur;
                  PhotoShop::resultat = img_resultat;
                }
                catch(const RGBException& m)
                {
                  cout << "Exception RGBException catchee..." << endl;
                  cout << "message = " << m.getMessageErreur() << endl;
                  cout << "valeur = " << m.getValeur() << endl;
                  dialogueErreur("Niveau de gris invalide","Impossible d'eclaircir l'image avec cette valeur !");
                }
            }
        }
        else
        {
          if(traitement == "Eclaircir (++)")
          {
            ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
            if(pNG == NULL)
            {
                dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
            }
            else
            {
                try
                {
                  ImageNG* img_resultat = new ImageNG();
                  (*img_resultat) = (*pNG);
                  (*img_resultat) = ++(*img_resultat);
                  PhotoShop::resultat = img_resultat;
                } 
                catch(const RGBException& m)
                {
                  cout << "Exception RGBException catchee..." << endl;
                  cout << "message = " << m.getMessageErreur() << endl;
                  cout << "valeur = " << m.getValeur() << endl;
                  dialogueErreur("Niveau de gris invalide","Impossible d'eclaircir l'image !");
                }
            }
          }
          else
          {
            if(traitement == "Assombrir (- val)")
            {
              ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
              if(pNG == NULL)
              {
                  dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
              }
              else
              {
                  int valeur = dialogueDemandeInt("Assombrir (- val)","Entrez une valeur :");
                  try
                  {
                    ImageNG* img_resultat = new ImageNG();
                    (*img_resultat) = (*pNG); // je mets image de pNG dans img_resultat pour ne pas modifier l'image dans la liste d'images car pNG pointe vers la liste!!!
                    (*img_resultat) = (*img_resultat) - valeur;
                    PhotoShop::resultat = img_resultat;
                  }
                  catch(const RGBException& m)
                  {
                    cout << "Exception RGBException catchee..." << endl;
                    cout << "message = " << m.getMessageErreur() << endl;
                    cout << "valeur = " << m.getValeur() << endl;
                    dialogueErreur("Niveau de gris invalide","Impossible d'assombrir l'image avec cette valeur !");
                  }
              }
            }
            else
            {
                if(traitement == "Assombrir (--)")
                {
                  ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                  if(pNG == NULL)
                  {
                      dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                  }
                  else
                  {
                      try
                      {
                        ImageNG* img_resultat = new ImageNG();
                        (*img_resultat) = (*pNG);
                        (*img_resultat) = --(*img_resultat);
                        PhotoShop::resultat = img_resultat;
                      } 
                      catch(const RGBException& m)
                      {
                        cout << "Exception RGBException catchee..." << endl;
                        cout << "message = " << m.getMessageErreur() << endl;
                        cout << "valeur = " << m.getValeur() << endl;
                        dialogueErreur("Niveau de gris invalide","Impossible d'assombrir l'image !");
                      }
                  }
                }
                else
                {
                    if(traitement == "Différence")
                    {
                      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                      if(pNG == NULL)
                      {
                          dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                      }
                      else
                      {
                          ImageNG* pNG1 = dynamic_cast<ImageNG*>(PhotoShop::operande2);
                          if(pNG1 == NULL)
                          {
                              dialogueErreur("operande2", "L'image dans l'operande2 doit etre de type NG !");
                          }
                          else
                          {
                              try
                              {
                                ImageNG* img_resultat = new ImageNG();
                                (*img_resultat) = (*pNG);
                                (*img_resultat) = (*img_resultat) - (*pNG1);
                                PhotoShop::resultat = img_resultat;
                              } 
                              catch(const RGBException& m)
                              {
                                cout << "Exception RGBException catchee..." << endl;
                                cout << "message = " << m.getMessageErreur() << endl;
                                cout << "valeur = " << m.getValeur() << endl;
                                dialogueErreur("Niveau de gris invalide","Impossible d'effectuer la difference entre les  2 images !");
                              }
                          }
                      }
                    }
                    else
                    {
                        if(traitement == "Comparaison (==)")
                        {
                              ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                              if(pNG == NULL)
                              {
                                  dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                              }
                              else
                              {
                                  ImageNG* pNG1 = dynamic_cast<ImageNG*>(PhotoShop::operande2);
                                  if(pNG1 == NULL)
                                  {
                                      dialogueErreur("operande2", "L'image dans l'operande2 doit etre de type NG !");
                                  }
                                  else
                                  {
                                      try
                                      {
                                        if((*pNG) == (*pNG1))
                                        {
                                            setResultatBoolean(1);
                                        }
                                        else
                                        {
                                            setResultatBoolean(0);
                                        }
                                      } 
                                      catch(const XYException& m)
                                      {
                                        cout << "Exception XYException catchee..." << endl;
                                        cout << "message = " << m.getMessageErreur() << endl;
                                        cout << "axe = " << m.getCoordonnee() << endl;
                                        dialogueErreur("erreur comparaison", "impossible de comprarer 2 images de dimensions differentes!");
                                        setResultatBoolean(-1);
                                      }
                                  }
                              }
                        }
                        else
                        {
                          if(traitement == "Comparaison (<)")
                          {
                              ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                              if(pNG == NULL)
                              {
                                  dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                              }
                              else
                              {
                                  ImageNG* pNG1 = dynamic_cast<ImageNG*>(PhotoShop::operande2);
                                  if(pNG1 == NULL)
                                  {
                                      dialogueErreur("operande2", "L'image dans l'operande2 doit etre de type NG !");
                                  }
                                  else
                                  {
                                      try
                                      {
                                        if((*pNG) < (*pNG1))
                                        {
                                            setResultatBoolean(1);
                                        }
                                        else
                                        {
                                            setResultatBoolean(0);
                                        }
                                      } 
                                      catch(const XYException& m)
                                      {
                                        cout << "Exception XYException catchee..." << endl;
                                        cout << "message = " << m.getMessageErreur() << endl;
                                        cout << "axe = " << m.getCoordonnee() << endl;
                                        dialogueErreur("erreur comparaison", "impossible de comprarer 2 images de dimensions differentes!");
                                        setResultatBoolean(-1);
                                      }
                                  }
                              }
                          }
                          else
                          {
                            if(traitement == "Comparaison (>)")
                            {
                                ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                if(pNG == NULL)
                                {
                                    dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                }
                                else
                                {
                                    ImageNG* pNG1 = dynamic_cast<ImageNG*>(PhotoShop::operande2);
                                    if(pNG1 == NULL)
                                    {
                                        dialogueErreur("operande2", "L'image dans l'operande2 doit etre de type NG !");
                                    }
                                    else
                                    {
                                        try
                                        {
                                          if((*pNG) > (*pNG1))
                                          {
                                              setResultatBoolean(1);
                                          }
                                          else
                                          {
                                              setResultatBoolean(0);
                                          }
                                        } 
                                        catch(const XYException& m)
                                        {
                                          cout << "Exception XYException catchee..." << endl;
                                          cout << "message = " << m.getMessageErreur() << endl;
                                          cout << "axe = " << m.getCoordonnee() << endl;
                                          dialogueErreur("erreur comparaison", "impossible de comprarer 2 images de dimensions differentes!");
                                          setResultatBoolean(-1);
                                        }
                                    }
                                }
                            }
                            else
                            {
                              if(traitement == "Seuillage")
                              {
                                ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                if(pNG == NULL)
                                {
                                  dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                }
                                else
                                {
                                    int valeur = dialogueDemandeInt("Seuillage","Entrez une valeur pour le seuil :");
                                    ImageNG* img_copie = new ImageNG(); // copie dans une image NG
                                    (*img_copie) = (*pNG);
                                    ImageB*  img_resultat = new ImageB(); // creation image B
                                    (*img_resultat) = Traitements::Seuillage((*img_copie),valeur);
                                    PhotoShop::resultat = img_resultat;
                                }
                              }
                              else
                              {
                                if(traitement == "Filtre moyenneur")
                                {
                                  ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                  if(pNG == NULL)
                                  {
                                    dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                  }
                                  else
                                  {
                                      int valeur = dialogueDemandeInt("Filtre moyenneur","Entrez une valeur pour la taille :");
                                      try
                                      {
                                        ImageNG* img_resultat = new ImageNG(); 
                                        (*img_resultat) = (*pNG);
                                        (*img_resultat) = Traitements::FiltreMoyenneur((*img_resultat),valeur);
                                        PhotoShop::resultat = img_resultat;
                                      }
                                      catch(const Exception& m)
                                      {
                                        cout << "Exception Exception catchee..." << endl;
                                        cout << "message = " << m.getMessageErreur() << endl;
                                        dialogueErreur("taille", "La taille du filtre doit toujours etre un nombre impair !");
                                      }
                                  }
                                }
                                else
                                {
                                  if(traitement == "Filtre médian")
                                  {
                                    ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                    if(pNG == NULL)
                                    {
                                      dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                    }
                                    else
                                    {
                                        int valeur = dialogueDemandeInt("Filtre median","Entrez une valeur pour la taille :");
                                        try
                                        {
                                          ImageNG* img_resultat = new ImageNG(); 
                                          (*img_resultat) = (*pNG);
                                          (*img_resultat) = Traitements::FiltreMedian((*img_resultat),valeur);
                                          PhotoShop::resultat = img_resultat;
                                        }
                                        catch(const Exception& m)
                                        {
                                          cout << "Exception Exception catchee..." << endl;
                                          cout << "message = " << m.getMessageErreur() << endl;
                                          dialogueErreur("taille", "La taille du filtre doit toujours etre un nombre impair !");
                                        }
                                    }
                                  }
                                  else
                                  {
                                    if(traitement == "Erosion")
                                    {
                                      ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                      if(pNG == NULL)
                                      {
                                        dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                      }
                                      else
                                      {
                                          int valeur = dialogueDemandeInt("Filtre median","Entrez une valeur pour la taille :");
                                          try
                                          {
                                            ImageNG* img_resultat = new ImageNG(); 
                                            (*img_resultat) = (*pNG);
                                            (*img_resultat) = Traitements::Erosion((*img_resultat),valeur);
                                            PhotoShop::resultat = img_resultat;
                                          }
                                          catch(const Exception& m)
                                          {
                                            cout << "Exception Exception catchee..." << endl;
                                            cout << "message = " << m.getMessageErreur() << endl;
                                            dialogueErreur("taille", "La taille entree doit toujours etre un nombre impair !");
                                          }
                                      }
                                    }
                                    else
                                    {
                                      if(traitement == "Dilatation")
                                      {
                                        ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                        if(pNG == NULL)
                                        {
                                          dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                        }
                                        else
                                        {
                                            int valeur = dialogueDemandeInt("Dilatation","Entrez une valeur pour la taille :");
                                            try
                                            {
                                              ImageNG* img_resultat = new ImageNG(); 
                                              (*img_resultat) = (*pNG);
                                              (*img_resultat) = Traitements::Dilatation((*img_resultat),valeur);
                                              PhotoShop::resultat = img_resultat;
                                            }
                                            catch(const Exception& m)
                                            {
                                              cout << "Exception Exception catchee..." << endl;
                                              cout << "message = " << m.getMessageErreur() << endl;
                                              dialogueErreur("taille", "La taille du entree doit toujours etre un nombre impair !");
                                            }
                                        }
                                      }
                                      else
                                      {
                                        if(traitement == "Négatif")
                                        {
                                          ImageNG* pNG = dynamic_cast<ImageNG*>(PhotoShop::operande1);
                                          if(pNG == NULL)
                                          {
                                            dialogueErreur("operande1", "L'image dans l'operande1 doit etre de type NG !");
                                          }
                                          else
                                          {
                                            ImageNG* img_resultat = new ImageNG(); 
                                            (*img_resultat) = (*pNG);
                                            (*img_resultat) = Traitements::Negatif((*img_resultat));
                                            PhotoShop::resultat = img_resultat;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                    }
                }
            }
          }
        }
        // mettre image resultat dans case resultat :
        if(traitement != "Comparaison (==)" && traitement != "Comparaison (<)" && traitement != "Comparaison (>)")
        {
            ImageNG* pNGresult = dynamic_cast<ImageNG*>(PhotoShop::resultat);
            if(pNGresult != NULL)
            {
                setImageNG("resultat",pNGresult);
            }
            else
            {
              ImageB* pBresult = dynamic_cast<ImageB*>(PhotoShop::resultat);
              if(pBresult != NULL)
              {
                  setImageB("resultat",pBresult);
              }
            }
        }
      }
    }
  }
}


// Fonctions ajoutees
int MainWindowPhotoShop::extension_valide(const string nomfichier)
{
  string extensionJPG =".jpg";
  string extensionBMP =".bmp";
  string extensionPNG =".png";

  size_t tailleExtension = extensionJPG.size();

  if(nomfichier.size() < tailleExtension)
  {
    return -1; // chaine trop courte
  }

  string extension_fichier = nomfichier.substr(nomfichier.size() - tailleExtension, tailleExtension); // extraire extension

  if(extension_fichier == extensionJPG || extension_fichier == extensionBMP || extension_fichier == extensionPNG)
  {
    return 1;
  }
  else
  {
    return -1;
  }
}
