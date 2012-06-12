#ifndef XML_DOM
#define XML_DOM

#include <QFile>
#include <QMessageBox>
#include <QtGui>
#include <QtXml>
#include <QWidget>

#include <iostream>
#include <QDomDocument>
#include "constante.h"



class Calculatrice;

//! Xml_Dom class.
/*!
  Classe de lecture de fichier XML
*/
class Xml_Dom : public QWidget
{
        public:
    //! constructeur.
    /*!
      \param pointeur sur la fenetre de la calculatrice
      lit puis construit les piles a l'ouverture de l'application
    */
        Xml_Dom(Calculatrice* c);
        //! destructeur.
        ~Xml_Dom();


};

#endif
