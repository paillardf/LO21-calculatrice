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

        void fPOW(); // puissance (entier, rationnel, r�el)
        void fMOD(); // modulo (entier)
        void fSIGN(); // inversion du signe (entier, rationnel, r�el, complexe)

        void fSIN(); // sinus (entier, rationnel, r�el)
        void fCOS(); // cosinus (entier, rationnel, r�el)
        void fTAN(); // tangente (entier, rationnel, r�el)
        void fSINH(); // sinus hyperbolique (entier, rationnel, r�el)
        void fCOSH(); // cosinus hyperbolique (entier, rationnel, r�el)
        void fTANH(); // tangente hyperbolique (entier, rationnel, r�el)
        void fLN(); // logarithme n�p�rien (entier, rationnel, r�el)
        void fLOG(); // logarithme d�cimal (entier, rationnel, r�el)
        void fINV(); // inverse (entier, rationnel, r�el)
        void fSQRT(); // racine carr� (entier, rationnel, r�el)
        void fSQR(); // fonction carr� (entier, rationnel, r�el, complexe)
        void fCUBE(); // fonction cube (entier, rationnel, r�el, complexe)
        void fact(); // factorielle (entier)
        void fEVAL(); // �valuation d'une expression (Expression)
};

#endif // PILE_H
