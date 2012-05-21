#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <pile.h>
#include <QString>

namespace Ui {
class Calculatrice;
}

class Calculatrice : public QMainWindow
{
    Q_OBJECT
    std::list<Pile> calc;




    
public:
    explicit Calculatrice(QWidget *parent = 0);
    ~Calculatrice();

    void afficher(QString str);


private:
    Ui::Calculatrice *ui;
};

#endif // CALCULATRICE_H
