
#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>
#include <QTextStream>
#include <typeinfo>

class Constante
{
public:
    //Constante();
    virtual QString getValuetoString() const = 0;
    virtual Constante * operator+(Constante & c1) = 0;
    virtual Constante * operator-(Constante & c1) = 0;
    virtual Constante * operator*(Constante & c1) = 0;
    virtual Constante * operator/(Constante & c1) = 0;
    //~Constante(){}

};


class CEntier : public Constante
{
private:
    int value;
public:

    CEntier(int v):value(v){}

    CEntier(const CEntier & c):value(c.getValue()){}
    int getValue() const{
        return value;
    }

    QString getValuetoString() const{
        QString test = QString::number(value);
        return test;
    }

    Constante * operator+(Constante & c1){};
    Constante * operator-(Constante & c1){};
    Constante * operator*(Constante & c1){};
    Constante * operator/(Constante & c1){};
    ~CEntier(){}
};

class CReel : public Constante
{
private:
    float value;

public:

    CReel(float v):value(v){}
    CReel(const CReel & c):value(c.getValue()){}

     float getValue() const{
        return value;
    }


    QString getValuetoString()const{
       return QString::number(value);
    }

    Constante * operator+(Constante & c1){};
    Constante * operator-(Constante & c1){};
    Constante * operator*(Constante & c1){};
    Constante * operator/(Constante & c1){};
    ~CReel(){}
};

class CRationnel : public Constante
{
private:
    int num;
    int denom;


    void toFraction(float f, int & n, int & d);
    int PGCD(int a, int b);

public:

    CRationnel(int n, int d):num(n), denom(d){}
    CRationnel(const CRationnel & c):num(c.getNum()), denom(c.getDenom()){}
    CRationnel(float f){

    }

    int getNum() const{
        return num;
    }
    int getDenom() const{
        return denom;
    }


    QString getValuetoString()const{
        QString test = QString::number(num)+'/'+QString::number(denom);
        return test;
    }

    Constante * operator+(Constante & c1){};
    Constante * operator-(Constante & c1){};
    Constante * operator*(Constante & c1){};
    Constante * operator/(Constante & c1){};
    ~CRationnel(){}
};


class CExpression : public Constante
{
private:
    QString exp;

public:

    CExpression(QString ex):exp(ex){}
    CExpression(const CExpression & c ):exp(c.getExp()){}

    QString getExp() const{
        return exp;
    }

    QString getValuetoString() const{
        return exp;
    }

    Constante * operator+(Constante & c1){};
    Constante * operator-(Constante & c1){};
    Constante * operator*(Constante & c1){};
    Constante * operator/(Constante & c1){};
    ~CExpression(){}
};



class CComplexe : public Constante
{
private:
    Constante* re;
    Constante* im;
public:

    CComplexe(Constante* r, Constante* i){re=r; im=i;}
    CComplexe(const CComplexe & c){
        if(typeid(*c.getIm()) ==typeid(CEntier)){
            im = (Constante *) new CEntier(*((CEntier*) c.getIm()));
        }else if(typeid(*c.getIm()) ==typeid(CReel)){
            im = (Constante *) new CReel(*((CReel*) c.getIm()));
        }else if(typeid(*c.getIm()) ==typeid(CRationnel)){
            im = (Constante *) new CRationnel(*((CRationnel*) c.getIm()));
        }else if(typeid(*c.getIm()) ==typeid(CComplexe)){
           im = (Constante *) new CComplexe(*((CComplexe*) c.getIm()));
        }else if(typeid(*c.getIm()) ==typeid(CExpression)){
           im = (Constante *) new CExpression(*((CExpression*) c.getIm()));
        }

        if(typeid(*c.getRe()) ==typeid(CEntier)){
            re = (Constante *) new CEntier(*((CEntier*) c.getRe()));
        }else if(typeid(*c.getRe()) ==typeid(CReel)){
            re = (Constante *) new CReel(*((CReel*) c.getRe()));
        }else if(typeid(*c.getRe()) ==typeid(CRationnel)){
            re = (Constante *) new CRationnel(*((CRationnel*) c.getRe()));
        }else if(typeid(*c.getRe()) ==typeid(CComplexe)){
           re = (Constante *) new CComplexe(*((CComplexe*) c.getRe()));
        }else if(typeid(*c.getRe()) ==typeid(CExpression)){
           re = (Constante *) new CExpression(*((CExpression*) c.getRe()));
        }

    }

    ~CComplexe(){delete re; delete im;}

    Constante* getRe() const {
        return re;
    }
    Constante* getIm() const{
        return im;
    }

    QString getValuetoString()const{
        QString test = re->getValuetoString()+'$'+im->getValuetoString();
        return test;
    }

    Constante * operator+(Constante & c1){};
    Constante * operator-(Constante & c1){};
    Constante * operator*(Constante & c1){};
    Constante * operator/(Constante & c1){};
};



#endif // CONSTANTE_H
