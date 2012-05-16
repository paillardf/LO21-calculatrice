
#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <string>
#include <strstream>
#include <typeinfo>

class Constante
{
public:
    Constante();
    virtual std::string getValuetoString() = 0;
    virtual Constante * operator+(Constante & c1) = 0;
};


class CReel
{
private:
    float value;
public:

    CReel(float v):value(v){}
    float getValue(){
        return value;
    }
    std::string getValuetoString(){
        std::strstream str;
        str<<value;
        return str.str();
    }

    Constante * operator+(Constante & c1);
};

class CRationnel
{
private:
    int num;
    int denom;
public:

    CRationnel(int n, int d):num(n), denom(d){}
    std::string getValuetoString(){
        return num + "/"+denom;
    }
    int getNum(){
        return num;
    }
    int getDenom(){
        return denom;
    }

    Constante * operator+(Constante & c1);
};


#endif // CONSTANTE_H
