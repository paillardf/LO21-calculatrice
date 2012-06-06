#include "pile.h"
#include "commande.h"


void CommandeEval::Do(){
    pile->pop();
    for (int i = 0; i < pCommande.size(); i++){
       Commande * c =  pCommande.at(i);
       c->Do();
    }
}
void CommandeEval::Undo(){
    for (int i =  pCommande.size()-1; i >=0 ; i--){
       Commande * c =  pCommande.at(i);
       c->Undo();
    }
    pile->push(expression);
}


    CommandeBasic::~CommandeBasic(){
        while(!newConst.isEmpty()){
            Constante * c = newConst.pop();
            delete c;
        }

    }

    void CommandeBasic::addOld(Constante * c){//ANCIENNE CONSTANTE SUR LA PILE
        oldConst.push(c);
    }
    void CommandeBasic::addNew(Constante * c){ //NOUVELLE CONSTANTE SUR LA PILE AJOUTE
        newConst.push(c);
    }

    void CommandeBasic::Do(){
        for (int i = 0; i < oldConst.size(); i ++){
            pile->pop();
        }

        for (int i = 0; i < newConst.size(); i ++){
            pile->push(newConst.at(i));
        }


    }

    void CommandeBasic::Undo(){
        for (int i = 0; i < newConst.size(); i ++){
            pile->pop();
        }

        for (int i = oldConst.size()-1; i >= 0; i --){
            pile->push(oldConst.at(i));
        }

    }





    CommandeSwap::~CommandeSwap(){

    }


    void CommandeSwap::addOld(Constante * c){ //NOUVELLE CONSTANTE SUR LA PILE AJOUTE
        oldConst.push(c);
    }

    void CommandeSwap::Do(){

           pile->swap();

    }

    void CommandeSwap::Undo(){
        for (int i = 0; i < oldConst.size(); i ++){
            pile->push(oldConst.at(i));
        }
        Do();
        for (int i = 0; i < oldConst.size(); i ++){
            pile->push(oldConst.at(i));
        }
    }

