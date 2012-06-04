#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <pile.h>
#include <QString>
#include <QSignalMapper>
#include <cmath>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Calculatrice;
}

class Calculatrice : public QMainWindow
{
    Q_OBJECT




public Q_SLOTS  :
    void creerTab();
    void ecrire(const QString &a);
    void effacer();
    void envoyer();
    void afficher(int max);
    void annuler();
    void retablir();
    
public:
    explicit Calculatrice(QWidget *parent = 0);
    ~Calculatrice();
    std::vector<Pile * > onglet;

private:
    static const QString AFFICHAGE_NAME;
    Ui::Calculatrice *ui;
    QSignalMapper * mapper;
    Pile *pileActive();
    void analyse(const QString & txt);
    Constante * getConstante(QString & txtTemp);
    int getSizeNumber(const QString & txt);




};

#endif // CALCULATRICE_H
