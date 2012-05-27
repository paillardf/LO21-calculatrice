#ifndef PILE_H
#define PILE_H

#include <constante.h>
#include <QLabel>
#include <QStack>
#include <cmath>
class Pile : public QStack<Constante *>
{

private:




public:
    Pile(QLabel * aff, int max);
    ~Pile();
    Pile& clone();
    QLabel * affichage;
    void afficher(int tailleMax);


//    void swap(int x, int y);
//    void sum(int x);
//    void mean(int x);
//    void clear();
//    void dup();
//    void drop();
};

#endif // PILE_H
