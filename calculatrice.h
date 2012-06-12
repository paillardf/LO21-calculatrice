#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <pile.h>
#include <QString>
#include <QSignalMapper>
#include <cmath>
#include <QMessageBox>
#include <QFile>
#include <xml_dom.h>
#include <ecrituredom.h>

namespace Ui {
class Calculatrice;
}


//! Calculatrice class.
/*!
  fenetre principale de la calculatrice.
*/
class Calculatrice : public QMainWindow
{
    Q_OBJECT



public Q_SLOTS  :
    //! cree un nouvel onglet
    /*!
          \sa detruireTab()
     */
    void creerTab();
    //! detruit l'onglet actif
    /*!
          \param index un integer (position de l'onglet)
          \sa creerTab()
     */
    void detruireTab(int index);
    //! ecrire dans le champ texte
    /*!
          \param a une QString.
          \sa effacer(), envoyer() et afficher()
     */
    void ecrire(const QString &a);
    //! effacer le dernier caractère du champ texte
    /*!
         \sa ecrire(), envoyer() et afficher()
     */
    void effacer();
    //! Envoyer le contenu du champ texte pour etre analyser
    /*!
         \sa ecrire(), effacer() et afficher()
     */
    void envoyer();
    //! afficher la pile active
    /*!
          \param max nombre d'element à afficher.
          \sa ecrire(), effacer() et envoyer()
     */
    void afficher(int max);
    //! annule la dernière commande
    /*!
          \sa retablir()
     */
    void annuler();
    //! retabli la dernière commande
    /*!
          \sa annuler()
     */
    void retablir();
    //! redimentionne la fenetre de la Calculatrice
    /*!
          \param boolean pour les deux positions.
     */
    void redimentionner(bool);
    
public:
    //! Initialisation d'un objet Calculatrice si aucun n'existe
    /*!
         \return pointeur vers un objet Calculatrice
          \sa kill(), Calculatrice() et ~Calculatrice()
     */
    static Calculatrice *getInstance ()
      {
        if (NULL == _singleton)
          {
            _singleton =  new Calculatrice();
          }
        return _singleton;
      }

    //! Detruit l'unique objet Calculatrice
    /*!
       \sa getInstance(), Calculatrice() et ~Calculatrice()
     */
    static void kill ()
      {
        if (NULL != _singleton)
          {
            delete _singleton;
            _singleton = NULL;
          }
      }

    //! Recherche et retourne la pile active
    /*!
      \return pointeur de pile active
     */
    Pile *pileActive();
    //! Tableau des pointeurs de piles
        /*! Chacune des piles correspond à un onglet dans la fenetre graphique */
    std::vector<Pile * > onglet;

    //! Active l'option Entier
    /*!
          \sa chgRationnel(), chgReel(), chgComplexe(), chgDegre(), chgRadian() et sauvegarde()
     */
    void chgEntier();
    //! Active l'option Rationnel
    /*!
          \sa chgEntier(), chgReel(), chgComplexe(), chgDegre(), chgRadian() et sauvegarde()
     */
    void chgRationnel();
    //! Active l'option Reel
    /*!
          \sa chgEntier(), chgRationnel(), chgComplexe(), chgDegre(), chgRadian() et sauvegarde()
     */
    void chgReel();
    //! Active l'option Complexe
    /*!
          \sa chgEntier(), chgRationnel(), chgReel(), chgDegre(), chgRadian() et sauvegarde()
     */
    void chgComplexe();
    //! Active l'option Degre
    /*!
          \sa chgEntier(), chgRationnel(), chgReel(), chgComplexe(), chgRadian() et sauvegarde()
     */
    void chgDegre();
    //! Active l'option Radian
    /*!
          \sa chgEntier(), chgRationnel(), chgReel(), chgComplexe(), chgDegre() et sauvegarde()
     */
    void chgRadian();
    //! Enregistre l'etat actuelle des piles et options de la calculatrice.
    /*!
          \sa chgEntier(), chgRationnel(), chgReel(), chgComplexe(), chgDegre() et chgRadian()
     */
    void sauvegarde();


private:
    //! un constructeur.
        /*!
          constructeur prive utilise par le singleton
        */
    explicit Calculatrice(QWidget *parent = 0);
    //! un destructeur.
        /*!
          destructeur prive utilise par le singleton
        */
    ~Calculatrice();

    //! pointeur vers l'unique objet Calculatrice
    static Calculatrice * _singleton;
    //! variable du nom du widget d'affichage
    static const QString AFFICHAGE_NAME;
    //! pointeur l'interface ui
    Ui::Calculatrice *ui;
    //! Pointeur du mapper
        /*! Fait le lien entre les boutons et la fonction ecrire */
    QSignalMapper * mapper;


    //! Analyse de la chaine de caractere passe en argument
        /*!
          \param txt QString
          \sa getConstante() et getSizeNumber()
        */
    void analyse(const QString & txt);
    //! Creer une constante d'apres une chaine de caractere
        /*!
          \param txtTemp reference de QString (modifié par la fonction)
          \return un pointeur de constante
          \sa analyse() et getSizeNumber()
        */
    Constante * getConstante(QString & txtTemp);
    //! compte le nombre de chiffre d'une chaine de caratere
        /*!
          \param txt QString
          \return entier nombre de chiffres
          \sa analyse() et getConstante()
        */
    int getSizeNumber(const QString & txt);

    //! Analyse et traite une expression sur la pile active
    void fEVAL();

};




#endif // CALCULATRICE_H
