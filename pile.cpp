#include "pile.h"

Pile::Pile(QLabel * aff, QRadioButton * _btEntier,QRadioButton * _btRationnel,QRadioButton * _btDegre,QCheckBox * _btComplexe, int max):
    affichage(aff),
    btEntier(_btEntier),
    btRationnel(_btRationnel),
    btDegre(_btDegre),
    btComplexe(_btComplexe),
    posCommande(0),
    executionCommande(false)

{
    afficher(max);
}

Pile::~Pile()
{
    while(!listeCommande.empty()){
        Commande * c = listeCommande.pop();
        delete c;
    }

}
//############# COMMANDE ##################
void Pile::saveCommande(Commande * c){
//en cas d'utilisation des fonctions de la pile dans un do ou undo d'une commande,
//la commande cree ne doit pas être concerve (utile uniquement pour commande Non Basic
    if(executionCommande){
        delete c;
    }else{

        for (int i = posCommande; i>0;i--){
            delete listeCommande.pop();
        }
        listeCommande.push(c);
    }
}

void Pile::annuler()
{
    if(posCommande <=listeCommande.size()-1){//Pas de commande a retablir
        executionCommande = true;//On empeche de nouvelle commande de s'enregistrer pendant l'execution d'une commande
        Commande * c = listeCommande.at(listeCommande.size()-1-posCommande);
        qDebug()<<"AVANT TO DO";
        c->Undo();
        qDebug()<<"APRES TO DO";
        posCommande ++;
        executionCommande = false;
    }

}

void Pile::retablir(){
    if(posCommande !=0){ //== 0 pas de commande a retablir
        executionCommande = true;//On empeche de nouvelle commande de s'enregistrer pendant l'execution d'une commande
        posCommande --;
        Commande * c = listeCommande.at(listeCommande.size()-1-posCommande);
        c->Do();
        executionCommande = false;

    }
}



//############# COMMANDE ##################
Pile& Pile::clone(Pile & p) const{

    for(int i = 0; i<this->size(); i++){
        Constante * c = this->at(i);
        if(typeid(*c) ==typeid(CEntier)){
             p.push((Constante * )new CEntier(*((CEntier*) c)));
        }else if(typeid(*c) ==typeid(CRationnel)){
            p.push((Constante * )new CRationnel(*((CRationnel*) c)));
        }else if(typeid(*c) ==typeid(CReel)){
            p.push((Constante * )new CReel(*((CReel*) c)));
        }else if(typeid(*c) ==typeid(CComplexe)){
            p.push((Constante * )new CComplexe(*((CComplexe*) c)));
        }else if(typeid(*c) ==typeid(CExpression)){
            p.push((Constante * ) new CExpression(*((CExpression*) c)));
        }
    }
}

void Pile::afficher(int tailleMax){
    QString txt = "";
    int j = 0;
    for ( int i = size() - 1; i >=0; i-- )
    {
    j++;
    if(j>tailleMax)
        break;

        Constante * c = at(i);
        txt+=c->getValuetoString();
        if(i<size())
            txt+= " | ";
    }
     affichage->setText("Pile : |" + txt);
}

void Pile::cast(Constante* & cst){
    if(typeid(*cst) ==typeid(CEntier) && !isEntier()){
        CEntier *  tmp =(CEntier*) cst;
        if(isRationnel()){

            cst = new CRationnel(tmp->getValue(), 1);
        }else {
            cst = new CReel(tmp->getValue());
        }
        delete tmp;

    }
    else if(typeid(*cst) ==typeid(CRationnel) && !isRationnel()){
        CRationnel * tmp = (CRationnel*) cst;
        if(isEntier()){

            cst = new CEntier(tmp->getNum()/tmp->getDenom());
        }else {
            cst = new CReel(tmp->getNum()/tmp->getDenom());
        }
        delete tmp;

    }
    else if(typeid(*cst) ==typeid(CReel) && !(isReel()))
    { CReel * tmp = (CReel*) cst;
        if(isEntier()){

            cst = new CEntier(tmp->getValue());
        }else {
            cst = new CRationnel(tmp->getValue());
        }
        delete tmp;

    }

}



void Pile::swap(){

    if(typeid(*this->top()) ==typeid(CEntier)){
         Constante* t = this->pop();
            if(typeid(*this->top()) ==typeid(CEntier)){

                Constante* v = this->pop();
                CEntier *c1 = (CEntier*) t;
                CEntier *c2 = (CEntier*) v;


     int x =c1->getValue();
     int y = c2->getValue();
    if(x!=y){
        if(x>y){
            int a = x;
            x = y;
            y = a;
        }

        if(y>this->size()){
            throw std::logic_error( "SWAP : parametre trop grand pour la pile");
        }else if(x<1){
           throw std::logic_error( "SWAP : les parametres doivent être positifs");
        }


        x--;
        y--;
        QStack<Constante*> cop;

        for(int i=0; i<x; i++){
            cop.push(this->pop());
        }

        Constante* nouvy = this->pop();

        for(int i=x; i<y-1; i++){
            cop.push(this->pop());
        }

        Constante* nouvx = this->pop();

        this->push(nouvy);

        while(!cop.isEmpty()){
            this->push(cop.pop());
        }

        this->push(nouvx);

//ENREGISTREMENT DE LA COMMANDE
        CommandeSwap * cmd = new CommandeSwap(this);
        cmd->addOld(c1);
        cmd->addOld(c2);
        this->saveCommande(cmd);


    }
 return;
}else{
     this->push(t);
}
}

    throw std::logic_error( "SWAP : les parametres doivent être des entiers");
}

void Pile::sum(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        int x = c1->getValue();
        if(x>this->size()||x<0){
            this->push(nbr);
            throw std::logic_error( "SUM : le parametre est invalides(trop petit/trop grand)");
        }

        //Creation d'une commandeBasic
        CommandeBasic * cmd = new CommandeBasic(this);

        cmd->addOld(c1);//On ajoute les constantes parametre supprimees
    Constante* somme = new CReel(0.0);
    Constante* nsomme;

    for(int i =0; i<x; i++){

        cmd->addOld(this->top());//On ajoute les constantes supprimees
        nsomme = somme->operator +(*this->pop());
        delete somme;
        somme = nsomme;
    }

    this->push(somme);
    cmd->addNew(somme);
    this->saveCommande(cmd); //On enregistre la commande
    }else{
         throw std::logic_error( "SUM : le parametre doit être un entier");
    }
}

void Pile::mean(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        int x = c1->getValue();

        if(x>this->size()||x<0){
            this->push(nbr);
            throw std::logic_error( "MEAN : le parametre est invalides(trop petit/trop grand)");
        }

        //Creation d'une commandeBasic
        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(c1);//On ajoute les constantes parametre supprimees

        Constante* somme = new CReel(0.0);
        Constante* nsomme;
        for(int i =0; i<x; i++){
            cmd->addOld(this->top());//On ajoute les constantes supprimees
            nsomme = somme->operator +(*this->pop());
            delete somme;
            somme = nsomme;
        }

        this->push(somme);


    Constante* div = new CEntier(x);
    Constante * res = this->pop()->operator /(*div);
    this->push(res);
    cmd->addNew(res);
    this->saveCommande(cmd);

    delete div;
    delete somme;
    }else{
        throw std::logic_error( "SUM : le parametre doit être un entier");
   }
}

void Pile::clear(){

    if(!this->isEmpty()){
    CommandeBasic * cmd = new CommandeBasic(this);
        while(!this->isEmpty()){
            cmd->addOld(this->top());
            this->pop();
        }
    this->saveCommande(cmd);
    }
}

void Pile::dup(){

    if(this->isEmpty()){
        throw std::logic_error( "DUP : la pile est vide");

    }

    Constante* nouv;
   if(typeid(*this->top()) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) *this->top();
        nouv = new CEntier(c1);
        this->push(nouv);
    }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) *this->top();
        nouv = new CRationnel(c1);
        this->push(nouv);
    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        CReel &c1 = (CReel&) *this->top();
        nouv = new CReel(c1);
        this->push(nouv);
    }
    else if(typeid(*this->top()) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) *this->top();
        nouv = new CComplexe(c1);
        this->push(nouv);
    }
    else if(typeid(*this->top()) ==typeid(CExpression)){
        CExpression &c1 = (CExpression&) *this->top();
        nouv = new CExpression(c1);
        this->push(nouv);
    }
   CommandeBasic * cmd = new CommandeBasic(this);
   cmd->addNew(nouv);
   this->saveCommande(cmd);

}

void Pile::drop(){

    if(!this->isEmpty()){

        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(this->top());
        this->saveCommande(cmd);
        this->pop();
    }

}

void Pile::fAddition(){
    if(this->size()<2){
        throw std::logic_error( "ADDITION : il n'y a pas assez de paramatres");
    }
    Constante* inter = this->pop();
    Constante* inter2 = this->pop();
    Constante* res = inter2->operator +(*inter);

    this->cast(res);

    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(inter);
    cmd->addOld(inter2);
    cmd->addNew(res);
    this->saveCommande(cmd);



    }
void Pile::fSoustraction(){

    if(this->size()<2){
        throw std::logic_error( "SOUSTRACTION : il n'y a pas assez de paramatres");
    }

    Constante* inter = this->pop();
    Constante* inter2 = this->pop();
    Constante* res = inter2->operator -(*inter);

    this->cast(res);

    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(inter);
    cmd->addOld(inter2);
    cmd->addNew(res);
    this->saveCommande(cmd);

    }
void Pile::fMultiplication(){
    if(this->size()<2){
        throw std::logic_error( "MULTIPLICATION : il n'y a pas assez de paramatres");
    }

    Constante* inter = this->pop();
    Constante* inter2 = this->pop();
    Constante* res = inter2->operator *(*inter);

    this->cast(res);

    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(inter);
    cmd->addOld(inter2);
    cmd->addNew(res);
    this->saveCommande(cmd);


    }
void Pile::fDivision(){
    if(this->size()<2){
        throw std::logic_error( "DIVISION : il n'y a pas assez de paramatres");
    }

    Constante* inter = this->pop();
    Constante* inter2 = this->pop();
    Constante* res;
    try {
         res = inter2->operator /(*inter);
    } catch (std::exception e) { //ArithmeticException TODO
         this->push(inter2);
         this->push(inter);
         throw std::logic_error( "DIVISION : division par zero!");
    }


    this->cast(res);

    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(inter);
    cmd->addOld(inter2);
    cmd->addNew(res);
    this->saveCommande(cmd);


    }

void Pile::fPOW(){


    if(typeid(*this->top()) ==typeid(CEntier)){
         Constante* pow = this->pop();

            if(typeid(*this->top()) ==typeid(CEntier)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) pow;
                CEntier *c2 = (CEntier*) nbr;

                int resu = 1;
                for(int i =1; i<=c1->getValue() ; i++){
                    resu = resu*c2->getValue();}

                Constante * res = (Constante * ) new CEntier(resu);
                this->push(res);
                CommandeBasic * cmd = new CommandeBasic(this);
                cmd->addOld(pow);
                cmd->addOld(nbr);
                cmd->addNew(res);
                this->saveCommande(cmd);
            }
            if(typeid(*this->top()) ==typeid(CRationnel)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) pow;
                CRationnel *c2 = (CRationnel*) nbr;
                int resu = 1;
                int resu2 = 1;
                for(int i =1; i<=c1->getValue() ; i++){
                    resu = resu*c2->getNum();}
                for(int i =1; i<=c1->getValue() ; i++){
                    resu2 = resu2*c2->getDenom();}

                Constante * res = (Constante * ) new CRationnel(resu, resu2);
                this->push(res);
                CommandeBasic * cmd = new CommandeBasic(this);
                cmd->addOld(pow);
                cmd->addOld(nbr);
                cmd->addNew(res);
                this->saveCommande(cmd);

            }
            if(typeid(*this->top()) ==typeid(CReel)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) pow;
                CReel *c2 = (CReel*) nbr;
                int resu = 1;
                for(int i =1; i<=c1->getValue() ; i++){
                    resu = resu*c2->getValue();}
                Constante * res = (Constante * ) new CReel(resu);
                this->push(res);
                CommandeBasic * cmd = new CommandeBasic(this);
                cmd->addOld(pow);
                cmd->addOld(nbr);
                cmd->addNew(res);
                this->saveCommande(cmd);
            }
            else{
                this->push(pow);
                throw std::logic_error( "POW : le deuxieme parametre n'est pas de type valide");
            }
    }else{
        throw std::logic_error( "POW : le premier parametre doit être un entier");
    }

 } // puissance (entier, rationnel, réel)


void Pile::fMOD(){
    if(typeid(*this->top()) ==typeid(CEntier)){
         Constante* mod = this->pop();
            if(typeid(*this->top()) ==typeid(CEntier)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) mod;
                CEntier *c2 = (CEntier*) nbr;

                Constante* res= new CEntier(c2->getValue()%c1->getValue());
                this->push(res);
                CommandeBasic * cmd = new CommandeBasic(this);
                cmd->addOld(nbr);
                cmd->addOld(mod);
                cmd->addNew(res);
                this->saveCommande(cmd);

            }
            else{
                this->push(mod);
                throw std::logic_error( "POW : le deuxieme parametre doit être un entier");
            }
    }else{
        throw std::logic_error( "MODULO : le premier parametre doit être un entier");
    }

} // modulo (entier)

void Pile::fSIGN(){

    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        c1->setValue(-1*c1->getValue());
        Constante* res = c1;
        this->push(res);
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        c1->setNum(-1*c1->getNum());
        Constante* res = c1;
        this->push(res); }
    if(typeid(*this->top()) ==typeid(CComplexe)){
        Constante* nbr = this->pop();
        CComplexe *c1 = (CComplexe*) nbr;
//TODO
        Constante* res = c1;
        this->push(res); }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(-1*c1->getValue());
        Constante* res = c1;
        this->push(res); }


} // inversion du signe (entier, rationnel, réel, complexe)


void Pile::fSIN(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = sin(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = sin((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = sin(c1->getValue());
        this->push((Constante*)new CReel(res));
    }

} // sinus (entier, rationnel, réel)

void Pile::fCOS(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = cos(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = cos((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = cos(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // cosinus (entier, rationnel, réel)

void Pile::fTAN(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = tan(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = tan((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = tan(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // tangente (entier, rationnel, réel)

void Pile::fSINH(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = sinh(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = sinh((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = sinh(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // sinus hyperbolique (entier, rationnel, réel)

void Pile::fCOSH(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = cosh(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = cosh((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = cosh(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // cosinus hyperbolique (entier, rationnel, réel)

void Pile::fTANH(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = tanh(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = tanh((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = tanh(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // tangente hyperbolique (entier, rationnel, réel)


void Pile::fLN(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = log(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = log((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = log(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // logarithme népérien (entier, rationnel, réel)

void Pile::fLOG(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = log10(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        float res = log10((float)(c1->getNum()/c1->getDenom()));
        this->push((Constante*)new CReel(res));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        float res = log10(c1->getValue());
        this->push((Constante*)new CReel(res));
    }
} // logarithme décimal (entier, rationnel, réel)

void Pile::fINV(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        float res = 1.0/(float)(c1->getValue());
        this->push((Constante*)new CReel(res));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        int inter = c1->getNum();
        c1->setNum(c1->getDenom());
        c1->setDenom(inter);
        this->push((Constante*)c1);
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(1.0/c1->getValue());
        this->push((Constante*)c1);
    }
} // inverse (entier, rationnel, réel)

void Pile::fSQRT(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        this->push((Constante*)new CReel((float)sqrt(c1->getValue())));
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        this->push((Constante*)new CReel((float)sqrt(c1->getNum()/(float)c1->getDenom())));
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        this->push((Constante*)new CReel((float)sqrt(c1->getValue())));
    }
} // racine carré (entier, rationnel, réel)

void Pile::fSQR(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        c1->setValue(c1->getValue()*c1->getValue());
        this->push((Constante*)c1);
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        c1->setNum(c1->getNum()*c1->getNum());
        c1->setDenom(c1->getDenom()*c1->getDenom());
        this->push((Constante*)c1);
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(c1->getValue()*c1->getValue());
        this->push((Constante*)c1);
    }
    /*if(typeid(*this->top()) ==typeid(CComplexe)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(c1->getValue()*c1->getValue());
        this->push((Constante*)c1;
    }*/
} // fonction carré (entier, rationnel, réel, complexe)

void Pile::fCUBE(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        c1->setValue(c1->getValue()*c1->getValue()*c1->getValue());
        this->push((Constante*)c1);
          }
    if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        c1->setNum(c1->getNum()*c1->getNum()*c1->getNum());
        c1->setDenom(c1->getDenom()*c1->getDenom()*c1->getDenom());
        this->push((Constante*)c1);
    }
    if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(c1->getValue()*c1->getValue()*c1->getValue());
        this->push((Constante*)c1);
    }
    /*if(typeid(*this->top()) ==typeid(CComplexe)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        c1->setValue(c1->getValue()*c1->getValue());
        this->push((Constante*)c1;
    }*/
} // fonction cube (entier, rationnel, réel, complexe)

void Pile::fact(){
    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;

        int n = c1->getValue();
        int f = 1;
        while (n > 1) f *= n--;

        c1->setValue(f);
        this->push((Constante*)c1);
          }
} // factorielle (entier)

void Pile::fEVAL(){

} // évaluation d'une expression (Expression)
