#include "constante.h"

Constante * CEntier::operator+(Constante& c){
    if(typeid(c) == typeid(CEntier)){
            CEntier &c1 = (CEntier&) c;
            return (Constante *) new CEntier(c1.getValue()+this->getValue());
    }
 }

Constante * CReel::operator+(Constante & c){
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec());
    }
    else if(typeid(c) == typeid(CEntier))
    {}
 }


Constante * CRationnel::operator+(Constante & c){
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom+c1.getDenom());
    }
    else if(typeid(c) ==typeid(CEntier)){
        CEntier &c1 = (CEntier&) c;
        return (Constante *)new CRationnel(getNum()+getDenom()*c1.getValue(), getDenom());
    }

 }

Constante * CComplexe::operator+(Constante & c){
    if(typeid(c) ==typeid(CComplexe)){
        CComplexe &c1 = (CComplexe&) c;
        return (Constante *)new CRationnel(c1.getRe()+getRe(), c1.getRe()+getIm());

    }
 }
