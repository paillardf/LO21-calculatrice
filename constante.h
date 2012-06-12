
#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <QString>
#include <QTextStream>
#include <typeinfo>

//! Constante class.
/*!
  classe virtuelle des Constantes
*/
class Constante
{
public:

    //! retourne le contenu de la constante sous forme de texte
    /*!
      \return QString valeur formatee de la constante
    */
    virtual QString getValuetoString() const = 0;

    //! retourne le resultat de l'operation + entre deux constantes
    /*!
      \param c1 reference vers le deuxieme operande de type Constante
      \return un pointeur Constante sur le resultat
    */
    virtual Constante * operator+(Constante & c1) = 0;
    //! retourne le resultat de l'operation - entre deux constantes
    /*!
      \param c1 reference vers le deuxieme operande de type Constante
      \return un pointeur Constante sur le resultat
    */
    virtual Constante * operator-(Constante & c1) = 0;
    //! retourne le resultat de l'operation * entre deux constantes
    /*!
      \param c1 reference vers le deuxieme operande de type Constante
      \return un pointeur Constante sur le resultat
    */
    virtual Constante * operator*(Constante & c1) = 0;
    //! retourne le resultat de l'operation / entre deux constantes
    /*!
      \param c1 reference vers le deuxieme operande de type Constante
      \return un pointeur Constante sur le resultat
    */
    virtual Constante * operator/(Constante & c1) = 0;

    //! retourne une copie de la constante
    /*!
      \return pointeur vers une copie de la constante
    */
    virtual Constante * getCopy() = 0;


};

//! CEntier class.
/*!
  classe des types entier
*/
class CEntier : public Constante
{
private:
    //! valeur entiere de la constante
    int value;
public:

    //! constructeur.
    /*!
      \param v valeur entiere de la constante
    */
    CEntier(int v):value(v){}
    //! constructeur par copie.
    /*!
      \param c reference vers la constante a copier
    */
    CEntier(const CEntier & c):value(c.getValue()){}


    Constante * getCopy()
    {
        return new CEntier(*this);
    }


    //! retourne la valeur entier de la constante
    /*!
      \return valeur entiere
    */
    int getValue() const{
        return value;
    }

    //! affecter une valeur entier a la constante
    /*!
      \param e valeur entiere
    */
    void setValue(int e){
         value=e;
     }

    QString getValuetoString() const{
        QString test = QString::number(value);
        return test;
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);

    //! destructeur.
    ~CEntier(){}
};


//! CReel class.
/*!
  classe des types reels
*/
class CReel : public Constante
{
private:
    //! valeur de la constante
    float value;

public:

    //! constructeur.
    /*!
      \param v valeur de la constante
    */
    CReel(float v):value(v){}
    //! constructeur par copie.
    /*!
      \param c reference vers le CReel a copier
    */
    CReel(const CReel & c):value(c.getValue()){}

    Constante * getCopy()
    {
        return new CReel(*this);
    }

    //! retourne la valeur de la constante
    /*!
      \return valeur float
    */
     float getValue() const{
        return value;
    }
     //! affecter une valeur a la constante
     /*!
       \param e valeur float
     */
     void setValue(float e){
          value=e;
      }

    QString getValuetoString()const{
       return QString::number(value);
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
    //! destructeur.
    ~CReel(){}
};

//! CRationnel class.
/*!
  classe des types rationnels
*/
class CRationnel : public Constante
{
private:

    //! valeur entiere du numerateur
    int num;
    //! valeur entiere du denominateur
    int denom;

    //! converti un float en fraction
    /*!
      \param f valeur float a convertir
      \param n reference vers le numerateur
      \param d reference vers le denominateur
    */
    void toFraction(float f, int & n, int & d);

    //! calcul du pgcd
    /*!
      \param a parametre entier 1
      \param b parametre entier 2
      \return resultat entier
    */
    int PGCD(int a, int b);

public:
    //! constructeur.
    /*!
      \param n numerateur
      \param d denominateur
    */
    CRationnel(int n, int d):num(n), denom(d){}
    //! constructeur par copie.
    /*!
      \param c reference vers le CRationnel a copier
    */
    CRationnel(const CRationnel & c):num(c.getNum()), denom(c.getDenom()){}

    //! constructeur avec float.
    /*!
      \param f float a convertir
    */
    CRationnel(float f){
        toFraction(f, num, denom);
    }

    Constante * getCopy()
    {
        return new CRationnel(*this);
    }


    //! renvoit le numerateur.
    /*!
      \return numerateur integer
    */
    int getNum() const{
        return num;
    }

    //! renvoit le denominateur.
    /*!
      \return denominateur integer
    */
    int getDenom() const{
        return denom;
    }

    //! affect un numerateur.
    /*!
      \param e numerateur integer
    */
    void setNum(int e){
        num=e;
    }

    //! affect un denominateur.
    /*!
      \param e denominateur integer
    */
    void setDenom(int e){
        denom =e;
    }

    QString getValuetoString()const{
        QString test = QString::number(num)+'/'+QString::number(denom);
        return test;
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);

    //! destructeur.
    ~CRationnel(){}
};


//! CExpression class.
/*!
  classe des types expressions
*/
class CExpression : public Constante
{
private:
    //! Valeur de l expression
    QString exp;

public:
    //! constructeur.
    /*!
     \param ex expression
    */
    CExpression(const QString & ex):exp(ex){}
    //! constructeur par copie.
    /*!
     \param c reference de l'expression a copier
    */
    CExpression(const CExpression & c ):exp(c.getExp()){}


    Constante * getCopy()
    {
        return new CExpression(*this);
    }

    //! retourne la valeur de l'expression
    /*!
     \return QString expression
    */
    QString getExp() const{
        return exp;
    }
    //! affecte l'expression
    /*!
     \param e expression
    */
    void setExp(const QString & e){
         exp=e;
    }
    QString getValuetoString() const{
        return exp;
    }

    //! effectue l'operation - inversee
    /*!
     \param e valeur a ajouter
    */
    Constante * operator-(QString e);
    //! affectue l'operation / inversee
    /*!
     \param e valeur a ajouter
    */
    Constante * operator/(QString e);


    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);

    //! destructeur.
    ~CExpression(){}
};


//! CComplexe class.
/*!
  classe des types complexes
*/
class CComplexe : public Constante
{
private:
    //! pointeur vers la constante partie reel du CComplexe.
    Constante* re;
    //! pointeur vers la constante partie imaginaire du CComplexe.
    Constante* im;
public:
    //! constructeur.
    /*!
      \param r pointeur vers la constante partie reel
      \param i pointeur vers la constante partie imaginaire
    */
    CComplexe(Constante* r, Constante* i){re=r; im=i;}

    //! constructeur.
    /*!
      \param c reference vers le CComplexe a copier
    */
    CComplexe(const CComplexe & c){
        im = c.getIm()->getCopy();
        re = c.getRe()->getCopy();
   }

    Constante * getCopy()
    {
        return new CComplexe(*this);
    }

    //! destructeur.
    ~CComplexe(){delete re; delete im;}

    //! retourne la partie reel du complexe.
    /*!
      \return pointeur vers la constante partie reel
    */
    Constante* getRe() const {
        return re;
    }

    //! retourne la partie imaginaire du complexe.
    /*!
      \return pointeur vers la constante partie imaginaire
    */
    Constante* getIm() const{
        return im;
    }

    QString getValuetoString()const{
        QString test = re->getValuetoString()+'$'+im->getValuetoString();
        return test;
    }

    Constante * operator+(Constante & c1);
    Constante * operator-(Constante & c1);
    Constante * operator*(Constante & c1);
    Constante * operator/(Constante & c1);
};



#endif // CONSTANTE_H
