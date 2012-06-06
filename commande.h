#ifndef COMMANDE_H
#define COMMANDE_H
#include <constante.h>
#include <QStack>

class Pile;


//http://www.csharpfr.com/tutoriaux/COMMAND-PATTERN_824.aspx
class Commande
{

public:
   // Commande();
   // ~Commande();
    virtual void Do() = 0;
    virtual void Undo() = 0;
    virtual void Vider() = 0;

};

class CommandeBasic : public Commande
{
private:
    QStack<Constante *> newConst;
    QStack<Constante *>  oldConst;
    Pile * pile;

public:
    CommandeBasic(Pile * p):pile(p){}

    ~CommandeBasic();

    void Vider()
    {

        newConst.clear();
        oldConst.clear();
    }


    void addOld(Constante * c);
    void addNew(Constante * c);

    void Do();


    void Undo();

};

class CommandeEval : public Commande
{
private:
    QStack<Commande *> pCommande;
    Pile * pile;
    Constante * expression;

public:
    CommandeEval(Pile * p, Constante * c):pile(p), expression(c){}

    ~CommandeEval(){

        while(!pCommande.isEmpty()){
            Commande * c = pCommande.pop();
            delete c;
        }
    }


    void Vider()
    {
        pCommande.clear();
    }

    void addCommande(Commande * c){
        pCommande.push(c);
    }

    void Do();
    void Undo();
};

class CommandeSwap : public Commande
{
private:
    QStack<Constante *> oldConst;
    Pile * pile;

public:
    CommandeSwap(Pile * p):pile(p){}

    ~CommandeSwap();

    void Vider()
    {
        oldConst.clear();
    }

    void addOld(Constante * c);
    void Do();
    void Undo();
};


#endif // COMMANDE_H
