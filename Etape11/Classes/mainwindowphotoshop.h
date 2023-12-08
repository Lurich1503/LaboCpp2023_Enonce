#ifndef MAINWINDOWPHOTOSHOP_H
#define MAINWINDOWPHOTOSHOP_H

#include <QMainWindow>
#include <string>
using namespace std;


#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowPhotoShop; }
QT_END_NAMESPACE

class MainWindowPhotoShop : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowPhotoShop(QWidget *parent = nullptr);
    ~MainWindowPhotoShop();

    // Méthodes de la fenêtre
    void   setTitre(string titre);
    void   setNomImage(string nom);
    string getNomImage() const;
    void   setParametresImageNG(int max=-1,int min=-1,int luminance=-1,float contraste=0.0f);
    
    void setImageNG(string destination,const ImageNG* imageng=NULL);
    void setImageRGB(string destination,const ImageRGB* imagergb=NULL);
    void setImageB(string destination,const ImageB* imageb=NULL);
    
    void setResultatBoolean(int valeur=-1);

    // Table des images
    void ajouteTupleTableImages(int id,string type,string dimension,string nom);
    void videTableImages();
    int  getIndiceImageSelectionnee();

    // Combobox des traitements disponibles
    void   ajouteTraitementDisponible(string operation);
    void   videTraitementsDisponibles();
    string getTraitementSelectionne() const;

    // Clic sur la croix de la fenetre
    void closeEvent(QCloseEvent *event);

    // Boites de dialogues
    void   dialogueMessage(const char *titre, const char *message);
    void   dialogueErreur(const char *titre, const char *message);
    string dialogueDemandeTexte(const char *titre, const char *question);
    int    dialogueDemandeInt(const char *titre, const char *question);
    float  dialogueDemandeFloat(const char *titre, const char *question);
    string dialogueDemandeFichierOuvrir(const char* question);
    string dialogueDemandeFichierEnregistrer(const char* question);
    void   dialogueDemandeCouleur(const char* message,int* pRouge,int* pVert,int* pBleu);

private slots:
    void on_actionQuitter_triggered();
    void on_actionCharger_ImageNB_triggered();
    void on_actionEnregistrer_ImageNB_triggered();
    void on_actionCharger_ImageRGB_triggered();
    void on_tableWidgetImages_itemSelectionChanged();
    void on_pushButtonModifierNom_clicked();
    void on_actionCouleur_TRUE_pour_ImageB_triggered();
    void on_actionCouleur_FALSE_pour_imageB_triggered();
    void on_pushButtonOperande1_clicked();
    void on_pushButtonSupprimeOperande1_clicked();
    void on_pushButtonOperande2_clicked();
    void on_pushButtonSupprimerOperande2_clicked();
    void on_pushButtonResultat_clicked();
    void on_pushButtonSupprimerResultat_clicked();
    void on_pushButtonTraitement_clicked();
    void on_actionEnregistrer_ImageRGB_triggered();
    void on_actionEnregistrer_ImageB_triggered();
    void on_actionImage_selectionn_e_triggered();
    void on_actionImage_par_id_triggered();
    void on_actionImporterCSV_triggered();
    void on_actionReset_triggered();

private:
    Ui::MainWindowPhotoShop *ui;
};
#endif // MAINWINDOWPHOTOSHOP_H
