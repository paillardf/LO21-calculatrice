#include "calculatrice.h"
#include "ui_calculatrice.h"

const QString Calculatrice::AFFICHAGE_NAME = QString("affichage_pile");


Calculatrice::Calculatrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculatrice),
    onglet(0)
{

    ui->setupUi(this);
    connect(ui->addTab, SIGNAL(clicked()), this, SLOT(creerTab()));
    connect(ui->nbElementPile, SIGNAL(valueChanged(int)), this, SLOT(afficher(int)));

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
    QString txtTemp = txt;

    while(!txtTemp.isEmpty())
    {
        int pos = txtTemp.length()-1;
        QChar c = txtTemp.at(pos);

        if(c.isDigit()){
            Constante *  val = getConstante(txtTemp);
            if(ui->complexeBox->isChecked()&&!txtTemp.isEmpty()){
                pos = txtTemp.length()-1;
                c = txtTemp.at(pos);
                if(c=='$'){
                    val = new CComplexe(getConstante(txtTemp), val);
                }
            }
            this->pileActive()->push(val);
        }
    }
    this->pileActive()->afficher(ui->nbElementPile->value());
    //ui->entreeTxt->setText("FIN");
}

Constante * Calculatrice::getConstante(QString & txtTemp){

        QString a = getNumber(txtTemp);
        QString b = "";
        if(!txtTemp.isEmpty())
        {
            int pos = txtTemp.length()-1;
            QChar c = txtTemp.at(pos);


            if(c==','){//NOMBRE A VIRGULE
                txtTemp = txtTemp.left(pos);
                b=a;
                a = getNumber(txtTemp);
                pos = txtTemp.length()-1;
            }
        }



        if(ui->radioButton_Reel->isChecked()){
            QString nombre = a+","+b;
            return  new CReel(nombre.toDouble());

        }else if(ui->radioButton_Entier->isChecked()){
            QString nombre = a+","+b;
            return new CEntier(nombre.toInt());

        }else if(ui->radioButton_Rationnel->isChecked()){
           int coef = 0;
           coef = b.length();
           a.push_back(b);
           return new CRationnel(a.toInt(),pow(10, coef));
        }



}

void Calculatrice::afficher(int max){
    this->pileActive()->afficher(max);
}

QString &Calculatrice::getNumber(QString & txt){
    int pos = txt.length()-1;
    QChar c = txt.at(pos);

    while(c.isDigit()){

        if(pos>0){
            pos--;
        }else{
            break;
        }
        c = txt.at(pos);

    }
    QString r(txt.right(txt.length()-pos));
    txt = txt.left(pos);
    return r;
}

void Calculatrice::ecrire(const QString & txt){
    QString txtact = ui->entreeTxt->text();
    ui->entreeTxt->setText(txtact+txt);
    if(!txt[0].isDigit()){
        this->envoyer();
    }
}

void Calculatrice::effacer(){
    QString txtact = ui->entreeTxt->text();
    txtact.resize(txtact.length()-1);
   ui->entreeTxt->setText(txtact);
}

void Calculatrice::envoyer(){
    QString txt = ui->entreeTxt->text();
    analyse(txt);
}

Pile * Calculatrice::pileActive(){
    QLabel *fileNameLabel = ui->tabWidget->currentWidget()->findChild<QLabel *>(AFFICHAGE_NAME);


    for(int i =0; i< onglet.size(); ++i) {

       if(onglet.at(i)->affichage==fileNameLabel){
           return (onglet.at(i));
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
      Pile * nPile = new Pile(fileNameLabel,ui->radioButton_Entier, ui->radioButton_Rationnel, ui->radioButton_Degre, ui->complexeBox,  ui->nbElementPile->value());
      onglet.push_back(nPile);

     nPile->afficher(ui->nbElementPile->value());

}





Calculatrice::~Calculatrice()
{
    delete ui;
}

