#ifndef PILE_H
#define PILE_H

#include <commande.h>
#include <constante.h>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QStack>
#include <cmath>
#include <stdexcept>
#include <iostream>


//! Pile class.
/*!
  pile contenant les Constantes
*/
class Pile : public QStack<Constante *>
{

private:
//! Pointeur vers radioButton Entier
    QRadioButton * btEntier;
//! Pointeur vers radioButton Rationnel
    QRadioButton * btRationnel;
//! Pointeur vers radioButton Degre
    QRadioButton * btDegre;
//! Pointeur vers radioButton Complexe
    QCheckBox * btComplexe;

    //! Pile de pointeurs des commandes effectuees
    QStack<Commande *> listeCommande;
    //! etat d'enregistrement des commandes
    /*!
      0 = enregistrement normal
      1 = commande en cours d'utilisation, pas d'enregistrement
      2 = enregistrement des commandes dans une commande CommandeEval
    */
    int executionCommande;
    //! position dans la pile des commandes
    int posCommande;

    //! retour vrai si mode radian active
    /*!
     \return boolean valeur du bouton
    */
    bool isRadian(){ return !btDegre->isChecked();}
    //! retour vrai si mode btDegre active
    /*!
     \return boolean valeur du bouton
    */
    bool isDegre(){ return btDegre->isChecked();}
    //! retour vrai si mode btEntier active
    /*!
     \return boolean valeur du bouton
    */
    bool isEntier(){ return btEntier->isChecked();}
    //! retour vrai si mode btRationnel active
    /*!
     \return boolean valeur du bouton
    */
    bool isRationnel(){ return btRationnel->isChecked();}
    //! retour vrai si mode btReel active
    /*!
     \return boolean valeur du bouton
    */
    bool isReel(){ return !btRationnel->isChecked()&&!btEntier->isChecked();}
    //! retour vrai si mode btComplexe active
    /*!
     \return boolean valeur du bouton
    */
    bool isComplexe(){ return btComplexe->isChecked();}

public:
    //! constructeur.
    /*!
     \param aff pointeur sur l'afficheur de la pile
     \param _btEntier pointeur vers radioButton Entier
     \param _btRationnel pointeur vers radioButton Rationnel
     \param _btDegre pointeur vers radioButton Degre
     \param _btComplexe pointeur vers radioButton Complexe
     \param max nombre d'elements a afficher
    */
    Pile(QLabel * aff, QRadioButton * _btEntier,QRadioButton * _btRationnel,QRadioButton * _btDegre,QCheckBox * _btComplexe, int max);
    //! destructeur.
    /*!
    destruction de l'ensemble des commandes et des constantes
    */
    ~Pile();
    //! clone la pile dans p.
    /*!
        \param p pile copie
    */
    void clone(Pile &p) const;

    //! Pointeur vers l'affichage du texte
    QLabel * affichage;

    //! affect l'etat d execution des commandes.
    /*!
        \param i integer etat
        \sa executionCommande
    */
    void setExecutionCommande(int i){
        executionCommande = i;
    }


    //! cast la constante passe en argument en fonction des types actifs
    /*!
        \param cst constante a caster
    */
    void cast(Constante* & cst);
    //! affiche les tailleMax premiers elements de la pile
    /*!
        \param tailleMax integer nombre d element a afficher
    */
    void afficher(int tailleMax);

    //! annule la derniere commande
    void annuler();
    //! retabli la derniere commande
    void retablir();
    //! enregistre une commande
    /*!
        \param c Pointeur de commande a enregistrer
    */
    void saveCommande(Commande *c);

    //! effectue operation swap sur la pile
        void swap();
        //! effectue operation sum sur la pile
        void sum();
        //! effectue operation mean sur la pile
        void mean();
        //! effectue operation clear sur la pile
        void clear();
        //! effectue operation dup sur la pile
        void dup();
        //! effectue operation drop sur la pile
        void drop();


        //! effectue operation Addition sur la pile
        void fAddition();
        //! effectue operation Soustraction sur la pile
        void fSoustraction();
        //! effectue operation Multiplication sur la pile
        void fMultiplication();
        //! effectue operation Division sur la pile
        void fDivision();

        //! effectue fonction puissance (entier, rationnel, reel)
        void fPOW();
        //! effectue fonction modulo (entier)
        void fMOD();
        //! effectue  fonction inversion du signe (entier, rationnel, reel, complexe)
        void fSIGN();
        //! effectue fonction sinus (entier, rationnel, reel)
        void fSIN();
        //! effectue fonction cosinus (entier, rationnel, reel)
        void fCOS();
        //! effectue fonction tangente (entier, rationnel, reel)
        void fTAN();
        //! effectue fonction sinus hyperbolique (entier, rationnel, reel)
        void fSINH();
        //! effectue fonction cosinus hyperbolique (entier, rationnel, reel)
        void fCOSH();
        //! effectue fonction tangente hyperbolique (entier, rationnel, reel)
        void fTANH();
        //! effectue fonction logarithme neperien (entier, rationnel, reel)
        void fLN();
        //! effectue fonction logarithme decimal (entier, rationnel, reel)
        void fLOG();
        //! effectue fonction inverse (entier, rationnel, reel)
        void fINV();
        //! effectue fonction racine carre (entier, rationnel, reel)
        void fSQRT();
        //! effectue fonction carre (entier, rationnel, reel, complexe)
        void fSQR();
        //! effectue fonction cube (entier, rationnel, reel, complexe)
        void fCUBE();
        //! effectue factorielle (entier)
        void fact();
        //!  evaluation d'une expression (Expression)
        void fEVAL();
};

#endif // PILE_H
