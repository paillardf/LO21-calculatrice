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
    connect(ui->actionAnnuler, SIGNAL(triggered()), this , SLOT(annuler()));
    connect(ui->actionRetablir, SIGNAL(triggered()), this , SLOT(retablir()));
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
    mapper->setMapping(ui->BtSigne, "INV");
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
    connect(ui->BtPuissance, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtPuissance, "^");
    connect(ui->BtSIN, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSIN, "SIN");
    connect(ui->BtSINH, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSINH, "SINH");
    connect(ui->BtCOSH, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtCOSH, "COSH");
    connect(ui->BtCOS, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtCOS, "COS");
    connect(ui->BtTAN, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtTAN, "TAN");
    connect(ui->BtTANH, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtTANH, "TANH");
    connect(ui->BtLN, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtLN, "LN");
    connect(ui->BtLOG, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtLN, "LOG");
    connect(ui->BtSQR, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSQR, "SQR");
    connect(ui->BtSQRT, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSQRT, "SQRT");
    connect(ui->BtCUBE, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtCUBE, "CUBE");
//OPERATION SUR LA PILE
    connect(ui->BtDUP, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtDUP, "DUP");
    connect(ui->BtDROP, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtDROP, "DROP");
    connect(ui->BtSWAP, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSWAP, "SWAP");
    connect(ui->BtSUM, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtSUM, "SUM");
    connect(ui->BtMEAN, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtMEAN, "MEAN");
    connect(ui->BtCLEAR, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtCLEAR, "CLEAR");

    connect(mapper, SIGNAL(mapped(const QString &)), this, SLOT(ecrire(const QString &)));
    creerTab();

}

// GESTION DES ERREURS : QMessageBox::critical( 0, "Exception", "ex.what()", "Ok" );

//try
//    {
//        // std::logic_error hérite de std::exception
//        throw logic_error( "exception de test" );
//    }
//    catch ( exception e ) // traitement par valeur
//    {
//        cerr << e.what();
//    }

void Calculatrice::analyse(const QString & txt){
    QString txtTemp = txt;

    while(!txtTemp.isEmpty())
    {
        int pos = txtTemp.length()-1;
        QChar c = txtTemp.at(pos);

        if(c.isDigit()||txtTemp.right(1)=="'"){
            Constante *  val = getConstante(txtTemp);
            if(ui->complexeBox->isChecked()&&!txtTemp.isEmpty()){
                pos = txtTemp.length()-1;
                c = txtTemp.at(pos);
                if(c=='$'){
                    val = new CComplexe(getConstante(txtTemp), val);
                }
            }
            this->pileActive()->push(val);
        }else{


            if(c=='+'){

                pileActive()->fAddition();
                txtTemp = txtTemp.left(pos);
            }else if(c==' '){
                txtTemp = txtTemp.left(pos);
            }else if(c=='-'){
                pileActive()->fSoustraction();
                txtTemp = txtTemp.left(pos);
            }else if(c=='*'){
                pileActive()->fMultiplication();
                txtTemp = txtTemp.left(pos);
            }else if(c=='/'){
                pileActive()->fDivision();
                txtTemp = txtTemp.left(pos);
            }else if(c=='^'){
                pileActive()->fPOW();
                txtTemp = txtTemp.left(pos);
            }else if(c=='%'){
                pileActive()->fMOD();
                txtTemp = txtTemp.left(pos);
            }else if(c=='!'){
                pileActive()->fact();
                txtTemp = txtTemp.left(pos);
            }else if(txtTemp.right(4).compare("CUBE")==0){
                pileActive()->fCUBE();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(4).compare("SQRT")==0){
                pileActive()->fSQRT();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(3).compare("SQR")==0){
                pileActive()->fSQR();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(4).compare("SINH")==0){
                pileActive()->fSINH();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(3).compare("SIN")==0){
                pileActive()->fSIN();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(4).compare("COSH")==0){
                pileActive()->fCOSH();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(3).compare("COS")==0){
                pileActive()->fCOS();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(4).compare("TANH")==0){
                pileActive()->fTANH();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(3).compare("TAN")==0){
                pileActive()->fTAN();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(2).compare("LN")==0){
                pileActive()->fLN();
                txtTemp = txtTemp.left(pos-1);
            }else if(txtTemp.right(3).compare("LOG")==0){
                pileActive()->fLOG();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(3).compare("INV")==0){
                pileActive()->fINV();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(4).compare("SWAP")==0){
                pileActive()->swap();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(3).compare("DUP")==0){
                pileActive()->dup();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(3).compare("SUM")==0){
                pileActive()->sum();
                txtTemp = txtTemp.left(pos-2);
            }else if(txtTemp.right(4).compare("DROP")==0){
                pileActive()->drop();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(4).compare("MEAN")==0){
                pileActive()->mean();
                txtTemp = txtTemp.left(pos-3);
            }else if(txtTemp.right(5).compare("CLEAR")==0){
                pileActive()->clear();
                txtTemp = txtTemp.left(pos-4);
            }else{

                //ERREUR

            }


        }

    }
    this->pileActive()->afficher(ui->nbElementPile->value());
    //ui->entreeTxt->setText("FIN");
}


Constante * Calculatrice::getConstante(QString & txtTemp){

    if(txtTemp.right(1).compare("'")==0){
       int taille = txtTemp.size();
       txtTemp = txtTemp.left(taille-1);
       int pos = txtTemp.lastIndexOf("'");
       if(pos==-1){
           //ERREUR EXPRESSION NON FERMEE

       }else{
           txtTemp = txtTemp.left(pos);
           return new CExpression(txtTemp.right(taille-1-pos));

       }
    }else{


        QString a = getNumber(txtTemp);
        QString b = "";

        if(!txtTemp.isEmpty())
        {

            if(a[0]==','){//NOMBRE A VIRGULE


                b=a;
                QString c = getNumber(txtTemp);
                a =c;
                QString nombre = a+b;
                return  new CReel(nombre.toFloat());
            }
        }

            return new CEntier(a.toInt());

    }

}

void Calculatrice::afficher(int max){
    this->pileActive()->afficher(max);
}

void Calculatrice::annuler(){
     Pile * p = pileActive();
     p->annuler();
     p->afficher(ui->nbElementPile->value());
}

void Calculatrice::retablir(){
    Pile * p = pileActive();
    p->retablir();
    p->afficher(ui->nbElementPile->value());
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
    if(!ui->entreeTxt->text()[0].isDigit()&&!(ui->entreeTxt->text()[0] == ',') && !(ui->entreeTxt->text().indexOf("'")!=-1) ){ //TODO verifier si pas de '
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
    ui->entreeTxt->clear();

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

      Pile * pAct =  pileActive();
      if(pAct!=nPile){
              pileActive()->clone(*nPile);
      }

     nPile->afficher(ui->nbElementPile->value());
     ui->tabWidget->setCurrentWidget(newTab);

}





Calculatrice::~Calculatrice()
{
    delete ui;
}

