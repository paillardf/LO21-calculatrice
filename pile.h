#ifndef PILE_H
#define PILE_H

#include "constante.h"
#include "stack"

class Pile
{
    std::stack<Constante*> tpile;

public:
    Pile();
    ~Pile();

    void swap(int x, int y);
    void sum(int x);
    void mean(int x);
    void clear();
    void dup();
    void drop();
};

#endif // PILE_H
