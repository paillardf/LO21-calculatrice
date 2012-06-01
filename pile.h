#ifndef PILE_H
#define PILE_H

#include <commande.h>
#include <constante.h>
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QStack>
#include <QDebug>
#include <cmath>
#include <stdexcept>


class Pile : public QStack<Constante *>
{

private:

    QRadioButton * btEntier;
    QRadioButton * btRationnel;
    QRadioButton * btDegre;
    QCheckBox * btComplexe;

    QStack<Commande *> listeCommande;
    bool executionCommande;
    int posCommande;
    void saveCommande(Commande *c);

    bool isRadian(){ return !btDegre->isChecked();}
    bool isDegre(){ return btDegre->isChecked();}
    bool isEntier(){ return btEntier->isChecked();}
    bool isRationnel(){ return btRationnel->isChecked();}
    bool isReel(){ return !btRationnel->isChecked()&&!btEntier->isChecked();}
    bool isComplexe(){ return btComplexe->isChecked();}

public:
    Pile(QLabel * aff, QRadioButton * _btEntier,QRadioButton * _btRationnel,QRadioButton * _btDegre,QCheckBox * _btComplexe, int max);
    ~Pile();
    Pile& clone(Pile &p) const;
    QLabel * affichage;
    void cast(Constante* & cst);
    void afficher(int tailleMax);
    void annuler();
    void retablir();

        void swap();
        void sum();
        void mean();
        void clear();
        void dup();
        void drop();

        void fAddition();
        void fSoustraction();
        void fMultiplication();
        void fDivision();

        void fPOW(); // puissance (entier, rationnel, réel)
        void fMOD(); // modulo (entier)
        void fSIGN(); // inversion du signe (entier, rationnel, réel, complexe)

        void fSIN(); // sinus (entier, rationnel, réel)
        void fCOS(); // cosinus (entier, rationnel, réel)
        void fTAN(); // tangente (entier, rationnel, réel)
        void fSINH(); // sinus hyperbolique (entier, rationnel, réel)
        void fCOSH(); // cosinus hyperbolique (entier, rationnel, réel)
        void fTANH(); // tangente hyperbolique (entier, rationnel, réel)
        void fLN(); // logarithme népérien (entier, rationnel, réel)
        void fLOG(); // logarithme décimal (entier, rationnel, réel)
        void fINV(); // inverse (entier, rationnel, réel)
        void fSQRT(); // racine carré (entier, rationnel, réel)
        void fSQR(); // fonction carré (entier, rationnel, réel, complexe)
        void fCUBE(); // fonction cube (entier, rationnel, réel, complexe)
        void fact(); // factorielle (entier)
        void fEVAL(); // évaluation d'une expression (Expression)
};

#endif // PILE_H
