#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <pile.h>
#include <QString>
#include <QSignalMapper>

namespace Ui {
class Calculatrice;
}

class Calculatrice : public QMainWindow
{
    Q_OBJECT
    std::list<Pile> onglet;



public Q_SLOTS  :
    void creerTab();
    void ecrire(const QString &a);
    void effacer();
    void envoyer();

    
public:
    explicit Calculatrice(QWidget *parent = 0);
    ~Calculatrice();

private:
    static const QString AFFICHAGE_NAME;
    Ui::Calculatrice *ui;
    QSignalMapper * mapper;
    Pile * pileActive();
    void analyse(const QString & txt);
};

#endif // CALCULATRICE_H
