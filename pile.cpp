#include "pile.h"

Pile::Pile(QLabel * aff, QRadioButton * _btEntier,QRadioButton * _btRationnel,QRadioButton * _btDegre,QCheckBox * _btComplexe, int max):
    affichage(aff),
    btEntier(_btEntier),
    btRationnel(_btRationnel),
    btDegre(_btDegre),
    btComplexe(_btComplexe)

{
    afficher(max);
}

Pile::~Pile()
{
}


Pile& Pile::clone(){
  //TODO
}

void Pile::afficher(int tailleMax){
    QString txt = "Pile :";
    for ( int i = 0; i < std::min(size(), tailleMax); i++ )
    {


        Constante * c = at(i);
        txt+=c->getValuetoString();
        if(i<size()-1)
            txt+= " , ";
    }
    affichage->setText(txt);
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



void Pile::swap(int x, int y){

    if(x!=y){
        if(x>y){
            int a = x;
            x = y;
            y = a;
        }

        QStack<Constante*> cop;

        for(int i=0; i<x; i++){
            cop.push(this->pop());
        }

        Constante* nouvy = cop.pop();

        for(int i=x; i<y; i++){
            cop.push(this->pop());
        }

        Constante* nouvx = cop.top();

        this->push(nouvy);

        for(int i=x; i<y; i++){
            push(cop.pop());
        }

        push(nouvx);

        for(int i=x; i<y; i++){
            push(cop.pop());
        }

    }

}

void Pile::sum(int x){

    Constante* somme = new CReel(0);
    for(int i =0; i<x; i++){
        somme = somme->operator +(*pop());
    }

    push(somme);

}

void Pile::mean(int x){

    this->sum(x);
    Constante* div = new CEntier(x);
    this->push(this->pop()->operator /(*div));
}

void Pile::clear(){
    while(!isEmpty()){
        pop();
    }
}

void Pile::dup(){
   if(typeid(top()) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) *top();
        Constante* nouv = new CEntier(c1.getValue());
        push(nouv);
    }
    else if(typeid(top()) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) *top();
        Constante* nouv = new CRationnel(c1.getNum(),c1.getDenom());
        push(nouv);
    }
    else if(typeid(top()) ==typeid(CReel)){
        CReel &c1 = (CReel&) *top();
        Constante* nouv = new CReel(c1.getValue());
        push(nouv);
    }
    /*else if(typeid(top()) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) *top();
        Constante* nouv = new CComplexe(c1.getRe(),c1.getIm());
        push(nouv);
    }*/
    else if(typeid(top()) ==typeid(CExpression)){
        CExpression &c1 = (CExpression&) *top();
        Constante* nouv = new CExpression(c1.getExp());
        push(nouv);
    }

}

void Pile::drop(){
    pop();
}

void Pile::fAddition(){
    Constante* inter = pop();
    Constante* inter2 = pop();
    Constante* resinter = inter->operator +(*inter2);

//    if(typeid(*resinter) ==typeid(CEntier) && !isEntier()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CRationnel) && !isRationnel()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CReel) && !isReel()){ /* Constante * res = CAST */ }

    push(resinter);

    }
void Pile::fSoustraction(){
    Constante* inter = pop();
    Constante* inter2 = pop();
    Constante* resinter = inter->operator -(*inter2);

//    if(typeid(*resinter) ==typeid(CEntier) && !isEntier()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CRationnel) && !isRationnel()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CReel) && !isReel()){ /* Constante * res = CAST */ }

    push(resinter);

    }
void Pile::fMultiplication(){
    Constante* inter = pop();
    Constante* inter2 = pop();
    Constante* resinter = inter->operator *(*inter2);

//    if(typeid(*resinter) ==typeid(CEntier) && !isEntier()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CRationnel) && !isRationnel()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CReel) && !isReel()){ /* Constante * res = CAST */ }

    push(resinter);

    }
void Pile::fDivision(){
    Constante* inter = pop();
    Constante* inter2 = pop();
    Constante* resinter = inter->operator /(*inter2);

//    if(typeid(*resinter) ==typeid(CEntier) && !isEntier()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CRationnel) && !isRationnel()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CReel) && !isReel()){ /* Constante * res = CAST */ }

    push(resinter);

    }

void Pile::fPOW(){
    if(typeid(top()) ==typeid(CEntier)){
    Constante* pow = pop();
    Constante* nbr = pop();
    CEntier *c1 = (CEntier*) pow;

    Constante* resinter = new CEntier(1);

    for(int i =1; i<c1->getValue() ; i++)
        resinter = resinter->operator *(*nbr);

//    if(typeid(*resinter) ==typeid(CEntier) && !isEntier()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CRationnel) && !isRationnel()){ /* Constante * res = CAST */ }
//    if(typeid(*resinter) ==typeid(CReel) && !isReel()){ /* Constante * res = CAST */ }

    push(resinter);}

    } // puissance (entier, rationnel, r�el)

void Pile::fMOD(){} // modulo (entier)
void Pile::fSIGN(){} // inversion du signe (entier, rationnel, r�el, complexe)


void Pile::fSIN(){} // sinus (entier, rationnel, r�el)
void Pile::fCOS(){} // cosinus (entier, rationnel, r�el)
void Pile::fTAN(){} // tangente (entier, rationnel, r�el)
void Pile::fSINH(){} // sinus hyperbolique (entier, rationnel, r�el)
void Pile::fCOSH(){} // cosinus hyperbolique (entier, rationnel, r�el)
void Pile::fTANH(){} // tangente hyperbolique (entier, rationnel, r�el)
void Pile::fLN(){} // logarithme n�p�rien (entier, rationnel, r�el)
void Pile::fLOG(){} // logarithme d�cimal (entier, rationnel, r�el)
void Pile::fINV(){} // inverse (entier, rationnel, r�el)
void Pile::fSQRT(){} // racine carr� (entier, rationnel, r�el)
void Pile::fSQR(){} // fonction carr� (entier, rationnel, r�el, complexe)
void Pile::fCUBE(){} // fonction cube (entier, rationnel, r�el, complexe)
void Pile::fact(){} // factorielle (entier)
void Pile::fEVAL(){} // �valuation d'une expression (Expression)
