#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <pile.h>

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
    
private:
    Ui::Calculatrice *ui;
};

#endif // CALCULATRICE_H
