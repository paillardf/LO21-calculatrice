#include <QtGui/QApplication>
#include "calculatrice.h"
#include "iostream"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Calculatrice w;
   w.show();

    Constante* test = new CEntier(8);
    Constante* test2 = new CEntier(5);
    //((test->operator+(*test2)).getValuetoString());
    QString str("TEST");
    w.afficher(str);
    a.exec();
}
