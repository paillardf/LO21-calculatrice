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

    void addOld(Constante * c);
    void addNew(Constante * c);

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

    void addOld(Constante * c);
    void Do();
    void Undo();
};


#endif // COMMANDE_H
