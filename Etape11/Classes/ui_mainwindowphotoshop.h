/********************************************************************************
** Form generated from reading UI file 'mainwindowphotoshop.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWPHOTOSHOP_H
#define UI_MAINWINDOWPHOTOSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowPhotoShop
{
public:
    QAction *actionCharger_ImageNB;
    QAction *actionCharger_ImageRGB;
    QAction *actionEnregistrer_ImageNB;
    QAction *actionEnregistrer_ImageRGB;
    QAction *actionEnregistrer_ImageB;
    QAction *actionQuitter;
    QAction *actionImage_par_id;
    QAction *actionImage_selectionn_e;
    QAction *actionCouleur_TRUE_pour_ImageB;
    QAction *actionCouleur_FALSE_pour_imageB;
    QAction *actionImporterCSV;
    QAction *actionReset;
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QTableWidget *tableWidgetImages;
    QScrollArea *scrollAreaSelection;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLineEdit *lineEditNom;
    QLabel *label_3;
    QLineEdit *lineEditMin;
    QLabel *label_4;
    QLineEdit *lineEditMax;
    QLabel *label_5;
    QLineEdit *lineEditLuminance;
    QLabel *label_6;
    QLineEdit *lineEditContraste;
    QPushButton *pushButtonModifierNom;
    QLabel *label_7;
    QFrame *frame_2;
    QScrollArea *scrollAreaOperande1;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *scrollAreaOperande2;
    QWidget *scrollAreaWidgetContents_3;
    QScrollArea *scrollAreaResultat;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButtonOperande1;
    QPushButton *pushButtonOperande2;
    QPushButton *pushButtonResultat;
    QLabel *label_11;
    QComboBox *comboBoxTraitements;
    QPushButton *pushButtonTraitement;
    QCheckBox *checkBoxResultat;
    QPushButton *pushButtonSupprimeOperande1;
    QPushButton *pushButtonSupprimerOperande2;
    QPushButton *pushButtonSupprimerResultat;
    QMenuBar *menubar;
    QMenu *menuImages;
    QMenu *menuSupprimer;
    QMenu *menuParam_tres;
    QMenu *menuBiblioth_que;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowPhotoShop)
    {
        if (MainWindowPhotoShop->objectName().isEmpty())
            MainWindowPhotoShop->setObjectName(QString::fromUtf8("MainWindowPhotoShop"));
        MainWindowPhotoShop->resize(1021, 840);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowPhotoShop->sizePolicy().hasHeightForWidth());
        MainWindowPhotoShop->setSizePolicy(sizePolicy);
        actionCharger_ImageNB = new QAction(MainWindowPhotoShop);
        actionCharger_ImageNB->setObjectName(QString::fromUtf8("actionCharger_ImageNB"));
        actionCharger_ImageRGB = new QAction(MainWindowPhotoShop);
        actionCharger_ImageRGB->setObjectName(QString::fromUtf8("actionCharger_ImageRGB"));
        actionEnregistrer_ImageNB = new QAction(MainWindowPhotoShop);
        actionEnregistrer_ImageNB->setObjectName(QString::fromUtf8("actionEnregistrer_ImageNB"));
        actionEnregistrer_ImageRGB = new QAction(MainWindowPhotoShop);
        actionEnregistrer_ImageRGB->setObjectName(QString::fromUtf8("actionEnregistrer_ImageRGB"));
        actionEnregistrer_ImageB = new QAction(MainWindowPhotoShop);
        actionEnregistrer_ImageB->setObjectName(QString::fromUtf8("actionEnregistrer_ImageB"));
        actionQuitter = new QAction(MainWindowPhotoShop);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionImage_par_id = new QAction(MainWindowPhotoShop);
        actionImage_par_id->setObjectName(QString::fromUtf8("actionImage_par_id"));
        actionImage_selectionn_e = new QAction(MainWindowPhotoShop);
        actionImage_selectionn_e->setObjectName(QString::fromUtf8("actionImage_selectionn_e"));
        actionCouleur_TRUE_pour_ImageB = new QAction(MainWindowPhotoShop);
        actionCouleur_TRUE_pour_ImageB->setObjectName(QString::fromUtf8("actionCouleur_TRUE_pour_ImageB"));
        actionCouleur_FALSE_pour_imageB = new QAction(MainWindowPhotoShop);
        actionCouleur_FALSE_pour_imageB->setObjectName(QString::fromUtf8("actionCouleur_FALSE_pour_imageB"));
        actionImporterCSV = new QAction(MainWindowPhotoShop);
        actionImporterCSV->setObjectName(QString::fromUtf8("actionImporterCSV"));
        actionReset = new QAction(MainWindowPhotoShop);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        centralwidget = new QWidget(MainWindowPhotoShop);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 17));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 30, 1001, 331));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        tableWidgetImages = new QTableWidget(frame);
        tableWidgetImages->setObjectName(QString::fromUtf8("tableWidgetImages"));
        tableWidgetImages->setGeometry(QRect(10, 10, 651, 221));
        scrollAreaSelection = new QScrollArea(frame);
        scrollAreaSelection->setObjectName(QString::fromUtf8("scrollAreaSelection"));
        scrollAreaSelection->setGeometry(QRect(670, 10, 321, 311));
        scrollAreaSelection->setStyleSheet(QString::fromUtf8("background-color: lightgrey"));
        scrollAreaSelection->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 319, 309));
        scrollAreaSelection->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 64, 21));
        lineEditNom = new QLineEdit(frame);
        lineEditNom->setObjectName(QString::fromUtf8("lineEditNom"));
        lineEditNom->setGeometry(QRect(60, 240, 381, 25));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 270, 41, 21));
        lineEditMin = new QLineEdit(frame);
        lineEditMin->setObjectName(QString::fromUtf8("lineEditMin"));
        lineEditMin->setGeometry(QRect(60, 270, 111, 25));
        lineEditMin->setAlignment(Qt::AlignCenter);
        lineEditMin->setReadOnly(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 300, 41, 21));
        lineEditMax = new QLineEdit(frame);
        lineEditMax->setObjectName(QString::fromUtf8("lineEditMax"));
        lineEditMax->setGeometry(QRect(60, 300, 111, 25));
        lineEditMax->setAlignment(Qt::AlignCenter);
        lineEditMax->setReadOnly(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 270, 91, 21));
        lineEditLuminance = new QLineEdit(frame);
        lineEditLuminance->setObjectName(QString::fromUtf8("lineEditLuminance"));
        lineEditLuminance->setGeometry(QRect(320, 270, 121, 25));
        lineEditLuminance->setAlignment(Qt::AlignCenter);
        lineEditLuminance->setReadOnly(true);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 300, 81, 21));
        lineEditContraste = new QLineEdit(frame);
        lineEditContraste->setObjectName(QString::fromUtf8("lineEditContraste"));
        lineEditContraste->setGeometry(QRect(320, 300, 121, 25));
        lineEditContraste->setAlignment(Qt::AlignCenter);
        lineEditContraste->setReadOnly(true);
        pushButtonModifierNom = new QPushButton(frame);
        pushButtonModifierNom->setObjectName(QString::fromUtf8("pushButtonModifierNom"));
        pushButtonModifierNom->setGeometry(QRect(452, 240, 201, 81));
        pushButtonModifierNom->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 370, 221, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(10);
        label_7->setFont(font);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 390, 1001, 401));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        scrollAreaOperande1 = new QScrollArea(frame_2);
        scrollAreaOperande1->setObjectName(QString::fromUtf8("scrollAreaOperande1"));
        scrollAreaOperande1->setGeometry(QRect(10, 80, 321, 311));
        scrollAreaOperande1->setStyleSheet(QString::fromUtf8("background-color: lightgrey"));
        scrollAreaOperande1->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 319, 309));
        scrollAreaOperande1->setWidget(scrollAreaWidgetContents_2);
        scrollAreaOperande2 = new QScrollArea(frame_2);
        scrollAreaOperande2->setObjectName(QString::fromUtf8("scrollAreaOperande2"));
        scrollAreaOperande2->setGeometry(QRect(340, 80, 321, 311));
        scrollAreaOperande2->setStyleSheet(QString::fromUtf8("background-color: lightgrey"));
        scrollAreaOperande2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 319, 309));
        scrollAreaOperande2->setWidget(scrollAreaWidgetContents_3);
        scrollAreaResultat = new QScrollArea(frame_2);
        scrollAreaResultat->setObjectName(QString::fromUtf8("scrollAreaResultat"));
        scrollAreaResultat->setGeometry(QRect(670, 80, 321, 311));
        scrollAreaResultat->setStyleSheet(QString::fromUtf8("background-color: lightgrey"));
        scrollAreaResultat->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 319, 309));
        scrollAreaResultat->setWidget(scrollAreaWidgetContents_4);
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(120, 50, 101, 31));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(450, 50, 111, 31));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(800, 50, 71, 31));
        pushButtonOperande1 = new QPushButton(frame_2);
        pushButtonOperande1->setObjectName(QString::fromUtf8("pushButtonOperande1"));
        pushButtonOperande1->setGeometry(QRect(10, 50, 31, 25));
        pushButtonOperande1->setStyleSheet(QString::fromUtf8("background-color: lightgreen"));
        pushButtonOperande2 = new QPushButton(frame_2);
        pushButtonOperande2->setObjectName(QString::fromUtf8("pushButtonOperande2"));
        pushButtonOperande2->setGeometry(QRect(340, 50, 31, 25));
        pushButtonOperande2->setStyleSheet(QString::fromUtf8("background-color: lightgreen"));
        pushButtonResultat = new QPushButton(frame_2);
        pushButtonResultat->setObjectName(QString::fromUtf8("pushButtonResultat"));
        pushButtonResultat->setGeometry(QRect(670, 50, 31, 25));
        pushButtonResultat->setStyleSheet(QString::fromUtf8("background-color: yellow"));
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 101, 21));
        comboBoxTraitements = new QComboBox(frame_2);
        comboBoxTraitements->setObjectName(QString::fromUtf8("comboBoxTraitements"));
        comboBoxTraitements->setGeometry(QRect(120, 10, 241, 25));
        pushButtonTraitement = new QPushButton(frame_2);
        pushButtonTraitement->setObjectName(QString::fromUtf8("pushButtonTraitement"));
        pushButtonTraitement->setGeometry(QRect(380, 10, 121, 25));
        pushButtonTraitement->setStyleSheet(QString::fromUtf8("background-color: lightblue"));
        checkBoxResultat = new QCheckBox(frame_2);
        checkBoxResultat->setObjectName(QString::fromUtf8("checkBoxResultat"));
        checkBoxResultat->setEnabled(true);
        checkBoxResultat->setGeometry(QRect(530, 10, 91, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setBold(true);
        font1.setWeight(75);
        checkBoxResultat->setFont(font1);
        checkBoxResultat->setStyleSheet(QString::fromUtf8("background-color: lightyellow;\n"
"border: 1px solid gray;"));
        checkBoxResultat->setCheckable(true);
        pushButtonSupprimeOperande1 = new QPushButton(frame_2);
        pushButtonSupprimeOperande1->setObjectName(QString::fromUtf8("pushButtonSupprimeOperande1"));
        pushButtonSupprimeOperande1->setGeometry(QRect(50, 50, 31, 25));
        pushButtonSupprimeOperande1->setStyleSheet(QString::fromUtf8("background-color: orange"));
        pushButtonSupprimerOperande2 = new QPushButton(frame_2);
        pushButtonSupprimerOperande2->setObjectName(QString::fromUtf8("pushButtonSupprimerOperande2"));
        pushButtonSupprimerOperande2->setGeometry(QRect(380, 50, 31, 25));
        pushButtonSupprimerOperande2->setStyleSheet(QString::fromUtf8("background-color: orange"));
        pushButtonSupprimerResultat = new QPushButton(frame_2);
        pushButtonSupprimerResultat->setObjectName(QString::fromUtf8("pushButtonSupprimerResultat"));
        pushButtonSupprimerResultat->setGeometry(QRect(710, 50, 31, 25));
        pushButtonSupprimerResultat->setStyleSheet(QString::fromUtf8("background-color: orange"));
        MainWindowPhotoShop->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowPhotoShop);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1021, 22));
        menuImages = new QMenu(menubar);
        menuImages->setObjectName(QString::fromUtf8("menuImages"));
        menuSupprimer = new QMenu(menubar);
        menuSupprimer->setObjectName(QString::fromUtf8("menuSupprimer"));
        menuParam_tres = new QMenu(menubar);
        menuParam_tres->setObjectName(QString::fromUtf8("menuParam_tres"));
        menuBiblioth_que = new QMenu(menubar);
        menuBiblioth_que->setObjectName(QString::fromUtf8("menuBiblioth_que"));
        MainWindowPhotoShop->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowPhotoShop);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowPhotoShop->setStatusBar(statusbar);

        menubar->addAction(menuImages->menuAction());
        menubar->addAction(menuSupprimer->menuAction());
        menubar->addAction(menuParam_tres->menuAction());
        menubar->addAction(menuBiblioth_que->menuAction());
        menuImages->addAction(actionCharger_ImageNB);
        menuImages->addAction(actionCharger_ImageRGB);
        menuImages->addSeparator();
        menuImages->addAction(actionEnregistrer_ImageNB);
        menuImages->addAction(actionEnregistrer_ImageRGB);
        menuImages->addAction(actionEnregistrer_ImageB);
        menuImages->addSeparator();
        menuImages->addAction(actionQuitter);
        menuSupprimer->addAction(actionImage_par_id);
        menuSupprimer->addAction(actionImage_selectionn_e);
        menuParam_tres->addAction(actionCouleur_TRUE_pour_ImageB);
        menuParam_tres->addAction(actionCouleur_FALSE_pour_imageB);
        menuBiblioth_que->addAction(actionImporterCSV);
        menuBiblioth_que->addAction(actionReset);

        retranslateUi(MainWindowPhotoShop);

        QMetaObject::connectSlotsByName(MainWindowPhotoShop);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowPhotoShop)
    {
        MainWindowPhotoShop->setWindowTitle(QApplication::translate("MainWindowPhotoShop", "MainWindowPhotoShop", nullptr));
        actionCharger_ImageNB->setText(QApplication::translate("MainWindowPhotoShop", "Charger ImageNG", nullptr));
        actionCharger_ImageRGB->setText(QApplication::translate("MainWindowPhotoShop", "Charger ImageRGB", nullptr));
        actionEnregistrer_ImageNB->setText(QApplication::translate("MainWindowPhotoShop", "Enregistrer ImageNG", nullptr));
        actionEnregistrer_ImageRGB->setText(QApplication::translate("MainWindowPhotoShop", "Enregistrer ImageRGB", nullptr));
        actionEnregistrer_ImageB->setText(QApplication::translate("MainWindowPhotoShop", "Enregistrer ImageB", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindowPhotoShop", "Quitter", nullptr));
        actionImage_par_id->setText(QApplication::translate("MainWindowPhotoShop", "Image par id", nullptr));
        actionImage_selectionn_e->setText(QApplication::translate("MainWindowPhotoShop", "Image selectionn\303\251e", nullptr));
        actionCouleur_TRUE_pour_ImageB->setText(QApplication::translate("MainWindowPhotoShop", "Couleur TRUE pour ImageB", nullptr));
        actionCouleur_FALSE_pour_imageB->setText(QApplication::translate("MainWindowPhotoShop", "Couleur FALSE pour imageB", nullptr));
        actionImporterCSV->setText(QApplication::translate("MainWindowPhotoShop", "Importer images \303\240 partir d'un fichier CSV", nullptr));
        actionReset->setText(QApplication::translate("MainWindowPhotoShop", "Reset", nullptr));
        label->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600; color:#204a87;\">Biblioth\303\250que :</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindowPhotoShop", "Nom :", nullptr));
        label_3->setText(QApplication::translate("MainWindowPhotoShop", "Min :", nullptr));
        label_4->setText(QApplication::translate("MainWindowPhotoShop", "Max :", nullptr));
        label_5->setText(QApplication::translate("MainWindowPhotoShop", "Luminance :", nullptr));
        label_6->setText(QApplication::translate("MainWindowPhotoShop", "Contraste :", nullptr));
        pushButtonModifierNom->setText(QApplication::translate("MainWindowPhotoShop", "Modifier Nom", nullptr));
        label_7->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600; color:#204a87;\">Atelier de traitement :</span></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600;\">Op\303\251rande 1</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600;\">Op\303\251rande 2</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600;\">R\303\251sultat</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonOperande1->setToolTip(QApplication::translate("MainWindowPhotoShop", "Importer de la biblioth\303\250que", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonOperande1->setText(QApplication::translate("MainWindowPhotoShop", "\\/", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonOperande2->setToolTip(QApplication::translate("MainWindowPhotoShop", "Importer de la biblioth\303\250que", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonOperande2->setText(QApplication::translate("MainWindowPhotoShop", "\\/", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonResultat->setToolTip(QApplication::translate("MainWindowPhotoShop", "Exporter vers la biblioth\303\250que", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonResultat->setText(QApplication::translate("MainWindowPhotoShop", "/\\", nullptr));
        label_11->setText(QApplication::translate("MainWindowPhotoShop", "<html><head/><body><p><span style=\" font-weight:600;\">Traitement :</span></p></body></html>", nullptr));
        pushButtonTraitement->setText(QApplication::translate("MainWindowPhotoShop", "Go !", nullptr));
        checkBoxResultat->setText(QApplication::translate("MainWindowPhotoShop", "R\303\251sultat", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonSupprimeOperande1->setToolTip(QApplication::translate("MainWindowPhotoShop", "Supprimer", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonSupprimeOperande1->setText(QApplication::translate("MainWindowPhotoShop", "X", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonSupprimerOperande2->setToolTip(QApplication::translate("MainWindowPhotoShop", "Supprimer", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonSupprimerOperande2->setText(QApplication::translate("MainWindowPhotoShop", "X", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonSupprimerResultat->setToolTip(QApplication::translate("MainWindowPhotoShop", "Supprimer", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonSupprimerResultat->setText(QApplication::translate("MainWindowPhotoShop", "X", nullptr));
        menuImages->setTitle(QApplication::translate("MainWindowPhotoShop", "Images", nullptr));
        menuSupprimer->setTitle(QApplication::translate("MainWindowPhotoShop", "Supprimer", nullptr));
        menuParam_tres->setTitle(QApplication::translate("MainWindowPhotoShop", "Param\303\250tres", nullptr));
        menuBiblioth_que->setTitle(QApplication::translate("MainWindowPhotoShop", "Biblioth\303\250que", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowPhotoShop: public Ui_MainWindowPhotoShop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWPHOTOSHOP_H
