#ifndef COMMANDE_H
#define COMMANDE_H
#include <constante.h>
#include <QStack>


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
    QStack<Constante *> * pile;

public:
    CommandeBasic(QStack<Constante *> * p):pile(p){}

    ~CommandeBasic(){
        while(!newConst.isEmpty()){
            Constante * c = newConst.pop();
            delete c;
        }

        while(!oldConst.isEmpty()){
            Constante * c = oldConst.pop();
            delete c;
        }
    }

    void addOld(Constante * c){//ANCIENNE CONSTANTE SUR LA PILE
        oldConst.push(c);
    }
    void addNew(Constante * c){ //NOUVELLE CONSTANTE SUR LA PILE AJOUTE
        newConst.push(c);
    }

    void Do(){
        for (int i = 0; i < oldConst.size(); i ++){
            pile->pop();
        }

        for (int i = 0; i < newConst.size(); i ++){
            pile->push(newConst.at(i));
        }


    }

    void Undo(){
        for (int i = 0; i < newConst.size(); i ++){
            pile->pop();
        }

        for (int i = oldConst.size()-1; i >= 0; i --){
            pile->push(oldConst.at(i));
        }

    }

};


#endif // COMMANDE_H
