#include "calculatrice.h"
#include "ui_calculatrice.h"

const QString Calculatrice::AFFICHAGE_NAME = QString("affichage_pile");


Calculatrice::Calculatrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculatrice)
{

    ui->setupUi(this);
    connect(ui->addTab, SIGNAL(clicked()), this, SLOT(creerTab()));


    mapper = new QSignalMapper();

    connect(ui->BtBack, SIGNAL(clicked()), this, SLOT(effacer()));
    connect(ui->BtVider, SIGNAL(clicked()), ui->entreeTxt, SLOT(clear()));
    connect(ui->BtEnvoyer, SIGNAL(clicked()), this, SLOT(envoyer()));
    // PAVE NUMERIQUE
    connect(ui->Bt0, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt0, "0");
    connect(ui->Bt1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt1, "1");
    connect(ui->Bt2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt2, "2");
    connect(ui->Bt3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt3, "3");
    connect(ui->Bt4, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt4, "4");
    connect(ui->Bt5, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt5, "5");
    connect(ui->Bt6, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt6, "6");
    connect(ui->Bt7, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt7, "7");
    connect(ui->Bt8, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt8, "8");
    connect(ui->Bt9, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->Bt9, "9");
    //OPERATEUR
    connect(ui->BtPlus, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtPlus, "+");
    connect(ui->BtMoins, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtMoins, "-");
    connect(ui->BtVirgule, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtVirgule, ",");
    connect(ui->BtSigne, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSigne, "NEG");
    connect(ui->BtMult, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtMult, "*");
    connect(ui->BtDiv, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtDiv, "/");
    connect(ui->BtExpression, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtExpression, "'");
    connect(ui->BtPuissance, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtPuissance, "^");
    connect(ui->BtEspace, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtEspace, " ");
    //FONCTION
    connect(ui->BtFactoriel, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtFactoriel, "!");
    connect(ui->BtModulo, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtModulo, "%");


    connect(mapper, SIGNAL(mapped(const QString &)), this, SLOT(ecrire(const QString &)));
    creerTab();



}

void Calculatrice::analyse(const QString & txt){

}

void Calculatrice::ecrire(const QString & txt){
    QString txtact = ui->entreeTxt->text();
    ui->entreeTxt->setText(txtact+txt);
}

void Calculatrice::effacer(){
    QString txtact = ui->entreeTxt->text();
    txtact.resize(txtact.length()-1);
   ui->entreeTxt->setText(txtact);
}

void Calculatrice::envoyer(){
    QString txt = ui->entreeTxt->text();
    analyser(txt);
}

void Calculatrice::afficherPile(const QString & txt){
    analyser(txt);
    this->pileActive()->afficher();
}

Pile * Calculatrice::pileActive(){
    QLabel *fileNameLabel = ui->tabWidget->currentWidget()->findChild<QLabel *>(AFFICHAGE_NAME);

    std::list<Pile>::const_iterator
        lit (onglet.begin()),
        lend(onglet.end());
    for(;lit!=lend;++lit) {
        Pile p = (*lit);
       if(p.affichage==fileNameLabel){
           return &p;
       }
    }

}

//AJOUTE UN NOUVEL ONGLET ET CREE UNE NOUVELLE PILE
void Calculatrice::creerTab(){
    QWidget *newTab = new QWidget( ui->tabWidget );
    QLabel *fileNameLabel = new QLabel(tr("Pile"));
    fileNameLabel->setObjectName (AFFICHAGE_NAME);
    QVBoxLayout *mainLayout = new QVBoxLayout;
      mainLayout->addWidget(fileNameLabel);
      newTab->setLayout(mainLayout);
      ui->tabWidget->addTab( newTab, ( "New tab" ) );

      Pile * nPile = new Pile(fileNameLabel);
      onglet.push_back( *nPile);

}

Calculatrice::~Calculatrice()
{
    delete ui;
}

