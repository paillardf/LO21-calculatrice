#include "constante.h"
#include "iostream"
#include "math.h"
#include <sstream>


int CRationnel::PGCD(int a, int b){
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

void CRationnel::toFraction(float f, int & n, int & d){
    QString s;
    QTextStream * tmp = new QTextStream(&s);
    tmp->operator <<(f);
    int cmpt= -1;
    int lenght = s.size();
    for (int i = 0; i < lenght; i++){
        if(s.at(i)=='.'){
            cmpt = 0;
        }else if(cmpt>=0){
            cmpt++;
        }

    }
    if(cmpt>=5){
        double nn;
        nn = f * powf(10, cmpt);
        d = 1* powf(10, cmpt);
        int r=PGCD(nn,d);
        while(r!=1){

             nn =nn/r;
             d=d/r;
             r=PGCD(n,d);
        }

        //pas de - au dénominateur
        if(d<0){
            n=-nn;
            d=-d;
            }
    }else if(cmpt>=0){
        n = f * powf(10, cmpt);
        d = 1* powf(10, cmpt);
        int r=PGCD(n,d);
        while(r!=1){

             n=n/r;
             d=d/r;
             r=PGCD(n,d);
        }

        //pas de - au dénominateur
        if(d<0){
            n=-n;
            d=-d;
            }
    }else{

        n = f;
        d = 1;
    }

}

Constante * CEntier::operator+(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier(c1.getValue()+this->getValue());
    }
    else {
        Constante* test = this;
        return c.operator+(*test);}
    }

Constante * CRationnel::operator+(Constante & c){
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom*c1.getDenom());
    }
    else if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CRationnel(getNum()+getDenom()*c1.getValue(), getDenom());
    }
    else{ Constante* test = this;
        return c.operator+(*test);}

 }

Constante * CReel::operator+(Constante & c){
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(c1.getValue()+getValue());
    }
    else if(typeid(c) == typeid(CEntier))
    {
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CReel(getValue()+(float)c1.getValue());
    }
    else if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        double test = (double)((float)c1.getNum())/(double)(c1.getDenom());
        return (Constante *)new CReel(test+getValue());
    }
    else{ Constante* test = this;
        return c.operator+(*test);}
 }

//Constante * CComplexe::operator+(Constante & c){
//    if(typeid(c) ==typeid(CEntier)){
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CComplexe(this->operator +(c1),getIm());

//    }
//  if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CComplexe(new CRationnel(c1.getNum()+getRe()*c1.getDenom(),c1.getDenom()),getIm());

//    }
//    if(typeid(c) ==typeid(CReel)){
//        CReel &c1 = (CReel&) c;
//        return (Constante *)new CComplexe(new CReel(c1.getEnt()+getRe(),c1.getDec()), getIm());

//    }
//    if(typeid(c) ==typeid(CComplexe)){
//        CComplexe &c1 = (CComplexe&) c;
//        return (Constante *)new CComplexe(c1.getRe()+getRe(), c1.getIm()+getIm());

//    }
//    else{ return c.operator +(this);}
// }

Constante * CExpression::operator+(Constante & c){
    return (Constante *)new CExpression('+'+' '+QString(getExp()+' '+c.getValuetoString()));
 }

//////////////////////////////////////////////////////////////////////////////////////////////

Constante * CEntier::operator-(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier(getValue()-c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            c1.setNum(-1*c1.getNum());
            return c1.operator +(*this);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            c1.setValue(-1*getValue());
            return c1.operator +(*this);
    }
   /* if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(getValue()-c1.getRe(),c1.getIm());
    }*/
   if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -((Constante & ) *this);
    }
}

Constante * CRationnel::operator-(Constante & c){

    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CRationnel(getNum()-c1.getValue()*getDenom(),getDenom());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            return (Constante *) new CRationnel(getNum()*c1.getDenom()-c1.getNum()*getDenom(),getDenom()*c1.getDenom());
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            c1.setValue(-1*c1.getValue());
            return c1.operator +(*this);
    }
   /* if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(c1.getValue()-this->getValue());
    }*/
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator-((Constante & ) *this);
    }

 }

Constante * CReel::operator-(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CReel(getValue()-(float)c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            float test = getValue() - (float)c1.getNum()/(float)c1.getDenom();
            return (Constante *) new CReel(test);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(getValue()-c1.getValue());
    }
    /*if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(c1.getValue()-this->getValue());
    }*/
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -((Constante & ) *this);
    }
 }

/*Constante * CComplexe::operator-(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier(c1.getValue()-this->getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            return (Constante *) new CRationnel(c1.getValue()-this->getValue());
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(c1.getValue()-this->getValue());
    }
    if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(c1.getValue()-this->getValue());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return (Constante *) new CExpression(c1.getValue()-this->getValue());
    }
    }
 }*/

Constante * CExpression::operator-(Constante & c){
    return (Constante *)new CExpression(QString('-'+' '+getExp()+' '+c.getValuetoString()));

 }

//////////////////////////////////////////////////////////////////////////////////////////////

Constante * CEntier::operator/(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier((int)(getValue()/c1.getValue()));
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            int inter = c1.getNum();
            c1.setNum(c1.getDenom());
            c1.setDenom(inter);
            return c1.operator *(*this);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            c1.setValue(1/c1.getValue());
            return c1.operator *(*this);
    }
   /* if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(getValue()-c1.getRe(),c1.getIm());
    }*/
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -((Constante & ) *this);
    }
    }

Constante * CRationnel::operator/(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CRationnel(getNum(),getDenom()*c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            return (Constante *) new CRationnel(getNum()*c1.getDenom(),getDenom()*c1.getNum());
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            c1.setValue(1/c1.getValue());
            return c1.operator *(*this);
    }
   /* if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(c1.getValue()-this->getValue());
    }*/
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -((Constante & ) *this);
    }

 }

Constante * CReel::operator/(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CReel(getValue()/(float)c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            float test = (getValue() * (float)c1.getDenom())/(float)c1.getNum();
            return (Constante *) new CReel(test);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(getValue()/c1.getValue());
    }
    /*if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(c1.getValue()-this->getValue());
    }*/
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator /((Constante & ) *this);
    }
 }

/*Constante * CComplexe::operator/(Constante & c){
    if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CComplexe((Constante *) new CEntier(c1.getValue()+getRe()),(Constante *) new CEntier(getIm()));

    }
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CComplexe(new CRationnel(c1.getNum()+getRe()*c1.getDenom(),c1.getDenom()),getIm());

    }
    if(typeid(c) ==typeid(CReel)){
        CReel &c1 = (CReel&) c;
        return (Constante *)new CComplexe(new CReel(c1.getEnt()+getRe(),c1.getDec()), getIm());

    }
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CComplexe(c1.getRe()+getRe(), c1.getIm()+getIm());

    }
    else{ return c.operator +(this);}
 }*/


Constante * CExpression::operator/(Constante & c){
    return (Constante *)new CExpression('/' +' '+ QString(getExp()+' '+c.getValuetoString()));
}

//////////////////////////////////////////////////////////////////////////////////////////////

Constante * CEntier::operator*(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier(c1.getValue()*this->getValue());
    }
    else {
        Constante* test = this;
        return c.operator*(*test);}
    }

Constante * CRationnel::operator*(Constante & c){
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CRationnel(c1.getNum()*num, denom*c1.getDenom());
    }
    else if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CRationnel(getNum()*c1.getValue(), getDenom());
    }
    else{ Constante* test = this;
        return c.operator*(*test);}

 }

Constante * CReel::operator*(Constante & c){
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;

            return (Constante *) new CReel(c1.getValue()*getValue());

    }
    else if(typeid(c) == typeid(CEntier))
    {
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CReel(getValue()*c1.getValue());
    }
    else if(typeid(c) ==typeid(CRationnel)){

        CRationnel &c1 = (CRationnel&) c;

        double test = (getValue()*c1.getNum())/c1.getDenom();

        return (Constante *)new CReel(test);
    }
    else{ Constante* test = this;
        return c.operator*(*test);}
 }

/*Constante * CComplexe::operator*(Constante & c){
    if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CComplexe((Constante *) new CEntier(c1.getValue()+getRe()),(Constante *) new CEntier(getIm()));

    }
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CComplexe(new CRationnel(c1.getNum()+getRe()*c1.getDenom(),c1.getDenom()),getIm());

    }
    if(typeid(c) ==typeid(CReel)){
        CReel &c1 = (CReel&) c;
        return (Constante *)new CComplexe(new CReel(c1.getEnt()+getRe(),c1.getDec()), getIm());

    }
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CComplexe(c1.getRe()+getRe(), c1.getIm()+getIm());

    }
    else{ return c.operator +(this);}
 }*/

Constante * CExpression::operator*(Constante & c){
    return (Constante *)new CExpression('* '+QString(getExp()+' '+c.getValuetoString()));

 }
//////////////////////////////////////////////////////////////////////////////////////////////
