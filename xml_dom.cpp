#include "Xml_Dom.h"


#include "calculatrice.h"


using namespace std;

Xml_Dom::Xml_Dom(Calculatrice* c) : QWidget()
{
    QDomDocument doc("mydocument");
     QFile file("xml_doc.xml");
     if (!file.open(QIODevice::ReadOnly)){
         QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
         return;}
     if (!doc.setContent(&file)) {
         QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
         file.close();
         return;
     }

     file.close();

     QDomElement docElem = doc.documentElement();

      QDomNode n = docElem.firstChild();
       while(!n.isNull()) {//QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le doc");
      QDomElement e = n.toElement(); // try to convert the node to an element.
      if(!e.isNull()) {
         //QMessageBox::information(this, "Nom de la balise", "Le nom de la balise est :" + e.tagName());
                 if(e.tagName()=="GUI"){
                    //modifGUI

                     QDomNodeList Lbout = n.childNodes();
                     for(int h=0; h<Lbout.size();h++){
                         QDomNode newGUI = Lbout.at(h);
                         QDomElement eet = newGUI.toElement();
                         if(!eet.isNull()) {

                     if(eet.attribute("value")=="Entier"){
                         c->chgEntier();
                     }
                     if(eet.attribute("value")=="Rationnel"){
                         c->chgRationnel();
                     }
                     if(eet.attribute("value")=="Reel"){
                         c->chgReel();
                     }
                     if(eet.attribute("value")=="Degre"){
                         c->chgDegre();
                     }
                     if(eet.attribute("value")=="Radian"){
                         c->chgRadian();
                     }
                     if(eet.attribute("value")=="Complexe"){
                         c->chgComplexe();
                     }
                 }}

                }

                if(e.tagName()=="Piles"){

                     QDomNodeList Lpiles = n.childNodes();

                     for(int j=0; j<Lpiles.size(); j++){
                         QDomNode newpile = Lpiles.at(j);
                         QDomElement eee = newpile.toElement();
                         //QMessageBox::information(this, "Nom de la pile", "pile : " + eee.tagName());
                        if(eee.tagName()=="Pile"){
                           c->creerTab();
                           c->pileActive()->clear();
                             QDomNodeList Lconst = newpile.childNodes();
                             for(int r=0; r<Lconst.size();r++){
                            // while(!Lconst.isEmpty()){
                                 QDomNode newconst = Lconst.at(r);
                                 QDomElement ee = newconst.toElement(); // try to convert the node to an element.
                                 if(!ee.isNull()) {
                                    //QMessageBox::information(this, "Nom de la const", "constante:" + ee.text());
                                    //QMessageBox::information(this, "value de la const", "val constante:" + ee.attribute("value"));

                                    if(ee.attribute("value")=="Entier"){
                                                int ent = ee.text().toInt();//QMessageBox::information(this, "entier", ent);
                                                c->pileActive()->push(new CEntier(ent));

                                    }
                                    if(ee.attribute("value")=="Rationnel"){
                                        QString str = ee.text(); QStringList li = str.split("/");
                                        int ent = li.at(0).toInt();
                                        int dec = li.at(1).toInt();
                                        c->pileActive()->push(new CRationnel(ent,dec));
                                        //QMessageBox::information(this, "rat", "val constante:" + li.at(0));
                                        //QMessageBox::information(this, "rat", "val constante:" + li.at(1));
                                    }
                                    if(ee.attribute("value")=="Reel"){
                                        float val = ee.text().toFloat();
                                        c->pileActive()->push(new CReel(val));
                                        //QMessageBox::information(this, "reel", "val constante:" + val);
                                    }
                                    if(ee.attribute("value")=="Expression"){
                                        c->pileActive()->push(new CExpression(ee.text()));
                                        //QMessageBox::information(this, "exp", "val constante:" + ee.text());
                                    }
                                    if(ee.attribute("value")=="Complexe"){
                                        QString str = ee.text(); QStringList li = str.split("=");
                                        QString first = li.at(0);
                                        QString second = li.at(1);
                                        QStringList li1 = first.split(":");
                                        QStringList li2 = second.split(":");
                                        QString type1 = li1.at(0);
                                        QString type2 = li2.at(0);
                                        QString val1 = li1.at(1);
                                        QString val2 = li2.at(1);

                                        Constante* re;
                                        Constante* im;

                                        if(type1=="entier"){
                                            int ent = val1.toInt();
                                            re = (Constante*) new CEntier(ent);
                                        }
                                        if(type1=="rationnel"){
                                            QString str = val1; QStringList li8 = str.split("/");
                                            int ent = li8.at(0).toInt();
                                            int dec = li8.at(1).toInt();
                                            re = (Constante*) new CRationnel(ent,dec);
                                        }
                                        if(type1=="reel"){
                                            int val = val1.toFloat();
                                            re = (Constante*) new CReel(val);
                                        }


                                        if(type2=="entier"){
                                            int ent = val2.toInt();
                                            im = (Constante*) new CEntier(ent);
                                        }
                                        if(type2=="rationnel"){
                                            QString str = val2; QStringList li8 = str.split("/");
                                            int ent = li8.at(0).toInt();
                                            int dec = li8.at(1).toInt();
                                            im = (Constante*) new CRationnel(ent,dec);
                                        }
                                        if(type2=="reel"){
                                            int val = val2.toFloat();
                                            im = (Constante*) new CReel(val);
                                        }

                                        c->pileActive()->push(new CComplexe(re,im));
                                    }


                                }
                            }
                             c->pileActive()->afficher(5);
                         }
                     }
                 }

           }
         n = n.nextSibling();
      }

}

Xml_Dom::~Xml_Dom()
{

}
