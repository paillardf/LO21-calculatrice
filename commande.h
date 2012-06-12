#ifndef COMMANDE_H
#define COMMANDE_H
#include <constante.h>
#include <QStack>

class Pile;

//! Commande class.
/*!
  classe virtuelle des commandes
*/
class Commande
{

public:

    //! executer l'operation
    virtual void Do() = 0;

    //! executer l'operation inverse
    virtual void Undo() = 0;

//! vide les piles de la commande.
    virtual void Vider() = 0;

};

//! CommandeBasic class.
/*!
  traite la majorite des commandes de la calculatrice.
*/
class CommandeBasic : public Commande
{
private:
    //! Pile de pointeur de constante.
             /*! stock l'ensemble des constantes ajoutees sur la pile. */
    QStack<Constante *> newConst;
    //! Pile de pointeur de constante.
             /*! stock l'ensemble des constantes enlevees de la pile. */
    QStack<Constante *>  oldConst;
    //! pointeur sur la pile
    Pile * pile;

public:
    //! constructeur.
        /*!
          \param Pointeur vers la pile stockant la commande
        */
    CommandeBasic(Pile * p):pile(p){}
    //! destructeur.
        /*!
          detruit la commande et les constantes de la pile newConst
        */
    ~CommandeBasic();

    //! vide les piles de la commande.
    void Vider()
    {
        newConst.clear();
        oldConst.clear();
    }

    //! ajoute une constante a la pile oldConst.
        /*!
          \param Pointeur vers la constante a stocker
        */
    void addOld(Constante * c);

    //! ajoute une constante a la pile newConst.
        /*!
          \param Pointeur vers la constante a stocker
        */
    void addNew(Constante * c);

        //! executer l'operation
    /*!
      depile les constantes stocker dans oldConst
      empile les constantes nouvelles de pile
    */
    void Do();

    //! executer l'operation inverse
        /*!
          depile les constantes nouvelles de pile
          empile les constantes stocker dans oldConst
        */
    void Undo();

};
//! CommandeEval class.
/*!
  commande de la fonction eval.
*/
class CommandeEval : public Commande
{
private:   
    //! Pile de pointeur commande.
             /*! stock l'ensemble des commandes executees pendant l evaluation de l expression. */
    QStack<Commande *> pCommande;
        //! pointeur sur la pile
    Pile * pile;
        //! pointeur sur l'expression evaluee
    Constante * expression;

public:

    //! constructeur.
        /*!
          \param c pointeur la constante expression evaluee
          \param p pointeur vers la pile stockant la commande
        */

    CommandeEval(Pile * p, Constante * c):pile(p), expression(c){}
    //! destructeur.
        /*!
          detruit la commande et les commandes de la pile pCommande
        */
    ~CommandeEval(){

        while(!pCommande.isEmpty()){
            Commande * c = pCommande.pop();
            delete c;
        }
    }

    //! vide les piles de la commande.
    void Vider()
    {
        pCommande.clear();
    }

        //! empile les pointeurs de commande dans pCommande
    /*!
      \param pointeur vers la commande a stocker
    */
    void addCommande(Commande * c){
        pCommande.push(c);
    }
        //! executer l'operation
    /*!
     execute l'ensemble des Do() des commandes de la pile
    */
    void Do();

    //! executer l'operation inverse
        /*!
execute l'ensemble des Undo() des commandes de la pile
        */
    void Undo();

};
//! CommandeSwap class.
/*!
  commande de la fonction swap.
*/
class CommandeSwap : public Commande
{
private:
    //! Pile des pointeurs de constantes parametres de la fonction swap
    QStack<Constante *> oldConst;
    //! Pointeur vers la pile
    Pile * pile;

public:
    //! constructeur.
        /*!
          \param p Pointeur vers la pile stockant la commande
        */
    CommandeSwap(Pile * p):pile(p){}

    //! destructeur.
    ~CommandeSwap();

    //! vide le contenu de la pile oldConst
    void Vider()
    {
        oldConst.clear();
    }
    //! ajoute la constante sur la pile oldConst
        /*!
          \param Pointeur vers la Constante a stocker
        */
    void addOld(Constante * c);
    //! effectue un swap sur la pile
    void Do();
    //! ajoute les parametres de la pile oldConst puis effectue un swap sur la pile puis ajoute de nouveau les parametres de oldConst
    void Undo();
};


#endif // COMMANDE_H
