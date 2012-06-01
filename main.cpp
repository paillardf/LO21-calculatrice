#include <QtGui/QApplication>
#include "calculatrice.h"
#include "iostream"





int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   Calculatrice w;
   w.show();


//    CEntier test = CEntier(8);
//    CEntier test2 = CEntier(5);
//    Constante* result = test+test2;
//    QString str(result->getValuetoString());
//    w.afficher(str);

//   int i ,j;
//   toFraction(3.897 ,i , j);

//  qDebug()<< "Resultat = "<<i<<"/"<<j;


    a.exec();



}


