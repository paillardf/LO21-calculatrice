#include "ecrituredom.h"
#include "qmessagebox.h"

EcritureDom::EcritureDom()
{
            cal = doc.createElement("calcu");
            doc.appendChild(cal);
            GUI = doc.createElement("GUI");
            cal.appendChild(GUI);
            piles = doc.createElement("Piles");
            cal.appendChild(piles);

            file.setFileName("xml_doc.xml");

            if (!file.open(QIODevice::WriteOnly))
                int i = 4;// ouverture du fichier de sauvegarde
                   // return; // en écriture
            out.setDevice(&file); // association du flux au fichier
}

EcritureDom::~EcritureDom()
{
        // insertion en début de document de <?xml version="1.0" ?>
        QDomNode noeud = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"ISO-8859-1\"");
        doc.insertBefore(noeud,doc.firstChild());
        // sauvegarde dans le flux (deux espaces de décalage dans l'arborescence)
        doc.save(out,2);
        file.close();
}

void EcritureDom::ajoutpile(QStack<Constante *>* pile){

    QStack<Constante*> copie;
    while(!pile->isEmpty()){
        copie.push(pile->pop());;
    }


    QDomElement pil = doc.createElement("Pile");
    piles.appendChild(pil);

    Constante* inter;

    while(!copie.isEmpty()){
        inter = copie.pop();

        if(typeid(*inter) == typeid(CEntier)){
            CEntier *c1 = (CEntier*) inter;
            int value = c1->getValue();
            QDomElement Constan = doc.createElement("Constante");
            Constan.setAttribute("value","Entier");
            pil.appendChild(Constan);
            QString tes = tes.number(value);
            QDomText t1 = doc.createTextNode(tes);
            Constan.appendChild(t1);
        }
        else if(typeid(*inter) == typeid(CRationnel)){
            CRationnel *c1 = (CRationnel*) inter;
            int num = c1->getNum();
            int denom = c1->getDenom();
            QDomElement Constan = doc.createElement("Constante");
            Constan.setAttribute("value","Rationnel");
            pil.appendChild(Constan);
            QString tes = tes.number(num);
            QString tess = tess.number(denom);
            QString fin = tes+'/'+tess;
            QDomText t1 = doc.createTextNode(fin);
            Constan.appendChild(t1);
        }
        else if(typeid(*inter) == typeid(CReel)){
            CReel *c1 = (CReel*) inter;
            float val = c1->getValue();
            QDomElement Constan = doc.createElement("Constante");
            Constan.setAttribute("value","Reel");
            pil.appendChild(Constan);
            QString tes = tes.number(val);
            QDomText t1 = doc.createTextNode(tes);
            Constan.appendChild(t1);
        }
        else if(typeid(*inter) == typeid(CExpression)){
            CExpression *c1 = (CExpression*) inter;
            QString exp = c1->getExp();
            QDomElement Constan = doc.createElement("Constante");
            Constan.setAttribute("value","Expression");
            pil.appendChild(Constan);
            QDomText t1 = doc.createTextNode(exp);
            Constan.appendChild(t1);
        }
        else if(typeid(*inter) == typeid(CComplexe)){
            CComplexe *c1 = (CComplexe*) inter;
            Constante* re = c1->getRe();
            Constante* im = c1->getIm();
            QDomElement Constan = doc.createElement("Constante");
            Constan.setAttribute("value","Complexe");
            pil.appendChild(Constan);
            QString nbre,nbim;

            if(typeid(*re) == typeid(CEntier)){
                CEntier *c2 = (CEntier*) re;
                int value1 = c2->getValue();
                nbre = "entier:" + nbre.number(value1);
            }
            else if(typeid(*re) == typeid(CRationnel)){
                CRationnel *c2 = (CRationnel*) re;
                int num1 = c2->getNum();
                int denom1 = c2->getDenom();
                nbre = "rationnel:" + nbre.number(num1) + '/'+ nbre.number(denom1);
            }
            else if(typeid(*re) == typeid(CReel)){
                CReel *c2 = (CReel*) re;
                int val1 = c2->getValue();
                nbre = "reel:" + nbre.number(val1);
            }

            if(typeid(*im) == typeid(CEntier)){
                CEntier *c3 = (CEntier*) im;
                int value2 = c3->getValue();
                nbim = "entier:" + nbre.number(value2);
            }
            else if(typeid(*im) == typeid(CRationnel)){
                CRationnel *c3 = (CRationnel*) im;
                int num2 = c3->getNum();
                int denom2 = c3->getDenom();
                nbim = "rationnel:" + nbre.number(num2) + '/' + nbre.number(denom2);
            }
            else if(typeid(*im) == typeid(CReel)){
                CReel *c3 = (CReel*) im;
                int val2 = c3->getValue();
                nbim = "reel:" + nbre.number(val2);
            }

            QString res = nbre + '=' + nbim;
            QDomText t1 = doc.createTextNode(res);
            Constan.appendChild(t1);
        }
    }
}

void EcritureDom::ajoutpara(QString type){
    QDomElement bout = doc.createElement("bouton");
    GUI.appendChild(bout);
    bout.setAttribute("value",type);

}
