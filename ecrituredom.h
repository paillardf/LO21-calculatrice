#ifndef ECRITUREDOM_H
#define ECRITUREDOM_H

#include <QStack>
#include <QFile>
#include <constante.h>
#include <qdom.h>
#include "qtextstream.h"


//! EcritureDom class.
/*!
  classe d'ecriture dans un fichier xml de l'etat de la calculette
*/
class EcritureDom
{

        public:
    //! constructeur.
                EcritureDom();
    //! destructeur.
                ~EcritureDom();
                //! ajoute une pile dans le fichier xml
                /*!
                  \param pointeur vers la pile a ajouter
                */
                void ajoutpile(QStack<Constante *> * onglet);
                //! enregistre un parametre de la calculatrice
                /*!
                  \param valeur a ajouter
                */
                void ajoutpara(QString type);


        private :

                 //! variable du document
                QDomDocument doc;
                //! element XML calculatrice
                QDomElement cal;
                //! element XML GUI
                QDomElement GUI;
                //! element XML pile
                QDomElement piles;
                //! reference du fichier
                QFile file;
                //! stream d'ecrire dans le fichier
                QTextStream out;

};

#endif // ECRITUREDOM_H
