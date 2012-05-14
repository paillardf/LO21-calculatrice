#ifndef COMMANDE_H
#define COMMANDE_H
#include <constante.h>
#include <pile.h>

//http://www.csharpfr.com/tutoriaux/COMMAND-PATTERN_824.aspx
class Commande
{

public:
    void Commande();
    void ~Commande();
    void Do() = 0;
    void Undo() = 0;

};


class CommandeAdd : Commande
{
private:
    Constante cst1;
    Constante cst2;
    Pile pile;

public:
    CommandeAdd(Pile &p):pile(p){}
    void ~Commande(){
        delete(cst1);
        delete(cst2);
    }

    void Do(){

        Type res = cst1+cst2;
        pile
    }

    void Undo() = 0;

};


#endif // COMMANDE_H
