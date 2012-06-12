#include "pile.h"

Pile::Pile(QLabel * aff, QRadioButton * _btEntier,QRadioButton * _btRationnel,QRadioButton * _btDegre,QCheckBox * _btComplexe, int max):
    affichage(aff),
    btEntier(_btEntier),
    btRationnel(_btRationnel),
    btDegre(_btDegre),
    btComplexe(_btComplexe),
    posCommande(0),
    executionCommande(0)

{
    afficher(max);
}

Pile::~Pile()
{
    while(posCommande <=listeCommande.size()-1){
        this->annuler();
    }
    while(!listeCommande.empty()){
        Commande * c = listeCommande.pop();
        delete c;
    }
    while(!this->empty()){
        delete this->pop();
    }

}
//############# COMMANDE ##################
void Pile::saveCommande(Commande * c){
//en cas d'utilisation des fonctions de la pile dans un do ou undo d'une commande,
//la commande cree ne doit pas être concerve (utile uniquement pour commande Non Basic
    if(executionCommande ==2){ //2 ENREGISTREMENT DE L ENSEMBLE DES COMMANDES D UN EVAL
        CommandeEval * cmd = (CommandeEval *) listeCommande.top();
        cmd->addCommande(c);
    }else if(executionCommande==1){ //1 COMMANDE EN COURS D UTILISATION ON ENREGISTRE PAS
        c->Vider();
        delete c;
    }else{

        for (int i = posCommande; i>0;i--){
            delete listeCommande.pop();
        }
        posCommande = 0;
        listeCommande.push(c);
    }
}

void Pile::annuler()
{
    if(posCommande <=listeCommande.size()-1){//verification si commande a retablir
        executionCommande = 1;//On empeche de nouvelle commande de s'enregistrer pendant l'execution d'une commande
        Commande * c = listeCommande.at(listeCommande.size()-1-posCommande);
        c->Undo();
        posCommande ++;
        executionCommande = 0;
    }

}

void Pile::retablir(){
    if(posCommande !=0){ //== 0 pas de commande a retablir
        executionCommande = 1;//On empeche de nouvelle commande de s'enregistrer pendant l'execution d'une commande
        posCommande --;
        Commande * c = listeCommande.at(listeCommande.size()-1-posCommande);
        c->Do();
        executionCommande = 0;

    }
}



//############# OPERATION ##################
void Pile::clone(Pile & p) const{

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
//    if(typeid(*cst) ==typeid(CEntier) && !isEntier()){
//        CEntier *  tmp =(CEntier*) cst;
//        if(isRationnel()){

//            cst = new CRationnel(tmp->getValue(), 1);
//        }else {
//            cst = new CReel(tmp->getValue());
//        }
//        delete tmp;

//    }
    if(typeid(*cst) ==typeid(CRationnel) && !isRationnel()){
        CRationnel * tmp = (CRationnel*) cst;
        if(isEntier()){

            cst = new CEntier((float)tmp->getNum()/(float)tmp->getDenom());
        }else {
            cst = new CReel((float)tmp->getNum()/(float)tmp->getDenom());
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

    if(this->size()<2){
        throw std::logic_error( "SWAP : deux parametres sont necessaires");
    }
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
    if(this->isEmpty()){
        throw std::logic_error( "SUM :la pile est vide");
    }
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

    this->cast(somme);
    this->push(somme);
    cmd->addNew(somme);
    this->saveCommande(cmd); //On enregistre la commande
    }else{
         throw std::logic_error( "SUM : le parametre doit être un entier");
    }
}

void Pile::mean(){
    if(this->isEmpty()){
        throw std::logic_error( "MEAN :la pile est vide");
    }
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




    Constante* div = new CEntier(x);
    Constante * res = somme->operator /(*div);
    this->cast(res);
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

    }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) *this->top();
        nouv = new CRationnel(c1);
    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        CReel &c1 = (CReel&) *this->top();
        nouv = new CReel(c1);
    }
    else if(typeid(*this->top()) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) *this->top();
        nouv = new CComplexe(c1);
    }
    else if(typeid(*this->top()) ==typeid(CExpression)){
        CExpression &c1 = (CExpression&) *this->top();
        nouv = new CExpression(c1);
    }
   this->cast(nouv);
   this->push(nouv);
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
        if(typeid(*inter) ==typeid(CEntier)){
            if(((CEntier * )inter)->getValue()==0){
                throw std::logic_error("ERROR");
            }
        }else if(typeid(*inter) ==typeid(CRationnel)){
            if(((CRationnel * )inter)->getNum()==0){
                throw std::logic_error("ERROR");
            }
        }else if(typeid(*inter) ==typeid(CReel)){
            if(((CReel * )inter)->getValue()==0){
                throw std::logic_error("ERROR");
            }
        }
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
    if(this->size()<2){
        throw std::logic_error( "POW : Il n'y a pas assez de parametres");

    }

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
            else if(typeid(*this->top()) ==typeid(CRationnel)){
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
                this->cast(res);
                this->push(res);
                CommandeBasic * cmd = new CommandeBasic(this);
                cmd->addOld(pow);
                cmd->addOld(nbr);
                cmd->addNew(res);
                this->saveCommande(cmd);

            }
            else if(typeid(*this->top()) ==typeid(CReel)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) pow;
                CReel *c2 = (CReel*) nbr;
                int resu = 1;
                for(int i =1; i<=c1->getValue() ; i++){
                    resu = resu*c2->getValue();}
                Constante * res = (Constante * ) new CReel(resu);
                this->cast(res);
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
    if(this->size()<2){
        throw std::logic_error( "MODULO : Il n'y a pas assez de parametres");

    }
    if(typeid(*this->top()) ==typeid(CEntier)){
         Constante* mod = this->pop();
            if(typeid(*this->top()) ==typeid(CEntier)){
                Constante* nbr = this->pop();
                CEntier *c1 = (CEntier*) mod;
                if(c1->getValue()==0){
                    this->push(nbr);
                    this->push(mod);
                    throw std::logic_error( "POW : le parametre ne peux pas être 0");
                }
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
    if(!this->isEmpty()){
        Constante* nbr = this->pop();
        CEntier *c1 = new CEntier(0);
        Constante* res = c1->operator -(*nbr);
        this->cast(res);
        this->push(res);
        delete c1;
        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(nbr);
        cmd->addNew(res);
        this->saveCommande(cmd);

    }
    else{
        //EXPRESSION
        throw std::logic_error( "SIGN : la pile est vide");
    }


} // inversion du signe (entier, rationnel, réel, complexe, expression)


void Pile::fSIN(){

    if(this->isEmpty()){
        throw std::logic_error( "SIN : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "SIN : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = sin(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);


} // sinus (entier, rationnel, réel)

void Pile::fCOS(){
    if(this->isEmpty()){
        throw std::logic_error( "COS : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "COS : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = cos(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // cosinus (entier, rationnel, réel)

void Pile::fTAN(){
    if(this->isEmpty()){
        throw std::logic_error( "TAN : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "TAN : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = tan(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // tangente (entier, rationnel, réel)

void Pile::fSINH(){
    if(this->isEmpty()){
        throw std::logic_error( "SINH : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "SINH : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = sinh(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // sinus hyperbolique (entier, rationnel, réel)

void Pile::fCOSH(){
    if(this->isEmpty()){
        throw std::logic_error( "COSH : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "COSH : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = cosh(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // cosinus hyperbolique (entier, rationnel, réel)

void Pile::fTANH(){
    if(this->isEmpty()){
        throw std::logic_error( "TANH : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "TANH : le parametre est de type invalide");
    }

    if(isDegre()){
        val = val*M_PI*2/(float)380;
    }
    val = tanh(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // tangente hyperbolique (entier, rationnel, réel)


void Pile::fLN(){
    if(this->isEmpty()){
        throw std::logic_error( "LN : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "LN : le parametre est de type invalide");
    }


    val = log(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // logarithme népérien (entier, rationnel, réel)

void Pile::fLOG(){
    if(this->isEmpty()){
        throw std::logic_error( "LOG : la pile est vide");

    }

    float val = 0;
    Constante* nbr;

    if(typeid(*this->top()) ==typeid(CEntier)){
        nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
         val = c1->getValue();

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        val = (float)(c1->getNum()/c1->getDenom());

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        val = c1->getValue();
    }else{
        throw std::logic_error( "LOG : le parametre est de type invalide");
    }


    val = log10(val);

    Constante * res = (Constante*)new CReel(val);
    this->cast(res);
    this->push(res);

    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // logarithme décimal (entier, rationnel, réel)

void Pile::fINV(){

    if(this->isEmpty()){
        throw std::logic_error( "INV : la pile est vide");

    }

    Constante* nbr = this->pop();
    CEntier * c= new CEntier(1);
    Constante * res = c->operator /(*nbr);
    this->cast(res);
    this->push(res);
    delete c;
    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);

} // inverse (entier, rationnel, réel)

void Pile::fSQRT(){

    if(this->isEmpty()){
        throw std::logic_error( "SQRT : la pile est vide");

    }


    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = (CEntier*) nbr;
        Constante * res =(Constante*)new CReel((float)sqrt(c1->getValue()));
        this->push(res);

        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(nbr);
        cmd->addNew(res);
        this->saveCommande(cmd);

          }
    else if(typeid(*this->top()) ==typeid(CRationnel)){
        Constante* nbr = this->pop();
        CRationnel *c1 = (CRationnel*) nbr;
        Constante * res = (Constante*)new CReel((float)sqrt(c1->getNum()/(float)c1->getDenom()));
        this->cast(res);
        this->push(res);

        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(nbr);
        cmd->addNew(res);
        this->saveCommande(cmd);

    }
    else if(typeid(*this->top()) ==typeid(CReel)){
        Constante* nbr = this->pop();
        CReel *c1 = (CReel*) nbr;
        Constante * res =(Constante*)new CReel((float)sqrt(c1->getValue()));
        this->cast(res);
        this->push(res);

        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(nbr);
        cmd->addNew(res);
        this->saveCommande(cmd);

    }else{
        throw std::logic_error( "SQRT : le parametre est de type invalide");

    }
} // racine carré (entier, rationnel, réel)

void Pile::fSQR(){

    if(this->isEmpty()){
        throw std::logic_error( "SQR : la pile est vide");

    }


    Constante* nbr = this->pop();
    Constante * res = nbr->operator *(*nbr);
    this->cast(res);
    this->push(res);
    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // fonction carré (entier, rationnel, réel, complexe)

void Pile::fCUBE(){
    if(this->isEmpty()){
        throw std::logic_error( "CUBE : la pile est vide");

    }
    Constante* nbr = this->pop();
    Constante * res1 = nbr->operator *(*nbr);
    Constante * res = res1->operator *(*nbr);
    this->cast(res);
    this->push(res);

    delete res1;
    CommandeBasic * cmd = new CommandeBasic(this);
    cmd->addOld(nbr);
    cmd->addNew(res);
    this->saveCommande(cmd);
} // fonction cube (entier, rationnel, réel, complexe)

void Pile::fact(){

    if(this->isEmpty()){
        throw std::logic_error( "FACT : la pile est vide");

    }

    if(typeid(*this->top()) ==typeid(CEntier)){
        Constante* nbr = this->pop();
        CEntier *c1 = new CEntier(*((CEntier*) nbr));

        int n = c1->getValue();
        int f = 1;
        while (n > 1) f *= n--;

        c1->setValue(f);
        Constante * res = (Constante*)c1;
        this->cast(res);
        this->push(res);
        CommandeBasic * cmd = new CommandeBasic(this);
        cmd->addOld(nbr);
        cmd->addNew(res);
        this->saveCommande(cmd);

    }else{
        throw std::logic_error( "FACT : le parametre doit etre un entier");
    }
} // factorielle (entier)


