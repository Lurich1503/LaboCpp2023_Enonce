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
  if(NomFichier != "")
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

  if(NomFichier != "")
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
  int indice;
  string type;
  indice = dialogueDemandeInt("Supprimer image par id", "veuillez entrer un indice :");
  try
  {
    PhotoShop::getInstance().supprimeImageParIndice(indice);
  }
  catch(const ARRAYLISTException& m)
  {
    cout << "Exception ARRAYLISTException catchee..." << endl;
    cout << "message = " << m.getMessageErreur() << endl;
    cout << "valeur de l'indice = " << m.getValeur() << endl;
    dialogueErreur("erreur indice selectionnee","aucune image a cet indice dans la liste !");
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

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_actionCouleur_FALSE_pour_imageB_triggered()
{
  // Etape 12 (TO DO)

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
      Image* operande1 = instance;

      ImageNG* pNG = dynamic_cast<ImageNG*>(operande1);
      if(pNG != NULL)
      {
        setImageNG("operande1", pNG);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(operande1);
        if(pRGB != NULL)
        {
          setImageRGB("operande1", pRGB);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(operande1);
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
      Image* operande2 = instance;

      ImageNG* pNG = dynamic_cast<ImageNG*>(operande2);
      if(pNG != NULL)
      {
        setImageNG("operande2", pNG);
      }
      else
      {
        ImageRGB* pRGB = dynamic_cast<ImageRGB*>(operande2);
        if(pRGB != NULL)
        {
          setImageRGB("operande2", pRGB);
        }
        else
        {
          ImageB* pB = dynamic_cast<ImageB*>(operande2);
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

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonResultat_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonSupprimerResultat_clicked()
{
    // Etape 12 (TO DO)

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindowPhotoShop::on_pushButtonTraitement_clicked()
{
    // Etape 12 (TO DO)

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
