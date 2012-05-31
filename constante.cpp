#include "constante.h"
#include "iostream"
#include "math.h"
#include <sstream>

//Constante * CEntier::operator+(Constante& c){
//    if(typeid(c) == typeid(CEntier)){
//            CEntier &c1 = (CEntier&) c;
//            return (Constante *) new CEntier(c1.getValue()+this->getValue());
//    }
//    else {
//        Constante* test = this;
//        return c.operator+(*test);}
//    }

//Constante * CRationnel::operator+(Constante & c){
//    if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom*c1.getDenom());
//    }
//    else if(typeid(c) ==typeid(CEntier)){
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CRationnel(getNum()+getDenom()*c1.getValue(), getDenom());
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}

// }

//Constante * CReel::operator+(Constante & c){
//    if(typeid(c) == typeid(CReel)){
//            CReel &c1 = (CReel&) c;
//            int test = std::max((int)(1 + log10(c1.getDec())),(int)(1 + log10(getDec())));
//            int nouv = (int)(1+log10(c1.getDec()+this->getDec()));
//            if(nouv>test){
//                return (Constante *) new CReel(c1.getEnt()+this->getEnt()+1,c1.getDec()+this->getDec()-100);
//            }
//            else{
//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec());

//            }
//    }
//    else if(typeid(c) == typeid(CEntier))
//    {
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CReel(getEnt()+c1.getValue(), getDec());
//    }
//    else if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        double test = (double)(c1.getNum())/(double)(c1.getDenom());
//        int partieEntiere = (int) test;
//        double partieDecimal = test;
//        partieDecimal *= 100;
//        partieDecimal = partieDecimal - (partieEntiere * 100);
//        return (Constante *)new CReel(partieEntiere+getEnt(), getDec()+(int)partieDecimal);
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}
// }

/*Constante * CComplexe::operator+(Constante & c){
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

//Constante * CExpression::operator+(Constante & c){
//    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString()+' '+'+'));
// }

////////////////////////////////////////////////////////////////////////////////////////////////

//Constante * CEntier::operator-(Constante& c){
//    if(typeid(c) == typeid(CEntier)){
//            CEntier &c1 = (CEntier&) c;
//            return (Constante *) new CEntier(c1.getValue()-this->getValue());
//    }
//    else {
//        Constante* test = this;
//        return c.operator-(*test);}
//    }

//Constante * CRationnel::operator-(Constante & c){
//    if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom+c1.getDenom());
//    }
//    else if(typeid(c) ==typeid(CEntier)){
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CRationnel(getNum()+getDenom()*c1.getValue(), getDenom());
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}

// }

//Constante * CReel::operator-(Constante & c){
//    if(typeid(c) == typeid(CReel)){
//            CReel &c1 = (CReel&) c;
//            int test = std::max(1 + log10(c1.getDec()),1 + log10(getDec()));
//            if(1+log10(c1.getDec()+this->getDec())>test){

//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec()); //problème
//            }
//            else{
//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec());
//            }
//    }
//    else if(typeid(c) == typeid(CEntier))
//    {
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CReel(getEnt()+c1.getValue(), getDec());
//    }
//    else if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CReel(getEnt()+c1.getNum(), getDec()); //problème
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}
// }

/*Constante * CComplexe::operator-(Constante & c){
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

//Constante * CExpression::operator-(Constante & c){
//    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString()+' '+'-'));

// }

//////////////////////////////////////////////////////////////////////////////////////////////

//Constante * CEntier::operator/(Constante& c){
//    if(typeid(c) == typeid(CEntier)){
//            CEntier &c1 = (CEntier&) c;
//            return (Constante *) new CEntier(c1.getValue()/this->getValue());
//    }
//    else {
//        Constante* test = this;
//        return c.operator+(*test);}
//    }

//Constante * CRationnel::operator/(Constante & c){
//    if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CRationnel(c1.getNum()*denom+c1.getDenom()*num, denom+c1.getDenom());
//    }
//    else if(typeid(c) ==typeid(CEntier)){
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CRationnel(getNum()+getDenom()*c1.getValue(), getDenom());
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}

// }

//Constante * CReel::operator/(Constante & c){
//    if(typeid(c) == typeid(CReel)){
//            CReel &c1 = (CReel&) c;
//            int test = std::max(1 + log10(c1.getDec()),1 + log10(getDec()));
//            if(1+log10(c1.getDec()+this->getDec())>test){

//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec()); //problème
//            }
//            else{
//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec());
//            }
//    }
//    else if(typeid(c) == typeid(CEntier))
//    {
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CReel(getEnt()+c1.getValue(), getDec());
//    }
//    else if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CReel(getEnt()+c1.getNum(), getDec()); //problème
//    }
//    else{ Constante* test = this;
//        return c.operator+(*test);}
// }

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

//Constante * CExpression::operator/(Constante & c){
//    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString()+' '+'/'));

// }

////////////////////////////////////////////////////////////////////////////////////////////////

//Constante * CEntier::operator*(Constante& c){
//    if(typeid(c) == typeid(CEntier)){
//            CEntier &c1 = (CEntier&) c;
//            return (Constante *) new CEntier(c1.getValue()*this->getValue());
//    }
//    else {
//        Constante* test = this;
//        return c.operator*(*test);}
//    }

//Constante * CRationnel::operator*(Constante & c){
//    if(typeid(c) ==typeid(CRationnel)){
//        CRationnel &c1 = (CRationnel&) c;
//        return (Constante *)new CRationnel(c1.getNum()*num, denom*c1.getDenom());
//    }
//    else if(typeid(c) ==typeid(CEntier)){
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CRationnel(getNum()*c1.getValue(), getDenom());
//    }
//    else{ Constante* test = this;
//        return c.operator*(*test);}

// }

//Constante * CReel::operator*(Constante & c){
//    if(typeid(c) == typeid(CReel)){
//            CReel &c1 = (CReel&) c;
//            int test = std::max(1 + log10(c1.getDec()),1 + log10(getDec()));
//            if(1+log10(c1.getDec()+this->getDec())>test){

//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec()); //problème
//            }
//            else{
//                return (Constante *) new CReel(c1.getEnt()+this->getEnt(),c1.getDec()+this->getDec());
//            }
//    }
//    else if(typeid(c) == typeid(CEntier))
//    {
//        CEntier &c1 = (CEntier&) c;
//        return (Constante *)new CReel(getEnt()+c1.getValue(), getDec());
//    }
//    else if(typeid(c) ==typeid(CRationnel)){

//        CRationnel &c1 = (CRationnel&) c;


//        std::ostringstream oss;
//        oss << getEnt()+'.'+getDec();
//        std::string result = oss.str();

//        std::istringstream iss( result );
//        double nombre;
//        iss >> nombre;

//        double test = (double)(c1.getNum())/(double)(c1.getDenom());
//        int partieEntiere = (int) test;
//        double partieDecimal = test;
//        partieDecimal *= 100;
//        partieDecimal = partieDecimal - (partieEntiere * 100);


//        return (Constante *)new CReel(getEnt()+c1.getNum(), getDec()); //problème
//    }
//    else{ Constante* test = this;
//        return c.operator*(*test);} //problème
// }

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

//Constante * CExpression::operator*(Constante & c){
//    return (Constante *)new CExpression(QString(getExp()+' '+c.getValuetoString()+' '+'*'));

// }

//////////////////////////////////////////////////////////////////////////////////////////////
