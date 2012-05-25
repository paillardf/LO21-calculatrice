#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "stack"
#include <QLabel>

class Pile
{

private:

    std::stack<Constante*> tpile;



public:
    Pile(QLabel * aff);
    ~Pile();
    QLabel * affichage;

    void afficher(const std::stack<Constante *>& p);
    Constante * pop(){
        Constante * c = tpile.top();
        tpile.pop();
        return c;
    }

    void push(Constante * c){
        tpile.push(c);

    }

//    void swap(int x, int y);
//    void sum(int x);
//    void mean(int x);
//    void clear();
//    void dup();
//    void drop();
};

#endif // PILE_H
