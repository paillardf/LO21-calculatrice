
#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>
#include <strstream>
#include <typeinfo>

class Constante
{
public:
   // Constante();
    virtual QString getValuetoString() = 0;
    virtual Constante * operator+(Constante & c1) = 0;

};


class CEntier : public Constante
{
private:
    int value;
public:

    CEntier(int v):value(v){}
    int getValue(){
        return value;
    }
    QString getValuetoString(){
        QString str = "%1";
        return str.arg(value);
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
};

class CComplexe : public Constante
{
private:
    int re;
    int im;
public:

    CComplexe(int r, int i):re(r), im(i){}
    int getRe(){
        return re;
    }
    int getIm(){
        return im;
    }

    QString getValuetoString(){
        QString str = "%1 $ %2";
        return str.arg(re, im);
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
};

class CReel : public Constante
{
private:
    int ent;
    int dec;

public:

    CReel(int e, int d):ent(e),dec(d){}
    int getEnt(){
        return ent;
    }
    int getDec(){
        return dec;
    }

    QString getValuetoString(){
        QString str = "%1,%2";
        return str.arg(ent, dec);
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
};

class CRationnel : public Constante
{
private:
    int num;
    int denom;
public:

    CRationnel(int n, int d):num(n), denom(d){}

    int getNum(){
        return num;
    }
    int getDenom(){
        return denom;
    }

    QString getValuetoString(){
        QString str = "%1/%2";
        return str.arg(num, denom);
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
};


#endif // CONSTANTE_H
