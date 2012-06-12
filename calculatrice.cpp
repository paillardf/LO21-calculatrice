#include "calculatrice.h"
#include "ui_calculatrice.h"


const QString Calculatrice::AFFICHAGE_NAME = QString("affichage_pile");

Calculatrice *Calculatrice::_singleton = NULL;

Calculatrice::Calculatrice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculatrice),
    onglet(0)
{
//Qt::Dialog|
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);


    ui->setupUi(this);
    connect(ui->addTab, SIGNAL(clicked()), this, SLOT(creerTab()));
    connect(ui->nbElementPile, SIGNAL(valueChanged(int)), this, SLOT(afficher(int)));
    connect(ui->actionAnnuler, SIGNAL(triggered()), this , SLOT(annuler()));
    connect(ui->actionRetablir, SIGNAL(triggered()), this , SLOT(retablir()));
    connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(detruireTab(int)));
    connect(ui->actionClavier, SIGNAL(toggled(bool)), this, SLOT(redimentionner(bool)));



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
    mapper->setMapping(ui->BtSigne, "SIGN");
    connect(ui->BtInv, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtInv, "INV");
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
    connect(ui->BtComplexe, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtComplexe, "$");
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
    connect(ui->BtEval, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->BtEval, "EVAL");

    connect(mapper, SIGNAL(mapped(const QString &)), this, SLOT(ecrire(const QString &)));
    QFile file("xml_doc.xml");
       if (!file.open(QIODevice::ReadOnly)){
           creerTab();
       }else{
         Xml_Dom(this);
       }


}

void Calculatrice::sauvegarde(){

    EcritureDom* save = new EcritureDom();

    if(ui->complexeBox->isChecked()){
        save->ajoutpara("Complexe");
    }
    if(ui->radioButton_Degre->isChecked()){
        save->ajoutpara("Degre");
    }
    if(ui->radioButton_Entier->isChecked()){
        save->ajoutpara("Entier");
    }
    if(ui->radioButton_Radian->isChecked()){
        save->ajoutpara("Radian");
    }
    if(ui->radioButton_Rationnel->isChecked()){
        save->ajoutpara("Rationnel");
    }
    if(ui->radioButton_Reel->isChecked()){
        save->ajoutpara("Reel");
    }

    for(int i=0; i<this->onglet.size(); i++){
        save->ajoutpile((this->onglet.at(i)));
    }

    delete save;

}
void Calculatrice::chgEntier(){
    ui->radioButton_Entier->setChecked(true);
}
void Calculatrice::chgRationnel(){
    ui->radioButton_Rationnel->setChecked(true);
}
void Calculatrice::chgReel(){
    ui->radioButton_Reel->setChecked(true);
}
void Calculatrice::chgComplexe(){
    ui->complexeBox->setChecked(true);
}
void Calculatrice::chgDegre(){
    ui->radioButton_Degre->setChecked(true);
}
void Calculatrice::chgRadian(){
    ui->radioButton_Radian->setChecked(true);
}

void Calculatrice::analyse(const QString & txt){
    QString txtTemp = txt;

    while(!txtTemp.isEmpty())
    {
        QChar c = txtTemp.at(0);

        if(c.isDigit()||txtTemp.right(1).compare("'")==0){
            CommandeBasic *cmd = new CommandeBasic(this->pileActive());

            Constante *  val = getConstante(txtTemp);
            if(ui->complexeBox->isChecked()&&!txtTemp.isEmpty()){
                c = txtTemp.at(0);
                if(c=='$'){
                    txtTemp = txtTemp.right(txtTemp.length()-1);
                    val = new CComplexe(val,getConstante(txtTemp));
                }
            }

            cmd->addNew(val);
            this->pileActive()->push(val);
            this->pileActive()->saveCommande((Commande *) cmd);
        }else{

            int pos = txtTemp.length()-1;
            if(c=='+'){

                pileActive()->fAddition();
                txtTemp = txtTemp.right(pos);
            }else if(c==' '){
                txtTemp = txtTemp.right(pos);
            }else if(c=='-'){
                pileActive()->fSoustraction();
                txtTemp = txtTemp.right(pos);
            }else if(c=='*'){
                pileActive()->fMultiplication();
                txtTemp = txtTemp.right(pos);
            }else if(c=='/'){
                pileActive()->fDivision();
                txtTemp = txtTemp.right(pos);
            }else if(c=='^'){
                pileActive()->fPOW();
                txtTemp = txtTemp.right(pos);
            }else if(c=='%'){
                pileActive()->fMOD();
                txtTemp = txtTemp.right(pos);
            }else if(c=='!'){
                pileActive()->fact();
                txtTemp = txtTemp.right(pos);
            }else if(txtTemp.left(4).compare("CUBE")==0){
                pileActive()->fCUBE();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(4).compare("SQRT")==0){
                pileActive()->fSQRT();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(3).compare("SQR")==0){
                pileActive()->fSQR();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(4).compare("SINH")==0){
                pileActive()->fSINH();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(3).compare("SIN")==0){
                pileActive()->fSIN();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(4).compare("COSH")==0){
                pileActive()->fCOSH();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(3).compare("COS")==0){
                pileActive()->fCOS();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(4).compare("TANH")==0){
                pileActive()->fTANH();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(3).compare("TAN")==0){
                pileActive()->fTAN();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(2).compare("LN")==0){
                pileActive()->fLN();
                txtTemp = txtTemp.right(pos-1);
            }else if(txtTemp.left(3).compare("LOG")==0){
                pileActive()->fLOG();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(3).compare("INV")==0){
                pileActive()->fINV();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(4).compare("SIGN")==0){
                pileActive()->fSIGN();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(4).compare("SWAP")==0){
                pileActive()->swap();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(3).compare("DUP")==0){
                pileActive()->dup();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(3).compare("SUM")==0){
                pileActive()->sum();
                txtTemp = txtTemp.right(pos-2);
            }else if(txtTemp.left(4).compare("DROP")==0){
                pileActive()->drop();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(4).compare("MEAN")==0){
                pileActive()->mean();
                txtTemp = txtTemp.right(pos-3);
            }else if(txtTemp.left(5).compare("CLEAR")==0){
                pileActive()->clear();
                txtTemp = txtTemp.right(pos-4);
            }else if(txtTemp.left(4).compare("EVAL")==0){
                this->fEVAL();
                txtTemp = txtTemp.right(pos-3);
            }else{

                throw std::logic_error( "SYNTAXE : verifiez votre syntaxe, element invalide detecte");

            }


        }

    }
    this->pileActive()->afficher(ui->nbElementPile->value());
}

void Calculatrice::fEVAL(){
    Pile * p = pileActive();
    if(p->isEmpty()){
        throw std::logic_error( "EVAL : la pile est vide");

    }

    if(typeid(*p->top()) ==typeid(CExpression)){
        try{
            Constante * nbr = p->pop();
            CommandeEval * c = new CommandeEval(p, nbr);
            p->saveCommande(c);
            p->setExecutionCommande(2);// ON RECUPERE TOUTES LES COMMANDES ENREGISTRE
            this->analyse(nbr->getValuetoString());
            p->setExecutionCommande(0);
        }catch ( std::logic_error e ) // ERREUR PENDANT L EVALUATION DE L EXPRESSION
        {
          p->setExecutionCommande(0);
          p->retablir();
          throw e;

        }

    }else{
        throw std::logic_error( "EVAL : le parametre doit etre une expression");
    }
} // évaluation d'une expression (Expression)


Constante * Calculatrice::getConstante(QString & txtTemp){

    if(txtTemp.left(1).compare("'")==0){

       int taille = txtTemp.size();
       txtTemp = txtTemp.right(taille-1);
       int pos = txtTemp.lastIndexOf("'");

       if(pos==-1){
           throw std::logic_error( "SYNTAXE : expression non fermee");

       }else{
           QString val = txtTemp.left(pos);
           Constante * c = (Constante *) new CExpression(val);
           txtTemp = txtTemp.right(taille-pos-2);
           return c;

       }
    }else{

        int t = getSizeNumber(txtTemp);
        QString a = txtTemp.left(t);
        txtTemp = txtTemp.right(txtTemp.size()-t);
        if(!txtTemp.isEmpty())
        {

            if(txtTemp.at(0)==','){//NOMBRE A VIRGULE
                t = txtTemp.size()-1;
                QString tp = txtTemp.right(t);
                txtTemp = tp;
                t = getSizeNumber(txtTemp);
                QString b = txtTemp.left(t);
                txtTemp = txtTemp.right(txtTemp.size()-t);
                QString nombre = a+','+b;
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

int Calculatrice::getSizeNumber(const QString & txt){
    int pos = 0;
    QChar c = txt.at(pos);

    while(c.isDigit()){


            pos++;
        if(pos<txt.size()){
            c = txt.at(pos);
        }else{
            break;
        }


    }
    return pos;
}

void Calculatrice::ecrire(const QString & txt){
    QString txtact = ui->entreeTxt->text();
    ui->entreeTxt->setText(txtact+txt);
    if(!ui->entreeTxt->text()[0].isDigit()&&!(ui->entreeTxt->text()[0] == '$')&&!(ui->entreeTxt->text()[0] == ',') && !(ui->entreeTxt->text().indexOf("'")!=-1) ){ //TODO verifier si pas de '
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


//GESTION DES ERREURS : QMessageBox::critical( 0, "Exception", "ex.what()", "Ok" );

    try
        {
            analyse(txt);
            ui->entreeTxt->clear();
        }
        catch ( std::logic_error e ) // traitement par valeur
        {
           ui->entreeTxt->setText(txt);
           QMessageBox::critical( 0, "Exception", e.what(), "Ok" );
        }



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

void Calculatrice::detruireTab(int index){


            if (onglet.size()>1)
                {

                Pile * p = this->onglet.at(index);
                this->onglet.erase(this->onglet.begin()+index);
                delete p;

                ui->tabWidget->removeTab(index);

                }


}

void Calculatrice::creerTab(){
    QWidget *newTab = new QWidget( ui->tabWidget );
    QLabel *fileNameLabel = new QLabel(tr("Pile"));
    fileNameLabel->setObjectName (AFFICHAGE_NAME);
    QVBoxLayout *mainLayout = new QVBoxLayout;
      mainLayout->addWidget(fileNameLabel);
      newTab->setLayout(mainLayout);
      QString nom = "Feuille "+QString::number(onglet.size()+1);
      ui->tabWidget->addTab( newTab, nom);
      Pile * nPile = new Pile(fileNameLabel,ui->radioButton_Entier, ui->radioButton_Rationnel, ui->radioButton_Degre, ui->complexeBox,  ui->nbElementPile->value());
      onglet.push_back(nPile);

      Pile * pAct =  pileActive();
      if(pAct!=nPile){
              pileActive()->clone(*nPile);
      }

     nPile->afficher(ui->nbElementPile->value());
     ui->tabWidget->setCurrentWidget(newTab);





}



void Calculatrice::redimentionner(bool t){
    if(!t){
        this->resize(530, 260);

    }else{
        this->resize(530, 130);
    }
}

Calculatrice::~Calculatrice()
{

    this->sauvegarde();

    for(int i = 0; i < onglet.size(); i++){
        delete onglet.at(i);
    }

    delete ui;
}

