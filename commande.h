#ifndef COMMANDE_H
#define COMMANDE_H
#include <constante.h>
#include <pile.h>


//http://www.csharpfr.com/tutoriaux/COMMAND-PATTERN_824.aspx
class Commande
{

public:
   // Commande();
   // ~Commande();
    virtual void Do() = 0;
    virtual void Undo() = 0;

};


class CommandeAdd : public Commande
{
private:
    Constante * cst1;
    Constante *  cst2;
    Pile & pile;

public:
    CommandeAdd(Pile &p):pile(p){}

    ~CommandeAdd(){
        delete(cst1);
        delete(cst2);
    }

    void Do(){

        Constante * res = *cst1+*cst2;
        pile.push(res);
    }

    void Undo(){
    }

};


#endif // COMMANDE_H
