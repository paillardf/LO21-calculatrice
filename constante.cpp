#include "constante.h"


Constante * CReel::operator+(Constante & c){
    if(typeid(c) == typeid(CReel)){
            CReel &c1 = (CReel&) c;
            return (Constante *) new CReel(c1.getValue()+this->getValue());
    }
 }


Constante * CRationnel::operator+(Constante & c){
    if(typeid(c) ==typeid(CRationnel)){
        CRationnel &c1 = (CRationnel&) c;
        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom+c1.getDenom());

    }
 }
