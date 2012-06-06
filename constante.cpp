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

Constante * CComplexe::operator+(Constante & c){
    if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CComplexe(c1+(*getRe()) ,getIm());

    }
  if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;

        return (Constante *)new CComplexe(c1+*getRe(), getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CReel)){
        CReel &c1 = (CReel&) c;
        return (Constante *)new CComplexe(c1+*getRe(), getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CComplexe(c1.getRe()->operator +(*getRe()), c1.getIm()->operator +(*getIm()));

    }
    else{ return c.operator +(*this);}
 }

Constante * CExpression::operator+(Constante & c){
    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString())+' '+'+');
 }

/////////////////////////////////////////  OPERATOR - /////////////////////////////////////////////////////

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
            float res = this->getValue()-c1.getValue();
            return new CReel(res);
    }
    if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this-*c1.getRe(),c1.getIm()->getCopy());
    }
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
            float res = (float)this->getNum()/(float)this->getDenom() - c1.getValue();
            return new CReel(res);
    }
   if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this-*c1.getRe(), c1.getIm()->getCopy());
    }
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
    if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this-*c1.getRe(), c1.getIm()->getCopy());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -((Constante & ) *this);
    }
 }

Constante * CComplexe::operator-(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CComplexe(*this->getRe()-c1, this->getIm()->getCopy());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            return (Constante *) new CComplexe(*this->getRe()-c1, this->getIm()->getCopy());
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CComplexe(*this->getRe()-c1, this->getIm()->getCopy());
    }
    if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this->getRe()-*c1.getRe(), *this->getIm()-*c1.getIm());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator -(QString(getValuetoString()+' '+c1.getExp()+' '+'-'));
    }

 }

Constante * CExpression::operator-(Constante & c){
    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString())+ ' '+'-');

 }

//////////////////////////////////////// OPERATOR  /   //////////////////////////////////////////////////////

Constante * CEntier::operator/(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CRationnel(getValue() , c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            int num = c1.getDenom()*this->getValue();
            int denom = c1.getNum();
            return (Constante *) new CRationnel(num, denom);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            float res = ((float) this->getValue())/c1.getValue();
            return (Constante *) new CReel(res);
    }
   if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this/ *c1.getRe(),c1.getIm()->getCopy());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator /((Constante & ) *this);
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
            float den = ((float) this->getDenom())*c1.getValue();
            float res = ((float) this->getNum())/den;
            return (Constante *) new CReel(res);
    }
   if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this/ *c1.getRe(), c1.getIm()->getCopy());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator /((Constante & ) *this);
    }

 }

Constante * CReel::operator/(Constante & c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CReel(getValue()/(float)c1.getValue());
    }
    if(typeid(c) == typeid(CRationnel)){
            CRationnel &c1 = (CRationnel&) c;
            float res = (getValue() * (float)c1.getDenom())/(float)c1.getNum();
            return (Constante *) new CReel(res);
    }
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(getValue()/c1.getValue());
    }
    if(typeid(c) == typeid(CComplexe)){
            CComplexe &c1 = (CComplexe&) c;
            return (Constante *) new CComplexe(*this/ *c1.getRe(), c1.getIm()->getCopy());
    }
    if(typeid(c) == typeid(CExpression)){
            CExpression &c1 = (CExpression&) c;
            return c1.operator /((Constante & ) *this);
    }
 }

Constante * CComplexe::operator/(Constante & c){
    if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CComplexe(*this->getRe()/c1, this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CComplexe(*this->getRe()/c1, this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CReel)){
        CReel &c1 = (CReel&) c;
        return (Constante *)new CComplexe(*this->getRe()/c1, this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CComplexe(*this->getRe()/ *c1.getRe(), *this->getIm()/ * c1.getIm());

    }
    else{ return c.operator /(*this);}
 }


Constante * CExpression::operator/(Constante & c){
    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString()+' '+'/'));

 }

Constante * CExpression::operator-(QString e){return (Constante *) new CExpression(e);}
Constante * CExpression::operator/(QString e){return (Constante *) new CExpression(e);}

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

Constante * CComplexe::operator*(Constante & c){
    if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CComplexe(this->getRe()->operator *(c1), this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CComplexe(this->getRe()->operator *(c1), this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CReel)){
        CReel &c1 = (CReel&) c;
        return (Constante *)new CComplexe(this->getRe()->operator *(c1), this->getIm()->getCopy());

    }
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CComplexe(this->getRe()->operator *(*c1.getRe()), this->getIm()->operator *(*c1.getIm()));

    }
    else{ return c.operator *(*this);}
 }

Constante * CExpression::operator*(Constante & c){
    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString())+' ' +'*');

 }
//////////////////////////////////////////////////////////////////////////////////////////////
