#include <QtGui/QApplication>
#include "calculatrice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculatrice w;
    w.show();
    
    return a.exec();
}
