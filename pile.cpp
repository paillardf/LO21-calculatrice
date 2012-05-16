#include "pile.h"

Pile::Pile()
{
    tpile = std::stack<Constante*>();
}

Pile::~Pile()
{
}

//void Pile::swap(int x, int y){

//    if(x!=y){
//        if(x>y){
//            int a = x;
//            x = y;
//            y = a;
//        }

//        std::stack<Constante*> cop;

//        for(int i=0; i<x; i++){
//            cop.push(tpile.top());
//            tpile.pop();
//        }
//        Constante* nouvy = cop.top();

//        for(int i=x; i<y; i++){
//            cop.push(tpile.top());
//            tpile.pop();
//        }

//        Constante* nouvx = cop.top();

//        tpile.push(nouvy);

//        for(int i=x; i<y; i++){
//            tpile.push(cop.top());
//            cop.pop();
//        }

//        tpile.push(nouvx);

//        for(int i=x; i<y; i++){
//            tpile.push(cop.top());
//            cop.pop();
//        }

//    }

//}

//void Pile::sum(int x){

//    Constante* somme = new Constante();
//    for(int i =0; i<x; i++){
//        somme+=tpile.pop();
//    }

//    tpile.push(somme);

//}

//void Pile::mean(int x){

//    this.sum(x);
//    this.tpile.push(this.tpile.top()/x);
//}

//void Pile::clear(){
//    while(!tpile.Empty()){
//        tpile.pop();
//    }
//}

//void Pile::dup(){
//    tpile.push(tpile.top());
//}

//void Pile::drop(){
//    tpile.pop();
//}

