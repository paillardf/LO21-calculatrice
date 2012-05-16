/********************************************************************************
** Form generated from reading UI file 'calculatrice.ui'
**
** Created: Wed 16. May 15:01:14 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATRICE_H
#define UI_CALCULATRICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculatrice
{
public:
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QAction *actionClavier;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *pileTxt;
    QLineEdit *entreeTxt;
    QWidget *horizontalLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *pileLayout;
    QPushButton *BtSWAP;
    QPushButton *BtSUM;
    QPushButton *BtMEAN;
    QPushButton *BtCLEAR;
    QPushButton *BtDUP;
    QPushButton *BtDROP;
    QLabel *label;
    QFrame *line_2;
    QGridLayout *fonctionLayout;
    QPushButton *BtSIN;
    QPushButton *BtCOS;
    QPushButton *BtTAN;
    QPushButton *BtSINH;
    QPushButton *BtCOSH;
    QPushButton *BtTANH;
    QPushButton *BtLN;
    QPushButton *BtLN_2;
    QPushButton *BtSQRT;
    QPushButton *BtSQR;
    QPushButton *BtCUBE;
    QPushButton *BtFactoriel;
    QPushButton *BtComplexe;
    QLabel *label_2;
    QFrame *line;
    QGridLayout *numLayout;
    QPushButton *Bt8;
    QPushButton *Bt9;
    QPushButton *Bt4;
    QPushButton *Bt5;
    QPushButton *Bt6;
    QPushButton *Bt1;
    QPushButton *Bt2;
    QPushButton *Bt3;
    QPushButton *Bt0;
    QPushButton *BtPlus;
    QPushButton *BtMult;
    QPushButton *BtDiv;
    QPushButton *BtSigne;
    QPushButton *BtVirgule;
    QPushButton *BtEval;
    QPushButton *BtExpression;
    QPushButton *Bt7;
    QPushButton *BtMoins;
    QPushButton *BtModulo;
    QPushButton *BtPuissance;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *entreeTypeLayout;
    QRadioButton *radioButton_Entier;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *angleTypeLayout;
    QRadioButton *radioButton_Degre;
    QRadioButton *radioButton_Radian;
    QSpinBox *nbElementPile;
    QPushButton *addTab;
    QMenuBar *menuBar;
    QMenu *menuKjg;
    QMenu *menuAffichage;

    void setupUi(QMainWindow *Calculatrice)
    {
        if (Calculatrice->objectName().isEmpty())
            Calculatrice->setObjectName(QString::fromUtf8("Calculatrice"));
        Calculatrice->resize(523, 235);
        actionAnnuler = new QAction(Calculatrice);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(Calculatrice);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        actionClavier = new QAction(Calculatrice);
        actionClavier->setObjectName(QString::fromUtf8("actionClavier"));
        actionClavier->setCheckable(true);
        centralWidget = new QWidget(Calculatrice);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 621, 221));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pileTxt = new QLineEdit(tab);
        pileTxt->setObjectName(QString::fromUtf8("pileTxt"));
        pileTxt->setGeometry(QRect(50, 10, 371, 20));
        pileTxt->setFrame(false);
        pileTxt->setDragEnabled(false);
        pileTxt->setReadOnly(true);
        entreeTxt = new QLineEdit(tab);
        entreeTxt->setObjectName(QString::fromUtf8("entreeTxt"));
        entreeTxt->setGeometry(QRect(50, 40, 201, 20));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 501, 111));
        gridLayout = new QGridLayout(horizontalLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pileLayout = new QGridLayout();
        pileLayout->setSpacing(6);
        pileLayout->setObjectName(QString::fromUtf8("pileLayout"));
        BtSWAP = new QPushButton(horizontalLayoutWidget);
        BtSWAP->setObjectName(QString::fromUtf8("BtSWAP"));

        pileLayout->addWidget(BtSWAP, 2, 0, 1, 1);

        BtSUM = new QPushButton(horizontalLayoutWidget);
        BtSUM->setObjectName(QString::fromUtf8("BtSUM"));

        pileLayout->addWidget(BtSUM, 3, 0, 1, 1);

        BtMEAN = new QPushButton(horizontalLayoutWidget);
        BtMEAN->setObjectName(QString::fromUtf8("BtMEAN"));

        pileLayout->addWidget(BtMEAN, 4, 0, 1, 1);

        BtCLEAR = new QPushButton(horizontalLayoutWidget);
        BtCLEAR->setObjectName(QString::fromUtf8("BtCLEAR"));

        pileLayout->addWidget(BtCLEAR, 5, 0, 1, 1);

        BtDUP = new QPushButton(horizontalLayoutWidget);
        BtDUP->setObjectName(QString::fromUtf8("BtDUP"));

        pileLayout->addWidget(BtDUP, 2, 1, 1, 1);

        BtDROP = new QPushButton(horizontalLayoutWidget);
        BtDROP->setObjectName(QString::fromUtf8("BtDROP"));

        pileLayout->addWidget(BtDROP, 3, 1, 1, 1);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);

        pileLayout->addWidget(label, 1, 0, 1, 2);


        gridLayout->addLayout(pileLayout, 0, 0, 1, 1);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 1, 1);

        fonctionLayout = new QGridLayout();
        fonctionLayout->setSpacing(6);
        fonctionLayout->setObjectName(QString::fromUtf8("fonctionLayout"));
        BtSIN = new QPushButton(horizontalLayoutWidget);
        BtSIN->setObjectName(QString::fromUtf8("BtSIN"));

        fonctionLayout->addWidget(BtSIN, 2, 0, 1, 1);

        BtCOS = new QPushButton(horizontalLayoutWidget);
        BtCOS->setObjectName(QString::fromUtf8("BtCOS"));

        fonctionLayout->addWidget(BtCOS, 3, 0, 1, 1);

        BtTAN = new QPushButton(horizontalLayoutWidget);
        BtTAN->setObjectName(QString::fromUtf8("BtTAN"));

        fonctionLayout->addWidget(BtTAN, 4, 0, 1, 1);

        BtSINH = new QPushButton(horizontalLayoutWidget);
        BtSINH->setObjectName(QString::fromUtf8("BtSINH"));

        fonctionLayout->addWidget(BtSINH, 2, 1, 1, 1);

        BtCOSH = new QPushButton(horizontalLayoutWidget);
        BtCOSH->setObjectName(QString::fromUtf8("BtCOSH"));

        fonctionLayout->addWidget(BtCOSH, 3, 1, 1, 1);

        BtTANH = new QPushButton(horizontalLayoutWidget);
        BtTANH->setObjectName(QString::fromUtf8("BtTANH"));

        fonctionLayout->addWidget(BtTANH, 4, 1, 1, 1);

        BtLN = new QPushButton(horizontalLayoutWidget);
        BtLN->setObjectName(QString::fromUtf8("BtLN"));

        fonctionLayout->addWidget(BtLN, 5, 0, 1, 1);

        BtLN_2 = new QPushButton(horizontalLayoutWidget);
        BtLN_2->setObjectName(QString::fromUtf8("BtLN_2"));

        fonctionLayout->addWidget(BtLN_2, 5, 1, 1, 1);

        BtSQRT = new QPushButton(horizontalLayoutWidget);
        BtSQRT->setObjectName(QString::fromUtf8("BtSQRT"));

        fonctionLayout->addWidget(BtSQRT, 4, 2, 1, 1);

        BtSQR = new QPushButton(horizontalLayoutWidget);
        BtSQR->setObjectName(QString::fromUtf8("BtSQR"));

        fonctionLayout->addWidget(BtSQR, 5, 2, 1, 1);

        BtCUBE = new QPushButton(horizontalLayoutWidget);
        BtCUBE->setObjectName(QString::fromUtf8("BtCUBE"));

        fonctionLayout->addWidget(BtCUBE, 3, 2, 1, 1);

        BtFactoriel = new QPushButton(horizontalLayoutWidget);
        BtFactoriel->setObjectName(QString::fromUtf8("BtFactoriel"));

        fonctionLayout->addWidget(BtFactoriel, 2, 2, 1, 1);

        BtComplexe = new QPushButton(horizontalLayoutWidget);
        BtComplexe->setObjectName(QString::fromUtf8("BtComplexe"));

        fonctionLayout->addWidget(BtComplexe, 2, 3, 1, 1);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        fonctionLayout->addWidget(label_2, 1, 0, 1, 4);


        gridLayout->addLayout(fonctionLayout, 0, 2, 1, 1);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 1, 1);

        numLayout = new QGridLayout();
        numLayout->setSpacing(6);
        numLayout->setObjectName(QString::fromUtf8("numLayout"));
        Bt8 = new QPushButton(horizontalLayoutWidget);
        Bt8->setObjectName(QString::fromUtf8("Bt8"));

        numLayout->addWidget(Bt8, 1, 1, 1, 1);

        Bt9 = new QPushButton(horizontalLayoutWidget);
        Bt9->setObjectName(QString::fromUtf8("Bt9"));

        numLayout->addWidget(Bt9, 1, 2, 1, 1);

        Bt4 = new QPushButton(horizontalLayoutWidget);
        Bt4->setObjectName(QString::fromUtf8("Bt4"));

        numLayout->addWidget(Bt4, 2, 0, 1, 1);

        Bt5 = new QPushButton(horizontalLayoutWidget);
        Bt5->setObjectName(QString::fromUtf8("Bt5"));

        numLayout->addWidget(Bt5, 2, 1, 1, 1);

        Bt6 = new QPushButton(horizontalLayoutWidget);
        Bt6->setObjectName(QString::fromUtf8("Bt6"));

        numLayout->addWidget(Bt6, 2, 2, 1, 1);

        Bt1 = new QPushButton(horizontalLayoutWidget);
        Bt1->setObjectName(QString::fromUtf8("Bt1"));

        numLayout->addWidget(Bt1, 3, 0, 1, 1);

        Bt2 = new QPushButton(horizontalLayoutWidget);
        Bt2->setObjectName(QString::fromUtf8("Bt2"));

        numLayout->addWidget(Bt2, 3, 1, 1, 1);

        Bt3 = new QPushButton(horizontalLayoutWidget);
        Bt3->setObjectName(QString::fromUtf8("Bt3"));

        numLayout->addWidget(Bt3, 3, 2, 1, 1);

        Bt0 = new QPushButton(horizontalLayoutWidget);
        Bt0->setObjectName(QString::fromUtf8("Bt0"));

        numLayout->addWidget(Bt0, 4, 0, 1, 1);

        BtPlus = new QPushButton(horizontalLayoutWidget);
        BtPlus->setObjectName(QString::fromUtf8("BtPlus"));

        numLayout->addWidget(BtPlus, 4, 3, 1, 1);

        BtMult = new QPushButton(horizontalLayoutWidget);
        BtMult->setObjectName(QString::fromUtf8("BtMult"));

        numLayout->addWidget(BtMult, 2, 3, 1, 1);

        BtDiv = new QPushButton(horizontalLayoutWidget);
        BtDiv->setObjectName(QString::fromUtf8("BtDiv"));

        numLayout->addWidget(BtDiv, 1, 3, 1, 1);

        BtSigne = new QPushButton(horizontalLayoutWidget);
        BtSigne->setObjectName(QString::fromUtf8("BtSigne"));

        numLayout->addWidget(BtSigne, 4, 1, 1, 1);

        BtVirgule = new QPushButton(horizontalLayoutWidget);
        BtVirgule->setObjectName(QString::fromUtf8("BtVirgule"));

        numLayout->addWidget(BtVirgule, 4, 2, 1, 1);

        BtEval = new QPushButton(horizontalLayoutWidget);
        BtEval->setObjectName(QString::fromUtf8("BtEval"));
        BtEval->setEnabled(true);

        numLayout->addWidget(BtEval, 4, 4, 1, 1);

        BtExpression = new QPushButton(horizontalLayoutWidget);
        BtExpression->setObjectName(QString::fromUtf8("BtExpression"));

        numLayout->addWidget(BtExpression, 3, 4, 1, 1);

        Bt7 = new QPushButton(horizontalLayoutWidget);
        Bt7->setObjectName(QString::fromUtf8("Bt7"));
        Bt7->setAutoDefault(false);
        Bt7->setDefault(false);
        Bt7->setFlat(false);

        numLayout->addWidget(Bt7, 1, 0, 1, 1);

        BtMoins = new QPushButton(horizontalLayoutWidget);
        BtMoins->setObjectName(QString::fromUtf8("BtMoins"));

        numLayout->addWidget(BtMoins, 3, 3, 1, 1);

        BtModulo = new QPushButton(horizontalLayoutWidget);
        BtModulo->setObjectName(QString::fromUtf8("BtModulo"));

        numLayout->addWidget(BtModulo, 2, 4, 1, 1);

        BtPuissance = new QPushButton(horizontalLayoutWidget);
        BtPuissance->setObjectName(QString::fromUtf8("BtPuissance"));

        numLayout->addWidget(BtPuissance, 1, 4, 1, 1);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        numLayout->addWidget(label_3, 0, 0, 1, 4);


        gridLayout->addLayout(numLayout, 0, 4, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 46, 20));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 40, 46, 20));
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(260, 40, 241, 21));
        entreeTypeLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        entreeTypeLayout->setSpacing(6);
        entreeTypeLayout->setContentsMargins(11, 11, 11, 11);
        entreeTypeLayout->setObjectName(QString::fromUtf8("entreeTypeLayout"));
        entreeTypeLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Entier = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_Entier->setObjectName(QString::fromUtf8("radioButton_Entier"));
        radioButton_Entier->setAutoRepeat(false);

        entreeTypeLayout->addWidget(radioButton_Entier);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        entreeTypeLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        entreeTypeLayout->addWidget(radioButton_3);

        horizontalLayoutWidget_3 = new QWidget(tab);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(260, 60, 151, 21));
        angleTypeLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        angleTypeLayout->setSpacing(6);
        angleTypeLayout->setContentsMargins(11, 11, 11, 11);
        angleTypeLayout->setObjectName(QString::fromUtf8("angleTypeLayout"));
        angleTypeLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Degre = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_Degre->setObjectName(QString::fromUtf8("radioButton_Degre"));
        radioButton_Degre->setChecked(true);
        radioButton_Degre->setAutoRepeat(false);

        angleTypeLayout->addWidget(radioButton_Degre);

        radioButton_Radian = new QRadioButton(horizontalLayoutWidget_3);
        radioButton_Radian->setObjectName(QString::fromUtf8("radioButton_Radian"));

        angleTypeLayout->addWidget(radioButton_Radian);

        nbElementPile = new QSpinBox(tab);
        nbElementPile->setObjectName(QString::fromUtf8("nbElementPile"));
        nbElementPile->setGeometry(QRect(440, 10, 46, 22));
        tabWidget->addTab(tab, QString());
        addTab = new QPushButton(centralWidget);
        addTab->setObjectName(QString::fromUtf8("addTab"));
        addTab->setGeometry(QRect(500, 0, 31, 21));
        Calculatrice->setCentralWidget(centralWidget);
        addTab->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(Calculatrice);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 523, 18));
        menuKjg = new QMenu(menuBar);
        menuKjg->setObjectName(QString::fromUtf8("menuKjg"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        Calculatrice->setMenuBar(menuBar);

        menuBar->addAction(menuKjg->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuKjg->addAction(actionAnnuler);
        menuKjg->addAction(actionR_tablir);
        menuAffichage->addAction(actionClavier);

        retranslateUi(Calculatrice);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Calculatrice);
    } // setupUi

    void retranslateUi(QMainWindow *Calculatrice)
    {
        Calculatrice->setWindowTitle(QApplication::translate("Calculatrice", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("Calculatrice", "Annuler", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("Calculatrice", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionClavier->setText(QApplication::translate("Calculatrice", "Clavier", 0, QApplication::UnicodeUTF8));
        pileTxt->setInputMask(QString());
        pileTxt->setText(QString());
        BtSWAP->setText(QApplication::translate("Calculatrice", "SWAP", 0, QApplication::UnicodeUTF8));
        BtSUM->setText(QApplication::translate("Calculatrice", "SUM", 0, QApplication::UnicodeUTF8));
        BtMEAN->setText(QApplication::translate("Calculatrice", "MEAN", 0, QApplication::UnicodeUTF8));
        BtCLEAR->setText(QApplication::translate("Calculatrice", "CLEAR", 0, QApplication::UnicodeUTF8));
        BtDUP->setText(QApplication::translate("Calculatrice", "DUP", 0, QApplication::UnicodeUTF8));
        BtDROP->setText(QApplication::translate("Calculatrice", "DROP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Calculatrice", "Op\303\251ration sur la pile:", 0, QApplication::UnicodeUTF8));
        BtSIN->setText(QApplication::translate("Calculatrice", "SIN", 0, QApplication::UnicodeUTF8));
        BtCOS->setText(QApplication::translate("Calculatrice", "COS", 0, QApplication::UnicodeUTF8));
        BtTAN->setText(QApplication::translate("Calculatrice", "TAN", 0, QApplication::UnicodeUTF8));
        BtSINH->setText(QApplication::translate("Calculatrice", "SINH", 0, QApplication::UnicodeUTF8));
        BtCOSH->setText(QApplication::translate("Calculatrice", "COSH", 0, QApplication::UnicodeUTF8));
        BtTANH->setText(QApplication::translate("Calculatrice", "TANH", 0, QApplication::UnicodeUTF8));
        BtLN->setText(QApplication::translate("Calculatrice", "LN", 0, QApplication::UnicodeUTF8));
        BtLN_2->setText(QApplication::translate("Calculatrice", "LOG", 0, QApplication::UnicodeUTF8));
        BtSQRT->setText(QApplication::translate("Calculatrice", "SQRT", 0, QApplication::UnicodeUTF8));
        BtSQR->setText(QApplication::translate("Calculatrice", "SQR", 0, QApplication::UnicodeUTF8));
        BtCUBE->setText(QApplication::translate("Calculatrice", "CUBE", 0, QApplication::UnicodeUTF8));
        BtFactoriel->setText(QApplication::translate("Calculatrice", "!", 0, QApplication::UnicodeUTF8));
        BtComplexe->setText(QApplication::translate("Calculatrice", "$", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Calculatrice", "Fonction:", 0, QApplication::UnicodeUTF8));
        Bt8->setText(QApplication::translate("Calculatrice", "8", 0, QApplication::UnicodeUTF8));
        Bt9->setText(QApplication::translate("Calculatrice", "9", 0, QApplication::UnicodeUTF8));
        Bt4->setText(QApplication::translate("Calculatrice", "4", 0, QApplication::UnicodeUTF8));
        Bt5->setText(QApplication::translate("Calculatrice", "5", 0, QApplication::UnicodeUTF8));
        Bt6->setText(QApplication::translate("Calculatrice", "6", 0, QApplication::UnicodeUTF8));
        Bt1->setText(QApplication::translate("Calculatrice", "1", 0, QApplication::UnicodeUTF8));
        Bt2->setText(QApplication::translate("Calculatrice", "2", 0, QApplication::UnicodeUTF8));
        Bt3->setText(QApplication::translate("Calculatrice", "3", 0, QApplication::UnicodeUTF8));
        Bt0->setText(QApplication::translate("Calculatrice", "0", 0, QApplication::UnicodeUTF8));
        BtPlus->setText(QApplication::translate("Calculatrice", "+", 0, QApplication::UnicodeUTF8));
        BtMult->setText(QApplication::translate("Calculatrice", "*", 0, QApplication::UnicodeUTF8));
        BtDiv->setText(QApplication::translate("Calculatrice", "/", 0, QApplication::UnicodeUTF8));
        BtSigne->setText(QApplication::translate("Calculatrice", "(-)", 0, QApplication::UnicodeUTF8));
        BtVirgule->setText(QApplication::translate("Calculatrice", ",", 0, QApplication::UnicodeUTF8));
        BtEval->setText(QApplication::translate("Calculatrice", "Eval", 0, QApplication::UnicodeUTF8));
        BtExpression->setText(QApplication::translate("Calculatrice", "'", 0, QApplication::UnicodeUTF8));
        Bt7->setText(QApplication::translate("Calculatrice", "7", 0, QApplication::UnicodeUTF8));
        BtMoins->setText(QApplication::translate("Calculatrice", "-", 0, QApplication::UnicodeUTF8));
        BtModulo->setText(QApplication::translate("Calculatrice", "%", 0, QApplication::UnicodeUTF8));
        BtPuissance->setText(QApplication::translate("Calculatrice", "^", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Calculatrice", "Pav\303\251 num\303\251rique:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Calculatrice", "Pile:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Calculatrice", "Entr\303\251e:", 0, QApplication::UnicodeUTF8));
        radioButton_Entier->setText(QApplication::translate("Calculatrice", "Entier", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Calculatrice", "Rationnel", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Calculatrice", "Complexe", 0, QApplication::UnicodeUTF8));
        radioButton_Degre->setText(QApplication::translate("Calculatrice", "Degre", 0, QApplication::UnicodeUTF8));
        radioButton_Radian->setText(QApplication::translate("Calculatrice", "Radian", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Calculatrice", "Tab 1", 0, QApplication::UnicodeUTF8));
        addTab->setText(QApplication::translate("Calculatrice", "+", 0, QApplication::UnicodeUTF8));
        menuKjg->setTitle(QApplication::translate("Calculatrice", "Edition", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("Calculatrice", "Affichage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calculatrice: public Ui_Calculatrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATRICE_H
